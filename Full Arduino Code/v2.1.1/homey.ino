//================================================================================//
//                                 SETUP
//================================================================================//
void setupHomey() {
  //----- Start with a device name
  Homey.begin("Homey e-paper");  //Get name for your device

  //----- Add capability
  Homey.setClass("sensor");
  Homey.addCapability("measure_battery");

  //----- Setting card
  Homey.addAction("Settings", defineSettings);                 //"Language=FR; Deep_SleepTime=0; Click_Mark_Enable=true; Wake_Up_With_Touch_Screen=true;
  Homey.addAction("Battery_Calibration", batteryCalibration);  // "Voltage_Min=3, Voltage_Max=4.2" USE POINT NOT COMMA IN VALUE
  Homey.addAction("Screen_Repair", screenRepair);

  //----- Action card
  Homey.addAction("Screen_Layout", defineLayout);  // "Z1=D, Z2=S, Z3=S, Z4=S, Z5=S, Z6=D, Z7=S, Z8=S"
  Homey.addAction("Header", writeHeaderValue);     // "Value_1=21.5°C; Value_2=12:30"
  Homey.addAction("Zone_1", displayZone1);         //"Name=Salon; Value_L1=ON; Value_L2=; Clickable=true; Icon=light; Type=light; Font_Size=1"
  Homey.addAction("Zone_2", displayZone2);
  Homey.addAction("Zone_3", displayZone3);
  Homey.addAction("Zone_4", displayZone4);
  Homey.addAction("Zone_5", displayZone5);
  Homey.addAction("Zone_6", displayZone6);
  Homey.addAction("Zone_7", displayZone7);
  Homey.addAction("Zone_8", displayZone8);
}  //END setupHomey()






//================================================================================//
//                                 BATTERY CALIBRATION
//================================================================================//
void batteryCalibration() {
  String data = Homey.value;
  homeyData homeyValues = extractHomeyData(data);
  minVolt = (homeyValues.vMin).toFloat();
  maxVolt = (homeyValues.vMax).toFloat();
  prefs.putString("maxVolt", String(maxVolt));
  prefs.putString("minVolt", String(minVolt));
}  //END batteryCalibration()





//================================================================================//
//                                 DEFINE SETTINGS
//================================================================================//
void defineSettings() {
  String data = Homey.value;
  homeyData homeyValues = extractHomeyData(data);
  lang = homeyValues.language;
  clickMarkEnable = stringToBool(homeyValues.enableClickMark);
  touchScreenWakeUp = stringToBool(homeyValues.wakeUpWithTouchScreen);
  displayWithTouchScreen = stringToBool(homeyValues.touchScreenMount);
  timeDeepSleep = (homeyValues.timeDeepSleep).toInt();
  timeBeforeSleep = homeyValues.beforeSleepTime.toInt();
  String easterEggToday = homeyValues.enableEasterEgg;
  if (easterEggToday == "ignore today" && easterEggToday != "") {
    ignoreEasterEgg();
  } else if (easterEggToday == "") easterEgg = true;
  else easterEgg = stringToBool(homeyValues.enableEasterEgg);
  if (!displayWithTouchScreen) {
    clickMarkEnable = false;
    touchScreenWakeUp = false;
  }
  if (timeDeepSleep == 0 && !displayWithTouchScreen && !touchScreenWakeUp) {
    deepSleepEnable = false;
  }
  if (timeDeepSleep == 0 && displayWithTouchScreen && !touchScreenWakeUp) {
    deepSleepEnable = false;
  }
  if (timeDeepSleep == 0 && displayWithTouchScreen && touchScreenWakeUp) {
    deepSleepEnable = true;
  }

  if (timeDeepSleep >= 1) deepSleepEnable = true;
  prefs.putBool("clickMark", clickMarkEnable);
  prefs.putBool("screenWakeUp", touchScreenWakeUp);
  prefs.putInt("timeDeepSleep", timeDeepSleep);
  prefs.putBool("deepSleep", deepSleepEnable);
  prefs.putString("lang", lang);
  prefs.putBool("touchScreen", displayWithTouchScreen);
  prefs.putBool("easterEgg", easterEgg);
  prefs.putBool("deepSleep", deepSleepEnable);
  prefs.putInt("timeBeforeSleep", timeBeforeSleep);

  debug("Settings received: " + data);
  debug("timeDeepSleep = " + String(timeDeepSleep));
  debug("deepSleepEnable = " + String(deepSleepEnable));
  debug("clickMarkEnable = " + String(clickMarkEnable));
  debug("touchScreenWakeUp = " + String(touchScreenWakeUp));
  debug("timeBeforeSleep = " + String(timeBeforeSleep));
  debug("minVolt = " + String(minVolt));
  debug("maxVolt = " + String(maxVolt));
  debug("New params received.");
  currentMillisRestart = millis();  // goToRestart()
  waitForRestart = true;            // goToRestart()
  //ESP.restart();
}  //END defineSetting()





