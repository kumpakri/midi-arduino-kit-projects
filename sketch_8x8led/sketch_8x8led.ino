/**
 * @file sketch_8x8led.ino
 * @author Kristyna Kumpanova (kumpakri@gmail.com)
 * @brief Programm for Arduino UNO to display sequence of
 *        characters on the 8x8 LED matrix. Pin setting is
 *        located in "setting_8x8led_matrix.h". Modify this
 *        file to reflect your circuit.
 * @date 13th March 2021
 */
 
#include "setting_8x8led_matrix.h"
#include "sign_library.h"

const byte rows[] = {
  ROW_1, ROW_2, ROW_3, ROW_4, ROW_5, ROW_6, ROW_7, ROW_8  
};

const byte columns[] = {
  COL_1, COL_2, COL_3, COL_4, COL_5, COL_6, COL_7, COL_8  
};

enum DisplayMode{
  standbyMode,
  textMode,  
  shiftingTextMode,
};

// standbyMode setting
static unsigned long timeLastLoop;
// pulsingHeart:300/pulsingCircle:100
const unsigned long frameDelay_ms = 100;
// pulsingHeart:4/pulsingCircle:6
const byte nFrames = 6;

static unsigned long timeLastFrameChange;
static byte picIndex;
static byte shift;

DisplayMode displayMode = shiftingTextMode;


void setup() {
  Serial.begin(9600);
  
  for(const byte pin : rows) {
    pinMode(pin, OUTPUT);
  }
  for(const byte pin : columns) {
    pinMode(pin, OUTPUT);
  }

  timeLastLoop = millis();
  timeLastFrameChange = millis();
  picIndex = 0;
  shift = 0;
}


void loop() {
  switch(displayMode){
    case(standbyMode):
      drawStandyCircle();
      break;
    case(textMode):
      drawText("HELLO WORLD");
      break;
    case(shiftingTextMode):
      drawShiftingText("HELLO WORLD ");
      break;
  };
}

/**
 * @brief Retrieves one 8x8 sign from the list of many signs stacked together
 *        vertically in one list.
 * @param[in] list      list of 8x8 signs vertically stacked in one array
 * @param[in] index     index of the sign to be retrieved from the list
 * @param{out} screen   reference to output byte array
 */
void getScreen(byte list[], byte index, byte screen[]){
  screen[0] = list[index*8];
  screen[1] = list[index*8 + 1];
  screen[2] = list[index*8 + 2];
  screen[3] = list[index*8 + 3];
  screen[4] = list[index*8 + 4];
  screen[5] = list[index*8 + 5];
  screen[6] = list[index*8 + 6];
  screen[7] = list[index*8 + 7];
}

/**
 * @brief Retrieves one 8x8 sign from the list of many signs stacked together
 *        vertically in one list. Shifts the next letter into the screen
 *        based on the `shift` number of bits.
 * @param[in] list      list of 8x8 signs vertically stacked in one array
 * @param[in] index1     index of the first sign to be retrieved from the list
 * @param[in] index1     index of the second sign to be retrieved from the list
 * @param[in] shift     number of bits by which to shift the first letter
 * @param{out} screen   reference to output byte array
 */
void getShiftingScreen(byte list[], byte index1, byte index2, byte shift, byte screen[8]){
  byte masks[] = {0, 128, 192, 224, 240, 248, 252, 254};
  
  screen[0] = (list[index1*8] << shift) | ((list[index2*8] & masks[shift]) >> (8 - shift));
  screen[1] = (list[index1*8 + 1] << shift) | ((list[index2*8 + 1] & masks[shift]) >> (8 - shift));
  screen[2] = (list[index1*8 + 2] << shift) | ((list[index2*8 + 2] & masks[shift]) >> (8 - shift));
  screen[3] = (list[index1*8 + 3] << shift) | ((list[index2*8 + 3] & masks[shift]) >> (8 - shift));
  screen[4] = (list[index1*8 + 4] << shift) | ((list[index2*8 + 4] & masks[shift]) >> (8 - shift));
  screen[5] = (list[index1*8 + 5] << shift) | ((list[index2*8 + 5] & masks[shift]) >> (8 - shift));
  screen[6] = (list[index1*8 + 6] << shift) | ((list[index2*8 + 6] & masks[shift]) >> (8 - shift));
  screen[7] = (list[index1*8 + 7] << shift) | ((list[index2*8 + 7] & masks[shift]) >> (8 - shift));
}

void drawText(char text[]){
  if(text[picIndex] != '\0'){
    delay(2);
    byte index = text[picIndex]-64;
    if(text[picIndex] == ' '){
      index = 0;
    }
    byte currScreen[8];
    getScreen(alphabet, index, currScreen);

    drawScreen(currScreen);
    if(millis() - timeLastFrameChange > 400){
      timeLastFrameChange = millis();
      picIndex++;
    }
  } else {
    picIndex = 0;
    displayMode = standbyMode;
  }
    
}

void drawShiftingText(char text[]){
  if(text[picIndex+1] != '\0'){
    delay(2);
    byte index1 = text[picIndex]-64;
    if(text[picIndex] == ' '){
      index1 = 0;
    }

    byte index2 = text[picIndex+1]-64;
    if(text[picIndex+1] == ' '){
      index2 = 0;
    }
    
    byte currScreen[8];
    getShiftingScreen(alphabet, index1, index2, shift, currScreen);

    drawScreen(currScreen);
    if(millis() - timeLastFrameChange > 200){
      timeLastFrameChange = millis();
      shift++;
    }
    if(shift > 7){
      shift = 0;
      picIndex++;
    }
  } else {
    picIndex = 0;
    displayMode = standbyMode;
  }
}

void drawStandyCircle(){
  delay(2);
  // pulsingHeart/pulsingCircle
  byte currScreen[8]; 
  getScreen(pulsingCircle, picIndex, currScreen);

  drawScreen(currScreen);
  if(millis() - timeLastFrameChange > frameDelay_ms){
    timeLastFrameChange = millis();
    picIndex++;
    if(millis() - timeLastLoop > nFrames * frameDelay_ms){
      timeLastLoop = millis();
      picIndex = 0;
    }
  }
}

void drawScreen(byte buffer[]){
  // setting row after row
  for (byte i = 0; i < 8; i++) {
    setColumns(buffer[i]);
    // enable row
    digitalWrite(rows[i], LOW);
    delay(2);
    //disable row
    digitalWrite(rows[i], HIGH);
  }
}

void setColumns(byte b){
  for(byte i = 0; i < 8; i++){
    digitalWrite(columns[i], ((b << i) & B10000000) > 0);
  }
}
