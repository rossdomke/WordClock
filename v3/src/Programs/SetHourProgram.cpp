#include "SetHourProgram.h"
#include "../../State.h"
#include "../helpers.h"
#include <Arduino.h>
#include <FastLED.h>

#include "SetMinProgram.h"

//------------- Click Handlers ----------------//
void SetHourProgram::ClickHandler(State &state)
{
  debugln("SetHourProgram: click");
  state.ActiveProgram = new SetMinProgram();
}
void SetHourProgram::DoubleClickHandler(State &state)
{
  debugln("SetHourProgram: double click");
  ClickHandler(state);
}
void SetHourProgram::TripleClickHandler(State &state)
{
  debugln("SetHourProgram: triple click");
  ClickHandler(state);
}
void SetHourProgram::LongClickHandler(State &state)
{
  debugln("SetHourProgram: long click");
  ClickHandler(state);
}

//------------- Rotary Handlers ----------------//
void SetHourProgram::RotaryUpHandler(State &state)
{
  debugln("SetHourProgram: RotaryUp Handler");
  state.Time_SetRTC(60);
}
void SetHourProgram::RotaryDownHandler(State &state)
{
  debugln("SetHourProgram: RotaryDown Handler");
  state.Time_SetRTC(-60);
}

//----------------- Program --------------------//
void SetHourProgram::Run(State &state)
{
  EVERY_N_MILLISECONDS(100)
  {
    debugln(state.Time_GetHour());
  }
}