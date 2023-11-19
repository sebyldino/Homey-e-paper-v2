//================================================================================//
//                             ACTIVITY TOUCH SCREEN
//================================================================================//
void activityTouchScreen() {
  if (digitalRead(TOUCH_INT)) {
    lastActivity = millis();
    if (!screenTouched) {
      currentMillisBeforeSleep = millis();
      screenTouched = true;
      touch.scanPoint();
      touch.getPoint(x, y, 0);
      y = EPD_HEIGHT - y;
      onclick();
      debug("Screen Touched!");
    }
  }
  if (millis() - lastActivity >= intervalLastActivity) {
    if (screenTouched) debug("Screen Released.");
    if (screenTouched) screenTouched = false;
  }
}




//================================================================================//
//                                  ONCLICK
//================================================================================//
void onclick() {
  //debug("x = " + String(x) + "\ny = " + String(y));
  if (y >= 80 && y <= 280) {  //click on line 1
    onclickLine1();
  }
  if (y >= 320 && y <= 540) {  //click on line 2
    onclickLine2();
  }

  //For device in Q mode:
  if (y >= 281 && y <= 319) {
    onclickQmode();
  }
}  //END onclick()


//================================================================================//
//                                  ONCLICK LINE 1
//================================================================================//
void onclickLine1() {
  //Device 1
  if (device1clickable) {
    if ((typeZone1 == 'S' && (x >= 40 && x <= 235)) || (((typeZone1 == 'D') || (typeZone1 == 'Q')) && (x >= 40 && x <= 460)) || (typeZone1 == 'T' && (x >= 40 && x <= 690))) {
      bool success = Homey.trigger("Trigger_Device_1", "clicked");
      if (success) debug("Trigger Device 1 = Success");
      else debug("Trigger Device 1 = Error!");
      debug("Device 1 clicked!");
    }
  }

  // Device 2
  if (device2clickable) {
    if ((typeZone2 == 'S' && (x >= 270 && x <= 460)) || (((typeZone2 == 'D') || (typeZone2 == 'Q')) && (x >= 270 && x <= 690)) || (typeZone2 == 'T' && (x >= 270 && x <= 940))) {
      bool success = Homey.trigger("Trigger_Device_2", "clicked");
      if (success) debug("Trigger Device 2 = Success");
      else debug("Trigger Device 2 = Error!");
      debug("Device 2 clicked!");
    }
  }

  // Device 3
  if (device3clickable) {
    if ((typeZone3 == 'S' && (x >= 495 && x <= 690)) || (((typeZone3 == 'D') || (typeZone3 == 'Q')) && (x >= 495 && x <= 940))) {
      bool success = Homey.trigger("Trigger_Device_3", "clicked");
      if (success) debug("Trigger Device 3 = Success");
      else debug("Trigger Device 3 = Error!");
      debug("Device 3 clicked!");
    }
  }

  // Device 4
  if (device4clickable) {
    if (typeZone4 == 'S' && (x >= 720 && x <= 960)) {
      bool success = Homey.trigger("Trigger_Device_4", "clicked");
      if (success) debug("Trigger Device 4 = Success");
      else debug("Trigger Device 4 = Error!");
      debug("Device 4 clicked!");
    }
  }
}  //END onclickLine1()


