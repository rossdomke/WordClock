#include "SetMinProgram.h"
#include "../../State.h"
#include "../helpers.h"
#include <Arduino.h>
#include <FastLED.h>

#include "WordClockProgram.h"

//------------- Click Handlers ----------------//
void SetMinProgram::ClickHandler(State &state)
{
  debugln("SetMinProgram: click");
  state.ActiveProgram = new WordClockProgram();
}
void SetMinProgram::DoubleClickHandler(State &state)
{
  debugln("SetMinProgram: double click");
  ClickHandler(state);
}
void SetMinProgram::TripleClickHandler(State &state)
{
  debugln("SetMinProgram: triple click");
  ClickHandler(state);
}
void SetMinProgram::LongClickHandler(State &state)
{
  debugln("SetMinProgram: long click");
  ClickHandler(state);
}

//------------- Rotary Handlers ----------------//
void SetMinProgram::RotaryUpHandler(State &state)
{
  debugln("SetMinProgram: RotaryUp Handler");
  state.Time_SetRTC(1);
}
void SetMinProgram::RotaryDownHandler(State &state)
{
  debugln("SetMinProgram: RotaryDown Handler");
  state.Time_SetRTC(-1);
}

//----------------- Program --------------------//
void SetMinProgram::Run(State &state)
{
  EVERY_N_MILLISECONDS(100)
  {
    debugln(state.Time_GetMin());
  }
}