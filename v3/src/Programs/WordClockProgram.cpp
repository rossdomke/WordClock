#include "WordClockProgram.h"
#include "../../State.h"
#include "../helpers.h"
#include <Arduino.h>
#include <FastLED.h>

#include "SetTimeProgram.h"
#include "SetBrightnessProgram.h"
#include "../CharacterMasks.h"
namespace WordClock
{
  enum Words
  {
    Its,
    A,
    Half,
    MinTen,
    Quarter,
    Twenty,
    MinFive,
    To,
    Past,
    After,
    Seven,
    Noon,
    Midnight,
    Ten,
    Five,
    Nine,
    Two,
    Eleven,
    Eight,
    One,
    Six,
    Three,
    Four,
    Oclock,
    Pasta,
    MccIts,
    Last
  };
}
//------------- Click Handlers ----------------//
void WordClockProgram::ClickHandler(State &state)
{
  debugln("WordClockProgram: click");
  LightMcc = millis();
}
void WordClockProgram::DoubleClickHandler(State &state)
{
  debugln("WordClockProgram: double click");
  state.ActiveProgram = new SetBrightnessProgram();
}
void WordClockProgram::TripleClickHandler(State &state)
{
  debugln("WordClockProgram: triple click");
}
void WordClockProgram::LongClickHandler(State &state)
{
  debugln("WordClockProgram: long click");
  state.ActiveProgram = new SetTimeProgram();
}

//------------- Rotary Handlers ----------------//
void WordClockProgram::RotaryUpHandler(State &state)
{
  debugln("WordClockProgram: rotary up: ");
}
void WordClockProgram::RotaryDownHandler(State &state)
{
  debugln("WordClockProgram: rotary down: ");
}

//----------------- Program --------------------//
void WordClockProgram::Run(State &state)
{
  EVERY_N_SECONDS(2)
  {
    debug("The time is: ");
    debug(state.Time_GetHour());
    debug(":");
    debugln(state.Time_GetMin());
  }
  state.SetOnMaskRange(0, 10, 0, 10, false);
  state.SetClrMaskRange(0, 10, 0, 10, false);
  state.Time_FromRTC();
  uint8_t Hour = state.Time_GetHour();
  uint8_t Min = round(state.Time_GetMin() / 5.00) * 5;

  if (millis() - LightMcc < 1000 * 30)
  {
    LightWord(WordClock::Words::MccIts, state);
  }

  LightWord(WordClock::Words::Its, state);
  if (Min != 0 && Min != 60)
  {
    if (Min == 30)
    {
      LightWord(WordClock::Words::Past, state);
    }
    else if (Min > 30)
    {
      LightWord(WordClock::Words::To, state);
    }
    else
    {
      LightWord(WordClock::Words::After, state);
    }
  }
  if (Min > 30)
  {
    Hour = (Hour + 1) % 24;
  }
  if (Hour != 0 && Hour != 12)
  {
    LightWord(WordClock::Words::Oclock, state);
  }
  switch (Min)
  {
  case 0:
  case 60:
    break;
  case 5:
  case 55:
    LightWord(WordClock::Words::MinFive, state);
    break;
  case 10:
  case 50:
    LightWord(WordClock::Words::MinTen, state);
    break;
  case 15:
  case 45:
    LightWord(WordClock::Words::A, state);
    LightWord(WordClock::Words::Quarter, state);
    break;
  case 20:
  case 40:
    LightWord(WordClock::Words::Twenty, state);
    break;
  case 25:
  case 35:
    LightWord(WordClock::Words::Twenty, state);
    LightWord(WordClock::Words::MinFive, state);
    break;
  case 30:
    LightWord(WordClock::Words::Half, state);
    break;
  }
  switch (Hour)
  {
  case 0:
    LightWord(WordClock::Words::Midnight, state);
    break;
  case 12:
    LightWord(WordClock::Words::Noon, state);
    break;
  case 1:
  case 13:
    LightWord(WordClock::Words::One, state);
    break;
  case 2:
  case 14:
    LightWord(WordClock::Words::Two, state);
    break;
  case 3:
  case 15:
    LightWord(WordClock::Words::Three, state);
    break;
  case 4:
  case 16:
    LightWord(WordClock::Words::Four, state);
    break;
  case 5:
  case 17:
    LightWord(WordClock::Words::Five, state);
    break;
  case 6:
  case 18:
    LightWord(WordClock::Words::Six, state);
    break;
  case 7:
  case 19:
    LightWord(WordClock::Words::Seven, state);
    break;
  case 8:
  case 20:
    LightWord(WordClock::Words::Eight, state);
    break;
  case 9:
  case 21:
    LightWord(WordClock::Words::Nine, state);
    break;
  case 10:
  case 22:
    LightWord(WordClock::Words::Ten, state);
    break;
  case 11:
  case 23:
    LightWord(WordClock::Words::Eleven, state);
    break;
  }
  // state.SetOnMaskRange(0, 10, 0, 10, false);
  // DisplaySmallAlpha(state.OnMask, xchar % 26, 0, 0);
}

