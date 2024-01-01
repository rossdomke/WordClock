#include <FastLED.h>

#include "State.h"
#include "src/Programs/WordClockProgram.h"

State::State(uint8_t width, uint8_t height, CRGB *leds, bool *mask, DS3231 *rtc)
{
  Width = width;
  Height = height;
  Brightness = 100;
  Mask = mask;
  LEDs = leds;
  RealTimeClock = rtc;
  Speed = 2;
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