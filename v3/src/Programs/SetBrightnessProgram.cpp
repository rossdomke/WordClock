#include "SetBrightnessProgram.h"
#include "../../State.h"
#include "../helpers.h"
#include <Arduino.h>
#include "../CharacterMasks.h"

#include "SetSpeedProgram.h"
#include "SetColorProgram.h"
#include "WordClockProgram.h"
#include "FunimationProgram.h"

//------------- Click Handlers ----------------//
void SetBrightnessProgram::ClickHandler(State &state)
{
  debugln("SetBrightnessProgram: click");
  state.ActiveProgram = new SetColorProgram();
}
void SetBrightnessProgram::DoubleClickHandler(State &state)
{
  debugln("SetBrightnessProgram: double click");
  state.ActiveProgram = new FunimationProgram();
}
void SetBrightnessProgram::TripleClickHandler(State &state)
{
  debugln("SetBrightnessProgram: triple click");
  state.ActiveProgram = new SetSpeedProgram();
}
void SetBrightnessProgram::LongClickHandler(State &state)
{
  debugln("SetBrightnessProgram: long click");
  state.ActiveProgram = new WordClockProgram();
}
//------------- Rotary Handlers ----------------//
void SetBrightnessProgram::RotaryUpHandler(State &state)
{

  state.ChangeBrightness((MAX_BRIGHTNESS - MIN_BRIGHTNESS) / state.GetWidth());
  debug("SetBrightnessProgram: rotary up: ");
  debugln(state.GetBrightness());
}
void SetBrightnessProgram::RotaryDownHandler(State &state)
{

  state.ChangeBrightness(((MAX_BRIGHTNESS - MIN_BRIGHTNESS) / state.GetWidth()) * -1);
  debug("SetBrightnessProgram: rotary down: ");
  debugln(state.GetBrightness());
}
//----------------- SetBrightnessProgram --------------------//
void SetBrightnessProgram::Run(State &state)
{

  state.SetOnMaskRange(0, 10, 0, 5, false);
  state.SetOnMaskRange(0, 10, 6, 10, true);
  state.SetClrMaskRange(0, 10, 0, 5, true);
  state.SetClrMaskRange(0, 10, 6, 10, false);
  for (int x = 0; x < 11; x++)
  {
    for (int y = 0; y < 6; y++)
    {
      state.LEDs[XY(x, y, state.GetWidth(), state.GetHeight())] = CRGB::White;
    }
  }
  DisplaySmallAlpha(state.OnMask, CharMask::CharIdx::B, 0, 0, true);
  DisplaySmallAlpha(state.OnMask, CharMask::CharIdx::R, 4, 0, true);
  DisplaySmallAlpha(state.OnMask, CharMask::CharIdx::T, 8, 0, true);

  int8_t level = ((double)state.GetWidth() / (MAX_BRIGHTNESS - MIN_BRIGHTNESS)) * ((double)state.GetBrightness() - MIN_BRIGHTNESS) - 2;
  const uint8_t mag = 2;

  for (uint8_t x = 0; x < state.GetWidth(); x++)
  {
    for (uint8_t y = 6; y < state.GetHeight(); y++)
    {
      int8_t sinX = level + mag - sin(((2 * PI * y) / 5) - 18) * mag;
      state.OnMask[XY(x, y, state.GetWidth(), state.GetHeight())] = x <= sinX;
    }
  }
}