
//================================================================================//
//                                  DRAW ZONE 1
//================================================================================//
void drawZone1() {
  if (typeZone1 == 'S') epd_copy_to_framebuffer(zone1, (uint8_t *)tile_data, framebuffer);

  if (typeZone1 == 'D') {
    typeZone2 = 'X';
    epd_copy_to_framebuffer(zone1Double, (uint8_t *)doubleTile_data, framebuffer);
  }

  if (typeZone1 == 'T') {
    typeZone2 = 'X';
    typeZone3 = 'X';
    epd_copy_to_framebuffer(zone1Triple, (uint8_t *)tripleTile_data, framebuffer);
  }

  if (typeZone1 == 'Q') {
        typeZone2 = 'X';
        typeZone5 = 'X';
        typeZone6 = 'X';
        epd_copy_to_framebuffer(zone1Quadruple, (uint8_t *)quadrupleTile_data, framebuffer);
      }
}  //END drawZone1()



//================================================================================//
//                                  DRAW ZONE 2
//================================================================================//
void drawZone2() {
  if (typeZone2 == 'S') epd_copy_to_framebuffer(zone2, (uint8_t *)tile_data, framebuffer);

  if (typeZone2 == 'D') {
    typeZone3 = 'X';
    epd_copy_to_framebuffer(zone2Double, (uint8_t *)doubleTile_data, framebuffer);
  }

  if (typeZone2 == 'T') {
    typeZone3 = 'X';
    typeZone4 = 'X';
    epd_copy_to_framebuffer(zone2Triple, (uint8_t *)tripleTile_data, framebuffer);
  }

  if (typeZone2 == 'Q') {
        typeZone3 = 'X';
        typeZone6 = 'X';
        typeZone7 = 'X';
        epd_copy_to_framebuffer(zone2Quadruple, (uint8_t *)quadrupleTile_data, framebuffer);
      }
}  //END drawZone2()




//================================================================================//
//                                  DRAW ZONE 3
//================================================================================//
void drawZone3() {
  if (typeZone3 == 'S') epd_copy_to_framebuffer(zone3, (uint8_t *)tile_data, framebuffer);

  if ((typeZone3 == 'D') || (typeZone3 == 'T')){
    typeZone3 = 'D';
    typeZone4 = 'X';
    epd_copy_to_framebuffer(zone3Double, (uint8_t *)doubleTile_data, framebuffer);
  }

  if (typeZone3 == 'Q') {
        typeZone4 = 'X';
        typeZone7 = 'X';
        typeZone8 = 'X';
        epd_copy_to_framebuffer(zone3Quadruple, (uint8_t *)quadrupleTile_data, framebuffer);
      }
}  //END drawZone3()





//================================================================================//
//                                  DRAW ZONE 4
//================================================================================//
void drawZone4() {
  if ((typeZone4 == 'S') || (typeZone4 != 'S' && typeZone4 != 'X')) {
    epd_copy_to_framebuffer(zone4, (uint8_t *)tile_data, framebuffer);
    typeZone4 = 'S';
  }
}  //END drawZone4()







//================================================================================//
//                                  DRAW ZONE 5
//================================================================================//
void drawZone5() {
  if ((typeZone5 == 'S') || (typeZone5 == 'Q')) {
    typeZone5 = 'S';
    epd_copy_to_framebuffer(zone5, (uint8_t *)tile_data, framebuffer);
  }

  if (typeZone5 == 'D') {
    typeZone6 = 'X';
    epd_copy_to_framebuffer(zone5Double, (uint8_t *)doubleTile_data, framebuffer);
  }

  if (typeZone5 == 'T') {
    typeZone6 = 'X';
    typeZone7 = 'X';
    epd_copy_to_framebuffer(zone5Triple, (uint8_t *)tripleTile_data, framebuffer);
  }

}  //END drawZone5()




//================================================================================//
//                                  DRAW ZONE 6
//================================================================================//
void drawZone6() {
  if ((typeZone6 == 'S') || (typeZone6 == 'Q')) {
    typeZone6 = 'S';
    epd_copy_to_framebuffer(zone6, (uint8_t *)tile_data, framebuffer);
  }
  if (typeZone6 == 'D') {
    typeZone7 = 'X';
    epd_copy_to_framebuffer(zone6Double, (uint8_t *)doubleTile_data, framebuffer);
  }

  if (typeZone6 == 'T') {
    typeZone7 = 'X';
    typeZone8 = 'X';
    epd_copy_to_framebuffer(zone6Triple, (uint8_t *)tripleTile_data, framebuffer);
  }
}  //END drawZone6()




//================================================================================//
//                                  DRAW ZONE 7
//================================================================================//
void drawZone7() {
  if (typeZone7 == 'S') epd_copy_to_framebuffer(zone7, (uint8_t *)tile_data, framebuffer);

  if ((typeZone7 == 'D') || (typeZone7 == 'T')){
    typeZone7 = 'D';
    typeZone8 = 'X';
    epd_copy_to_framebuffer(zone7Double, (uint8_t *)doubleTile_data, framebuffer);
  }
}  //END drawZone7()







//================================================================================//
//                                  DRAW ZONE 8
//================================================================================//
void drawZone8() {
  if ((typeZone8 == 'S') || (typeZone8 != 'S' && typeZone8 != 'X')) {
    epd_copy_to_framebuffer(zone8, (uint8_t *)tile_data, framebuffer);
    typeZone8 = 'S';
  }
}  //END drawZone8()