void WordClockProgram::LightWord(uint8_t wrd, State &state)
{
  LightWord(wrd, true, state);
}
void WordClockProgram::LightWord(uint8_t wrd, bool on, State &state)
{
  switch (wrd)
  {
  case WordClock::Words::Its:
    state.SetOnMaskRange(0, 2, 0, 0, on);
    break;
  case WordClock::Words::A:
    state.SetOnMaskRange(4, 4, 0, 0, on);
    break;
  case WordClock::Words::Half:
    state.SetOnMaskRange(6, 9, 0, 0, on);
    break;
  case WordClock::Words::MinTen:
    state.SetOnMaskRange(1, 3, 1, 1, on);
    break;
  case WordClock::Words::Quarter:
    state.SetOnMaskRange(4, 10, 1, 1, on);
    break;
  case WordClock::Words::Twenty:
    state.SetOnMaskRange(0, 5, 2, 2, on);
    break;
  case WordClock::Words::MinFive:
    state.SetOnMaskRange(7, 10, 2, 2, on);
    break;
  case WordClock::Words::To:
    state.SetOnMaskRange(0, 1, 3, 3, on);
    break;
  case WordClock::Words::Past:
    state.SetOnMaskRange(2, 5, 3, 3, on);
    break;
  case WordClock::Words::After:
    state.SetOnMaskRange(6, 10, 3, 3, on);
    break;
  case WordClock::Words::Seven:
    state.SetOnMaskRange(1, 5, 4, 4, on);
    break;
  case WordClock::Words::Noon:
    state.SetOnMaskRange(7, 10, 4, 4, on);
    break;
  case WordClock::Words::Midnight:
    state.SetOnMaskRange(0, 7, 6, 6, on);
    break;
  case WordClock::Words::Ten:
    state.SetOnMaskRange(8, 10, 6, 6, on);
    break;
  case WordClock::Words::Five:
    state.SetOnMaskRange(0, 3, 7, 7, on);
    break;
  case WordClock::Words::Nine:
    state.SetOnMaskRange(4, 7, 7, 7, on);
    break;
  case WordClock::Words::Two:
    state.SetOnMaskRange(8, 10, 7, 7, on);
    break;
  case WordClock::Words::Eleven:
    state.SetOnMaskRange(0, 5, 8, 8, on);
    break;
  case WordClock::Words::Eight:
    state.SetOnMaskRange(6, 10, 8, 8, on);
    break;
  case WordClock::Words::One:
    state.SetOnMaskRange(0, 2, 9, 9, on);
    break;
  case WordClock::Words::Six:
    state.SetOnMaskRange(3, 5, 9, 9, on);
    break;
  case WordClock::Words::Three:
    state.SetOnMaskRange(6, 10, 9, 9, on);
    break;
  case WordClock::Words::Four:
    state.SetOnMaskRange(0, 3, 10, 10, on);
    break;
  case WordClock::Words::Oclock:
    state.SetOnMaskRange(5, 10, 10, 10, on);
    break;
  case WordClock::Words::Pasta:
    // state.SetOnMaskRange(3, 2, 6, on);
    break;
  case WordClock::Words::MccIts:
    state.SetOnMaskRange(1, 9, 5, 5, on);
    state.OnMask[XY(4, 5, state.GetWidth(), state.GetHeight())] = false;
    state.OnMask[XY(6, 5, state.GetWidth(), state.GetHeight())] = false;
    state.SetClrMaskRange(1, 9, 5, 5, on);
    for (int x = 1; x < 10; x++)
    {
      state.LEDs[XY(x, 5, state.GetWidth(), state.GetHeight())] = CRGB::Yellow;
    }
    break;
  default:
    state.SetOnMaskRange(2, 2, 8, 8, on);
    break;
  }
}