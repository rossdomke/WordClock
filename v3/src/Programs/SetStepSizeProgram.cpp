#include "SetStepSizeProgram.h"
#include "../../State.h"
#include "../helpers.h"
#include <Arduino.h>

#include "SetSpeedProgram.h"
#include "WordClockProgram.h"
#include "FunimationProgram.h"
//------------- Click Handlers ----------------//
void SetStepSizeProgram::ClickHandler(State &state)
{
  debugln("SetStepSizeProgram: click");
  state.ActiveProgram = new SetSpeedProgram();
}
void SetStepSizeProgram::DoubleClickHandler(State &state)
{
  debugln("SetStepSizeProgram: double click");
  state.ActiveProgram = new FunimationProgram();
}
void SetStepSizeProgram::TripleClickHandler(State &state)
{
  debugln("SetStepSizeProgram: triple click");
}
void SetStepSizeProgram::LongClickHandler(State &state)
{
  debugln("SetStepSizeProgram: long click");
  state.ActiveProgram = new WordClockProgram();
}

//------------- Rotary Handlers ----------------//
void SetStepSizeProgram::RotaryUpHandler(State &state)
{
  state.ChangeStepSize(1);
  debug("SetStepSizeProgram: rotary up: ");
  debugln(state.GetStepSize());

}
void SetStepSizeProgram::RotaryDownHandler(State &state)
{
  state.ChangeStepSize(-1);
  debug("SetStepSizeProgram: rotary down: ");
  debugln(state.GetStepSize());
}

//----------------- SetStepSizeProgram --------------------//
void SetStepSizeProgram::Run(State &state)
{
}