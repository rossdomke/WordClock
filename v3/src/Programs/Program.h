

#ifndef Program_h
#define Program_h
class State;

class Program
{
public:
  Program();
  virtual void ClickHandler(State&);
  virtual void DoubleClickHandler(State&);
  virtual void TripleClickHandler(State&);
  virtual void LongClickHandler(State&);
  virtual void RotaryUpHandler(State&);
  virtual void RotaryDownHandler(State&);
  virtual void Run(State&);
};
#endif