//================================================================================//
//                                  GO TO RESTART
//================================================================================//
void goToRestart() {
  if (millis() - currentMillisRestart > intervalRestart && waitForRestart) {
    debug("Restart...");
    ESP.restart();
  }
}  //END goToRestart()




//================================================================================//
//                                  DEEP SLEEP
//================================================================================//
void goDeepSleep() {
  if (deepSleepEnable && timeBeforeSleep == 0) {
    epd_poweron();
    epd_draw_image(deepSleepIcon, (uint8_t *)sleep_data, BLACK_ON_WHITE);
    epd_poweroff();
    debug("Go to Deep sleep for (minutes): " + String(timeDeepSleep));
    esp_deep_sleep_start();
  }
  if (deepSleepEnable && timeBeforeSleep > 0) {
    currentMillisBeforeSleep = millis();
    timerBeforeSleepStart = true;
  }
}  //END goDeepSleep()


//================================================================================//
//                                  WAIT BEFORE SLEEP
//================================================================================//
void waitBeforeSleep() {
  if ((timerBeforeSleepStart) && (millis() - currentMillisBeforeSleep > (timeBeforeSleep * 1000))) {
    epd_poweron();
    epd_draw_image(deepSleepIcon, (uint8_t *)sleep_data, BLACK_ON_WHITE);
    epd_poweroff();
    debug("Go to Deep sleep for (minutes): " + String(timeDeepSleep));
    esp_deep_sleep_start();
  }
}



//================================================================================//
//                                  GET BATTERY
//================================================================================//
void getBatteryPercent() {
  uint16_t v = analogRead(BATT_PIN);
  float battery_voltage = ((float)v / 4095.0) * 2.0 * 3.3 * (1100 / 1000.0);
  batteryPercent = String(map(int(battery_voltage * 100), int(minVolt * 100), int(maxVolt * 100), 0, 100)) + "%";  //volt are set to *100 to get accuracy
  debug("Battery Percent Raw= " + batteryPercent);
  batteryState = map((battery_voltage * 100), (minVolt * 100), (maxVolt * 100), 0, 100);
  if ((batteryPercent.toInt() >= 100) && (batteryPercent.toInt() <= 110)) {
    batteryPercent = "100%";  //get 10% error to batterie voltage
  }
  if (batteryPercent.toInt() <= 0) {
    batteryPercent = "0%";
    batteryState = 0;
  }
  if (batteryState > 100) batteryState = 100;
}  //END getBatteryPercent()



//================================================================================//
//                                  ICON CHOOSE
//================================================================================//
//epd_draw_image(iconZ1, (uint8_t *)deviceIconList[deviceIcon], BLACK_ON_WHITE);
void deviceIconNumber() {
  if (deviceIconChoose == "door") deviceIcon = 0;
  if (deviceIconChoose == "garage door") deviceIcon = 1;
  if (deviceIconChoose == "gate") deviceIcon = 2;
  if (deviceIconChoose == "humidity") deviceIcon = 3;
  if (deviceIconChoose == "light") deviceIcon = 4;
  if (deviceIconChoose == "logo") deviceIcon = 5;
  if (deviceIconChoose == "pressure") deviceIcon = 6;
  if (deviceIconChoose == "roller shutter") deviceIcon = 7;
  if (deviceIconChoose == "thermometer") deviceIcon = 8;
  if (deviceIconChoose == "window") deviceIcon = 9;
  if (deviceIconChoose == "wireless plug") deviceIcon = 10;
  if (deviceIconChoose == "lock") deviceIcon = 11;
  if (deviceIconChoose == "bathroom") deviceIcon = 12;
  if (deviceIconChoose == "bedroom") deviceIcon = 13;
  if (deviceIconChoose == "fan") deviceIcon = 14;
  if (deviceIconChoose == "garden") deviceIcon = 15;
  if (deviceIconChoose == "heater") deviceIcon = 16;
  if (deviceIconChoose == "home") deviceIcon = 17;
  if (deviceIconChoose == "kitchen") deviceIcon = 18;
  if (deviceIconChoose == "lounge") deviceIcon = 19;
  if (deviceIconChoose == "power counter") deviceIcon = 20;
  if (deviceIconChoose == "stove") deviceIcon = 21;
  if (deviceIconChoose == "swimming pool") deviceIcon = 22;
  if (deviceIconChoose == "water counter") deviceIcon = 23;
  if (deviceIconChoose == "alarm") deviceIcon = 24;
  if (deviceIconChoose == "alarm 2") deviceIcon = 25;
  if (deviceIconChoose == "horizontal battery") deviceIcon = 26;
  if (deviceIconChoose == "vertical battery") deviceIcon = 27;
  if (deviceIconChoose == "car") deviceIcon = 28;
  if (deviceIconChoose == "car 2") deviceIcon = 29;
  if (deviceIconChoose == "climate") deviceIcon = 30;
  if (deviceIconChoose == "co") deviceIcon = 31;
  if (deviceIconChoose == "co2") deviceIcon = 32;
  if (deviceIconChoose == "smoke sensor") deviceIcon = 33;
  if (deviceIconChoose == "water plant") deviceIcon = 34;
  if (deviceIconChoose == "water sensor") deviceIcon = 35;
  if (deviceIconChoose == "water sensor 2") deviceIcon = 36;
  if (deviceIconChoose == "wifi") deviceIcon = 37;
  if (deviceIconChoose == "wireless") deviceIcon = 38;
  if (deviceIconChoose == "3D print") deviceIcon = 39;
  if (deviceIconChoose == "lux") deviceIcon = 40;
  if (deviceIconChoose == "dollar") deviceIcon = 41;
  if (deviceIconChoose == "euro") deviceIcon = 42;
  if (deviceIconChoose == "lightbolt") deviceIcon = 43;
  if (deviceIconChoose == "washing machine") deviceIcon = 44;
  if (deviceIconChoose == "weather") deviceIcon = 45;
  if (deviceIconChoose == "wind") deviceIcon = 46;
  if (deviceIconChoose == "open envelope") deviceIcon = 47;
  if (deviceIconChoose == "close envelope") deviceIcon = 48;
  if (deviceIconChoose == "spa") deviceIcon = 49;
  if (deviceIconChoose == "octoprint") deviceIcon = 50;
  if (deviceIconChoose == "shopping") deviceIcon = 51;
  if (deviceIconChoose == "fish") deviceIcon = 52;
  if (deviceIconChoose == "mad") deviceIcon = 53;
  if (deviceIconChoose == "fool") deviceIcon = 54;
}  //END deviceIconNumber()