//================================================================================//
//                              SEND BATTERY TO HOMEY
//================================================================================//
void sendBatteryToHomey() {
  if (!batterySended) {
    getBatteryPercent();
    Homey.setCapabilityValue("measure_battery", (int)batteryState);
    batterySended = true;
    debug("Battery level send to Homey: " + String(batteryState));
  }

  if (((millis() - currentMillisSendBattery) >= intervalSendBattery) && (!wifiModeAP) && ((!updating))) {
    getBatteryPercent();
    Homey.setCapabilityValue("measure_battery", (int)batteryState);
    currentMillisSendBattery = millis();
    debug("Battery level send to Homey: " + String(batteryState));
  }

}  //END sendBatteryToHomey()





//================================================================================//
//                                  WRITE HEADER VALUE
//================================================================================//
void writeHeaderValue() {
  String data = Homey.value;
  homeyData homeyValues = extractHomeyData(data);
  String val1 = homeyValues.headerVal1;
  String val2 = homeyValues.headerVal2;
  epd_copy_to_framebuffer(fullHeader, (uint8_t *)whiteHeader_data, framebuffer);
  if (!easterEgg || !easterEggDay) {
    writeln((GFXfont *)&OpenSans18B, val1.c_str(), &headerValue_x, &header_y, framebuffer);
    writeln((GFXfont *)&OpenSans18B, val2.c_str(), &headerTime_x, &header_y, framebuffer);
  }
  if (easterEgg && easterEggDay && !aprilFish) displayEasterEgg();
  if (easterEgg && easterEggDay && aprilFish) {
    val1 = "??????";
    val2 = "! hsiF lirpA yppaH  :-)";
    writeln((GFXfont *)&OpenSans18B, val1.c_str(), &headerValue_x, &header_y, framebuffer);
    writeln((GFXfont *)&OpenSans18B, val2.c_str(), &headerTime_x, &header_y, framebuffer);
  }
  getBatteryPercent();
  debug("Battery Percent = " + batteryPercent);
  if (batteryPercent.toInt() == 100) {
    writeln((GFXfont *)&OpenSans18B, batteryPercent.c_str(), &headerBattery_x, &header_y, framebuffer);
  } else if (batteryPercent.toInt() <= 99) {
    batteryPercent = " " + batteryPercent;
    writeln((GFXfont *)&OpenSans18B, batteryPercent.c_str(), &headerBattery_x, &header_y, framebuffer);
  } else drawBatteryIcon();
  counterDevice++;
  debug("Header data: " + String(data));
}  //END writeHeaderValue()





