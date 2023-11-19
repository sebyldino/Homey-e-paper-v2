//================================================================================//
//                                  READ DATA
//================================================================================//
void readData() {
  SSID = prefs.getString("SSID", "");
  PASSWORD = prefs.getString("PASSWORD", "");
  clickMarkEnable = prefs.getBool("clickMark", false);
  touchScreenWakeUp = prefs.getBool("screenWakeUp", false);
  timeDeepSleep = prefs.getInt("timeDeepSleep", 5);
  deepSleepEnable = prefs.getBool("deepSleep", false);
  easterEgg = prefs.getBool("easterEgg", true);
  fromApMode = prefs.getBool("fromApMode", false);
  minVolt = prefs.getString("minVolt", "3").toFloat();
  maxVolt = prefs.getString("maxVolt", "4.2").toFloat();
  lang = prefs.getString("lang", "EN");
  displayWithTouchScreen = prefs.getBool("touchScreen", false);
  today = prefs.getInt("today", 1);
  ignoreToday = prefs.getBool("ignoreToday", false);
  timeBeforeSleep = prefs.getInt("timeBeforeSleep", 0);

  debug("======== START DATA READ  ========= \nSSID: " + SSID + "\nPASSWORD: " + PASSWORD + "\nclickMarkEnable = " + String(clickMarkEnable) + "\ntouchScreenWakeUp = " + String(touchScreenWakeUp)
        + "\ntimeDeepSleep = " + String(timeDeepSleep) + "\ndeepSleepEnable = " + String(deepSleepEnable) + "\nfromApMode = " + String(fromApMode)
        + "\nminVolt = " + String(minVolt) + "\nmaxVolt = " + String(maxVolt) + "\nLanguage = " + lang + "\ntimeBeforeSleep = " + String(timeBeforeSleep) + "\n========  END DATA READ  =========");
}  //END readData()





//================================================================================//
//                                  SERVER REQUEST
//================================================================================//
void serverRequest() {
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/html", wifiWebPage);
    debug("Client Connected");
  });

  server.on("/wifi", HTTP_POST, [](AsyncWebServerRequest *request) {
    SSID = request->arg("SSID").c_str();
    PASSWORD = request->arg("PASSWORD").c_str();
    prefs.putString("SSID", SSID);
    prefs.putString("PASSWORD", PASSWORD);
    debug("SSID received from web: " + String(SSID));
    debug("PASSWORD received from web: " + String(PASSWORD));
    request->send(200);
    ESP.restart();
  });

  if (!wifiModeAP) {
    AsyncElegantOTA.begin(&server);
    server.begin();
  }
  debug("Server started!");
}  //END serverRequest()





//================================================================================//
//                                  WIFI INITIALISATION
//================================================================================//
bool initWiFi() {
  if (SSID == "" || PASSWORD == "") {
    debug("Undefined SSID or PASSWORD.");
    return false;
  }

  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PASSWORD);
  debug("Connecting to WiFi...");

  unsigned long currentMillis = millis();

  while (WiFi.status() != WL_CONNECTED) {
    //checkWifi();
    if (millis() - currentMillisWifi >= intervalWifi) {
      debug("Failed to connect.");
      return false;
    }
  }
  debug("WiFi mode STATION. IP adress: " + WiFi.localIP().toString());
  return true;
}  //END initWifi()





//================================================================================//
//                                 CHECK WIFI
//================================================================================//
void checkWifi() {
  if (WiFi.status() != WL_CONNECTED) {
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillisCheckWifi >= intervalCheckWifi) {  //Trying reconnect take more than 30sec -> restart ESP
      debug("Reconnect to WiFi failed! Rebooting ESP32...");
      ESP.restart();
    }

    // Try to reconnect Wi-Fi
    debug("WiFi connexion lost. Trying to reconnect...");
    WiFi.reconnect();

    previousMillisCheckWifi = currentMillis;
  }
}  //END checkWifi()





//================================================================================//
//                                 DRAW AP IMAGE
//================================================================================//
void drawApImage() {
  epd_poweron();
  epd_clear();
  epd_draw_grayscale_image(epd_full_screen(), (uint8_t *)ApImage_data);
  epd_poweroff();
}  //END drawApImage()