//================================================================================//
//                                 ERROR MESSAGE
//================================================================================//
/* Print an error message on display like:
errorMessage("This is an error message on first Line", "this is on second line");
*/
void errorMessage(String line1, String line2 = "") {  
  if (line1.length() > 45) {
    line1 = line1.substring(0, 45);
  }
  int errorMsg_x = 5;
  int errorMsg_y = 220;
  epd_poweron();
  epd_clear();
  writeln((GFXfont *)&OpenSans18B, line1.c_str(), &errorMsg_x, &errorMsg_y, NULL);
  if (line2 != "") {
    if (line2.length() > 45) {
      line1 = line2.substring(0, 45);
    }
    errorMsg_x = 5;
    errorMsg_y += 45;  // adjust y position for second line
    writeln((GFXfont *)&OpenSans18B, line2.c_str(), &errorMsg_x, &errorMsg_y, NULL);
  }
  if (!wifiModeAP) {
    progressBar(15);
    ESP.restart();
  }
  epd_poweroff();
}



//================================================================================//
//                                  PROGRESS BAR
//================================================================================//

void progressBar(int delayInSeconds) {
  int text_x = 30;
  int text_y = 525;
  int progress_x = 242;  // +212
  int progress_y = 529;
  writeln((GFXfont *)&OpenSans18B, String("Rebooting [                                ]").c_str(), &text_x, &text_y, NULL);
  for (int i = 0; i <= 14; i++) {
    writeln((GFXfont *)&OpenSans18B, String("=").c_str(), &progress_x, &progress_y, NULL);
    delay(delayInSeconds * 1000 / 15);  // Convert seconds to milliseconds and divide by 15
  }
}




//================================================================================//
//                                  SRTING TO BOOL
//================================================================================//
bool stringToBool(const String &str) {
  if (str.equalsIgnoreCase("true")) {
    return true;
  } else if (str.equalsIgnoreCase("false")) {
    return false;
  } else {
    // If error, return false by default
    return false;
  }
}








//================================================================================//
//                                  GET VALUE
//================================================================================//
char getValue(String data, String key) {
  // Find the position of the key in the string
  int keyPosition = data.indexOf(key);
  if (keyPosition != -1) {
    // Advance to the equal sign
    keyPosition = data.indexOf('=', keyPosition) + 1;
    if (keyPosition > 0 && keyPosition < data.length()) {
      // Extract the character following the equal sign
      return data.charAt(keyPosition);
    }
  }
  return 'S';  // Return 'S' by default if the key is not found
}





