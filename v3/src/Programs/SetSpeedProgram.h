#ifndef SetSpeedProgram_h
#define SetSpeedProgram_h
#include "Program.h"
class State;

class SetSpeedProgram : public Program
{
public:
  SetSpeedProgram(){};
  virtual void ClickHandler(State &);
  virtual void DoubleClickHandler(State &);
  virtual void TripleClickHandler(State &);
  virtual void LongClickHandler(State &);
  virtual void RotaryUpHandler(State &);
  virtual void RotaryDownHandler(State &);
  virtual void Run(State &);
};
#endif