//================================================================================//
//                                 DRAW WIFI SUCCESS
//================================================================================//
void drawWifiSuccess() {
  fromApMode = false;
  prefs.putBool("fromApMode", fromApMode);
  epd_poweron();
  epd_clear();
  epd_draw_grayscale_image(epd_full_screen(), (uint8_t *)wifiSuccessfully_data);
  epd_poweroff();
  delay(1000);
}  //END drawWifiSuccess()


//================================================================================//
//                                 RESTART IN AP MODE
//================================================================================//
void autoRestartApMode() {
  if (millis() >= timeAutoRestart) {
    debug("Auto Restart (every 5 min when Homey e-paper is in WiFi AP mode)...");
    ESP.restart();
  }
}  //END autoRestartApMode()

//================================================================================//
//                                 DEFINE LANGUAGE
//================================================================================//
void defineLanguage() {
  //French
  if (lang == "FR") {
    String ON = "ON";  // type = onoff
    OFF = "OFF";
    OPEN = "Ouvert";  //type = door
    CLOSE = "Fermé";
    LIGHT_ON = "Allumé";  // type = light
    LIGHT_OFF = "Éteint";
    PRESENT = "Présent";  // type  = presence
    ABSENT = "Absent";
    YES = "Oui";  // type = yesno
    NO = "Non";
    WET = "Hummide";  // type = wetdry
    DRY = "Sec";
    LOCK = "Verrouillé";
    UNLOCK = "Déverrouillé";
    HEATER_ON = "Allumé";  // type = heater
    HEATER_OFF = "Éteint";


     //weather
    CLEAR = "ciel dégagé";
    CLEAR2 = "";
    CLEAR_NIGHT = "nuit dégagée";
    CLOUD = "nuageux";
    CLOUD2 = "";
    CLOUD3 = "";
    CLOUD4 = "";
    FOG = "brume";
    FOG2 = "brouillard";
    FOG3 = "brumeux";
    HAIL = "bruine";
    HAIL2 = "bruine légère";
    PARTLY_CLOUDY = "partiellement nuageux";
    PARTLY_CLOUDY2 = "peu nuageux";
    PARTLY_CLOUDY3 = "";
    PARTLY_CLOUDY4 = "";
    RAIN = "pluvieux";
    RAIN2 = "bruine";
    RAIN3 = "pluie modérée";
    RAIN4 = "";
    RAIN5 = "";
    RAINY_CLOUDY = "légère pluie";
    RAINY_CLOUDY2 = "";
    RAINY_CLOUDY3 = "";
    RAINY_CLOUDY4 = "";
    RAINY_CLOUDY5 = "";
    RAINY_CLOUDY6 = "";
    RAINY_CLOUDY7 = "";
    RAINY_CLOUDY8 = "";
    RAINY_CLOUDY9 = "";
    RAINY_CLOUDY10 = "";
    SNOW = "neige";
    SNOW2 = "neigeux";
    STORM = "orage";
    STORM_RAIN = "orage et pluie";
    TWO_CLOUDS = "couvert";
    TWO_CLOUDS2 = "";
    WIND = "vent";
    WIND2 = "vent fort";
    WIND3 = "venteux";
  }
  //English
  if (lang == "EN") {
    String ON = "ON";  // type = onoff
    OFF = "OFF";
    OPEN = "Open";  //type = door
    CLOSE = "Close";
    LIGHT_ON = "ON";  // type = light
    LIGHT_OFF = "OFF";
    PRESENT = "Present";  // type  = presence
    ABSENT = "Absent";
    YES = "Yes";  // type = yesno
    NO = "No";
    WET = "Wet";  // type = wetdry
    DRY = "Dry";
    LOCK = "Lock";
    UNLOCK = "Unlock";
    HEATER_ON = "ON";  // type = heater
    HEATER_OFF = "OFF";


    //weather
    CLEAR = "clear sky";
    CLEAR2 = "";
    CLEAR_NIGHT = "clear night";
    CLOUD = "cloudy";
    CLOUD2 = "scattered clouds";
    CLOUD3 = "cloud";
    CLOUD4 = "";
    FOG = "haze";
    FOG2 = "fog";
    FOG3 = "mist";
    HAIL = "hail";
    HAIL2 = "";
    PARTLY_CLOUDY = "partly cloudy";
    PARTLY_CLOUDY2 = "";
    PARTLY_CLOUDY3 = "";
    PARTLY_CLOUDY4 = "";
    RAIN = "rain";
    RAIN2 = "rainy";
    RAIN3 = "";
    RAIN4 = "";
    RAIN5 = "";
    RAINY_CLOUDY = "shower rain";
    RAINY_CLOUDY2 = "";
    RAINY_CLOUDY3 = "";
    RAINY_CLOUDY4 = "";
    RAINY_CLOUDY5 = "";
    RAINY_CLOUDY6 = "";
    RAINY_CLOUDY7 = "";
    RAINY_CLOUDY8 = "";
    RAINY_CLOUDY9 = "";
    RAINY_CLOUDY10 = "";
    SNOW = "snow";
    SNOW2 = "snowy";
    STORM = "thunderstorm";
    STORM_RAIN = "thunderstorm rain";
    TWO_CLOUDS = "broken clouds";
    TWO_CLOUDS2 = "";
    WIND = "wind";
    WIND2 = "";
    WIND3 = "";
  }
  //Dutch
  if (lang == "NL") {
    String ON = "AAN";  // type = onoff
    OFF = "UIT";
    OPEN = "Open";  //type = door
    CLOSE = "Dicht";
    LIGHT_ON = "AAN";  // type = light
    LIGHT_OFF = "UIT";
    PRESENT = "Aanwezig";  // type  = presence
    ABSENT = "Afwezig";
    YES = "Ja";  // type = yesno
    NO = "Neen";
    WET = "Nat";  // type = wetdry
    DRY = "Droog";
    LOCK = "Gesloten";
    UNLOCK = "Open";
    HEATER_ON = "AAN";  // type = heater
    HEATER_OFF = "UIT";



    //weather
    CLEAR = "Onbewolkt";
    CLEAR2 = "zonnig";
    CLEAR_NIGHT = "helderenacht";
    CLOUD = "Geheel bewolkt";
    CLOUD2 = "Overwegend bewolkt";
    CLOUD3 = "bewolkt";
    CLOUD4 = "nachtbewolkt";
    FOG = "mist";
    FOG2 = "nachtmist";
    FOG3 = "";
    HAIL = "hagel";
    HAIL2 = "";
    PARTLY_CLOUDY = "Licht bewolkt";
    PARTLY_CLOUDY2 = "lichtbewolkt";
    PARTLY_CLOUDY3 = "Half bewolkt";
    PARTLY_CLOUDY4 = "halfbewolkt";
    RAIN = "Regen";
    RAIN2 = "regen";
    RAIN3 = "Motregen";
    RAIN4 = "Motregen en regen";
    RAIN5 = "Dichte motregen";
    RAINY_CLOUDY = "Lichte regen";
    RAINY_CLOUDY2 = "halfbewolkt_regen";
    RAINY_CLOUDY3 = "buien";
    RAINY_CLOUDY4 = "Lichte motregen";
    RAINY_CLOUDY5 = "Lichte motregen en regen";
    RAINY_CLOUDY6 = "Af en toe lichte regen";
    RAINY_CLOUDY7 = "Droog na motregen";
    RAINY_CLOUDY8 = "Droog na regen";
    RAINY_CLOUDY9 = "Af en toe neerslag";
    RAINY_CLOUDY10 = "Droog na neerslag";
    SNOW = "sneeuw";
    SNOW2 = "";
    STORM = "Storm";
    STORM_RAIN = "";
    TWO_CLOUDS = "Zwaar bewolkt";
    TWO_CLOUDS2 = "zwaarbewolkt";
    WIND = "Harde wind";
    WIND2 = "";
    WIND3 = "";
  }
}  //END defineLanguage()