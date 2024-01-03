#include "FunimationProgram.h"
#include "../../State.h"
#include "../helpers.h"
#include <Arduino.h>

//------------- Click Handlers ----------------//
void FunimationProgram::ClickHandler(State &state)
{
  debugln("FunimationProgram: click");
}
void FunimationProgram::DoubleClickHandler(State &state)
{
  debugln("FunimationProgram: double click");
}
void FunimationProgram::TripleClickHandler(State &state)
{
  debugln("FunimationProgram: triple click");
}
void FunimationProgram::LongClickHandler(State &state)
{
  debugln("FunimationProgram: long click");
}

//------------- Rotary Handlers ----------------//
void FunimationProgram::RotaryUpHandler(State &state)
{
  debugln("FunimationProgram: rotary up: ");
}
void FunimationProgram::RotaryDownHandler(State &state)
{
  debugln("FunimationProgram: rotary down: ");
}

//----------------- FunimationProgram --------------------//
void FunimationProgram::Run(State &state)
{
}