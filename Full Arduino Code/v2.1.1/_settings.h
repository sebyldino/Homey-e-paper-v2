#include <Arduino.h>
#include <esp_task_wdt.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "epd_driver.h"
#include <Wire.h>
#include <touch.h>
#include <Preferences.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <Homey.h>
TouchClass touch;
Preferences prefs;
#include "files.h"
#include "wifiWebPage.h"
#include <ESPAsyncWebServer.h>
#include <DNSServer.h>
#include <AsyncTCP.h>
#include <AsyncElegantOTA.h>
#include <time.h>
AsyncWebServer server(80);
void debug();
void errorMessage();
void progressBar();





//========================   DEBUG    ==========================
bool serialDebug = true;


//========================   RELEASE    ==========================
bool releaseSended = false;


//========================   TIMER BEFORE RESTART    ==========================
bool waitForRestart = false;
unsigned long currentMillisRestart;
int intervalRestart = 2000;


//=======================   LANGUAGE    ========================
String lang;

String ON;  // type = onoff
String OFF;
String OPEN;  //type = door
String CLOSE;
String LIGHT_ON;  // type = light
String LIGHT_OFF;
String PRESENT;  // type  = presence
String ABSENT;
String YES;  // type = yesno
String NO;
String WET;  // type = wetdry
String DRY;
String HEATER_ON;  // type = heater
String HEATER_OFF;
String LOCK;
String UNLOCK;




//=======================   WEATHER    ========================
String weather;
int weatherIcon;

String CLEAR;
String CLEAR2;
String CLEAR_NIGHT;
String CLOUD;
String CLOUD2;
String CLOUD3;
String CLOUD4;
String FOG;
String FOG2;
String FOG3;
String HAIL;
String HAIL2;
String PARTLY_CLOUDY;
String PARTLY_CLOUDY2;
String PARTLY_CLOUDY3;
String PARTLY_CLOUDY4;
String RAIN;
String RAIN2;
String RAIN3;
String RAIN4;
String RAIN5;
String RAINY_CLOUDY;
String RAINY_CLOUDY2;
String RAINY_CLOUDY3;
String RAINY_CLOUDY4;
String RAINY_CLOUDY5;
String RAINY_CLOUDY6;
String RAINY_CLOUDY7;
String RAINY_CLOUDY8;
String RAINY_CLOUDY9;
String RAINY_CLOUDY10;
String SNOW;
String SNOW2;
String STORM; 
String STORM_RAIN; 
String TWO_CLOUDS;
String TWO_CLOUDS2;
String WIND;
String WIND2;
String WIND3;

//====================   WIFI    ======================
String SSID;
String PASSWORD;
const char *SSID_AP = "Homey e-paper";
const char *PASSWORD_AP = NULL;
unsigned long currentMillisWifi;
int intervalWifi = 15000;  //Time for trying to connect in STA mode before enter in AP mode
bool wifiModeAP;
unsigned long previousMillisCheckWifi = 0;
int intervalCheckWifi = 30000;
int timeAutoRestart = 5 * (1000 * 60);  //Auto restart in AP mode every 5 min


//====================   CAPTIVE PORTAIL    ======================
DNSServer dnsServer;
class CaptiveRequestHandler : public AsyncWebHandler {
public:
  CaptiveRequestHandler() {}
  virtual ~CaptiveRequestHandler() {}

  bool canHandle(AsyncWebServerRequest *request) {
    return true;
  }

  void handleRequest(AsyncWebServerRequest *request) {
    request->send_P(200, "text/html", wifiWebPage);
  }
};


//====================   DEEP SLEEP    ======================
#define uS_TO_S_FACTOR 1000000ULL  // Conversion factor for micro seconds to seconds
int timeDeepSleep;
bool deepSleepEnable;
bool touchScreenWakeUp;
int timeBeforeSleep;
bool timerBeforeSleepStart = false;
unsigned long currentMillisBeforeSleep;



