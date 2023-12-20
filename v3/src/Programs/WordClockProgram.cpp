#include "WordClockProgram.h"
#include "../../State.h"
#include <Arduino.h>

#include "SetHourProgram.h"

void WordClockProgram::ClickHandler(State &state)
{
  Serial.println("WordClockProgram click");
}
void WordClockProgram::DoubleClickHandler(State &state)
{
  Serial.println("WordClockProgram double click");
}
void WordClockProgram::TripleClickHandler(State &state)
{
  Serial.println("WordClockProgram triple click");
}
void WordClockProgram::LongClickHandler(State &state)
{
  Serial.println("WordClockProgram long click");
  state.ActiveProgram = new SetHourProgram();
}
void WordClockProgram::RotaryUpHandler(State &state)
{
  Serial.println("WordClockProgram rotary up");
}
void WordClockProgram::RotaryDownHandler(State &state)
{
  Serial.println("WordClockProgram rotary down");
}
void WordClockProgram::Run(State &state)
{
  Serial.println("WordClockProgram rum");
}