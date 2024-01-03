#ifndef State_h
#define State_h

#include <Arduino.h>
#include <DS3231.h>
#include <Wire.h>
#include <FastLED.h>
#include "src/ColorAnimations.h"

class Program;
class CRGB;

class State
{
public:
  State(uint8_t, uint8_t, CRGB *, bool *, DS3231 *);
  Program *ActiveProgram;
  bool *Mask;
  CRGB *LEDs;
  DS3231 *RealTimeClock;

  // Variables

  // Getters and Setters
  uint8_t GetBrightness();       // NI
  void ChangeBrightness(int8_t); // NI
  void Time_SetRTC(int8_t);
  uint16_t Time_FromRTC();
  uint8_t Time_GetHour();
  uint8_t Time_GetMin();
  uint8_t GetFrame();
  uint8_t GetStepSize();
  uint8_t GetWidth();
  uint8_t GetHeight();
  ColorAnimationFunc GetColorAnimation();
  uint8_t SetColorAnimation(int8_t);
  CRGBPalette16 GetColorPalette();
  uint8_t SetColorPalette(int8_t);

  // Computed Getters
  uint8_t GetNumOfLEDs();

  // Functions
  void AdvanceFrame();

  // SetColorAnimation
private:
  uint8_t Brightness;
  uint8_t PaletteIdx;
  uint8_t ColorAnimationIdx;
  uint8_t StepSize;
  uint8_t Speed;
  uint8_t Frame;
  uint8_t Width;
  uint8_t Height;
  uint16_t Time;
};
#endif