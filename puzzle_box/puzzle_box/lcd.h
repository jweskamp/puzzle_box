// lcd.h

#ifndef _LCD_h
#define _LCD_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

/*------------------------------------------
Function Prototypes
------------------------------------------*/
void LCD_init();

#endif

