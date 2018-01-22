// Graphic LCD Functions
// 
// 

#include "lcd.h"
#include <SoftwareSerial.h>
#include <SerialGraphicLCD.h>

/*------------------------------------------
Object Declarations
------------------------------------------*/
LCD myLCD;

/*------------------------------------------
Init Functions
------------------------------------------*/
void LCD_init()
{
	delay(1200);
	myLCD.setHome();
}

/*------------------------------------------
Proccessing Functions
------------------------------------------*/
