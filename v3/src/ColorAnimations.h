#ifndef coloranimations_h
#define coloranimations_h
#include <FastLED.h>

inline CRGB vmirror(CRGBPalette16 palette, uint8_t frame, uint8_t stepSize, uint8_t x, uint8_t y)
{
  return ColorFromPalette(palette, frame + (5 - abs(5 - y)) * stepSize, 255, LINEARBLEND);
}

inline CRGB hmirror(CRGBPalette16 palette, uint8_t frame, uint8_t stepSize, uint8_t x, uint8_t y)
{
  return ColorFromPalette(palette, frame + (5 - abs(5 - x)) * stepSize, 255, LINEARBLEND);
}

inline CRGB circleout(CRGBPalette16 palette, uint8_t frame, uint8_t stepSize, uint8_t x, uint8_t y)
{
  return ColorFromPalette(palette, frame + max(abs(5 - x), abs(5 - y)) * stepSize, 255, LINEARBLEND);
}
inline CRGB circlein(CRGBPalette16 palette, uint8_t frame, uint8_t stepSize, uint8_t x, uint8_t y)
{
  return ColorFromPalette(palette, (255 - frame) + max(abs(5 - x), abs(5 - y)) * stepSize, 255, LINEARBLEND);
}
inline CRGB leftToRight(CRGBPalette16 palette, uint8_t frame, uint8_t stepSize, uint8_t x, uint8_t y)
{
  return ColorFromPalette(palette, frame + x * stepSize, 255, LINEARBLEND);
}
inline CRGB topToBottom(CRGBPalette16 palette, uint8_t frame, uint8_t stepSize, uint8_t x, uint8_t y)
{
  return ColorFromPalette(palette, frame + y * stepSize, 255, LINEARBLEND);
}
typedef CRGB (*ColorAnimationFunc)(CRGBPalette16 palette, uint8_t frame, uint8_t stepSize, uint8_t x, uint8_t y);
typedef CRGB (*ColorAnimationFuncs[])(CRGBPalette16 palette, uint8_t frame, uint8_t stepSize, uint8_t x, uint8_t y);

inline ColorAnimationFuncs ColorAnimations = {leftToRight, topToBottom, vmirror, hmirror, circleout, circlein};

#endif