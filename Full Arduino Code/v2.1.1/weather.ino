void weatherIconNumber() {
  if (weather == CLEAR) weatherIcon = 1;        //clear
  else if (weather == CLEAR2) weatherIcon = 1;  //clear

  else if (weather == CLEAR_NIGHT) weatherIcon = 2;  //clear night

  else if (weather == CLOUD) weatherIcon = 3;   //cloudy
  else if (weather == CLOUD2) weatherIcon = 3;  //cloudy
  else if (weather == CLOUD3) weatherIcon = 3;  //cloudy
  else if (weather == CLOUD4) weatherIcon = 3;  //cloudy

  else if (weather == FOG) weatherIcon = 4;   //fog
  else if (weather == FOG2) weatherIcon = 4;  //fog
  else if (weather == FOG3) weatherIcon = 4;  //fog

  else if (weather == HAIL) weatherIcon = 5;   //hail
  else if (weather == HAIL2) weatherIcon = 5;  //hail

  else if (weather == PARTLY_CLOUDY) weatherIcon = 6;   //partly cloudy
  else if (weather == PARTLY_CLOUDY2) weatherIcon = 6;  //partly cloudy
  else if (weather == PARTLY_CLOUDY3) weatherIcon = 6;  //partly cloudy
  else if (weather == PARTLY_CLOUDY4) weatherIcon = 6;  //partly cloudy

  else if (weather == RAIN) weatherIcon = 7;   //rainy
  else if (weather == RAIN2) weatherIcon = 7;  //rainy
  else if (weather == RAIN3) weatherIcon = 7;  //rainy
  else if (weather == RAIN4) weatherIcon = 7;  //rainy
  else if (weather == RAIN5) weatherIcon = 7;  //rainy

  else if (weather == RAINY_CLOUDY) weatherIcon = 8;    //rainy cloudy
  else if (weather == RAINY_CLOUDY2) weatherIcon = 8;   //rainy cloudy
  else if (weather == RAINY_CLOUDY3) weatherIcon = 8;   //rainy cloudy
  else if (weather == RAINY_CLOUDY4) weatherIcon = 8;   //rainy cloudy
  else if (weather == RAINY_CLOUDY5) weatherIcon = 8;   //rainy cloudy
  else if (weather == RAINY_CLOUDY6) weatherIcon = 8;   //rainy cloudy
  else if (weather == RAINY_CLOUDY7) weatherIcon = 8;   //rainy cloudy
  else if (weather == RAINY_CLOUDY8) weatherIcon = 8;   //rainy cloudy
  else if (weather == RAINY_CLOUDY9) weatherIcon = 8;   //rainy cloudy
  else if (weather == RAINY_CLOUDY10) weatherIcon = 8;  //rainy cloudy

  else if (weather == SNOW) weatherIcon = 9;   //snowy
  else if (weather == SNOW2) weatherIcon = 9;  //snowy

  else if (weather == STORM) weatherIcon = 10;  //storm

  else if (weather == STORM_RAIN) weatherIcon = 11;  //storm rainy

  else if (weather == TWO_CLOUDS) weatherIcon = 12;   //two clouds
  else if (weather == TWO_CLOUDS2) weatherIcon = 12;  //two clouds

  else if (weather == WIND) weatherIcon = 13;   //windy
  else if (weather == WIND2) weatherIcon = 13;  //windy
  else if (weather == WIND3) weatherIcon = 13;  //windy
  else weatherIcon = 0;
}  //END weatherIconNumber()