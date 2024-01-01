#ifndef helpers_h
#define helpers_h

uint16_t XY(uint8_t x, uint8_t y, uint8_t w, uint8_t h)
{
  bool serpentine = true;
  uint16_t i;
  uint8_t ex = x;
  uint8_t why = y;
  if (true)
  {
    ex = w - x - 1;
    why = h - y - 1;
  }
  if (serpentine == false)
  {
    i = (y * w) + x;
  }

  if (serpentine == true)
  {
    if (why & 0x01)
    {
      // Odd rows run backwards
      uint8_t reverseX = (w - 1) - ex;
      i = (why * w) + reverseX;
    }
    else
    {
      // Even rows run forwards
      i = (why * w) + ex;
    }
  }

  return i;
}
#endif