//====================   SETTINGS MODE    ======================
String screenLayout;  // = "Z1=D, Z2=S, Z3=S, Z4=S, Z5=S, Z6=D, Z7=S, Z8=S";
char typeZone1;       //S for Simple tile, D for Double tile
char typeZone2;
char typeZone3;
char typeZone4;
char typeZone5;
char typeZone6;
char typeZone7;
char typeZone8;

bool device1clickable;
bool device2clickable;
bool device3clickable;
bool device4clickable;
bool device5clickable;
bool device6clickable;
bool device7clickable;
bool device8clickable;



//========================   BATTERY    ==========================
String batteryPercent;
float minVolt = 3;
float maxVolt = 4.2;
bool batterySended = false;
int batteryState;
unsigned long currentMillisSendBattery;
int intervalSendBattery = 10 * (1000 * 60);  // Send battery level every 10 minutes



//======================     ICONS     =======================
String deviceIconChoose;
int deviceIcon;
//define device icon 80x80 px
const uint8_t *deviceIconList80[] = { door80_data, garageDoor80_data, gate80_data, humidity80_data, light80_data, logo80_data,
                                      pressure80_data, rollerShutter80_data, thermometer80_data, window80_data, wirelessPlug80_data, lock80_data,
                                      bathroom80_data, bedroom80_data, fan80_data, garden80_data, heater80_data, home80_data, kitchen80_data, lounge80_data,
                                      powerCounter80_data, stove80_data, swimmingPool80_data, waterCounter80_data, alarm80_data, alarm280_data,
                                      batteryH80_data, batteryV80_data, car80_data, car280_data, climate80_data, co80_data, co280_data, smokeSensor80_data, waterPlant80_data,
                                      waterSensor80_data, waterSensor280_data, wifi80_data, wireless80_data, printer80_data, lux80_data, dollar80_data, euro80_data, lightbolt80_data,
                                      washingMachine80_data, weather80_data, wind80_data, openEnvelope80_data, closeEnvelope80_data, spa80_data, octoprint80_data, shopping80_data, fish_data, mad_data, fool_data };

//define weather icon
const uint8_t *weatherIconList[] = {logoSmall_data, clear_data, clearNight_data, cloudy_data, fog_data, hail_data, partlyCloudy_data, rainy_data,
                                    rainyCloudy_data, snowy_data, storm_data, stormRainy_data, twoClouds_data, windy_data
                                   };

//======================     DISPLAY     =======================
uint8_t *framebuffer = NULL;
unsigned long currentMillisScreenRepair;
int intervalScreenRepair = 1000;
int counterSreenRepair = 0;
bool updating = false;
int counterDevice = 0;
int previousCounterDevice = 0;
int expectedDevice = -2;
bool clickMarkEnable;
bool fromApMode;
bool paperScreenOnline = false;
unsigned long waitForUpdate;
int previousStateButton1 = HIGH;
int previousStateButton2 = HIGH;
int previousStateButton3 = HIGH;



//======================     TOUCH SCREEN     =======================
uint16_t x, y;
bool screenTouched = false;
unsigned long lastActivity;
int intervalLastActivity = 300;
bool displayWithTouchScreen;




//======================     TIME & EASTER EGG     =======================
unsigned long currentMillisGetTime;
int intervalGetTime = 1000;
int day;
int month;
int year;
bool halloween;
bool christmas;
bool newYear;
bool aprilFish;
bool easterEgg;
bool easterEggDay = false;
const char *ntpServer = "pool.ntp.org";
const long gmtOffset_sec = 2;
const int daylightOffset_sec = 3600;
int today;
bool ignoreToday = false;



//====================      EXTRACT VALUES        ====================
String extractValue(String data, String key) {
  int start = data.indexOf(key);
  if (start == -1) {
    return "";
  }
  start += key.length();

  int end = data.indexOf(";", start);
  int endWithSpace = data.indexOf("; ", start);
  if (endWithSpace != -1 && (end == -1 || endWithSpace < end)) {
    end = endWithSpace;
  }
  if (end == -1) {
    end = data.length();
  }
  return data.substring(start, end);
}

