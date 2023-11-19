//================================================================================//
//                                  SETUP EPD
//================================================================================//
void setupEPD() {
  framebuffer = (uint8_t *)ps_calloc(sizeof(uint8_t), EPD_WIDTH * EPD_HEIGHT / 2);
  if (!framebuffer) {
    Serial.println("Alloc memory failed !!!");
    while (1)
      ;
  }
  memset(framebuffer, 0xFF, EPD_WIDTH * EPD_HEIGHT / 2);
  epd_init();  //screen initialization
}  //END setupEPD()






//================================================================================//
//                                  DEFINE LAYOUT
//================================================================================//
void defineLayout() {
  waitForUpdate = millis();
  updating = true;
  String value = Homey.value;
  debug("Screen Layout received: " + value);
  typeZone1 = getValue(value, "Z1");
  typeZone2 = getValue(value, "Z2");
  typeZone3 = getValue(value, "Z3");
  typeZone4 = getValue(value, "Z4");
  typeZone5 = getValue(value, "Z5");
  typeZone6 = getValue(value, "Z6");
  typeZone7 = getValue(value, "Z7");
  typeZone8 = getValue(value, "Z8");
  drawZones();

}  //END defineLayout()





//================================================================================//
//                                  DRAW ZONES
//================================================================================//
void drawZones() {
  drawZone1();
  drawZone2();
  drawZone3();
  drawZone4();
  drawZone5();
  drawZone6();
  drawZone7();
  drawZone8();

  //-------------- Count number of device
  expectedDevice = 0;  //declare to -2 at the begining so set to 0;
  if (typeZone1 != 'X') expectedDevice++;
  if (typeZone2 != 'X') expectedDevice++;
  if (typeZone3 != 'X') expectedDevice++;
  if (typeZone4 != 'X') expectedDevice++;
  if (typeZone5 != 'X') expectedDevice++;
  if (typeZone6 != 'X') expectedDevice++;
  if (typeZone7 != 'X') expectedDevice++;
  if (typeZone8 != 'X') expectedDevice++;

  //-------------- Serial Debug
  debug("Number of expected devices: " + String(expectedDevice + 1));  //+1 for the header values
  debug("Zones Layout (1rst, 2nd...): " + String(typeZone1) + " " + String(typeZone2) + " " + String(typeZone3) + " " + String(typeZone4) + " " + String(typeZone5) + " " + String(typeZone6) + " " + String(typeZone7) + " " + String(typeZone8));
}  //END drawZones()





//================================================================================//
//                                  DRAW BATTERY ICON
//================================================================================//
void drawBatteryIcon() {
  getBatteryPercent();
  if (batteryPercent.toInt() >= 101) {
    epd_copy_to_framebuffer(headerBattery, (uint8_t *)charging40_data, framebuffer);
  }
}  //END drawBatteryIcon()







//================================================================================//
//                                  DRAW CLICK MARK
//================================================================================//
void drawClickMark() {
  if (clickMarkEnable) {
    //--------------   Zone 1
    if (device1clickable) {
      Rect_t markArea;
      if (typeZone1 == 'S') {
        markArea = {
          .x = 195,  //+195
          .y = 90,   //+30
          .width = 16,
          .height = 16
        };
      }
      if ((typeZone1 == 'D') || (typeZone1 == 'Q')) {
        markArea = {
          .x = 435,  //+435
          .y = 90,   //+30
          .width = 16,
          .height = 16
        };
      }
      if (typeZone1 == 'T') {
        markArea = {
          .x = 675,  //+195
          .y = 90,   //+30
          .width = 16,
          .height = 16
        };
      }
      epd_copy_to_framebuffer(markArea, (uint8_t *)clickMark_data, framebuffer);
    }

    //--------------   Zone 2
    if (device2clickable) {
      Rect_t markArea;
      if (typeZone2 == 'S') {
        markArea = {
          .x = 435,  //+195
          .y = 90,   //+30
          .width = 16,
          .height = 16
        };
      }
      if ((typeZone2 == 'D') || (typeZone2 == 'Q')) {
        markArea = {
          .x = 675,  //+35
          .y = 90,   //+30
          .width = 16,
          .height = 16
        };
      }
      if (typeZone2 == 'T') {
        markArea = {
          .x = 915,  //+195
          .y = 90,   //+30
          .width = 16,
          .height = 16
        };
      }
      epd_copy_to_framebuffer(markArea, (uint8_t *)clickMark_data, framebuffer);
    }


    //--------------   Zone 3
    if (device3clickable) {
      Rect_t markArea;
      if (typeZone3 == 'S') {
        markArea = {
          .x = 675,  //+195
          .y = 90,   //+30
          .width = 16,
          .height = 16
        };
      }
      if ((typeZone3 == 'D') || (typeZone3 == 'Q')) {
        markArea = {
          .x = 915,  //+435
          .y = 90,   //+30
          .width = 16,
          .height = 16
        };
      }
      epd_copy_to_framebuffer(markArea, (uint8_t *)clickMark_data, framebuffer);
    }

    //--------------   Zone 4
    if (device4clickable) {
      Rect_t markArea;
      if (typeZone4 == 'S') {
        markArea = {
          .x = 915,  //+195
          .y = 90,   //+30
          .width = 16,
          .height = 16
        };
      }
      epd_copy_to_framebuffer(markArea, (uint8_t *)clickMark_data, framebuffer);
    }

    //--------------   Zone 5
    if (device5clickable) {
      Rect_t markArea;
      if (typeZone5 == 'S') {
        markArea = {
          .x = 195,  //+195
          .y = 330,  //+30
          .width = 16,
          .height = 16
        };
      }
      if (typeZone5 == 'D') {
        markArea = {
          .x = 435,  //+435
          .y = 330,  //+30
          .width = 16,
          .height = 16
        };
      }
      if (typeZone5 == 'T') {
        markArea = {
          .x = 675,  //+195
          .y = 330,  //+30
          .width = 16,
          .height = 16
        };
      }
      epd_copy_to_framebuffer(markArea, (uint8_t *)clickMark_data, framebuffer);
    }

    //--------------   Zone 6
    if (device6clickable) {
      Rect_t markArea;
      if (typeZone6 == 'S') {
        markArea = {
          .x = 435,  //+195
          .y = 330,  //+30
          .width = 16,
          .height = 16
        };
      }
      if (typeZone6 == 'D') {
        markArea = {
          .x = 675,  //+435
          .y = 330,  //+30
          .width = 16,
          .height = 16
        };
      }
      if (typeZone6 == 'T') {
        markArea = {
          .x = 915,  //+195
          .y = 330,  //+30
          .width = 16,
          .height = 16
        };
      }
      epd_copy_to_framebuffer(markArea, (uint8_t *)clickMark_data, framebuffer);
    }

    //--------------   Zone 7
    if (device7clickable) {
      Rect_t markArea;
      if (typeZone7 == 'S') {
        markArea = {
          .x = 675,  //+195
          .y = 330,  //+30
          .width = 16,
          .height = 16
        };
      }
      if (typeZone7 == 'D') {
        markArea = {
          .x = 915,  //+435
          .y = 330,  //+30
          .width = 16,
          .height = 16
        };
      }
      epd_copy_to_framebuffer(markArea, (uint8_t *)clickMark_data, framebuffer);
    }

    //--------------   Zone 8
    if (device8clickable) {
      Rect_t markArea;
      if (typeZone8 == 'S') {
        markArea = {
          .x = 915,  //+195
          .y = 330,  //+30
          .width = 16,
          .height = 16
        };
      }
      epd_copy_to_framebuffer(markArea, (uint8_t *)clickMark_data, framebuffer);
    }
  }
  debug("Click mark drawed");
}  //END drawClickMark()






