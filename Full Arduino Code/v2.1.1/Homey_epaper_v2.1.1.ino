//================================================================================//
//                                      PARAMS
//================================================================================//
#define LILYGO // or M5_PAPER
#include "_settings.h"
String release = "v2.1.1";




//================================================================================//
//                                      SETUP
//================================================================================//
void setup() {
  pinMode(BUTTON_1, INPUT);  //S4 on board, 0 = button pressed, 1 = button released.
  pinMode(BUTTON_2, INPUT);  //S2 on board, 0 = button pressed, 1 = button released
  pinMode(BUTTON_3, INPUT);  //S3 on board, 0 = button pressed, 1 = button released
  Serial.begin(115200);
  debug("\n \n//************************   STARTING E-PAPER... ************************//");
  debug("Realease: " + release);
  prefs.begin("my-app", false);
  readData();
  defineLanguage();
  setupEPD();

  if (initWiFi()) {
    if (fromApMode) {
      drawWifiSuccess();
    }
    //readData();
    if (touchScreenWakeUp) {
      esp_sleep_enable_ext1_wakeup(GPIO_SEL_13, ESP_EXT1_WAKEUP_ANY_HIGH);
    }
    if (deepSleepEnable && timeDeepSleep >= 1) {
      esp_sleep_enable_timer_wakeup((timeDeepSleep * 60) * uS_TO_S_FACTOR);  //uS_TO_S_FACTOR convert in second, so timeDeepSleep need to be *60 to set time in minutes
    }
    //updateDisplay();
    if (displayWithTouchScreen) {
      setupTouchScreen();
    }
    setupHomey();
    serverRequest();
    if (!displayWithTouchScreen) {
      clickMarkEnable = false;
      touchScreenWakeUp = false;
    }
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
    getTime();
    debug("//************************   SETUP COMPLETED (in wifi STA mode) ************************// \n");
  }

  else {
    wifiModeAP = true;
    fromApMode = true;
    prefs.putBool("fromApMode", fromApMode);
    WiFi.mode(WIFI_AP);
    WiFi.softAP(SSID_AP, PASSWORD_AP);
    IPAddress IP = WiFi.softAPIP();
    debug("Starting in AP WiFi mode. Please connect to '" + String(SSID_AP) + "' WiFi network \n to configure WiFi");
    drawApImage();
    serverRequest();
    dnsServer.start(53, "*", WiFi.softAPIP());
    server.addHandler(new CaptiveRequestHandler()).setFilter(ON_AP_FILTER);
    server.begin();
    debug("//************************   SETUP COMPLETED (in wifi AP mode) ************************// \n");
  }
}  //END setup()






//================================================================================//
//                                        LOOP
//================================================================================//
void loop() {
  dnsServer.processNextRequest();
  if (wifiModeAP) {
    autoRestartApMode();
    //progressBar(300);
  }
  if (!wifiModeAP) {
    if (displayWithTouchScreen) {
      activityTouchScreen();
      listenScreenRepair();
    }
    checkUpdate();
    Homey.loop();
    if (!paperScreenOnline) {
      paperScreenOnline = Homey.trigger("Homey_e_paper", "Online");
    }
    if (!releaseSended) {
      releaseSended = Homey.trigger("Release", release);
    }
    sendBatteryToHomey();
    checkWifi();
    waitBeforeSleep();
    listenButton();
  }

  if (previousCounterDevice != counterDevice) {
    previousCounterDevice = counterDevice;
    debug("Number of devices updated: " + String(counterDevice));
  }
  if (!updating) getTime();
  goToRestart();

}  //END loop()
