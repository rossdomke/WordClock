uint8_t hue = 0;





void SolidRainbow(){
  EVERY_N_MILLISECONDS(40){
    hue++;
  }
  for(uint8_t i = 0; i < NUM_LEDS; i++){
    leds[i].setHue(hue);
  }
}

uint8_t LastRandomColor = 0;
void RandomColor(){
  EVERY_N_SECONDS(30){
    LastRandomColor = random8(0,255);
  }
  for(uint8_t i = 0; i < NUM_LEDS; i++){
    leds[i].setHue(LastRandomColor);
  }
}




void Rainbow(){
  EVERY_N_MILLISECONDS(20){
    if(forward){
      hue+= 1;
    }else{
      hue-= 1;
    }
  }
  for(uint8_t y = 0; y < 11; y++){
    for(uint8_t x = 0; x < 11; x++){
      uint8_t shiftMx = 0;
      leds[XY(x, y)].setHue(hue + rainbowPatterns[currentRainbowMode](x, y));
    }
  }
}
uint8_t hueShift = 10;
uint8_t FMIRROR(uint8_t x, uint8_t y){
  return (hueShift * ((Vert ? ty : tx) - abs((Vert ? ty : tx) - (Vert ? y : x))));
}
uint8_t FCIRCLE(uint8_t x, uint8_t y){
  return (hueShift * max(abs(tx-x), abs(ty-y)));
}
uint8_t FSIDETOSIDE( uint8_t x, uint8_t y){
  return (hueShift * (Vert ? y : x));
}
uint8_t FDIAGONAL(uint8_t x, uint8_t y){
   if(Vert)
    return  x * hueShift + y * hueShift;
   return (11 - x) * hueShift + y * hueShift;
}
