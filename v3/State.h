#ifndef State_h
#define State_h

#include <Arduino.h>

class Program;
class CRGB;

class State
{
public:
  State(uint8_t, uint8_t,CRGB*, bool*);
  Program *ActiveProgram;
  bool *Mask;
  CRGB *LEDs;

  // Getters and Setters
  uint8_t GetBrightness();       // NI
  void ChangeBrightness(int8_t); // NI

  // Computed Getters
  uint8_t GetNumOfLEDs();
  // Functions
  void AdvanceFrame(); // NI

private:
  uint8_t Brightness;
  uint8_t PaletteIdx;
  uint8_t ColorAnimationIdx;
  uint8_t StepSize;
  uint8_t Speed;
  uint8_t Frame;
  uint8_t Width;
  uint8_t Height;
};
#endif