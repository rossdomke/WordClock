#ifndef SetColorProgram_h
#define SetColorProgram_h
#include "Program.h"
class State;

class SetColorProgram : public Program
{
public:
  SetColorProgram(){};
  virtual void ClickHandler(State &);
  virtual void DoubleClickHandler(State &);
  virtual void TripleClickHandler(State &);
  virtual void LongClickHandler(State &);
  virtual void RotaryUpHandler(State &);
  virtual void RotaryDownHandler(State &);
  virtual void Run(State &);
};
#endif