//================================================================================//
//                                  DISPLAY ZONES VALUES
//================================================================================//
//----- Zone 1
void displayZone1() {
  String data = Homey.value;
  debug("Data Zone 1: " + data);
  homeyData homeyValues = extractHomeyData(data);
  String type = homeyValues.type;
  String fontSize = homeyValues.sizeFont;
  deviceIconChoose = homeyValues.icon;
  String firstLineValue = convertType(homeyValues.valueL1, type);
  String secondLineValue = convertType(homeyValues.valueL2, type);
  String line3 = homeyValues.valueL3;
  String line4 = homeyValues.valueL4;
  String line5 = homeyValues.valueL5;
  String line6 = homeyValues.valueL6;
  String line7 = homeyValues.valueL7;
  String line8 = homeyValues.valueL8;
  String nameZone1 = homeyValues.name;
  device1clickable = stringToBool(homeyValues.clickable);
  weather = firstLineValue;
  if (easterEgg && aprilFish) {
    deviceIconChoose = "fool";
    fontSize = 5;
  }

  if (typeZone1 == 'S') {
    nameZone1 = nameZone1.substring(0, 11);
    firstLineValue = firstLineValue.substring(0, 7);
    secondLineValue = secondLineValue.substring(0, 7);
  }
  deviceIconNumber();
  if (type == "weather") {
    weatherIconNumber();
    epd_copy_to_framebuffer(iconZone1, (uint8_t *)weatherIconList[weatherIcon], framebuffer);
  } else
    epd_copy_to_framebuffer(iconZone1, (uint8_t *)deviceIconList80[deviceIcon], framebuffer);
  writeln(selectFontValue(fontSize), firstLineValue.c_str(), &valueZ1_x, &valueZ1_y, framebuffer);  //========
  valueZ1_x = 125;
  int line2_y = valueZ1Line2_y + (fontSize.toInt() * 4);                                                             //========
  writeln(selectFontValue(fontSize), secondLineValue.c_str(), &valueZ1_x, &line2_y, framebuffer);                    //=======
  if (typeZone1 != 'Q') writeln(selectFontName(fontSize), nameZone1.c_str(), &nameZ1_x, &nameLine1_y, framebuffer);  //=========
  else writeln(selectFontName(fontSize), nameZone1.c_str(), &nameZ1_x, &nameLine2_y, framebuffer);                   //=======
  if (typeZone1 == 'Q') {
    columnZ1_x = 30;
    int Qline3_y = valueQLine3_y + (fontSize.toInt() * 4);
    int Qline4_y = Qline3_y + (fontSize.toInt() * 4) + 35;
    int Qline5_y = Qline4_y + (fontSize.toInt() * 4) + 35;
    int Qline6_y = Qline5_y + (fontSize.toInt() * 4) + 35;
    int Qline7_y = Qline6_y + (fontSize.toInt() * 4) + 35;
    int Qline8_y = Qline7_y + (fontSize.toInt() * 4) + 35;

    writeln(selectFontValue(fontSize), line3.c_str(), &columnZ1_x, &Qline3_y, framebuffer);
    columnZ1_x = 30;
    writeln(selectFontValue(fontSize), line4.c_str(), &columnZ1_x, &Qline4_y, framebuffer);
    columnZ1_x = 30;
    writeln(selectFontValue(fontSize), line5.c_str(), &columnZ1_x, &Qline5_y, framebuffer);
    columnZ1_x = 30;
    writeln(selectFontValue(fontSize), line6.c_str(), &columnZ1_x, &Qline6_y, framebuffer);
    if (fontSize.toInt() <= 3) {
      columnZ1_x = 30;
      writeln(selectFontValue(fontSize), line7.c_str(), &columnZ1_x, &Qline7_y, framebuffer);
    }
    if (fontSize.toInt() <= 2) {
      columnZ1_x = 30;
      writeln(selectFontValue(fontSize), line8.c_str(), &columnZ1_x, &Qline8_y, framebuffer);
    }
  }
  counterDevice++;
}  //END Zone 1


