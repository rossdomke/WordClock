#include <FastLED.h>
#include <Arduino.h>
#include <FlashStorage_SAMD.h>

#include "State.h"
#include "src/Programs/WordClockProgram.h"
#include "src/ColorAnimations.h"
#include "src/ColorPallettes.h"
#include "src/helpers.h"

#include "src/Programs/SetColorProgram.h"

State::State(uint8_t width, uint8_t height, CRGB *leds, bool *onMask, bool *clrMask, DS3231 *rtc)
{
  Width = width;
  Height = height;
  Brightness = MAX_BRIGHTNESS;
  OnMask = onMask;
  ColorMask = clrMask;
  SetOnMaskRange(0, 10, 0, 10, true);
  SetClrMaskRange(0, 10, 0, 10, false);
  LEDs = leds;
  RealTimeClock = rtc;
  Speed = 2;
  StepSize = 30;
  Frame = 0;
  ColorAnimationIdx = 0;
  PaletteIdx = 0;
  ActiveProgram = new WordClockProgram();
  NeedSave = false;
  Time_FromRTC();
  // ReadStateFromMemory();
}

void State::ReadStateFromMemory()
{
  debugln("read state");
  Serial.println(BOARD_NAME);
  Serial.println(FLASH_STORAGE_SAMD_VERSION);
  debug("EEPROM Length: ");
  debugln(EEPROM.length());
  uint8_t test = EEPROM.read(EEPROM_ADDR_COLOR);
  debug("value in color: ");
  debugln(test);

  // Check if EEPROM is initialized
  if (EEPROM.read(EEPROM_ADDR_INIT_VECT_1) == EEPROM_VAL_INIT_VECT_1 &&
      EEPROM.read(EEPROM_ADDR_INIT_VECT_2) == EEPROM_VAL_INIT_VECT_2 &&
      EEPROM.read(EEPROM_ADDR_INIT_VECT_3) == EEPROM_VAL_INIT_VECT_3 &&
      EEPROM.read(EEPROM_ADDR_INIT_VECT_4) == EEPROM_VAL_INIT_VECT_4 &&
      EEPROM.read(EEPROM_ADDR_INIT_VECT_5) == EEPROM_VAL_INIT_VECT_5)
  {
    debugln("EEPROM initialized, reading state from flash memory.");
    ColorAnimationIdx = EEPROM.read(EEPROM_ADDR_ANIMATION) % (sizeof(ColorAnimations) / sizeof(ColorAnimationFunc));
    Brightness = EEPROM.read(EEPROM_ADDR_BRIGHTNESS) % MAX_BRIGHTNESS;
    PaletteIdx = EEPROM.read(EEPROM_ADDR_COLOR) % (sizeof(ColorPalettes) / sizeof(CRGBPalette16));
    StepSize = EEPROM.read(EEPROM_ADDR_FRAMESTEP) % MAX_STEPSIZE;
    Speed = EEPROM.read(EEPROM_ADDR_SPEED) % MAX_SPEED;
  }
  else
  {
    debugln("Initializing EEPROM");
    // EEPROM.update(EEPROM_ADDR_ANIMATION, ColorAnimationIdx);
    // EEPROM.update(EEPROM_ADDR_BRIGHTNESS, Brightness);
    // EEPROM.update(EEPROM_ADDR_COLOR, PaletteIdx);
    // EEPROM.update(EEPROM_ADDR_FRAMESTEP, StepSize);
    // EEPROM.update(EEPROM_ADDR_SPEED, Speed);
    EEPROM.update(EEPROM_ADDR_INIT_VECT_1, EEPROM_VAL_INIT_VECT_1);
    EEPROM.update(EEPROM_ADDR_INIT_VECT_2, EEPROM_VAL_INIT_VECT_2);
    EEPROM.update(EEPROM_ADDR_INIT_VECT_3, EEPROM_VAL_INIT_VECT_3);
    EEPROM.update(EEPROM_ADDR_INIT_VECT_4, EEPROM_VAL_INIT_VECT_4);
    EEPROM.update(EEPROM_ADDR_INIT_VECT_5, EEPROM_VAL_INIT_VECT_5);
    StateUpdated();
  }
}
const unsigned long SaveThreshold = 1000 * 60 * 1; // check save every 1 minute
void State::WriteStateToMemory()
{
  if (NeedSave && (millis() - LastStateUpdate) > SaveThreshold)
  {
    debugln("Saving EEPROM");
    EEPROM.update(EEPROM_ADDR_ANIMATION, ColorAnimationIdx);
    EEPROM.update(EEPROM_ADDR_BRIGHTNESS, Brightness);
    EEPROM.update(EEPROM_ADDR_COLOR, PaletteIdx);
    EEPROM.update(EEPROM_ADDR_FRAMESTEP, StepSize);
    EEPROM.update(EEPROM_ADDR_SPEED, Speed);
    EEPROM.commit();
  }
  else if (NeedSave)
  {
    debug("Too Soon to save: ");
    debug(millis() - LastStateUpdate);
    debug(" threshold: ");
    debugln(SaveThreshold);
  }
}

