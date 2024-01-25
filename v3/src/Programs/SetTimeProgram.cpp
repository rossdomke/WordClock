#include "SetTimeProgram.h"
#include "../../State.h"
#include <Arduino.h>
#include <FastLED.h>

#include "../helpers.h"
#include "../CharacterMasks.h"
#include "WordClockProgram.h"

//------------- Click Handlers ----------------//
void SetTimeProgram::ClickHandler(State &state)
{
  debugln("SetTimeProgram: click");
  // state.ActiveProgram = new SetMinProgram();
  if (Mode == SetTime::Mode::SetHour)
  {
    Mode = SetTime::Mode::SetMin;
  }
  else
  {
    Mode = SetTime::Mode::SetHour;
  }
}
void SetTimeProgram::DoubleClickHandler(State &state)
{
  debugln("SetTimeProgram: double click");
  // ClickHandler(state);
}
void SetTimeProgram::TripleClickHandler(State &state)
{
  debugln("SetTimeProgram: triple click");
  // ClickHandler(state);
}
void SetTimeProgram::LongClickHandler(State &state)
{
  debugln("SetTimeProgram: long click");
  state.ActiveProgram = new WordClockProgram();
}

//------------- Rotary Handlers ----------------//
void SetTimeProgram::RotaryUpHandler(State &state)
{
  debug("SetHour--> ");
  debug(state.Time_GetHour());
  debug(":");
  debugln(state.Time_GetMin());
  int8_t amount = 1;
  if (Mode == SetTime::Mode::SetHour)
    amount = 60;

  state.Time_SetRTC(amount);
}
void SetTimeProgram::RotaryDownHandler(State &state)
{
  debug("SetHour--> ");
  debug(state.Time_GetHour());
  debug(":");
  debugln(state.Time_GetMin());

  int8_t amount = -1;
  if (Mode == SetTime::Mode::SetHour)
    amount = -60;

  state.Time_SetRTC(amount);
}

//----------------- Program --------------------//
void SetTimeProgram::Run(State &state)
{
  EVERY_N_SECONDS(1)
  {
    debug("SetHour--> ");
    debug(state.Time_GetHour());
    debug(":");
    debugln(state.Time_GetMin());
  }
  state.SetOnMaskRange(0, 10, 0, 10, false);
  bool showIndicator = state.GetStaticFrame() % 32 < 26;
  uint8_t HourTensDigit = state.Time_GetHour() / 10;
  uint8_t HourOnesDigit = state.Time_GetHour() % 10;
  uint8_t MinTensDigit = state.Time_GetMin() / 10;
  uint8_t MinOnesDigit = state.Time_GetMin() % 10;

  if (Mode != SetTime::Mode::SetHour || showIndicator)
  {
    DisplaySmallAlpha(state.OnMask, CharMask::CharIdx::H, 0, 0, true);
  }
  DisplaySmallNum(state.OnMask, HourTensDigit, 4, 0, true);
  DisplaySmallNum(state.OnMask, HourOnesDigit, 8, 0, true);

  if (Mode != SetTime::Mode::SetMin || showIndicator)
  {
    DisplaySmallAlpha(state.OnMask, CharMask::CharIdx::M, 0, 6, true);
  }
  DisplaySmallNum(state.OnMask, MinTensDigit, 4, 6, true);
  DisplaySmallNum(state.OnMask, MinOnesDigit, 8, 6, true);
}