//----- Zone 2
void displayZone2() {
  if (typeZone2 != 'X') {
    String data = Homey.value;
    debug("Data Zone 2: " + data);
    homeyData homeyValues = extractHomeyData(data);
    String type = homeyValues.type;
    String fontSize = homeyValues.sizeFont;
    deviceIconChoose = homeyValues.icon;
    String firstLineValue = convertType(homeyValues.valueL1, type);
    String secondLineValue = convertType(homeyValues.valueL2, type);
    String line3 = homeyValues.valueL3;
    String line4 = homeyValues.valueL4;
    String line5 = homeyValues.valueL5;
    String line6 = homeyValues.valueL6;
    String line7 = homeyValues.valueL7;
    String line8 = homeyValues.valueL8;
    String nameZone1 = homeyValues.name;
    device2clickable = stringToBool(homeyValues.clickable);
    weather = firstLineValue;
    if (typeZone2 == 'S') {
      nameZone1 = nameZone1.substring(0, 11);
      firstLineValue = firstLineValue.substring(0, 7);
      secondLineValue = secondLineValue.substring(0, 7);
    }
    if (easterEgg && aprilFish) {
      deviceIconChoose = "fish";
      fontSize = 2;
    }
    deviceIconNumber();
    if (type == "weather") {
      weatherIconNumber();
      epd_copy_to_framebuffer(iconZone2, (uint8_t *)weatherIconList[weatherIcon], framebuffer);
    } else
      epd_copy_to_framebuffer(iconZone2, (uint8_t *)deviceIconList80[deviceIcon], framebuffer);
    writeln(selectFontValue(fontSize), firstLineValue.c_str(), &valueZ2_x, &valueZ1_y, framebuffer);  //======
    valueZ2_x = 365;
    int line2_y = valueZ1Line2_y + (fontSize.toInt() * 4);                                                             //========
    writeln(selectFontValue(fontSize), secondLineValue.c_str(), &valueZ2_x, &line2_y, framebuffer);                    //======
    if (typeZone2 != 'Q') writeln(selectFontName(fontSize), nameZone1.c_str(), &nameZ2_x, &nameLine1_y, framebuffer);  //======
    else writeln(selectFontName(fontSize), nameZone1.c_str(), &nameZ2_x, &nameLine2_y, framebuffer);                   //======
    if (typeZone2 == 'Q') {
      columnZ2_x = 270;  //+240
      int Qline3_y = valueQLine3_y + (fontSize.toInt() * 4);
      int Qline4_y = Qline3_y + (fontSize.toInt() * 4) + 35;
      int Qline5_y = Qline4_y + (fontSize.toInt() * 4) + 35;
      int Qline6_y = Qline5_y + (fontSize.toInt() * 4) + 35;
      int Qline7_y = Qline6_y + (fontSize.toInt() * 4) + 35;
      int Qline8_y = Qline7_y + (fontSize.toInt() * 4) + 35;

      writeln(selectFontValue(fontSize), line3.c_str(), &columnZ2_x, &Qline3_y, framebuffer);
      columnZ2_x = 270;
      writeln(selectFontValue(fontSize), line4.c_str(), &columnZ2_x, &Qline4_y, framebuffer);
      columnZ2_x = 270;
      writeln(selectFontValue(fontSize), line5.c_str(), &columnZ2_x, &Qline5_y, framebuffer);
      columnZ2_x = 270;
      writeln(selectFontValue(fontSize), line6.c_str(), &columnZ2_x, &Qline6_y, framebuffer);
      if (fontSize.toInt() <= 3) {
        columnZ2_x = 270;
        writeln(selectFontValue(fontSize), line7.c_str(), &columnZ2_x, &Qline7_y, framebuffer);
      }
      if (fontSize.toInt() <= 2) {
        columnZ2_x = 270;
        writeln(selectFontValue(fontSize), line8.c_str(), &columnZ2_x, &Qline8_y, framebuffer);
      }
    }
    counterDevice++;
  }
}  //END Zone 2


