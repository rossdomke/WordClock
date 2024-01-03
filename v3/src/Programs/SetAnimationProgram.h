#ifndef SetAnimationProgram_h
#define SetAnimationProgram_h
#include "Program.h"
class State;

class SetAnimationProgram : public Program
{
public:
  SetAnimationProgram(){};
  virtual void ClickHandler(State &);
  virtual void DoubleClickHandler(State &);
  virtual void TripleClickHandler(State &);
  virtual void LongClickHandler(State &);
  virtual void RotaryUpHandler(State &);
  virtual void RotaryDownHandler(State &);
  virtual void Run(State &);
};
#endif