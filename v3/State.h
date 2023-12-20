#ifndef State_h
#define State_h

#include <Arduino.h>

class Program;

class State
{
public:
  State();
  Program *ActiveProgram;
  bool *Mask;

private:
  uint8_t Brightness;
  uint8_t PaletteIdx;
  uint8_t ColorAnimationIdx;
  uint8_t StepSize;
  uint8_t Speed;
};
#endif