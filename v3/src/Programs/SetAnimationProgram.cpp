#include "SetAnimationProgram.h"
#include "../../State.h"
#include "../helpers.h"
#include <Arduino.h>

#include "WordClockProgram.h"
#include "SetSpeedProgram.h"
#include "FunimationProgram.h"
#include "SetBrightnessProgram.h"
//------------- Click Handlers ----------------//
void SetAnimationProgram::ClickHandler(State &state)
{
  debugln("SetAnimationProgram: click");
  state.ActiveProgram = new SetBrightnessProgram();
}
void SetAnimationProgram::DoubleClickHandler(State &state)
{
  debugln("SetAnimationProgram: double click");
  state.ActiveProgram = new FunimationProgram();
}
void SetAnimationProgram::TripleClickHandler(State &state)
{
  debugln("SetAnimationProgram: triple click");
  state.ActiveProgram = new SetSpeedProgram();
}
void SetAnimationProgram::LongClickHandler(State &state)
{
  debugln("SetAnimationProgram: long click");
  state.ActiveProgram = new WordClockProgram();
}

//------------- Rotary Handlers ----------------//
void SetAnimationProgram::RotaryUpHandler(State &state)
{
  debug("SetAnimationProgram: rotary up: ");
  uint8_t idx = state.SetColorAnimation(1);
  debugln(idx);
}
void SetAnimationProgram::RotaryDownHandler(State &state)
{
  debugln("SetAnimationProgram: rotary down: ");
  uint8_t idx = state.SetColorAnimation(-1);
  debugln(idx);
}

//----------------- SetAnimationProgram --------------------//
void SetAnimationProgram::Run(State &state)
{
}