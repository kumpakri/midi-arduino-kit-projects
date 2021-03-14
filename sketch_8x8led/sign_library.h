byte alphabet[] = {
  // space / '@'
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  // A
  B00000000,
  B00011000,
  B00100100,
  B00100100,
  B00111100,
  B00100100,
  B00100100,
  B00100100,
  // B
  B00000000,
  B00011100,
  B00100100,
  B00100100,
  B00011100,
  B00100100,
  B00100100,
  B00011100,
  // C
  B00000000,
  B00111000,
  B01000100,
  B00000010,
  B00000010,
  B00000010,
  B01000100,
  B00111000,
  // D
  B00000000,
  B00011110,
  B00100010,
  B01000010,
  B01000010,
  B01000010,
  B00100010,
  B00011110,
  // E
  B00000000,
  B00111100,
  B00000100,
  B00000100,
  B00111100,
  B00000100,
  B00000100,
  B00111100,
  // F
  B00000000,
  B00111100,
  B00000100,
  B00000100,
  B00111100,
  B00000100,
  B00000100,
  B00000100,
  // G
  B00000000,
  B00111000,
  B01000100,
  B00000010,
  B01110010,
  B01000010,
  B01000100,
  B00111000,
  // H
  B00000000,
  B00100100,
  B00100100,
  B00100100,
  B00111100,
  B00100100,
  B00100100,
  B00100100,
  // I
  B00000000,
  B00111000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00111000,
  // J
  B00000000,
  B00100000,
  B00100000,
  B00100000,
  B00100000,
  B00100100,
  B00100100,
  B00011000,
  // K
  B00000000,
  B00100010,
  B00010010,
  B00001010,
  B00000110,
  B00001010,
  B00010010,
  B00100010,
  // L
  B00000000,
  B00000100,
  B00000100,
  B00000100,
  B00000100,
  B00000100,
  B00000100,
  B00111100,
  // M
  B00000000,
  B01000100,
  B01101100,
  B01010100,
  B01000100,
  B01000100,
  B01000100,
  B01000100,
  // N
  B00000000,
  B01000100,
  B01001100,
  B01010100,
  B01100100,
  B01100100,
  B01000100,
  B01000100,
  // O
  B00000000,
  B00011000,
  B00100100,
  B00100100,
  B00100100,
  B00100100,
  B00100100,
  B00011000,
  // P
  B00000000,
  B00011100,
  B00100100,
  B00100100,
  B00011100,
  B00000100,
  B00000100,
  B00000100,
  // Q
  B00000000,
  B00011000,
  B00100100,
  B00100100,
  B00100100,
  B00110100,
  B00100100,
  B01011000,
  // R
  B00000000,
  B00011100,
  B00100100,
  B00100100,
  B00011100,
  B00100100,
  B01000100,
  B01000100,
  // S
  B00000000,
  B00111000,
  B00000100,
  B00000100,
  B00011000,
  B00100000,
  B00100000,
  B00011100,
  // T
  B00000000,
  B01111100,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  // U
  B00000000,
  B00100100,
  B00100100,
  B00100100,
  B00100100,
  B00100100,
  B00100100,
  B00011000,
  // V
  B00000000,
  B01000100,
  B01000100,
  B01000100,
  B01000100,
  B01000100,
  B00101000,
  B00010000,
  // W
  B00000000,
  B01000100,
  B01000100,
  B01000100,
  B01000100,
  B01010100,
  B01101100,
  B01000100,
  // X
  B00000000,
  B00100100,
  B00100100,
  B00100100,
  B00011000,
  B00100100,
  B00100100,
  B00100100,
  // Y
  B00000000,
  B01000100,
  B01000100,
  B00101000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  // Z
  B00000000,
  B00111100,
  B00100000,
  B00010000,
  B00111100,
  B00001000,
  B00000100,
  B00111100,
};

byte signEmpty[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
};

byte signFull[] = {
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
};

byte signHeart1[] = {
  B00000000,
  B01100110,
  B11111111,
  B11111111,
  B01111110,
  B00111100,
  B00011000,
  B00000000,
};

byte signCircle1[] = {
  B00011000,
  B01000010,
  B00000000,
  B10000001,
  B10000001,
  B00000000,
  B01000010,
  B00011000,
};

byte signCircle2[] = {
  B00000000,
  B00011000,
  B00100100,
  B01000010,
  B01000010,
  B00100100,
  B00011000,
  B00000000,
};

byte signCircle3[] = {
  B00000000,
  B00000000,
  B00011000,
  B00100100,
  B00100100,
  B00011000,
  B00000000,
  B00000000,
};

byte signCircle4[] = {
  B00000000,
  B00000000,
  B00000000,
  B00011000,
  B00011000,
  B00000000,
  B00000000,
  B00000000,
};

byte signDiag[] = {
  B10000000,
  B01000000,
  B00100000,
  B00010000,
  B00001000,
  B00000100,
  B00000010,
  B00000001,
};

// 6 frames
byte pulsingCircle[] = {B00011000,
  B01000010,
  B00000000,
  B10000001,
  B10000001,
  B00000000,
  B01000010,
  B00011000,
  B00000000,
  B00011000,
  B00100100,
  B01000010,
  B01000010,
  B00100100,
  B00011000,
  B00000000,
  B00000000,
  B00000000,
  B00011000,
  B00100100,
  B00100100,
  B00011000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00011000,
  B00011000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00011000,
  B00100100,
  B00100100,
  B00011000,
  B00000000,
  B00000000,
  B00000000,
  B00011000,
  B00100100,
  B01000010,
  B01000010,
  B00100100,
  B00011000,
  B00000000,};

//5 frames
byte pulsingHeart[] = {
  B00000000,
  B01100110,
  B11111111,
  B11111111,
  B01111110,
  B00111100,
  B00011000,
  B00000000,
  B00000000,
  B00000000,
  B00110110,
  B00111110,
  B00011100,
  B00001000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00010100,
  B00011100,
  B00001000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00110110,
  B00111110,
  B00011100,
  B00001000,
  B00000000,
  B00000000,
};