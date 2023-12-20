#ifndef SetHourProgram_h
#define SetHourProgram_h
#include "Program.h"
class State;

class SetHourProgram : public Program
{
public:
  SetHourProgram(){};
  virtual void ClickHandler(State &);
  virtual void DoubleClickHandler(State &);
  virtual void TripleClickHandler(State &);
  virtual void LongClickHandler(State &);
  virtual void RotaryUpHandler(State &);
  virtual void RotaryDownHandler(State &);
  virtual void Run(State &);
};
#endif