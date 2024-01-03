#include "SetBrightnessProgram.h"
#include "../../State.h"
#include "../helpers.h"
#include <Arduino.h>

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
}
void SetBrightnessProgram::LongClickHandler(State &state)
{
  debugln("SetBrightnessProgram: long click");
  state.ActiveProgram = new WordClockProgram();
}

//------------- Rotary Handlers ----------------//
void SetBrightnessProgram::RotaryUpHandler(State &state)
{
  state.ChangeBrightness(5);
  debug("SetBrightnessProgram: rotary up: ");
  debugln(state.GetBrightness());
}
void SetBrightnessProgram::RotaryDownHandler(State &state)
{
  state.ChangeBrightness(-5);
  debug("SetBrightnessProgram: rotary down: ");
  debugln(state.GetBrightness());
}

//----------------- SetBrightnessProgram --------------------//
void SetBrightnessProgram::Run(State &state)
{
}