#ifndef helpers_h
#define helpers_h

#define MAX_BRIGHTNESS 150
#define MIN_BRIGHTNESS 25

#define MAX_SPEED 15
#define MIN_SPEED 1

#define MAX_STEPSIZE 30
#define MIN_STEPSIZE 1

#define EEPROM_ADDR_BRIGHTNESS 0
#define EEPROM_ADDR_FRAMESTEP 1
#define EEPROM_ADDR_ANIMATION 2
#define EEPROM_ADDR_COLOR 3
#define EEPROM_ADDR_SPEED 4
#define EEPROM_ADDR_INIT_VECT_1 6
#define EEPROM_ADDR_INIT_VECT_2 7
#define EEPROM_ADDR_INIT_VECT_3 8
#define EEPROM_ADDR_INIT_VECT_4 9
#define EEPROM_ADDR_INIT_VECT_5 10
#define EEPROM_VAL_INIT_VECT_1 69
#define EEPROM_VAL_INIT_VECT_2 4
#define EEPROM_VAL_INIT_VECT_3 20
#define EEPROM_VAL_INIT_VECT_4 110
#define EEPROM_VAL_INIT_VECT_5 254

#define DEBUG 0

#if DEBUG == 1
#define debug(x) Serial.print(x)
#define debugln(x) Serial.println(x)
#define debugBIN(x) Serial.println(x, BIN)
#else
#define debug(x)
#define debugln(x)
#define debugBIN(x)
#endif

#define XY(x, y, w, h) XY_Vert_TopRightStart_Serp(x, y, w, h)

inline uint16_t XY_Vert_TopRightStart_Serp(uint8_t x, uint8_t y, uint8_t w, uint8_t h)
{
  uint16_t i = 0;
  i = (w - x) * w;
  if (x & 0x01)
    i -= y;
  else
    i -= (h - y) - 1;

  i--;
  if (i > w * h)
    i = 0;

  return i;
}
// inline uint16_t XY(uint8_t x, uint8_t y, uint8_t w, uint8_t h)
// {
//   bool serpentine = true;
//   uint16_t i;
//   uint8_t ex = x;
//   uint8_t why = y;
//   if (true)
//   {
//     ex = w - x - 1;
//     why = h - y - 1;
//   }
//   if (serpentine == false)
//   {
//     i = (y * w) + x;
//   }

//   if (serpentine == true)
//   {
//     if (why & 0x01)
//     {
//       // Odd rows run backwards
//       uint8_t reverseX = (w - 1) - ex;
//       i = (why * w) + reverseX;
//     }
//     else
//     {
//       // Even rows run forwards
//       i = (why * w) + ex;
//     }
//   }

//   return i;
// }

#endif