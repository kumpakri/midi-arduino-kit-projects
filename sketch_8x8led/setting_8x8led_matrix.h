/**
 *  Pin setting for the 8x8 LED matrix
 *  
 *     16 15 14 13 12 11 10  9
 *      |  |  |  |  |  |  |  |
 *     ------------------------
 *    |                        |
 *    |                        |
 *    |     8x8 LED matrix     |
 *    |        PIN OUT         |
 *    |                        |
 *    |                        |
 *    |                        |
 *    |       label side       |
 *     ------------------------
 *      |  |  |  |  |  |  |  |
 *      1  2  3  4  5  6  7  6
 */

#define ROW_1 A0 //pin 9
#define ROW_2 2 //pin 14
#define ROW_3 3 //pin 8
#define ROW_4 4 //pin 12
#define ROW_5 5 //pin 1
#define ROW_6 6 //pin 7
#define ROW_7 7 //pin 2
#define ROW_8 8 //pin 5

#define COL_1 9 //pin 13
#define COL_2 10 //pin 3
#define COL_3 11 //pin 4
#define COL_4 12 //pin 10
#define COL_5 13 //pin 6
#define COL_6 A1 //pin 11
#define COL_7 A2 //pin 15
#define COL_8 A3 //pin 16
