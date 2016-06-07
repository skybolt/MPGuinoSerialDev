#include "mpguino_conf.h"

// --------------- constants --------------------
#define LcdCharHeightPix  8 
#if (UNO_MODIFICATIONS == 1) //is this a problem? Could any of these assignments affect read analog 1 instead of 0?
 #define DIPin             8 // register select RS, meelis 4, arduino default 12, new lcd 8 
 #define EnablePin         9 // enable pin, 5 meelis, 11 arduino, 9 new
 #define ContrastPin       6  //
 #define DB4Pin            4 //d4? 7 meelis, 5 arduino, 4 lcd
 #define DB5Pin            5 //d5? 8 meelis, 4 arduoni, 5 lcd
 #define BrightnessPin     9 //?
 #define DB6Pin            6 //6? meelis 12, 3 arduino, 6 lcd
 #define DB7Pin            7 //d7? 13 meelis, 2 arduino, 7 lcd
#else 
 #define DIPin             4 // register select RS  
 #define EnablePin         5 
 #define ContrastPin       6  
 #define DB4Pin            7
 #define DB5Pin            8
 #define BrightnessPin     9
 #define DB6Pin            12
 #define DB7Pin            13  
#endif


/* --- LCD Commands --- */
#define LCD_ClearDisplay                  0x01
#define LCD_ReturnHome                    0x02

#define LCD_EntryMode                     0x04
#define LCD_EntryMode_Increment           0x02

#define LCD_DisplayOnOffCtrl              0x08
#define LCD_DisplayOnOffCtrl_DispOn       0x04
#define LCD_DisplayOnOffCtrl_CursOn       0x02
#define LCD_DisplayOnOffCtrl_CursBlink    0x01

#define LCD_SetCGRAM                      0x40
#define LCD_SetDDRAM                      0x80
/* you can OR a memory address with each of the above */

/*Replace #include "WConstants.h"  //all things wiring / arduino
#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif
*/

//LCD prototype      
namespace LCD{      
  void gotoXY(unsigned char x, unsigned char y);      
  void print(char * string);      
  void init();      
  void writeCGRAM(char *newchars, unsigned char numnew);
  void tickleEnable();      
  void cmdWriteSet();      
  void LcdCommandWrite(unsigned char value);      
  void LcdDataWrite(unsigned char value);
  unsigned char pushNibble(unsigned char value);      
};      
