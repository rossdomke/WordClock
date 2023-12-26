#include <FastLED.h>
#include <Button2.h>
#include <RotaryEncoder.h>
#include <FastLED.h>

#include "State.h"
#include "src/Programs/Program.h"

FASTLED_USING_NAMESPACE
#define WIDTH 3
#define HEIGHT 3

const int P_ENC_BTN = 10;
const int P_ENC_A = 2;
const int P_ENC_B = 1;
const int P_SCL = 5;
const int P_SDA = 4;
const int P_LED = 3;

Button2 BtnEnc;
RotaryEncoder *Encoder = nullptr;
State *AppState = nullptr;
CRGB leds[WIDTH * HEIGHT]; 
bool mask[WIDTH * HEIGHT];

void setup()
{
  Serial.begin(115200);
  delay(50);

  // BtnEnc Setup
  BtnEnc.begin(P_ENC_BTN, INPUT_PULLUP, false);
  attachInterrupt(digitalPinToInterrupt(P_ENC_BTN), BtnEncInterupt, CHANGE);
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
  attachInterrupt(digitalPinToInterrupt(P_ENC_A), RotaryInterupt, CHANGE);
  attachInterrupt(digitalPinToInterrupt(P_ENC_B), RotaryInterupt, CHANGE);

  AppState = new State(WIDTH, HEIGHT, leds, mask);

  // Setup FastLED
  FastLED.addLeds<WS2812B, P_LED, GRB>(AppState->LEDs, AppState->GetNumOfLEDs()).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(AppState->GetBrightness());
}

ulong beforeMillis = 0;
ulong afterMillis = 0;
ulong milliDiff = 0;
void loop()
{
  BtnEnc.loop();
  beforeMillis = millis();
  AppState->ActiveProgram->Run(*AppState);

  AppState->LEDs[0] = CRGB::Purple;
  for (int x = 1; x < 9; x++)
  {
    AppState->LEDs[x] = CRGB::White;
  }
  FastLED.setBrightness(AppState->GetBrightness());
  FastLED.show();
  afterMillis = millis();
  if (afterMillis - beforeMillis > 100)
  {
    Serial.print("!!!WARNING!!! Active Program took too long: ");
    Serial.print(afterMillis - beforeMillis);
    Serial.println("ms");
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
