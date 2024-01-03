#ifndef FunimationProgram_h
#define FunimationProgram_h
#include "Program.h"
class State;

class FunimationProgram : public Program
{
public:
  FunimationProgram(){};
  virtual void ClickHandler(State &);
  virtual void DoubleClickHandler(State &);
  virtual void TripleClickHandler(State &);
  virtual void LongClickHandler(State &);
  virtual void RotaryUpHandler(State &);
  virtual void RotaryDownHandler(State &);
  virtual void Run(State &);
};
#endif