//================================================================================//
//                                  CONVERT TYPE
//================================================================================//
String convertType(String inputValue, String type) {
  String outputValue = inputValue;
  if ((inputValue == "true") || (inputValue == "false")) {
    //light
    if (type == "light") {
      if (inputValue == "true") outputValue = LIGHT_ON;
      if (inputValue == "false") outputValue = LIGHT_OFF;
    }
    //onoff
    if (type == "onoff") {
      if (inputValue == "true") outputValue = ON;
      if (inputValue == "false") outputValue = OFF;
    }
    //door
    if (type == "door") {
      if (inputValue == "true") outputValue = OPEN;
      if (inputValue == "false") outputValue = CLOSE;
    }
    //presence
    if (type == "presence") {
      if (inputValue == "true") outputValue = PRESENT;
      if (inputValue == "false") outputValue = ABSENT;
    }
    //yesno
    if (type == "yesno") {
      if (inputValue == "true") outputValue = YES;
      if (inputValue == "false") outputValue = NO;
    }
    //heater
    if (type == "heater") {
      if (inputValue == "true") outputValue = HEATER_OFF;  //invert for heater
      if (inputValue == "false") outputValue = HEATER_ON;
    }
    //lock
    if (type == "lock") {
      if (inputValue == "true") outputValue = LOCK;  //invert for heater
      if (inputValue == "false") outputValue = UNLOCK;
    }
    //wetdry
    if (type == "wetdry") {
      if (inputValue == "true") outputValue = WET;  //true = alarm
      if (inputValue == "false") outputValue = DRY;
    }

  }  //
  return outputValue;
}  //END convertType()


//================================================================================//
//                                  GET TIME
//================================================================================//
void getTime() {
  time_t currentTime;
  if (millis() - currentMillisGetTime > intervalGetTime) {
    currentMillisGetTime = millis();
    struct tm *timeInfo;
    time(&currentTime);
    timeInfo = localtime(&currentTime);
    day = timeInfo->tm_mday;
    month = timeInfo->tm_mon + 1;
    year = timeInfo->tm_year + 1900;
    //debug("Date Now: " + String(day) + "/" + String(month) + "/" + String(year));
    checkEasterEgg();
  }
}




//================================================================================//
//                                 CHECK EASTER EGG
//================================================================================//
void checkEasterEgg() {
  if (ignoreToday && (today != day) && (year >= 2023)) {
    ignoreToday = false;
    easterEgg = true;
    prefs.putBool("ignoreToday", ignoreToday);
    prefs.putBool("easterEgg", easterEgg);
  }
  if (easterEgg) {
    if ((day == 31) && (month == 10)) {  //Halloween
      halloween = true;
      easterEggDay = true;
    } else if ((day == 25) && (month == 12)) {  //Christmas
      christmas = true;
      easterEggDay = true;
    } else if ((day == 1) && (month == 1) && (year >= 2023)) {  // New Year
      newYear = true;
      easterEggDay = true;
    } else if ((day == 1) && (month == 4)) {  // April Fish
      aprilFish = true;
      easterEggDay = true;
    }
    else {
      halloween = false;
      christmas = false;
      newYear = false;
      aprilFish = false;
      easterEggDay = false;
    }
  }
}  //END easterEgg()





//================================================================================//
//                                 DISPLAY EASTER EGG
//================================================================================//
void displayEasterEgg() {
  //HEADER
  if (halloween) {
    epd_copy_to_framebuffer(partialHeader, (uint8_t *)halloweenBanner_data, framebuffer);
  }
  if (christmas) {
    epd_copy_to_framebuffer(partialHeader, (uint8_t *)christmasBanner_data, framebuffer);
  }
  if (newYear) {
    epd_copy_to_framebuffer(partialHeader, (uint8_t *)newYearBanner_data, framebuffer);
  } 
}  //END displayEasterEgg()






//================================================================================//
//                                 IGNORE EASTER EGG
//================================================================================//
void ignoreEasterEgg() {
  easterEgg = false;
  ignoreToday = true;
  today = day;
  prefs.putInt("today", today);
  prefs.putBool("ignoreToday", ignoreToday);
  prefs.putBool("easterEgg", easterEgg);
}  //END ignoreEasterEgg()






//================================================================================//
//                                  DEBUG FUNCTION
//================================================================================//
// Use it like:  debug("Message print in serial monitor. You can print int too, like this:" + String(myInt))
void debug(String message) {
  if (serialDebug) {
    Serial.println(message);
  }
}  //END debug()