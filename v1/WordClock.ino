#include "FastLED.h"

FASTLED_USING_NAMESPACE

#include <btn.h>


#include <DS3231.h>

DS3231  rtc(SDA, SCL);

btn b1 = btn(10, btn::HoldType::ONE_CLICK);
btn b2 = btn(11, btn::HoldType::ONE_CLICK);
btn b3 = btn(12, btn::HoldType::ONE_CLICK);
#define DATA_PIN 13
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB

const uint8_t kMatrixWidth = 11;
const uint8_t kMatrixHeight = 11;

// Param for different pixel layouts
const bool    kMatrixSerpentineLayout = true;
const uint16_t NUM_LEDS = kMatrixWidth * kMatrixHeight;
CRGB leds[NUM_LEDS];
bool mask[NUM_LEDS];

#define FRAMES_PER_SECOND 120;


uint16_t XY( uint8_t x, uint8_t y)
{
  uint16_t i;
  
  if( kMatrixSerpentineLayout == false) {
    i = (y * kMatrixWidth) + x;
  }

  if( kMatrixSerpentineLayout == true) {
    if( y & 0x01) {
      // Odd rows run backwards
      uint8_t reverseX = (kMatrixWidth - 1) - x;
      i = (y * kMatrixWidth) + reverseX;
    } else {
      // Even rows run forwards
      i = (y * kMatrixWidth) + x;
    }
  }
  
  return i;
}
Time t;
uint8_t tmp = 99;
void setup() {
  delay(3000);

  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  
  FastLED.setBrightness(255);
  Serial.begin(57600);
  fill_solid( &(leds[0]), NUM_LEDS, CRGB::Orange);
  Serial.println("Ready");
  rtc.begin();
//  rtc.setDOW(TUESDAY);     // Set Day-of-Week to SUNDAY
//  rtc.setTime(20, 41, 0);     // Set the time to 12:00:00 (24hr format)
//  rtc.setDate(12, 20, 2016);   // Set the date to January 1st, 2014
  t = rtc.getTime();
  tmp = rtc.getTemp() * 1.8 + 32;
}
//
uint8_t CurrentMode = 0;
typedef void (*ModeFunction[])();
ModeFunction Modes = {MainWordClock, Temp, SetHour, SetMin, Demo};

//uint8_t CurrentMask = 3;
//typedef void (*MaskFunction[])();
//MaskFunction Masks = {None, Seconds, Random, WordClock};

uint8_t CurrentDemo = 0;
typedef void (*DemoFunction[])();
DemoFunction Demos = {NoMaskRain, RandomMask};

uint8_t CurrentColor = 0;
typedef void (*ColorFunction[])();
ColorFunction Colors = {Rainbow, SolidRainbow, RandomColor};

uint8_t currentRainbowMode = 0;
typedef uint8_t (*RainbowPatternList[])(uint8_t x, uint8_t y);
RainbowPatternList rainbowPatterns = {FMIRROR, FCIRCLE, FSIDETOSIDE, FDIAGONAL};


bool ClearTimer = false;

bool forward = true;
bool Vert = false;
uint8_t tx = 5;
uint8_t ty = 5;

void loop() {
  EVERY_N_MILLISECONDS(20){
//    PhotoResistBright();
  }

  if(b1.CheckButton()){
    CurrentMode = (CurrentMode + 1) % 5;
    ClearTimer = true;
    Serial.println("b1");
  }

  Modes[CurrentMode]();
  RunMask();
  FastLED.show();
}

void DeferToColor(){
  switch(CurrentColor){
    case 0:
      tx = random8(0,12);
      ty = random8(0,12);
      Vert = random8(0,2);
      forward = random8(0,2);
      currentRainbowMode = (currentRainbowMode + 1) % 4;
      break;
    default:
      Serial.println("No Defer");
  }
}
void MainWordClock(){
  WordClock();
  Colors[CurrentColor]();
  if(b2.CheckButton()){
    CurrentColor = (CurrentColor + 1) % 3;
  }
  if(b3.CheckButton()){
    DeferToColor();
  }
}


void Temp(){
  Colors[CurrentColor]();
  
  EVERY_N_MILLISECONDS(500){
    tmp = rtc.getTemp() * 1.8 + 32;
  }
  
  DisplayNum(tmp/10, false);
  DisplayNum(tmp %10, true);
  mask[XY(9,0)] = true;

  if(b2.CheckButton()){
    CurrentColor = (CurrentColor + 1) % 3;
  }
  if(b3.CheckButton()){
    DeferToColor();
  }
}
bool ShowNumber = true;
uint8_t DispCount = 0;
void SetHour(){
  Colors[CurrentColor]();
  EVERY_N_MILLISECONDS(250){
    if(DispCount == 6){
      ShowNumber = false;
    }else{
      ShowNumber = true;
    }
    t = rtc.getTime();
    DispCount = (DispCount + 1) % 7;
  }
  if(ShowNumber){
    uint8_t tmpHour = t.hour % 12;
    if(tmpHour == 0){
      tmpHour = 12;
    }
    DisplayNum(tmpHour/10, false);
    DisplayNum(tmpHour %10, true);
    if(t.hour > 11){
      
    }else{
      mask[XY(4,0)] = true;
    }
  }else{
    SetMaskRange(0,0,10,10, false);
  }
  if(b2.CheckButton()){
    rtc.setTime((t.hour + 1) % 24, t.min, t.sec);
    t = rtc.getTime();
  }
  if(b3.CheckButton()){
    rtc.setTime((t.hour + 23) % 24, t.min, t.sec);
    t = rtc.getTime();
  }
}
void SetMin(){
  Colors[CurrentColor]();
  EVERY_N_MILLISECONDS(250){
    if(DispCount == 3){
      ShowNumber = false;
    }else{
      ShowNumber = true;
    }
    t = rtc.getTime();
    DispCount = (DispCount + 1) % 4;
  }
  if(ShowNumber){
    DisplayNum(t.min/10, false);
    DisplayNum(t.min %10, true);
  }else{
    SetMaskRange(0,0,10,10, false);
  }
  if(b2.CheckButton()){
    rtc.setTime(t.hour, (t.min + 1) % 60, t.sec);
    t = rtc.getTime();
  }
  if(b3.CheckButton()){
    rtc.setTime(t.hour, (t.min + 59) % 60, t.sec);
    t = rtc.getTime();
  }
}

void Demo(){
  Demos[CurrentDemo]();
  if(b2.CheckButton()){
    CurrentDemo = (CurrentDemo + 1) % 2;
    Serial.println(CurrentDemo);
  }
}

void RunMask(){
  for(int i = 0; i < NUM_LEDS; i++){
    leds[i].fadeToBlackBy(255 * (1 - mask[i]));
  }
}
void swap8(uint8_t *x, uint8_t *y){
  uint8_t t = *x;
  *x = *y;
  *y = t;
}

