#include <FastLED.h>

#include "State.h"
#include "src/Programs/WordClockProgram.h"

State::State(uint8_t width, uint8_t height, CRGB *leds, bool *mask) 
{
  Width = width;
  Height = height;
  Brightness = 100;
  Mask = mask;
  LEDs = leds;
  ActiveProgram = new WordClockProgram();
}

uint8_t State::GetBrightness()
{
  return Brightness;
}
void State::ChangeBrightness(int8_t amount)
{
  Brightness = Brightness + amount;
}

uint8_t State::GetNumOfLEDs()
{
  return Width * Height;
}