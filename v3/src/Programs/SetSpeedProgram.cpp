#include "SetSpeedProgram.h"
#include "../../State.h"
#include "../helpers.h"
#include <Arduino.h>

//------------- Click Handlers ----------------//
void SetSpeedProgram::ClickHandler(State &state)
{
  debugln("SetSpeedProgram: click");
}
void SetSpeedProgram::DoubleClickHandler(State &state)
{
  debugln("SetSpeedProgram: double click");
}
void SetSpeedProgram::TripleClickHandler(State &state)
{
  debugln("SetSpeedProgram: triple click");
}
void SetSpeedProgram::LongClickHandler(State &state)
{
  debugln("SetSpeedProgram: long click");
}

//------------- Rotary Handlers ----------------//
void SetSpeedProgram::RotaryUpHandler(State &state)
{
  debugln("SetSpeedProgram: rotary up: ");
}
void SetSpeedProgram::RotaryDownHandler(State &state)
{
  debugln("SetSpeedProgram: rotary down: ");
}

//----------------- SetSpeedProgram --------------------//
void SetSpeedProgram::Run(State &state)
{
}