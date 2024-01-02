#include "Program.h"
#include "../../State.h"
#include "../helpers.h"
#include <Arduino.h>

//------------- Click Handlers ----------------//
void Program::ClickHandler(State &state)
{
  debugln("program: click");
}
void Program::DoubleClickHandler(State &state)
{
  debugln("program: double click");
}
void Program::TripleClickHandler(State &state)
{
  debugln("program: triple click");
}
void Program::LongClickHandler(State &state)
{
  debugln("program: long click");
}

//------------- Rotary Handlers ----------------//
void Program::RotaryUpHandler(State &state)
{
  debugln("program: rotary up: ");
}
void Program::RotaryDownHandler(State &state)
{
  debugln("program: rotary down: ");
}

//----------------- Program --------------------//
void Program::Run(State &state)
{
}