#ifndef WordClockProgram_h
#define WordClockProgram_h
#include "Program.h"
#include <Arduino.h>

class State;

class WordClockProgram : public Program
{
public:
  WordClockProgram(){};
  virtual void ClickHandler(State &);
  virtual void DoubleClickHandler(State &);
  virtual void TripleClickHandler(State &);
  virtual void LongClickHandler(State &);
  virtual void RotaryUpHandler(State &);
  virtual void RotaryDownHandler(State &);
  virtual void Run(State &);

private:
  long LightMcc;
  void LightWord(uint8_t, State &);
  void LightWord(uint8_t, bool, State &);
};
#endif