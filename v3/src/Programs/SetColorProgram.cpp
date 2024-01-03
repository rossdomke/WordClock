#include "SetColorProgram.h"
#include "../../State.h"
#include "../helpers.h"
#include <Arduino.h>

#include "SetAnimationProgram.h"
#include "WordClockProgram.h"
#include "FunimationProgram.h"
//------------- Click Handlers ----------------//
void SetColorProgram::ClickHandler(State &state)
{
  debugln("SetColorProgram: click");
  state.ActiveProgram = new SetAnimationProgram();
}
void SetColorProgram::DoubleClickHandler(State &state)
{
  debugln("SetColorProgram: double click");
  state.ActiveProgram = new FunimationProgram();
}
void SetColorProgram::TripleClickHandler(State &state)
{
  debugln("SetColorProgram: triple click");
}
void SetColorProgram::LongClickHandler(State &state)
{
  debugln("SetColorProgram: long click");
  state.ActiveProgram = new WordClockProgram();
}

//------------- Rotary Handlers ----------------//
void SetColorProgram::RotaryUpHandler(State &state)
{
  debug("SetColorProgram: rotary up: ");
  uint8_t idx = state.SetColorPalette(1);
  debugln(idx);
}
void SetColorProgram::RotaryDownHandler(State &state)
{
  debug("SetColorProgram: rotary down: ");
  uint8_t idx = state.SetColorPalette(-1);
  debugln(idx);
}

//----------------- SetColorProgram --------------------//
void SetColorProgram::Run(State &state)
{
}