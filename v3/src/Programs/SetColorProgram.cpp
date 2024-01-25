#include "SetColorProgram.h"
#include "../../State.h"
#include "../helpers.h"
#include <Arduino.h>
#include "../CharacterMasks.h"

#include "SetSpeedProgram.h"
#include "SetAnimationProgram.h"
#include "WordClockProgram.h"
#include "FunimationProgram.h"
//------------- Click Handlers ----------------//
void SetColorProgram::ClickHandler(State &state)
{
  debugln("SetColorProgram: click");
  state.ActiveProgram = new SetAnimationProgram();
}
void SetColorProgram::DoubleClickHandler(State &state)
{
  debugln("SetColorProgram: double click");
  state.ActiveProgram = new FunimationProgram();
}
void SetColorProgram::TripleClickHandler(State &state)
{
  debugln("SetColorProgram: triple click");
  state.ActiveProgram = new SetSpeedProgram();
}
void SetColorProgram::LongClickHandler(State &state)
{
  debugln("SetColorProgram: long click");
  state.ActiveProgram = new WordClockProgram();
}

//------------- Rotary Handlers ----------------//
void SetColorProgram::RotaryUpHandler(State &state)
{
  debug("SetColorProgram: rotary up: ");
  uint8_t idx = state.SetColorPalette(1);
  debugln(idx);
}
void SetColorProgram::RotaryDownHandler(State &state)
{
  debug("SetColorProgram: rotary down: ");
  uint8_t idx = state.SetColorPalette(-1);
  debugln(idx);
}

//----------------- SetColorProgram --------------------//
void SetColorProgram::Run(State &state)
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
  DisplaySmallAlpha(state.OnMask, CharMask::CharIdx::C, 0, 0, true);
  DisplaySmallAlpha(state.OnMask, CharMask::CharIdx::L, 4, 0, true);
  DisplaySmallAlpha(state.OnMask, CharMask::CharIdx::R, 8, 0, true);
}