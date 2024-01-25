#ifndef SetTimeProgram_h
#define SetTimeProgram_h
#include "Program.h"
class State;
namespace SetTime
{
  enum Mode
  {
    SetHour,
    SetMin
  };
}
class SetTimeProgram : public Program
{
public:
  SetTimeProgram()
  {
    Mode = SetTime::Mode::SetHour;
  };
  virtual void ClickHandler(State &);
  virtual void DoubleClickHandler(State &);
  virtual void TripleClickHandler(State &);
  virtual void LongClickHandler(State &);
  virtual void RotaryUpHandler(State &);
  virtual void RotaryDownHandler(State &);
  virtual void Run(State &);

private:
  SetTime::Mode Mode;
};
#endif