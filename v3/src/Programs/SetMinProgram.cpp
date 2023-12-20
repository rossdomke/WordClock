#include "SetMinProgram.h"
#include "../../State.h"
#include <Arduino.h>

#include "WordClockProgram.h"

void SetMinProgram::ClickHandler(State &state)
{
  Serial.println("SetMinProgram click");
  state.ActiveProgram = new WordClockProgram();
}
void SetMinProgram::DoubleClickHandler(State &state)
{
  Serial.println("SetMinProgram double click");
  ClickHandler(state);
}
void SetMinProgram::TripleClickHandler(State &state)
{
  Serial.println("SetMinProgram triple click");
  ClickHandler(state);
}
void SetMinProgram::LongClickHandler(State &state)
{
  Serial.println("SetMinProgram long click");
  ClickHandler(state);
}
void SetMinProgram::RotaryUpHandler(State &state)
{
  Serial.println("SetMinProgram rotary up");
}
void SetMinProgram::RotaryDownHandler(State &state)
{
  Serial.println("SetMinProgram rotary down");
}
void SetMinProgram::Run(State &state)
{
  Serial.println("SetMinProgram rum");
}