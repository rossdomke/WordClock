#include "SetAnimationProgram.h"
#include "../../State.h"
#include "../helpers.h"
#include <Arduino.h>
#include "../CharacterMasks.h"

#include "WordClockProgram.h"
#include "SetSpeedProgram.h"
#include "FunimationProgram.h"
#include "SetBrightnessProgram.h"
//------------- Click Handlers ----------------//
void SetAnimationProgram::ClickHandler(State &state)
{
  debugln("SetAnimationProgram: click");
  state.ActiveProgram = new SetBrightnessProgram();
}
void SetAnimationProgram::DoubleClickHandler(State &state)
{
  debugln("SetAnimationProgram: double click");
  state.ActiveProgram = new FunimationProgram();
}
void SetAnimationProgram::TripleClickHandler(State &state)
{
  debugln("SetAnimationProgram: triple click");
  state.ActiveProgram = new SetSpeedProgram();
}
void SetAnimationProgram::LongClickHandler(State &state)
{
  debugln("SetAnimationProgram: long click");
  state.ActiveProgram = new WordClockProgram();
}

//------------- Rotary Handlers ----------------//
void SetAnimationProgram::RotaryUpHandler(State &state)
{
  debug("SetAnimationProgram: rotary up: ");
  uint8_t idx = state.SetColorAnimation(1);
  debugln(idx);
}
void SetAnimationProgram::RotaryDownHandler(State &state)
{
  debugln("SetAnimationProgram: rotary down: ");
  uint8_t idx = state.SetColorAnimation(-1);
  debugln(idx);
}

//----------------- SetAnimationProgram --------------------//
void SetAnimationProgram::Run(State &state)
{
  state.SetOnMaskRange(0, 10, 0, 5, false);
  state.SetOnMaskRange(0, 10, 6, 10, true);
  state.SetClrMaskRange(0, 10, 0, 5, true);
  state.SetClrMaskRange(0, 10, 6, 10, false);
  for (int x = 0; x < 11; x++)
  {
    for (int y = 0; y < 6; y++)
    {
      state.LEDs[XY(x, y, state.GetWidth(), state.GetHeight())] = CRGB::White;
    }
  }
  DisplaySmallAlpha(state.OnMask, CharMask::CharIdx::A, 0, 0, true);
  DisplaySmallAlpha(state.OnMask, CharMask::CharIdx::N, 4, 0, true);
  DisplaySmallAlpha(state.OnMask, CharMask::CharIdx::I, 8, 0, true);
}