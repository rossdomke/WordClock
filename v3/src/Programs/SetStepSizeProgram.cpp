#include "SetStepSizeProgram.h"
#include "../../State.h"
#include "../helpers.h"
#include <Arduino.h>

//------------- Click Handlers ----------------//
void SetStepSizeProgram::ClickHandler(State &state)
{
  debugln("SetStepSizeProgram: click");
}
void SetStepSizeProgram::DoubleClickHandler(State &state)
{
  debugln("SetStepSizeProgram: double click");
}
void SetStepSizeProgram::TripleClickHandler(State &state)
{
  debugln("SetStepSizeProgram: triple click");
}
void SetStepSizeProgram::LongClickHandler(State &state)
{
  debugln("SetStepSizeProgram: long click");
}

//------------- Rotary Handlers ----------------//
void SetStepSizeProgram::RotaryUpHandler(State &state)
{
  debugln("SetStepSizeProgram: rotary up: ");
}
void SetStepSizeProgram::RotaryDownHandler(State &state)
{
  debugln("SetStepSizeProgram: rotary down: ");
}

//----------------- SetStepSizeProgram --------------------//
void SetStepSizeProgram::Run(State &state)
{
}