#include "SetHourProgram.h"
#include "../../State.h"
#include <Arduino.h>
#include <FastLED.h>

#include "SetMinProgram.h"

//------------- Click Handlers ----------------//
void SetHourProgram::ClickHandler(State &state)
{
  Serial.println("SetHourProgram: click");
  state.ActiveProgram = new SetMinProgram();
}
void SetHourProgram::DoubleClickHandler(State &state)
{
  Serial.println("SetHourProgram: double click");
  ClickHandler(state);
}
void SetHourProgram::TripleClickHandler(State &state)
{
  Serial.println("SetHourProgram: triple click");
  ClickHandler(state);
}
void SetHourProgram::LongClickHandler(State &state)
{
  Serial.println("SetHourProgram: long click");
  ClickHandler(state);
}

//------------- Rotary Handlers ----------------//
void SetHourProgram::RotaryUpHandler(State &state)
{
  state.Time_SetRTC(60);
}
void SetHourProgram::RotaryDownHandler(State &state)
{
  state.Time_SetRTC(-60);
}

//----------------- Program --------------------//
void SetHourProgram::Run(State &state)
{
  EVERY_N_MILLISECONDS(100)
  {
    Serial.println(state.Time_GetHour());
  }
}