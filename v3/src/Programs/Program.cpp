#include "Program.h"
#include "../../State.h"
#include <Arduino.h>

#include "WordClockProgram.h"

  Program::Program(){}
  void Program::ClickHandler(State& state){
    Serial.println("program click");
  }
  void Program::DoubleClickHandler(State& state){
    Serial.println("program double click");
  }
  void Program::TripleClickHandler(State& state){
    Serial.println("program triple click");
  }
  void Program::LongClickHandler(State& state){
    Serial.println("program long click");
    state.ActiveProgram = new WordClockProgram();
  }
  void Program::RotaryUpHandler(State& state){
    Serial.print("program rotary up: ");
    Serial.println(++state.TestVal);
  }
  void Program::RotaryDownHandler(State& state){
    Serial.print("program rotary down: ");
    Serial.println(--state.TestVal);
  }
  void Program::Run(State& state){
    Serial.println("program rum");
  }