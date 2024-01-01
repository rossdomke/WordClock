#include "WordClockProgram.h"
#include "../../State.h"
#include <Arduino.h>
#include <FastLED.h>

#include "SetHourProgram.h"
//------------- Click Handlers ----------------//
void WordClockProgram::ClickHandler(State &state)
{
  Serial.println("WordClockProgram: click");
}
void WordClockProgram::DoubleClickHandler(State &state)
{
  Serial.println("WordClockProgram: double click");
}
void WordClockProgram::TripleClickHandler(State &state)
{
  Serial.println("WordClockProgram: triple click");
}
void WordClockProgram::LongClickHandler(State &state)
{
  Serial.println("WordClockProgram: long click");
  state.ActiveProgram = new SetHourProgram();
}

//------------- Rotary Handlers ----------------//
void WordClockProgram::RotaryUpHandler(State &state)
{
  Serial.println("WordClockProgram: rotary up");
  state.ChangeBrightness(5);
  Serial.println(state.GetBrightness());
}
void WordClockProgram::RotaryDownHandler(State &state)
{
  Serial.println("WordClockProgram: rotary down");
  state.ChangeBrightness(-5);
  Serial.println(state.GetBrightness());
}

//----------------- Program --------------------//
void WordClockProgram::Run(State &state)
{
  EVERY_N_SECONDS(1)
  {
    state.Time_FromRTC();
    Serial.print(state.Time_GetHour());
    Serial.print(":");
    Serial.println(state.Time_GetMin());
  }
}