//----- Zone 3
void displayZone3() {
  if (typeZone3 != 'X') {
    String data = Homey.value;
    debug("Data Zone 3: " + data);
    homeyData homeyValues = extractHomeyData(data);
    String type = homeyValues.type;
    String fontSize = homeyValues.sizeFont;
    deviceIconChoose = homeyValues.icon;
    String firstLineValue = convertType(homeyValues.valueL1, type);
    String secondLineValue = convertType(homeyValues.valueL2, type);
    String line3 = homeyValues.valueL3;
    String line4 = homeyValues.valueL4;
    String line5 = homeyValues.valueL5;
    String line6 = homeyValues.valueL6;
    String line7 = homeyValues.valueL7;
    String line8 = homeyValues.valueL8;
    String nameZone1 = homeyValues.name;
    device3clickable = stringToBool(homeyValues.clickable);
    weather = firstLineValue;
    if (typeZone3 == 'S') {
      nameZone1 = nameZone1.substring(0, 11);
      firstLineValue = firstLineValue.substring(0, 7);
      secondLineValue = secondLineValue.substring(0, 7);
    }
    if (easterEgg && aprilFish) {
      deviceIconChoose = "fish";
      fontSize = 1;
    }
    deviceIconNumber();
    if (type == "weather") {
      weatherIconNumber();
      epd_copy_to_framebuffer(iconZone3, (uint8_t *)weatherIconList[weatherIcon], framebuffer);
    } else
      epd_copy_to_framebuffer(iconZone3, (uint8_t *)deviceIconList80[deviceIcon], framebuffer);
    writeln(selectFontValue(fontSize), firstLineValue.c_str(), &valueZ3_x, &valueZ1_y, framebuffer);  //======
    valueZ3_x = 605;
    int line2_y = valueZ1Line2_y + (fontSize.toInt() * 4);                                                             //========
    writeln(selectFontValue(fontSize), secondLineValue.c_str(), &valueZ3_x, &line2_y, framebuffer);                    //======
    if (typeZone3 != 'Q') writeln(selectFontName(fontSize), nameZone1.c_str(), &nameZ3_x, &nameLine1_y, framebuffer);  //======
    else writeln(selectFontName(fontSize), nameZone1.c_str(), &nameZ3_x, &nameLine2_y, framebuffer);                   //======
    if (typeZone2 == 'Q') {
      columnZ3_x = 510;  //+240
      int Qline3_y = valueQLine3_y + (fontSize.toInt() * 4);
      int Qline4_y = Qline3_y + (fontSize.toInt() * 4) + 35;
      int Qline5_y = Qline4_y + (fontSize.toInt() * 4) + 35;
      int Qline6_y = Qline5_y + (fontSize.toInt() * 4) + 35;
      int Qline7_y = Qline6_y + (fontSize.toInt() * 4) + 35;
      int Qline8_y = Qline7_y + (fontSize.toInt() * 4) + 35;

      writeln(selectFontValue(fontSize), line3.c_str(), &columnZ3_x, &Qline3_y, framebuffer);
      columnZ3_x = 510;
      writeln(selectFontValue(fontSize), line4.c_str(), &columnZ3_x, &Qline4_y, framebuffer);
      columnZ3_x = 510;
      writeln(selectFontValue(fontSize), line5.c_str(), &columnZ3_x, &Qline5_y, framebuffer);
      columnZ3_x = 510;
      writeln(selectFontValue(fontSize), line6.c_str(), &columnZ3_x, &Qline6_y, framebuffer);
      if (fontSize.toInt() <= 3) {
        columnZ3_x = 510;
        writeln(selectFontValue(fontSize), line7.c_str(), &columnZ3_x, &Qline7_y, framebuffer);
      }
      if (fontSize.toInt() <= 2) {
        columnZ3_x = 510;
        writeln(selectFontValue(fontSize), line8.c_str(), &columnZ3_x, &Qline8_y, framebuffer);
      }
    }
    counterDevice++;
  }
}  //END Zone 3


//----- Zone 4
void displayZone4() {
  if (typeZone4 != 'X') {
    String data = Homey.value;
    debug("Data Zone 4: " + data);
    homeyData homeyValues = extractHomeyData(data);
    String type = homeyValues.type;
    String fontSize = homeyValues.sizeFont;
    deviceIconChoose = homeyValues.icon;
    String firstLineValue = convertType(homeyValues.valueL1, type);
    String secondLineValue = convertType(homeyValues.valueL2, type);
    String nameZone1 = homeyValues.name;
    device4clickable = stringToBool(homeyValues.clickable);
    weather = firstLineValue;
    if (typeZone4 == 'S') {
      nameZone1 = nameZone1.substring(0, 11);
      firstLineValue = firstLineValue.substring(0, 7);
      secondLineValue = secondLineValue.substring(0, 7);
    }
    if (easterEgg && aprilFish) {
      deviceIconChoose = "mad";
      fontSize = 4;
    }
    deviceIconNumber();
    if (type == "weather") {
      weatherIconNumber();
      epd_copy_to_framebuffer(iconZone4, (uint8_t *)weatherIconList[weatherIcon], framebuffer);
    } else
      epd_copy_to_framebuffer(iconZone4, (uint8_t *)deviceIconList80[deviceIcon], framebuffer);
    writeln(selectFontValue(fontSize), firstLineValue.c_str(), &valueZ4_x, &valueZ1_y, framebuffer);  //======
    valueZ4_x = 845;
    int line2_y = valueZ1Line2_y + (fontSize.toInt() * 4);                                           //========
    writeln(selectFontValue(fontSize), secondLineValue.c_str(), &valueZ4_x, &line2_y, framebuffer);  //======
    writeln(selectFontName(fontSize), nameZone1.c_str(), &nameZ4_x, &nameLine1_y, framebuffer);      //======
    counterDevice++;
  }
}  //END Zone 4




