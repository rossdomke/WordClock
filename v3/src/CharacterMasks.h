#ifndef CharacterMasks_h
#define CharacterMasks_h

struct LargeChar
{
    byte l1 : 5;
    byte l2 : 5;
    byte l3 : 5;
    byte l4 : 5;
    byte l5 : 5;
    byte l6 : 5;
    byte l7 : 5;
};

inline LargeChar LargeNumbers[10] = {
    // 0 - Zero
    {
        B01110,
        B10001,
        B10001,
        B10001,
        B10001,
        B10001,
        B01110,
    },
    // 1 - One
    {
        B01100,
        B00100,
        B00100,
        B00100,
        B00100,
        B00100,
        B00100,
    },
    // 2 - Two
    {
        B01110,
        B10001,
        B00001,
        B00010,
        B00100,
        B01000,
        B11111,
    },
    // 3 - Three
    {
        B01110,
        B10001,
        B00001,
        B00110,
        B00001,
        B10001,
        B01110,
    },
    // 4 - Four
    {
        B00010,
        B00110,
        B01010,
        B10010,
        B11111,
        B00010,
        B00010,
    },
    // 5 - Five
    {
        B11111,
        B10000,
        B11110,
        B00001,
        B00001,
        B10001,
        B01110,
    },
    // 6 - Six
    {
        B01110,
        B10000,
        B10000,
        B11110,
        B10001,
        B10001,
        B01110,
    },
    // 7 - Seven
    {
        B11111,
        B00001,
        B00010,
        B00100,
        B01000,
        B01000,
        B01000,
    },
    // 8 - Eight
    {
        B01110,
        B10001,
        B10001,
        B01110,
        B10001,
        B10001,
        B01110,
    },
    // 9 - Nine
    {
        B01110,
        B10001,
        B10001,
        B01111,
        B00001,
        B00001,
        B01110,
    },
};

struct SmallCharacter
{
    byte l1 : 3;
    byte l2 : 3;
    byte l3 : 3;
    byte l4 : 3;
    byte l5 : 3;
};

inline SmallCharacter SmallNumbers[10] = {
    // 0
    {
        B111,
        B101,
        B101,
        B101,
        B111,
    },
    // 1
    {
        B110,
        B010,
        B010,
        B010,
        B111,
    },
    // 2
    {
        B010,
        B101,
        B010,
        B100,
        B111,
    },
    // 3
    {
        B110,
        B001,
        B110,
        B001,
        B110,
    },
    // 4
    {
        B101,
        B101,
        B111,
        B001,
        B001,
    },
    // 5
    {
        B111,
        B100,
        B110,
        B001,
        B110,
    },
    // 6
    {
        B011,
        B100,
        B110,
        B101,
        B111,
    },
    // 7
    {
        B111,
        B001,
        B010,
        B010,
        B100,
    },
    // 8
    {
        B111,
        B101,
        B111,
        B101,
        B111,
    },
    // 9
    {
        B111,
        B101,
        B111,
        B001,
        B011,
    },
};
enum CharIdx
{
    A,
    B,
    C,
    D,
    E,
    F,
    G,
    H,
    I,
    J,
    K,
    L,
    M,
    N,
    O,
    P,
    Q,
    R,
    S,
    T,
    U,
    V,
    W,
    X,
    Y,
    Z
};
inline SmallCharacter SmallAlphabet[26] = {
    // A
    {
        B010,
        B101,
        B111,
        B101,
        B101,
    },
    // B
    {
        B110,
        B101,
        B111,
        B101,
        B110,
    },
    // C
    {
        B111,
        B100,
        B100,
        B100,
        B111,
    },
    // D
    {
        B110,
        B101,
        B101,
        B101,
        B110,
    },
    // E
    {
        B111,
        B100,
        B111,
        B100,
        B111,
    },
    // F
    {
        B111,
        B100,
        B111,
        B100,
        B100,
    },
    // G
    {
        B111,
        B100,
        B111,
        B101,
        B111,
    },
    // H
    {
        B101,
        B101,
        B111,
        B101,
        B101,
    },
    // I
    {
        B111,
        B010,
        B010,
        B010,
        B111,
    },
    // J
    {B111, B001, B001, B101, B011},
    // K
    {
        B101,
        B110,
        B100,
        B110,
        B101,
    },
    // L
    {
        B100,
        B100,
        B100,
        B100,
        B111,
    },
    // M
    {
        B101,
        B111,
        B111,
        B101,
        B101,
    },
    // N
    {
        B111,
        B101,
        B101,
        B101,
        B101,
    },
    // O
    {
        B111,
        B101,
        B101,
        B101,
        B111,
    },
    // P
    {
        B111,
        B101,
        B111,
        B100,
        B100,
    },
    // Q
    {
        B010,
        B101,
        B101,
        B010,
        B001,
    },
    // R
    {
        B110,
        B101,
        B110,
        B101,
        B101,
    },
    // S
    {
        B011,
        B100,
        B011,
        B001,
        B110,
    },
    // T
    {
        B111,
        B010,
        B010,
        B010,
        B010,
    },
    // U
    {
        B101,
        B101,
        B101,
        B101,
        B111,
    },
    // V
    {
        B101,
        B101,
        B101,
        B111,
        B010,
    },
    // W
    {
        B101,
        B101,
        B111,
        B111,
        B101,
    },
    // X
    {
        B101,
        B101,
        B010,
        B101,
        B101,
    },
    // Y
    {
        B101,
        B101,
        B010,
        B010,
        B010,
    },
    // Z
    {
        B111,
        B001,
        B010,
        B100,
        B111,
    },
};
inline void DisplaySmallChar(bool *mask, SmallCharacter sChar, uint8_t startx, uint8_t startY)
{
    debug("Char Line1: ");
    debugBIN(sChar.l1);
    debugln("");
}
inline void DisplaySmallAlpha(bool *mask, CharIdx charIdx, uint8_t startX, uint8_t startY)
{
    SmallCharacter sChar = SmallAlphabet[charIdx];
    DisplaySmallChar(mask, sChar, startX, startY);
}
inline void DisplaySmallNum(bool *mask, uint8_t num, uint8_t startX, uint8_t startY)
{
    SmallCharacter sChar = SmallNumbers[num];
    DisplaySmallChar(mask, sChar, startX, startY);
}

#endif