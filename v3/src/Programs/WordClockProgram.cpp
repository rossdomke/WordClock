#include "WordClockProgram.h"
#include "../../State.h"
#include "../helpers.h"
#include <Arduino.h>
#include <FastLED.h>

#include "SetHourProgram.h"
#include "SetBrightnessProgram.h"
//------------- Click Handlers ----------------//
void WordClockProgram::ClickHandler(State &state)
{
  debugln("WordClockProgram: click");
}
void WordClockProgram::DoubleClickHandler(State &state)
{
  debugln("WordClockProgram: double click");
  state.ActiveProgram = new SetBrightnessProgram();
}
void WordClockProgram::TripleClickHandler(State &state)
{
  debugln("WordClockProgram: triple click");
}
void WordClockProgram::LongClickHandler(State &state)
{
  debugln("WordClockProgram: long click");
  state.ActiveProgram = new SetHourProgram();
}

//------------- Rotary Handlers ----------------//
void WordClockProgram::RotaryUpHandler(State &state)
{
  debugln("WordClockProgram: rotary up");
}
void WordClockProgram::RotaryDownHandler(State &state)
{
  debugln("WordClockProgram: rotary down");
}

//----------------- Program --------------------//
void WordClockProgram::Run(State &state)
{
  EVERY_N_SECONDS(1)
  {
    state.Time_FromRTC();
    debug(state.Time_GetHour());
    debug(":");
    debugln(state.Time_GetMin());
  }
}