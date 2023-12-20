#include "WordClockProgram.h"
#include "../../State.h"
#include <Arduino.h>

#include "Program.h"

WordClockProgram::WordClockProgram() {}
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
  state.ActiveProgram = new Program();
}
void WordClockProgram::RotaryUpHandler(State &state)
{
  Serial.print("WordClockProgram rotary up: ");
  Serial.println(++state.TestVal);
}
void WordClockProgram::RotaryDownHandler(State &state)
{
  Serial.print("WordClockProgram rotary down: ");
  Serial.println(--state.TestVal);
}
void WordClockProgram::Run(State &state)
{
  Serial.println("WordClockProgram rum");
}