struct homeyData {
  String icon;
  String name;
  String type;
  String valueL1;
  String valueL2;
  String valueL3;
  String valueL4;
  String valueL5;
  String valueL6;
  String valueL7;
  String valueL8;
  String clickable;
  String headerVal1;
  String headerVal2;
  String timeDeepSleep;
  String enableClickMark;
  String wakeUpWithTouchScreen;
  String wakeUpWithTimer;
  String vMax;
  String vMin;
  String language;
  String sizeFont;
  String touchScreenMount;
  String enableEasterEgg;
  String beforeSleepTime;
};

homeyData extractHomeyData(String data) {
  homeyData values;
  values.icon = extractValue(data, "Icon=");
  values.name = extractValue(data, "Name=");
  values.type = extractValue(data, "Type=");
  values.valueL1 = extractValue(data, "Value_L1=");
  values.valueL2 = extractValue(data, "Value_L2=");
  values.valueL3 = extractValue(data, "Value_L3=");
  values.valueL4 = extractValue(data, "Value_L4=");
  values.valueL5 = extractValue(data, "Value_L5=");
  values.valueL6 = extractValue(data, "Value_L6=");
  values.valueL7 = extractValue(data, "Value_L7=");
  values.valueL8 = extractValue(data, "Value_L8=");
  values.clickable = extractValue(data, "Clickable=");
  values.headerVal1 = extractValue(data, "Value_1=");
  values.headerVal2 = extractValue(data, "Value_2=");
  values.timeDeepSleep = extractValue(data, "Deep_Sleep_Time=");
  values.enableClickMark = extractValue(data, "Click_Mark_Enable=");
  values.wakeUpWithTouchScreen = extractValue(data, "Wake_Up_With_Touch_Screen=");
  values.wakeUpWithTimer = extractValue(data, "Wake_Up_With_Timer=");
  values.vMax = extractValue(data, "Voltage_Max=");
  values.vMin = extractValue(data, "Voltage_Min=");
  values.language = extractValue(data, "Language=");
  values.sizeFont = extractValue(data, "Font_Size=");
  values.touchScreenMount = extractValue(data, "Display_With_Touch_Screen=");
  values.enableEasterEgg = extractValue(data, "Easter_Egg=");
  values.beforeSleepTime = extractValue(data, "Time_Before_Sleep=");
  return values;
}




//========================   FONT SIZE    ==========================
// Font Values
GFXfont *selectFontValue(String fontSize) {
  if (fontSize == "1") {
    return (GFXfont *)&OpenSans12;
  } else if (fontSize == "2") {
    return (GFXfont *)&OpenSans16;
  } else if (fontSize == "3") {
    return (GFXfont *)&OpenSans18;
  } else if (fontSize == "4") {
    return (GFXfont *)&OpenSans20;
  } else if (fontSize == "5") {
    return (GFXfont *)&OpenSans24;
  } else {
    return (GFXfont *)&OpenSans12;
  }
}

//Font Names
GFXfont *selectFontName(String fontSize) {
  if (fontSize == "1") {
    return (GFXfont *)&OpenSans14B;
  } else if (fontSize == "2") {
    return (GFXfont *)&OpenSans18B;
  } else if (fontSize == "3") {
    return (GFXfont *)&OpenSans20B;
  } else if (fontSize == "4") {
    return (GFXfont *)&OpenSans24B;
  } else if (fontSize == "5") {
    return (GFXfont *)&OpenSans26B;
  } else {
    return (GFXfont *)&OpenSans14B;
  }
}



//========================   PSRAM    ==========================
#ifndef BOARD_HAS_PSRAM
#error "Please enable PSRAM !!!"
#endif


//========================   DEFINE PINS    ====================
//-----   M5 PAPER
#ifdef M5_PAPER  //M5 Paper

#define BUTTON_1 (37)  
#define BUTTON_2 (38)  
#define BUTTON_3 (39)  
#define BATT_PIN (35)  
#define SD_MISO (13)  
#define SD_MOSI (12)  
#define SD_SCLK (14)  
#define SD_CS (4)     
#define TOUCH_SCL (22)  
#define TOUCH_SDA (21)  
#define TOUCH_INT (36)  
#define GPIO_MISO (13)  
#define GPIO_MOSI (12)  
#define GPIO_SCLK (14)  
#define GPIO_CS (15)    


