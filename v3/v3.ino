#include <FastLED.h>
#include <Button2.h>
#include <RotaryEncoder.h>

#include "State.h"
#include "src/Programs/Program.h"

const int P_ENC_BTN = 10;
const int P_ENC_A = 2;
const int P_ENC_B = 1;
const int P_SCL = 5;
const int P_SDA = 4;
const int P_LED = 3;

Button2 BtnEnc;
RotaryEncoder *Encoder = nullptr;
State *AppState = nullptr;

void setup() {
  Serial.begin(115200);
  delay(50);

  //BtnEnc Setup
  BtnEnc.begin(P_ENC_BTN, INPUT_PULLUP, false);
  //BtnEnc Handlers
  BtnEnc.setClickHandler(BtnEnc_ClickHandler);
  BtnEnc.setDoubleClickHandler(BtnEnc_DoubleClickHandler);
  BtnEnc.setTripleClickHandler(BtnEnc_TripleClickHandler);
  BtnEnc.setLongClickDetectedHandler(BtnEnc_LongClickDetectedHandler);
  //BtnEnc Settings
  BtnEnc.setLongClickDetectedRetriggerable(false);
  BtnEnc.setLongClickTime(750);

  //Rotary Encoder Setup
  Encoder = new RotaryEncoder(P_ENC_A, P_ENC_B, RotaryEncoder::LatchMode::FOUR3);
  attachInterrupt(digitalPinToInterrupt(P_ENC_A), RotaryInterupt, CHANGE);
  attachInterrupt(digitalPinToInterrupt(P_ENC_B), RotaryInterupt, CHANGE);


  //State Setup
  AppState = new State();
  AppState->ActiveProgram = new Program();
}



void loop() {
  BtnEnc.loop();
}


void BtnEnc_ClickHandler(Button2& btn){
  AppState->ActiveProgram->ClickHandler(*AppState);
}
void BtnEnc_DoubleClickHandler(Button2& btn){
  AppState->ActiveProgram->DoubleClickHandler(*AppState);
}
void BtnEnc_TripleClickHandler(Button2& btn){
  AppState->ActiveProgram->TripleClickHandler(*AppState);
}
void BtnEnc_LongClickDetectedHandler(Button2& btn){
  AppState->ActiveProgram->LongClickHandler(*AppState);
}

static int RotaryPos = 0;
void RotaryInterupt()
{
  Encoder->tick(); // just call tick() to check the state.
  int newPos = Encoder->getPosition();
  if (RotaryPos != newPos) {
    if(RotaryEncoder::Direction::CLOCKWISE == Encoder->getDirection()){
      AppState->ActiveProgram->RotaryUpHandler(*AppState);
    }else{
      AppState->ActiveProgram->RotaryDownHandler(*AppState);
    }
    RotaryPos = newPos;
  }
}