void State::PrintStateValues()
{
  debugln("--------STATE VALUES--------");
  debug("Color Animation Index: ");
  debugln(ColorAnimationIdx);
  debug("Brightness: ");
  debugln(Brightness);
  debug("Color Palette Index: ");
  debugln(PaletteIdx);
  debug("Frame Step Size: ");
  debugln(StepSize);
  debug("Frame Speed: ");
  debugln(Speed);
  debugln("=============================");
}

void State::StateUpdated()
{
  NeedSave = true;
  LastStateUpdate = millis();
}

uint8_t State::GetBrightness()
{
  return Brightness;
}
void State::ChangeBrightness(int8_t amount)
{
  if (Brightness + amount < MIN_BRIGHTNESS && amount < 0)
  {
    return;
  }
  if (Brightness + amount > MAX_BRIGHTNESS && amount > 0)
  {
    return;
  }
  StateUpdated();
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
uint8_t State::ChangeStepSize(int8_t amount)
{
  if (StepSize + amount < MIN_STEPSIZE && amount < 0)
  {
    return StepSize;
  }
  if (StepSize + amount > MAX_STEPSIZE && amount > 0)
  {
    return StepSize;
  }
  StateUpdated();
  StepSize += amount;
  return StepSize;
}
uint8_t State::GetSpeed()
{
  return Speed;
}
uint8_t State::ChangeSpeed(int8_t amount)
{
  if (Speed + amount < MIN_SPEED && amount < 0)
  {
    return Speed;
  }
  if (Speed + amount > MAX_SPEED && amount > 0)
  {
    return Speed;
  }
  Speed += amount;
  StateUpdated();
  return Speed;
}
ColorAnimationFunc State::GetColorAnimation()
{
  return ColorAnimations[ColorAnimationIdx];
}

uint8_t State::SetColorAnimation(int8_t direction)
{
  uint8_t maxIdx = sizeof(ColorAnimations) / sizeof(ColorAnimationFunc);
  if (direction < 0 && ColorAnimationIdx == 0)
    ColorAnimationIdx = maxIdx;

  ColorAnimationIdx += direction;
  ColorAnimationIdx = ColorAnimationIdx % maxIdx;
  StateUpdated();
  return ColorAnimationIdx;
}
CRGBPalette16 State::GetColorPalette()
{
  return ColorPalettes[PaletteIdx];
}
uint8_t State::SetColorPalette(int8_t direction)
{
  uint8_t maxIdx = sizeof(ColorPalettes) / sizeof(CRGBPalette16);
  if (direction < 0 && PaletteIdx == 0)
    PaletteIdx = maxIdx;

  PaletteIdx += direction;
  PaletteIdx = PaletteIdx % maxIdx;
  StateUpdated();
  return PaletteIdx;
}
void State::SetMaskRange(bool *mask, uint8_t x1, uint8_t x2, uint8_t y1, uint8_t y2, bool on)
{
  for (uint8_t o = x1; o <= x2; o++)
  {
    for (uint8_t i = y1; i <= y2; i++)
    {
      mask[XY(o, i, Width, Height)] = on;
    }
  }
}
void State::SetOnMaskRange(uint8_t x1, uint8_t x2, uint8_t y1, uint8_t y2, bool on)
{
  SetMaskRange(OnMask, x1, x2, y1, y2, on);
}
void State::SetClrMaskRange(uint8_t x1, uint8_t x2, uint8_t y1, uint8_t y2, bool on)
{
  SetMaskRange(ColorMask, x1, x2, y1, y2, on);
}
