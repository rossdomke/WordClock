#ifndef SetStepSizeProgram_h
#define SetStepSizeProgram_h
#include "Program.h"
class State;

class SetStepSizeProgram : public Program
{
public:
  SetStepSizeProgram(){};
  virtual void ClickHandler(State &);
  virtual void DoubleClickHandler(State &);
  virtual void TripleClickHandler(State &);
  virtual void LongClickHandler(State &);
  virtual void RotaryUpHandler(State &);
  virtual void RotaryDownHandler(State &);
  virtual void Run(State &);
};
#endif