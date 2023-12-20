#ifndef SetMinProgram_h
#define SetMinProgram_h
#include "Program.h"
class State;

class SetMinProgram : public Program
{
public:
  SetMinProgram(){};
  virtual void ClickHandler(State &);
  virtual void DoubleClickHandler(State &);
  virtual void TripleClickHandler(State &);
  virtual void LongClickHandler(State &);
  virtual void RotaryUpHandler(State &);
  virtual void RotaryDownHandler(State &);
  virtual void Run(State &);
};
#endif