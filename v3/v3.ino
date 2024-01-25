#include <FastLED.h>
#include <Button2.h>
#include <RotaryEncoder.h>
#include <FastLED.h>
#include <DS3231.h>

#include "State.h"
#include "src/Programs/Program.h"
#include "src/Helpers.h"
#include "src/ColorAnimations.h"
#include "src/ColorPallettes.h"
#include "src/CharacterMasks.h"

FASTLED_USING_NAMESPACE
#define WIDTH 11
#define HEIGHT 11

const int P_ENC_BTN = 9;
const int P_ENC_A = 8;
const int P_ENC_B = 10;
const int P_SCL = 5;
const int P_SDA = 4;
const int P_LED = 3;

Button2 BtnEnc;
RotaryEncoder *Encoder = nullptr;
State *AppState = nullptr;
CRGB leds[WIDTH * HEIGHT];
bool onMask[WIDTH * HEIGHT];
bool clrMask[WIDTH * HEIGHT];
DS3231 rtc;

void setup()
{
  Serial.begin(115200);
  delay(100);
  debug("Wordclock Startup");

  // RTC Setup
  Wire.begin();

  // BtnEnc Setup
  BtnEnc.begin(P_ENC_BTN, INPUT_PULLUP, false);
  // attachInterrupt(digitalPinToInterrupt(P_ENC_BTN), BtnEncInterupt, CHANGE);
  // BtnEnc Handlers
  BtnEnc.setClickHandler(BtnEnc_ClickHandler);
  BtnEnc.setDoubleClickHandler(BtnEnc_DoubleClickHandler);
  BtnEnc.setTripleClickHandler(BtnEnc_TripleClickHandler);
  BtnEnc.setLongClickDetectedHandler(BtnEnc_LongClickDetectedHandler);
  // BtnEnc Settings
  BtnEnc.setLongClickDetectedRetriggerable(false);
  BtnEnc.setLongClickTime(750);

  // Rotary Encoder Setup
  Encoder = new RotaryEncoder(P_ENC_A, P_ENC_B, RotaryEncoder::LatchMode::FOUR3);
  // attachInterrupt(digitalPinToInterrupt(P_ENC_A), RotaryInterupt, CHANGE);
  // attachInterrupt(digitalPinToInterrupt(P_ENC_B), RotaryInterupt, CHANGE);

  AppState = new State(WIDTH, HEIGHT, leds, onMask, clrMask, &rtc);

  // Setup FastLED
  // FastLED.addLeds<WS2812B, P_LED, GRB>(AppState->LEDs, AppState->GetNumOfLEDs()).setCorrection(TypicalLEDStrip);

  FastLED.addLeds<WS2812B, P_LED, GRB>(AppState->LEDs, AppState->GetNumOfLEDs()).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(AppState->GetBrightness());
}

ulong beforeMillis = 0;
ulong afterMillis = 0;
ulong milliDiff = 0;
void loop()
{
  BtnEnc.loop();
  RotaryInterupt();
  EVERY_N_MINUTES(1)
  {
    AppState->WriteStateToMemory();
  }
  EVERY_N_MILLISECONDS(50)
  {
    AppState->AdvanceFrame();

    beforeMillis = millis();
    AppState->ActiveProgram->Run(*AppState);
    // Color Animation
    ColorAnimationFunc clrAnimation = AppState->GetColorAnimation();
    CRGBPalette16 palette = AppState->GetColorPalette();
    for (uint8_t x = 0; x < AppState->GetWidth(); x++)
    {
      for (uint8_t y = 0; y < AppState->GetHeight(); y++)
      {
        uint16_t ledIdx = XY(x, y, AppState->GetWidth(), AppState->GetHeight());
        if (!AppState->ColorMask[ledIdx])
          AppState->LEDs[ledIdx] = clrAnimation(palette, AppState->GetFrame(), AppState->GetStepSize(), x, y);

        if (!AppState->OnMask[ledIdx])
          AppState->LEDs[ledIdx].fadeToBlackBy(255);
      }
    }
    FastLED.setBrightness(AppState->GetBrightness());
    FastLED.show();
    afterMillis = millis();
    if (afterMillis - beforeMillis > 100)
    {
      debug("!!!WARNING!!! Active Program took too long: ");
      debug(afterMillis - beforeMillis);
      debugln("ms");
    }
  }
}

void BtnEncInterupt()
{
  BtnEnc.loop();
}
void BtnEnc_ClickHandler(Button2 &btn)
{
  AppState->ActiveProgram->ClickHandler(*AppState);
}
void BtnEnc_DoubleClickHandler(Button2 &btn)
{
  AppState->ActiveProgram->DoubleClickHandler(*AppState);
}
void BtnEnc_TripleClickHandler(Button2 &btn)
{
  AppState->ActiveProgram->TripleClickHandler(*AppState);
}
void BtnEnc_LongClickDetectedHandler(Button2 &btn)
{
  AppState->ActiveProgram->LongClickHandler(*AppState);
}

static int RotaryPos = 0;
void RotaryInterupt()
{
  Encoder->tick();
  int newPos = Encoder->getPosition();
  if (RotaryPos != newPos)
  {
    if (RotaryEncoder::Direction::CLOCKWISE == Encoder->getDirection())
    {
      AppState->ActiveProgram->RotaryUpHandler(*AppState);
    }
    else
    {
      AppState->ActiveProgram->RotaryDownHandler(*AppState);
    }
    RotaryPos = newPos;
  }
}
