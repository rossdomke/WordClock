#include "SetSpeedProgram.h"
#include "../../State.h"
#include "../helpers.h"
#include <Arduino.h>
#include "../CharacterMasks.h"

#include "SetStepSizeProgram.h"
#include "SetBrightnessProgram.h"
#include "WordClockProgram.h"
#include "FunimationProgram.h"

//------------- Click Handlers ----------------//
void SetSpeedProgram::ClickHandler(State &state)
{
  debugln("SetSpeedProgram: click");
  state.ActiveProgram = new SetStepSizeProgram();
}
void SetSpeedProgram::DoubleClickHandler(State &state)
{
  debugln("SetSpeedProgram: double click");
  state.ActiveProgram = new FunimationProgram();
}
void SetSpeedProgram::TripleClickHandler(State &state)
{
  debugln("SetSpeedProgram: triple click");
  state.ActiveProgram = new SetBrightnessProgram();
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
  DisplaySmallAlpha(state.OnMask, CharMask::CharIdx::P, 4, 0, true);
  DisplaySmallAlpha(state.OnMask, CharMask::CharIdx::D, 8, 0, true);

  uint8_t SpdTensDigit = state.GetSpeed() / 10;
  uint8_t SpdOnesDigit = state.GetSpeed() % 10;
  DisplaySmallNum(state.OnMask, SpdTensDigit, 2, 6, true);
  DisplaySmallNum(state.OnMask, SpdOnesDigit, 6, 6, true);
}