//----- Zone 5
void displayZone5() {
  if (typeZone5 != 'X') {
    String data = Homey.value;
    debug("Data Zone 5: " + data);
    homeyData homeyValues = extractHomeyData(data);
    String type = homeyValues.type;
    String fontSize = homeyValues.sizeFont;
    deviceIconChoose = homeyValues.icon;
    String firstLineValue = convertType(homeyValues.valueL1, type);
    String secondLineValue = convertType(homeyValues.valueL2, type);
    String nameZone1 = homeyValues.name;
    device5clickable = stringToBool(homeyValues.clickable);
    weather = firstLineValue;
    if (typeZone5 == 'S') {
      nameZone1 = nameZone1.substring(0, 11);
      firstLineValue = firstLineValue.substring(0, 7);
      secondLineValue = secondLineValue.substring(0, 7);
    }
    if (easterEgg && aprilFish) {
      deviceIconChoose = "fish";
      fontSize = 3;
    }
    deviceIconNumber();
    if (type == "weather") {
      weatherIconNumber();
      epd_copy_to_framebuffer(iconZone5, (uint8_t *)weatherIconList[weatherIcon], framebuffer);
    } else
      epd_copy_to_framebuffer(iconZone5, (uint8_t *)deviceIconList80[deviceIcon], framebuffer);
    writeln(selectFontValue(fontSize), firstLineValue.c_str(), &valueZ5_x, &valueZ5_y, framebuffer);
    valueZ5_x = 125;
    int line2_y = valueZ5Line2_y + (fontSize.toInt() * 4);
    writeln(selectFontValue(fontSize), secondLineValue.c_str(), &valueZ5_x, &line2_y, framebuffer);
    writeln(selectFontName(fontSize), nameZone1.c_str(), &nameZ5_x, &nameLine2_y, framebuffer);
    counterDevice++;
  }
}  //END Zone 5


//----- Zone 6
void displayZone6() {
  if (typeZone6 != 'X') {
    String data = Homey.value;
    debug("Data Zone 6: " + data);
    homeyData homeyValues = extractHomeyData(data);
    String type = homeyValues.type;
    String fontSize = homeyValues.sizeFont;
    deviceIconChoose = homeyValues.icon;
    String firstLineValue = convertType(homeyValues.valueL1, type);
    String secondLineValue = convertType(homeyValues.valueL2, type);
    String nameZone1 = homeyValues.name;
    device6clickable = stringToBool(homeyValues.clickable);
    weather = firstLineValue;
    if (typeZone6 == 'S') {
      nameZone1 = nameZone1.substring(0, 11);
      firstLineValue = firstLineValue.substring(0, 7);
      secondLineValue = secondLineValue.substring(0, 7);
    }
    if (easterEgg && aprilFish) {
      deviceIconChoose = "fool";
      fontSize = 5;
    }
    deviceIconNumber();
    if (type == "weather") {
      weatherIconNumber();
      epd_copy_to_framebuffer(iconZone6, (uint8_t *)weatherIconList[weatherIcon], framebuffer);
    } else
      epd_copy_to_framebuffer(iconZone6, (uint8_t *)deviceIconList80[deviceIcon], framebuffer);
    writeln(selectFontValue(fontSize), firstLineValue.c_str(), &valueZ6_x, &valueZ5_y, framebuffer);
    valueZ6_x = 365;
    int line2_y = valueZ5Line2_y + (fontSize.toInt() * 4);
    writeln(selectFontValue(fontSize), secondLineValue.c_str(), &valueZ6_x, &line2_y, framebuffer);
    writeln(selectFontName(fontSize), nameZone1.c_str(), &nameZ6_x, &nameLine2_y, framebuffer);
    counterDevice++;
  }
}  //END Zone 6



