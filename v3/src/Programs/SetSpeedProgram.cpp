#include "SetSpeedProgram.h"
#include "../../State.h"
#include "../helpers.h"
#include <Arduino.h>


#include "SetBrightnessProgram.h"
#include "WordClockProgram.h"
#include "FunimationProgram.h"

//------------- Click Handlers ----------------//
void SetSpeedProgram::ClickHandler(State &state)
{
  debugln("SetSpeedProgram: click");
  state.ActiveProgram = new SetBrightnessProgram();
}
void SetSpeedProgram::DoubleClickHandler(State &state)
{
  debugln("SetSpeedProgram: double click");
  state.ActiveProgram = new FunimationProgram();
}
void SetSpeedProgram::TripleClickHandler(State &state)
{
  debugln("SetSpeedProgram: triple click");
}
void SetSpeedProgram::LongClickHandler(State &state)
{
  debugln("SetSpeedProgram: long click");
  state.ActiveProgram = new WordClockProgram();
}

//------------- Rotary Handlers ----------------//
void SetSpeedProgram::RotaryUpHandler(State &state)
{
  state.ChangeSpeed(1);
  debug("SetSpeedProgram: rotary up: ");
  debugln(state.GetSpeed());
}
void SetSpeedProgram::RotaryDownHandler(State &state)
{
  state.ChangeSpeed(-1);
  debug("SetSpeedProgram: rotary down: ");
  debugln(state.GetSpeed());
}

//----------------- SetSpeedProgram --------------------//
void SetSpeedProgram::Run(State &state)
{
}