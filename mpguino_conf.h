/* --- Compile-time options ---------------------------------- */

#define UNO_MODIFICATIONS          0//0 for default mpguino, 1 for newfangled lcd+buttons shield
#define MEMORY_REDUCDER            0 //0 to run nomrally, 1 to disable things to try and save memory
#define JSON_OUT                   1
#define BYPASS_INITIAL_SETUP       1
#define NANO_MODS                  0
#define SERIAL_MEM                 0


#define BARGRAPH_DISPLAY_CFG       0  /* 0=Off 1=On (+968 bytes) */
#define CFG_BIGFONT_TYPE           0  /* 0=BigNum screens off(-552) 1=Default 2=Modified (+24 bytes) */
#define CFG_FUELCUT_INDICATOR      0  /* 0=Off 1=char (+54) 2=spinner 3=bubble (+74) */
#define CFG_IDLE_MESSAGE           0 
#define CFG_SERIAL_TX              1  /* 0=Off 1=On (+232) */
#define SLEEP_CFG                  3  /* 0=Off 1=bl (+34) 2=lcd (+14) 3=both (+46)   */
#define TANK_IN_EEPROM_CFG         1  /* 0=Off 1=On (+34)  */
#define OUTSIDE_TEMP_CFG           0  /* 0=Off 1=On        */
#define BATTERY_VOLTAGE            1  /* 0=Off 1=On (+920) */
#define DRAGRACE_DISPLAY_CFG       1

#define CFG_UNITS                  1  /* 1=US  2=METRIC  */
