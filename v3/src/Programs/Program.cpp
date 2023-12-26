#include "Program.h"
#include "../../State.h"
#include <Arduino.h>

//------------- Click Handlers ----------------//
void Program::ClickHandler(State &state)
{
  Serial.println("program: click");
}
void Program::DoubleClickHandler(State &state)
{
  Serial.println("program: double click");
}
void Program::TripleClickHandler(State &state)
{
  Serial.println("program: triple click");
}
void Program::LongClickHandler(State &state)
{
  Serial.println("program: long click");
}

//------------- Rotary Handlers ----------------//
void Program::RotaryUpHandler(State &state)
{
  Serial.print("program: rotary up: ");
}
void Program::RotaryDownHandler(State &state)
{
  Serial.print("program: rotary down: ");
}

//----------------- Program --------------------//
void Program::Run(State &state)
{
}