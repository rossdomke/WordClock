#include <FastLED.h>

#include "State.h"
#include "src/Programs/WordClockProgram.h"
#include "src/ColorAnimations.h"
#include "src/ColorPallettes.h"

State::State(uint8_t width, uint8_t height, CRGB *leds, bool *mask, DS3231 *rtc)
{
  Width = width;
  Height = height;
  Brightness = 100;
  Mask = mask;
  LEDs = leds;
  RealTimeClock = rtc;
  Speed = 2;
  StepSize = 30;
  Frame = 0;
  ColorAnimationIdx = 0;
  PaletteIdx = 0;
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

void State::Time_SetRTC(int8_t amount)
{
  if (Time < abs(amount) && amount < 0)
  {
    Time = 24 * 60 + Time_GetMin() + amount;
  }
  else
  {
    Time = (Time + amount) % (24 * 60);
  }
  RealTimeClock->setHour(Time_GetHour());
  RealTimeClock->setMinute(Time_GetMin());
}
uint16_t State::Time_FromRTC()
{
  bool h12;
  bool hPM;
  uint8_t hour = RealTimeClock->getHour(h12, hPM);
  uint8_t min = RealTimeClock->getMinute();
  Time = (hour * 60) + min;
  return Time;
}
uint8_t State::Time_GetHour()
{
  return Time / 60;
}
uint8_t State::Time_GetMin()
{
  return Time % 60;
}
uint8_t State::GetNumOfLEDs()
{
  return Width * Height;
}

void State::AdvanceFrame()
{
  Frame += Speed;
}

uint8_t State::GetFrame()
{
  return Frame;
}

uint8_t State::GetWidth()
{
  return Width;
}

uint8_t State::GetHeight()
{
  return Height;
}
uint8_t State::GetStepSize()
{
  return StepSize;
}
ColorAnimationFunc State::GetColorAnimation()
{
  return ColorAnimations[ColorAnimationIdx];
}

void State::SetColorAnimation(int8_t direction)
{
  uint8_t maxIdx = sizeof(ColorAnimations) / sizeof(ColorAnimationFunc);
  if (direction < 0)
  {
    if (ColorAnimationIdx == 0)
    {
      ColorAnimationIdx = maxIdx;
    }
    else
    {
      ColorAnimationIdx -= direction;
    }
  }
  else
  {
    ColorAnimationIdx += direction;
    ColorAnimationIdx = ColorAnimationIdx % maxIdx;
  }
}
CRGBPalette16 State::GetColorPalette()
{
  return ColorPalettes[PaletteIdx];
}
void State::SetColorPalette(int8_t direction)
{
  uint8_t maxIdx = sizeof(ColorPalettes) / sizeof(CRGBPalette16);
  if (direction < 0)
  {
    if (PaletteIdx == 0)
    {
      PaletteIdx = maxIdx;
    }
    else
    {
      PaletteIdx -= direction;
    }
  }
  else
  {
    PaletteIdx += direction;
    PaletteIdx = PaletteIdx % maxIdx;
  }
}
