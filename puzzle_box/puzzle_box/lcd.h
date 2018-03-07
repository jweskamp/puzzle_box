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
void boot_splash();
void thermometer_print();
void snowflake_print(int x, int y);
void lcd_clear();
void print_step_to_lcd(int step);

#endif

