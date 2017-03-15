long lastBrightMillis = 0;

int16_t targetBright = 255;
int16_t currentBright = 255;
int16_t newRead = 0;
void PhotoResistBright(){
  newRead = map(analogRead(A0), 0, 700, 75, 255);
  //newRead = map(analogRead(A0), 0, 700, 1, 100);
  newRead = (newRead > 255) ? 255 : newRead;
  if((targetBright - 5) > newRead || newRead > (targetBright + 5)){
    targetBright = newRead;
    Serial.println(targetBright);
  }
  if(currentBright < targetBright){
    currentBright++;    
    Serial.print(currentBright);
    Serial.print(" - ");
    Serial.println(targetBright);
  }else if(currentBright > targetBright){
    currentBright--;
    Serial.print(currentBright);
    Serial.print(" - ");
    Serial.println(targetBright);
  }
  FastLED.setBrightness(currentBright);
}