//================================================================================//
//                                  CHECK UPDATE
//================================================================================//
void checkUpdate() {
  if (counterDevice == (expectedDevice + 1)) {
    debug("Updating display...");
    redefinedZones();
    drawClickMark();
    expectedDevice = -2;
    counterDevice = 0;
    epd_poweron();
    epd_clear();
    epd_draw_grayscale_image(epd_full_screen(), framebuffer);
    epd_poweroff();
    updating = false;
    goDeepSleep();
  }
  if ((millis() - waitForUpdate >= 20000) && (updating)) {
    updating = false;
    expectedDevice = -2;
    counterDevice = 0;
    debug("Timeout for update values! Timer reseted and ready to receive new data.");
    bool success = Homey.trigger("Timeout_Updating", "Timeout");
  }
}  //END checkUpdate()







//================================================================================//
//                                  SCREEN REPAIR
//================================================================================//
void screenRepair() {
  int32_t i = 0;
  Rect_t area = epd_full_screen();
  epd_poweron();
  delay(10);
  epd_clear();
  for (i = 0; i < 20; i++) {
    epd_push_pixels(area, 50, 0);
    delay(500);
  }
  epd_clear();
  for (i = 0; i < 40; i++) {
    epd_push_pixels(area, 50, 1);
    delay(500);
  }
  epd_clear();
  epd_poweroff_all();
  ESP.restart();
}  //END screenRepair()

//================================================================================//
//                                  LISTEN BUTTON
//================================================================================//
void listenButton() {
  int btn1 = digitalRead(BUTTON_1);
  int btn2 = digitalRead(BUTTON_2);
  int btn3 = digitalRead(BUTTON_3);
  if ((btn1 != previousStateButton1) && (btn1 == LOW)) {
      previousStateButton1 = btn1;
      bool success = Homey.trigger("Trigger_Button_1", "Button 1 Pressed");
      debug("Button 1 pressed!");
  }
  if ((btn1 != previousStateButton1) && (btn1 == HIGH)) {
      previousStateButton1 = btn1;
      debug("Button 1 released!");
  }
  //Button 2
  if ((btn2 != previousStateButton2) && (btn2 == LOW)) {
      previousStateButton2 = btn2;
      bool success = Homey.trigger("Trigger_Button_2", "Button 2 Pressed");
      debug("Button 2 pressed!");
  }
  if ((btn2 != previousStateButton2) && (btn2 == HIGH)) {
      previousStateButton2 = btn2;
      debug("Button 2 release!");
  }
  //Button 3
  if ((btn3 != previousStateButton3) && (btn3 == LOW)) {
      previousStateButton3 = btn3;
      bool success = Homey.trigger("Trigger_Button_3", "Button 3 Pressed");
      debug("Button 3 pressed!");
  }
  if ((btn3 != previousStateButton3) && (btn3 == HIGH)) {
      previousStateButton3 = btn3;
      debug("Button 3 release!");
  }
}