//----- Zone 7
void displayZone7() {
  if (typeZone7 != 'X') {
    String data = Homey.value;
    debug("Data Zone 7: " + data);
    homeyData homeyValues = extractHomeyData(data);
    String type = homeyValues.type;
    String fontSize = homeyValues.sizeFont;
    deviceIconChoose = homeyValues.icon;
    String firstLineValue = convertType(homeyValues.valueL1, type);
    String secondLineValue = convertType(homeyValues.valueL2, type);
    String nameZone1 = homeyValues.name;
    device7clickable = stringToBool(homeyValues.clickable);
    weather = firstLineValue;
    if (typeZone7 == 'S') {
      nameZone1 = nameZone1.substring(0, 11);
      firstLineValue = firstLineValue.substring(0, 7);
      secondLineValue = secondLineValue.substring(0, 7);
    }
    if (easterEgg && aprilFish) {
      deviceIconChoose = "mad";
      fontSize = 1;
    }
    deviceIconNumber();
    if (type == "weather") {  //weather
      weatherIconNumber();
      epd_copy_to_framebuffer(iconZone7, (uint8_t *)weatherIconList[weatherIcon], framebuffer);
    } else
      epd_copy_to_framebuffer(iconZone7, (uint8_t *)deviceIconList80[deviceIcon], framebuffer);
    writeln(selectFontValue(fontSize), firstLineValue.c_str(), &valueZ7_x, &valueZ5_y, framebuffer);
    valueZ7_x = 605;
    int line2_y = valueZ5Line2_y + (fontSize.toInt() * 4);
    writeln(selectFontValue(fontSize), secondLineValue.c_str(), &valueZ7_x, &line2_y, framebuffer);
    writeln(selectFontName(fontSize), nameZone1.c_str(), &nameZ7_x, &nameLine2_y, framebuffer);
    counterDevice++;
  }
}  //END Zone 7



//----- Zone 8
void displayZone8() {
  if (typeZone8 != 'X') {
    String data = Homey.value;
    debug("Data Zone 8: " + data);
    homeyData homeyValues = extractHomeyData(data);
    String type = homeyValues.type;
    String fontSize = homeyValues.sizeFont;
    deviceIconChoose = homeyValues.icon;
    String firstLineValue = convertType(homeyValues.valueL1, type);
    String secondLineValue = convertType(homeyValues.valueL2, type);
    String nameZone1 = homeyValues.name;
    device8clickable = stringToBool(homeyValues.clickable);
    weather = firstLineValue;
    if (typeZone8 == 'S') {
      nameZone1 = nameZone1.substring(0, 11);
      firstLineValue = firstLineValue.substring(0, 7);
      secondLineValue = secondLineValue.substring(0, 7);
    }
    if (easterEgg && aprilFish) {
      deviceIconChoose = "fool";
      fontSize = 2;
    }
    deviceIconNumber();
    if (type == "weather") {
      weatherIconNumber();
      epd_copy_to_framebuffer(iconZone8, (uint8_t *)weatherIconList[weatherIcon], framebuffer);
    } else
      epd_copy_to_framebuffer(iconZone8, (uint8_t *)deviceIconList80[deviceIcon], framebuffer);
    writeln(selectFontValue(fontSize), firstLineValue.c_str(), &valueZ8_x, &valueZ5_y, framebuffer);
    valueZ8_x = 845;
    int line2_y = valueZ5Line2_y + (fontSize.toInt() * 4);
    writeln(selectFontValue(fontSize), secondLineValue.c_str(), &valueZ8_x, &line2_y, framebuffer);
    writeln(selectFontName(fontSize), nameZone1.c_str(), &nameZ8_x, &nameLine2_y, framebuffer);
    counterDevice++;
  }
}  //END Zone 8