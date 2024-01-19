#include "FunimationProgram.h"
#include "../../State.h"
#include "../helpers.h"
#include <Arduino.h>

#include "WordClockProgram.h"
//------------- Click Handlers ----------------//
void FunimationProgram::ClickHandler(State &state)
{
  debugln("FunimationProgram: click");
    state.ActiveProgram = new WordClockProgram();
}
void FunimationProgram::DoubleClickHandler(State &state)
{
  debugln("FunimationProgram: double click");
    state.ActiveProgram = new WordClockProgram();
}
void FunimationProgram::TripleClickHandler(State &state)
{
  debugln("FunimationProgram: triple click");
    state.ActiveProgram = new WordClockProgram();
}
void FunimationProgram::LongClickHandler(State &state)
{
  debugln("FunimationProgram: long click");
    state.ActiveProgram = new WordClockProgram();
}

//------------- Rotary Handlers ----------------//
void FunimationProgram::RotaryUpHandler(State &state)
{
  debugln("FunimationProgram: rotary up: ");
}
void FunimationProgram::RotaryDownHandler(State &state)
{
  debugln("FunimationProgram: rotary down: ");
}

//----------------- FunimationProgram --------------------//
void FunimationProgram::Run(State &state)
{
    state.ActiveProgram = new WordClockProgram();
}