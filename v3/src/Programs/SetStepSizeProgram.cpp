#include "SetStepSizeProgram.h"
#include "../../State.h"
#include "../helpers.h"
#include <Arduino.h>
#include "../CharacterMasks.h"

#include "SetSpeedProgram.h"
#include "SetBrightnessProgram.h"
#include "WordClockProgram.h"
#include "FunimationProgram.h"
//------------- Click Handlers ----------------//
void SetStepSizeProgram::ClickHandler(State &state)
{
  debugln("SetStepSizeProgram: click");
  state.ActiveProgram = new SetSpeedProgram();
}
void SetStepSizeProgram::DoubleClickHandler(State &state)
{
  debugln("SetStepSizeProgram: double click");
  state.ActiveProgram = new FunimationProgram();
}
void SetStepSizeProgram::TripleClickHandler(State &state)
{
  debugln("SetStepSizeProgram: triple click");
  state.ActiveProgram = new SetBrightnessProgram();
}
void SetStepSizeProgram::LongClickHandler(State &state)
{
  debugln("SetStepSizeProgram: long click");
  state.ActiveProgram = new WordClockProgram();
}

//------------- Rotary Handlers ----------------//
void SetStepSizeProgram::RotaryUpHandler(State &state)
{
  state.ChangeStepSize(1);
  debug("SetStepSizeProgram: rotary up: ");
  debugln(state.GetStepSize());
}
void SetStepSizeProgram::RotaryDownHandler(State &state)
{
  state.ChangeStepSize(-1);
  debug("SetStepSizeProgram: rotary down: ");
  debugln(state.GetStepSize());
}

//----------------- SetStepSizeProgram --------------------//
void SetStepSizeProgram::Run(State &state)
{
  state.SetOnMaskRange(0, 10, 0, 10, false);
  state.SetOnMaskRange(0, 10, 5, 5, true);
  state.SetClrMaskRange(0, 10, 0, 10, true);
  state.SetClrMaskRange(0, 10, 5, 5, false);
  for (int x = 0; x < 11; x++)
  {
    for (int y = 0; y < 11; y++)
    {
      state.LEDs[XY(x, y, state.GetWidth(), state.GetHeight())] = CRGB::White;
    }
  }
  DisplaySmallAlpha(state.OnMask, CharMask::CharIdx::S, 0, 0, true);
  DisplaySmallAlpha(state.OnMask, CharMask::CharIdx::T, 4, 0, true);
  DisplaySmallAlpha(state.OnMask, CharMask::CharIdx::P, 8, 0, true);
  uint8_t StpTensDigit = state.GetStepSize() / 10;
  uint8_t StpOnesDigit = state.GetStepSize() % 10;
  DisplaySmallNum(state.OnMask, StpTensDigit, 2, 6, true);
  DisplaySmallNum(state.OnMask, StpOnesDigit, 6, 6, true);
}