//----- Lilygo T5
#elif defined(LILYGO)  

#define BUTTON_1 (39)  
#define BUTTON_2 (34)  
#define BUTTON_3 (35) 
#define BATT_PIN (36) 
#define SD_MISO (12)  
#define SD_MOSI (13)  
#define SD_SCLK (14)  
#define SD_CS (15)    
#define TOUCH_SCL (14) 
#define TOUCH_SDA (15)  
#define TOUCH_INT (13)  
#define GPIO_MISO (12)  
#define GPIO_MOSI (13)  
#define GPIO_SCLK (14)  
#define GPIO_CS (15)    
#endif


//**************************************************************************************************************************************//
//**************************************************************************************************************************************//
//                                                          DEFINE SIZE ZONE
//**************************************************************************************************************************************//
//**************************************************************************************************************************************//
/*
    Y
    ^
    |
    |
    |_ _ _  >  X
*/

//================================================================================//
//                                       COMMON VALUES
//================================================================================//
int nameLine1_y = 250;
int nameLine2_y = 490;
int valueQLine3_y = 220;
int valueQLine4_y = 255;
int valueQLine5_y = 290;
int valueQLine6_y = 325;
int valueQLine7_y = 360;
int valueQLine8_y = 395;
int valueQLine9_y = 430;




//================================================================================//
//                                       HEADER
//================================================================================//
int headerValue_x = 10;
int headerTime_x = 430;
int headerBattery_x = 840;
int header_y = 50;

Rect_t fullHeader = {
  .x = 0,
  .y = 0,
  .width = 960,
  .height = 60
};


//Deepsleep icon
Rect_t deepSleepIcon = {
  .x = 535,
  .y = 5,
  .width = sleep_width,
  .height = sleep_height
};


Rect_t partialHeader = {
  .x = 0,
  .y = 0,
  .width = 850,
  .height = 80
};

//Header Battery
Rect_t headerBattery = {
  .x = 870,
  .y = 15,
  .width = charging40_width,
  .height = charging40_height
};



//================================================================================//
//                                  ZONE 1
//================================================================================//
//Zone1
Rect_t zone1 = {
  .x = 0,
  .y = 60,
  .width = 240,
  .height = 240
};

//Zone 1 Double
Rect_t zone1Double = {
  .x = 0,
  .y = 60,
  .width = 480,
  .height = 240
};


//Zone 1 Triple
Rect_t zone1Triple = {
  .x = 0,
  .y = 60,
  .width = 720,
  .height = 240
};


//Zone 1 Quadruple
Rect_t zone1Quadruple = {
  .x = 0,
  .y = 60,
  .width = 480,
  .height = 480
};

//Icon Zone 1
Rect_t iconZone1 = {
  .x = 30,  //+30
  .y = 90,  //+30
  .width = 80,
  .height = 80
};


int valueZ1_x = 125;       //+125
int valueZ1_y = 140;       //+80
int valueZ1Line2_y = 175;  //+115   35px par ligne
int columnZ1_x = 30;       //+30

int nameZ1_x = 30;  //+30
//int nameZ1_y = 250;  //+190

//================================================================================//
//                                  ZONE 2
//================================================================================//
//Zone2
Rect_t zone2 = {
  .x = 240,
  .y = 60,
  .width = 240,
  .height = 240
};

//Zone 2 Double
Rect_t zone2Double = {
  .x = 240,
  .y = 60,
  .width = 480,
  .height = 240
};

//Zone 2 Triple
Rect_t zone2Triple = {
  .x = 240,
  .y = 60,
  .width = 720,
  .height = 240
};

//Zone 2 Triple
Rect_t zone2Quadruple = {
  .x = 240,
  .y = 60,
  .width = 480,
  .height = 480
};

//Icon Zone 2
Rect_t iconZone2 = {
  .x = 270,  //+30
  .y = 90,   //+30
  .width = 80,
  .height = 80
};

