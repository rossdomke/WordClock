#ifndef SetBrightnessProgram_h
#define SetBrightnessProgram_h
#include "Program.h"
class State;

class SetBrightnessProgram : public Program
{
public:
  SetBrightnessProgram(){};
  virtual void ClickHandler(State &);
  virtual void DoubleClickHandler(State &);
  virtual void TripleClickHandler(State &);
  virtual void LongClickHandler(State &);
  virtual void RotaryUpHandler(State &);
  virtual void RotaryDownHandler(State &);
  virtual void Run(State &);
};
#endif