//================================================================================//
//                                  ONCLICK LINE 2
//================================================================================//
void onclickLine2() {
  //Device 5
  if (device5clickable) {
    if ((typeZone5 == 'S' && (x >= 40 && x <= 235)) || (typeZone5 == 'D' && (x >= 40 && x <= 460)) || (typeZone5 == 'T' && (x >= 40 && x <= 690))) {
      bool success = Homey.trigger("Trigger_Device_5", "clicked");
      if (success) debug("Trigger Device 5 = Success");
      else debug("Trigger Device 5 = Error!");
      debug("Device 5 clicked!");
    }
  }

  // Device 6
  if (device6clickable) {
    if ((typeZone6 == 'S' && (x >= 270 && x <= 460)) || (typeZone6 == 'D' && (x >= 270 && x <= 690)) || (typeZone6 == 'T' && (x >= 270 && x <= 940))) {
      bool success = Homey.trigger("Trigger_Device_6", "clicked");
      if (success) debug("Trigger Device 6 = Success");
      else debug("Trigger Device 6 = Error!");
      debug("Device 6 clicked!");
    }
  }

  // Device 7
  if (device7clickable) {
    if ((typeZone7 == 'S' && (x >= 495 && x <= 690)) || (typeZone7 == 'D' && (x >= 495 && x <= 960))) {
      bool success = Homey.trigger("Trigger_Device_7", "clicked");
      if (success) debug("Trigger Device 7 = Success");
      else debug("Trigger Device 7 = Error!");
      debug("Device 7 clicked!");
    }
  }

  // Device 8
  if (device8clickable) {
    if (typeZone8 == 'S' && (x >= 720 && x <= 960)) {
      bool success = Homey.trigger("Trigger_Device_8", "clicked");
      if (success) debug("Trigger Device 8 = Success");
      else debug("Trigger Device 8 = Error!");
      debug("Device 8 clicked!");
    }
  }


  //-------------   SECOND LINE FOR QUADRUPLE DEVICE    --------------
  //Device 1 in Q mode
  if (device1clickable) {
    if ((typeZone1 == 'Q') && (x >= 40 && x <= 460)) {
      bool success = Homey.trigger("Trigger_Device_1", "clicked");
      if (success) debug("Trigger Device 1 = Success");
      else debug("Trigger Device 1 = Error!");
      debug("Device 1 clicked!");
    }
  }


  // Device 2 in Q mode
  if (device2clickable) {
    if ((typeZone2 == 'Q') && (x >= 270 && x <= 690)) {
      bool success = Homey.trigger("Trigger_Device_2", "clicked");
      if (success) debug("Trigger Device 2 = Success");
      else debug("Trigger Device 2 = Error!");
      debug("Device 2 clicked!");
    }
  }


  // Device 3 in Q mode
  if (device3clickable) {
    if ((typeZone3 == 'Q') && (x >= 495 && x <= 940)) {
      bool success = Homey.trigger("Trigger_Device_3", "clicked");
      if (success) debug("Trigger Device 3 = Success");
      else debug("Trigger Device 3 = Error!");
      debug("Device 3 clicked!");
    }
  }


}  //END onclickLine2()



//================================================================================//
//                                  ONCLICK Q MODE
//================================================================================//
//If click is between Line1 and Line2, check if there is a device in Q mode
void onclickQmode() {
  //Device 1 in Q mode
  if (device1clickable) {
    if ((typeZone1 == 'Q') && (x >= 40 && x <= 460)) {
      bool success = Homey.trigger("Trigger_Device_1", "clicked");
      if (success) debug("Trigger Device 1 = Success");
      else debug("Trigger Device 1 = Error!");
      debug("Device 1 clicked!");
    }
  }


  // Device 2 in Q mode
  if (device2clickable) {
    if ((typeZone2 == 'Q') && (x >= 270 && x <= 690)) {
      bool success = Homey.trigger("Trigger_Device_2", "clicked");
      if (success) debug("Trigger Device 2 = Success");
      else debug("Trigger Device 2 = Error!");
      debug("Device 2 clicked!");
    }
  }


  // Device 3 in Q mode
  if (device3clickable) {
    if ((typeZone3 == 'Q') && (x >= 495 && x <= 940)) {
      bool success = Homey.trigger("Trigger_Device_3", "clicked");
      if (success) debug("Trigger Device 3 = Success");
      else debug("Trigger Device 3 = Error!");
      debug("Device 3 clicked!");
    }
  }  //END onclickQmode()
}






//================================================================================//
//                                LISTEN SCREEN REPAIR
//================================================================================//
// long press (5 sec) on the header will start screenRepair()
void listenScreenRepair() {
  if (millis() - currentMillisScreenRepair > intervalScreenRepair) {
    currentMillisScreenRepair = millis();
    if (screenTouched && (y >= 0 && y <= 70)) {
      counterSreenRepair++;
    } else counterSreenRepair = 0;
  }
  if (counterSreenRepair >= 5) {
    debug("Start Screen Repair...");
    screenRepair();
  }
}




//================================================================================//
//                                  SETUP TOUCH SCREEN
//================================================================================//
void setupTouchScreen() {
  pinMode(TOUCH_INT, INPUT_PULLUP);
  Wire.begin(TOUCH_SDA, TOUCH_SCL);
  if (!touch.begin()) {
    debug("Start touchscreen failed! Please check wiring.");
    errorMessage("Start touchscreen failed! Please check wiring.");
    while (1)
      ;
  }
  debug("Started Touchscreen successfully!");
}  //END