int columnZ2_x = 270;
int valueZ2_x = 365;  //+125
int nameZ2_x = 270;   //+30




//================================================================================//
//                                  ZONE 3
//================================================================================//
//Zone3
Rect_t zone3 = {
  .x = 480,
  .y = 60,
  .width = 240,
  .height = 240
};

//Zone 3 Double
Rect_t zone3Double = {
  .x = 480,
  .y = 60,
  .width = 480,
  .height = 240
};

//Zone 3 Quadruple
Rect_t zone3Quadruple = {
  .x = 480,
  .y = 60,
  .width = 480,
  .height = 480
};

//Icon Zone 3
Rect_t iconZone3 = {
  .x = 510,  //+30
  .y = 90,   //+30
  .width = 80,
  .height = 80
};

int columnZ3_x = 510;
int valueZ3_x = 605;  //+125
int nameZ3_x = 510;   //+30


//================================================================================//
//                                  ZONE 4
//================================================================================//
//Zone4
Rect_t zone4 = {
  .x = 720,
  .y = 60,
  .width = 240,
  .height = 240
};

//Icon Zone 4
Rect_t iconZone4 = {
  .x = 750,  //+30
  .y = 90,   //+30
  .width = 80,
  .height = 80
};

int valueZ4_x = 845;  //+125
int nameZ4_x = 750;   //+30


//================================================================================//
//                                  ZONE 5
//================================================================================//
//Zone5
Rect_t zone5 = {
  .x = 0,
  .y = 300,
  .width = 240,
  .height = 240
};

//Zone 5 Double
Rect_t zone5Double = {
  .x = 0,
  .y = 300,
  .width = 480,
  .height = 240
};


//Zone 5 Triple
Rect_t zone5Triple = {
  .x = 0,
  .y = 300,
  .width = 720,
  .height = 240
};

//Icon Zone 5
Rect_t iconZone5 = {
  .x = 30,   //+30
  .y = 330,  //+30
  .width = 80,
  .height = 80
};


int valueZ5_x = 125;       //+125
int valueZ5_y = 380;       //+80
int valueZ5Line2_y = 415;  //+115
int nameZ5_x = 30;         //+30
//int nameZ5_y = 490;        //+190

//================================================================================//
//                                  ZONE 6
//================================================================================//
//Zone6
Rect_t zone6 = {
  .x = 240,
  .y = 300,
  .width = 240,
  .height = 240
};

//Zone 6 Double
Rect_t zone6Double = {
  .x = 240,
  .y = 300,
  .width = 480,
  .height = 240
};


//Zone 6 Triple
Rect_t zone6Triple = {
  .x = 240,
  .y = 300,
  .width = 720,
  .height = 240
};

//Icon Zone 6
Rect_t iconZone6 = {
  .x = 270,  //+30
  .y = 330,  //+30
  .width = 80,
  .height = 80
};

int valueZ6_x = 365;  //+125
int nameZ6_x = 270;   //+30


//================================================================================//
//                                  ZONE 7
//================================================================================//
//Zone7
Rect_t zone7 = {
  .x = 480,
  .y = 300,
  .width = 240,
  .height = 240
};

//Zone 7 Double
Rect_t zone7Double = {
  .x = 480,
  .y = 300,
  .width = 480,
  .height = 240
};

//Icon Zone 7
Rect_t iconZone7 = {
  .x = 510,  //+30
  .y = 330,  //+30
  .width = 80,
  .height = 80
};

int valueZ7_x = 605;  //+125
int nameZ7_x = 510;   //+30
//================================================================================//
//                                  ZONE 8
//================================================================================//
//Zone8
Rect_t zone8 = {
  .x = 720,
  .y = 300,
  .width = 240,
  .height = 240
};

//Icon Zone 8
Rect_t iconZone8 = {
  .x = 750,  //+30
  .y = 330,  //+30
  .width = 80,
  .height = 80
};

int valueZ8_x = 845;  //+125
int nameZ8_x = 750;   //+30
