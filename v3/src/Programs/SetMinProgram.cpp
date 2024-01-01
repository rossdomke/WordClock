#include "SetMinProgram.h"
#include "../../State.h"
#include <Arduino.h>
#include <FastLED.h>

#include "WordClockProgram.h"

//------------- Click Handlers ----------------//
void SetMinProgram::ClickHandler(State &state)
{
  Serial.println("SetMinProgram: click");
  state.ActiveProgram = new WordClockProgram();
}
void SetMinProgram::DoubleClickHandler(State &state)
{
  Serial.println("SetMinProgram: double click");
  ClickHandler(state);
}
void SetMinProgram::TripleClickHandler(State &state)
{
  Serial.println("SetMinProgram: triple click");
  ClickHandler(state);
}
void SetMinProgram::LongClickHandler(State &state)
{
  Serial.println("SetMinProgram: long click");
  ClickHandler(state);
}

//------------- Rotary Handlers ----------------//
void SetMinProgram::RotaryUpHandler(State &state)
{
  state.Time_SetRTC(1);
}
void SetMinProgram::RotaryDownHandler(State &state)
{
  state.Time_SetRTC(-1);
}

//----------------- Program --------------------//
void SetMinProgram::Run(State &state)
{
  EVERY_N_MILLISECONDS(100)
  {
    Serial.println(state.Time_GetMin());
  }
}