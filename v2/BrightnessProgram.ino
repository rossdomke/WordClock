#include "GlobalState.h"

void BrightnessProgram(GlobalState &_state){
  const uint8_t mag = 6;
  const uint8_t min = 50;
  const uint8_t max = 255;
  const uint8_t stepSize = (max - min) / _state.Height;

  if(_state.GetButtonStatus(3)){
    if((_state.GetBrightness() + stepSize) < max) 
      _state.SetBrightness(_state.GetBrightness() + stepSize);
  }
  if(_state.GetButtonStatus(4)){
    if((_state.GetBrightness() - stepSize) > min)
      _state.SetBrightness(_state.GetBrightness() - stepSize);
  }
  
  uint8_t level = ((double)_state.Height / (max-min)) * (max - (double)_state.GetBrightness());
  EVERY_N_MILLISECONDS(1500){
    Serial.print("level: ");
    Serial.println(level);
  }
  if(_state.RunAnimation){
    //TODO: Add button clicks to brightness program
   
    for(uint8_t x = 0; x < _state.Width; x++){
      for(uint8_t y = 0; y < _state.Height; y++){
        //sin((pi/22)x) * 2 + 3
        int8_t sinY = level + mag - sin(((2* PI) / 20) * x) * mag;    

        if(y >= sinY)
          _state.Mask[_state.XY(x,y)] = true;
        else
          _state.Mask[_state.XY(x,y)] = false;
        
      }
    }
  }
 
}
