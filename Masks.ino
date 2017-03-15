uint8_t number[10][11] = { {B00000, B00000, B01110, B10001, B10001, B10001, B10001, B10001, B01110, B00000, B00000, }, {B00000, B00000, B01100, B00100, B00100, B00100, B00100, B00100, B00100, B00000, B00000, }, {B00000, B00000, B01110, B10001, B00001, B00010, B00100, B01000, B11111, B00000, B00000 }, {B00000, B00000, B01110, B10001, B00001, B00110, B00001, B10001, B01110, B00000, B00000 }, {B00000, B00000, B00010, B00110, B01010, B10010, B11111, B00010, B00010, B00000, B00000 }, {B00000, B00000, B11111, B10000, B11110, B00001, B00001, B10001, B01110, B00000, B00000 }, {B00000, B00000, B01110, B10000, B10000, B11110, B10001, B10001, B01110, B00000, B00000 }, {B00000, B00000, B11111, B00001, B00010, B00100, B01000, B01000, B01000, B00000, B00000 }, {B00000, B00000, B01110, B10001, B10001, B01110, B10001, B10001, B01110, B00000, B00000 }, {B00000, B00000, B01110, B10001, B10001, B01111, B00001, B00001, B01110, B00000, B00000 } };

void None(){
  for(int i = 0; i < NUM_LEDS; i++){
    mask[i] = true;
  }
} 

void Random(){
  EVERY_N_SECONDS(1){
    for(int i = 0; i < NUM_LEDS; i++){
      mask[i] = random8(0,2);
    }
  }
}

void DisplayNum(uint8_t num, bool Right){
  for(int y = 0; y < 11; y++){
    for(int x = 0; x < 5; x++){
        mask[XY((Right ? x + 6 : x),y)] = (number[num][y] >> (4 - x)) % 2 ;
      }
    mask[XY(5,y)] = 0;
  }
}
enum Words {Its, A, Half, MinTen, Quarter, Twenty, MinFive, Way, Til, Past, Seven, Noon,
            Midnight, Ten, Five, Nine, Two, Eleven, Eight, One, Six, Three, Four, Oclock,
            Happy, Birth, Day};
uint8_t Hour = 0;
uint8_t Min = 0;
void WordClock(){
  for(int i = 0; i < NUM_LEDS; i++){
    mask[i] = 0;
  }
  EVERY_N_MILLISECONDS(500){
    t = rtc.getTime();
  }
  
  Hour = t.hour;
  Min = round(t.min / 5.00) * 5;

  LightWord(Words::Its);
  if(Min != 0 && Min != 60){
    if(Min > 30){
      LightWord(Words::Til);
    }else{
      LightWord(Words::Past);
    }
  }
  if(Min > 30){
    Hour = (Hour +1) % 24;
  }
  if(Hour != 0 && Hour != 12){
    LightWord(Words::Oclock);
  }
  switch(Min){
    case 0:
    case 60:
      break;
    case 5:
    case 55:
      LightWord(Words::MinFive);
      break;
    case 10:
    case 50:
      LightWord(Words::MinTen);
      break;
    case 15:
    case 45:
      LightWord(Words::A);
      LightWord(Words::Quarter);
      break;
    case 20:
    case 40:
      LightWord(Words::Twenty);
      break;
    case 25:
    case 35:
      LightWord(Words::Twenty);
      LightWord(Words::MinFive);
      break;
    case 30:
      LightWord(Words::Half);
      break;
  }
  switch(Hour){
    case 0:
      LightWord(Words::Midnight);
      break;
    case 12:
      LightWord(Words::Noon);
      break;
    case 1:
    case 13:
      LightWord(Words::One);
      break;
    case 2:
    case 14:
      LightWord(Words::Two);
      break;
    case 3:
    case 15:
      LightWord(Words::Three);
      break;
    case 4:
    case 16:
      LightWord(Words::Four);
      break;
    case 5:
    case 17:
      LightWord(Words::Five);
      break;
    case 6:
    case 18:
      LightWord(Words::Six);
      break;
    case 7:
    case 19:
      LightWord(Words::Seven);
      break;
    case 8:
    case 20:
      LightWord(Words::Eight);
      break;
    case 9:
    case 21:
      LightWord(Words::Nine);
      break;
    case 10:
    case 22:
      LightWord(Words::Ten);
      break;
    case 11:
    case 23:
      LightWord(Words::Eleven);
      break;
  }
}

void LightWord(uint8_t wrd){
  switch(wrd){
    case Words::Its:
      SetMaskRange(0, 0, 2, true);
      break;
    case Words::A:
      SetMaskRange(0, 4, 4, true);
      break;
    case Words::Half:
      SetMaskRange(0, 6, 9, true);
      break;
    case Words::MinTen:
      SetMaskRange(1, 1, 3, true);
      break;
    case Words::Quarter:
      SetMaskRange(1, 4, 10, true);
      break;
    case Words::Twenty:
      SetMaskRange(2, 0, 5, true);
      break;
    case Words::MinFive:
      SetMaskRange(2, 7, 10, true);
      break;
    case Words::Way:
      SetMaskRange(3, 0, 2, true);
      break;
    case Words::Til:
      SetMaskRange(3, 3, 5, true);
      break;
    case Words::Past:
      SetMaskRange(3, 6, 9, true);
      break;
    case Words::Seven:
      SetMaskRange(4, 1, 5, true);
      break;
    case Words::Noon:
      SetMaskRange(4, 7, 10, true);
      break;
    case Words::Midnight:
      SetMaskRange(6, 0, 7, true);
      break;
    case Words::Ten:
      SetMaskRange(6, 8, 10, true);
      break;
    case Words::Five:
      SetMaskRange(7, 0, 3, true);
      break;
    case Words::Nine:
      SetMaskRange(7, 4, 7, true);
      break;
    case Words::Two:
      SetMaskRange(7, 8, 10, true);
      break;
    case Words::Eleven:
      SetMaskRange(8, 0, 5, true);
      break;
    case Words::Eight:
      SetMaskRange(8, 6, 10, true);
      break;
    case Words::One:
      SetMaskRange(9, 0, 2, true);
      break;
    case Words::Six:
      SetMaskRange(9, 3, 5, true);
      break;
    case Words::Three:
      SetMaskRange(9, 6, 10, true);
      break;
    case Words::Four:
      SetMaskRange(10, 0, 3, true);
      break;
    case Words::Oclock:
      SetMaskRange(10, 5, 10, true);
      break;
  }
}

void SetMaskRange(uint8_t y,uint8_t x1,uint8_t x2, bool On){
  SetMaskRange(x1, y, x2, y, On);
}
void SetMaskRange(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, bool On){
  for(uint8_t o = x1; o <= x2; o++){
    for(uint8_t i = y1; i <= y2; i++){
      mask[XY(o, i)] = On;
    }
  }
}

