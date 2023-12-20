#include "SetHourProgram.h"
#include "../../State.h"
#include <Arduino.h>

#include "SetMinProgram.h"

void SetHourProgram::ClickHandler(State &state)
{
  Serial.println("SetHourProgram click");
  state.ActiveProgram = new SetMinProgram();
}
void SetHourProgram::DoubleClickHandler(State &state)
{
  Serial.println("SetHourProgram double click");
  ClickHandler(state);
}
void SetHourProgram::TripleClickHandler(State &state)
{
  Serial.println("SetHourProgram triple click");
  ClickHandler(state);
}
void SetHourProgram::LongClickHandler(State &state)
{
  Serial.println("SetHourProgram long click");
  ClickHandler(state);
}
void SetHourProgram::RotaryUpHandler(State &state)
{
  Serial.println("SetHourProgram rotary up");
}
void SetHourProgram::RotaryDownHandler(State &state)
{
  Serial.println("SetHourProgram rotary down");
}
void SetHourProgram::Run(State &state)
{
  Serial.println("SetHourProgram rum");
}