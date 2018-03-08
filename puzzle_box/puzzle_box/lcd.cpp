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
Constants
------------------------------------------*/
#define MAX_X 127
#define MAX_Y 63
#define MIN_X 0
#define MIN_Y 0
#define CENTER_X (MAX_X + 1) / 2
#define CENTER_Y (MAX_Y + 1) / 2

/*------------------------------------------
Global Variables
------------------------------------------*/
int circle_step;
unsigned long circle_time;
unsigned long circle_last_time;

/*------------------------------------------
Init Functions
------------------------------------------*/
void LCD_init()
{
	delay(1200);
	myLCD.setHome();
	myLCD.clearScreen();
	circle_step = 0;
	circle_last_time = millis();
}

/*------------------------------------------
Proccessing Functions
------------------------------------------*/
void boot_splash(boolean text)
{
	#define SIZE_OF_BOX_X	60
	#define SIZE_OF_BOX_Y	30
	#define CEN_BOX_Y		MAX_Y - 2 - (SIZE_OF_BOX_Y / 2)
	#define HAND_DELAY		100	

	if (text)
	{
		myLCD.printStr("     puzzle box!     ");
		delay(100);
	}

	myLCD.drawBox(CENTER_X - (SIZE_OF_BOX_X / 2), MAX_Y - 5 - SIZE_OF_BOX_Y, CENTER_X + (SIZE_OF_BOX_X / 2), MAX_Y - 5, 0);
	
	myLCD.drawCircle(CENTER_X, CEN_BOX_Y - 5, 5, 0);
	myLCD.drawCircle(CENTER_X, CEN_BOX_Y - 5, 4, 0);
	myLCD.eraseBlock(CENTER_X - 5, CEN_BOX_Y - 5, CENTER_X + 5, CEN_BOX_Y + 5);
	myLCD.drawBox(CENTER_X - 5, CEN_BOX_Y - 5, CENTER_X + 5, CEN_BOX_Y + 5, 0);
	
	//HAND
	myLCD.drawLine(CENTER_X, CEN_BOX_Y, CENTER_X,		CEN_BOX_Y - 5,		0);															// top
	delay(HAND_DELAY);
	myLCD.eraseBlock(CENTER_X - 4, CEN_BOX_Y - 4, CENTER_X + 4, CEN_BOX_Y + 4);
	
	myLCD.drawLine(CENTER_X, CEN_BOX_Y, CENTER_X + 1,	CEN_BOX_Y - 5,		0);
	delay(HAND_DELAY);
	myLCD.eraseBlock(CENTER_X - 4, CEN_BOX_Y - 4, CENTER_X + 4, CEN_BOX_Y + 4);
	
	myLCD.drawLine(CENTER_X, CEN_BOX_Y, CENTER_X + 2,	CEN_BOX_Y - 5,		0);
	delay(HAND_DELAY);
	myLCD.eraseBlock(CENTER_X - 4, CEN_BOX_Y - 4, CENTER_X + 4, CEN_BOX_Y + 4);
	
	myLCD.drawLine(CENTER_X, CEN_BOX_Y, CENTER_X + 3,	CEN_BOX_Y - 5,		0);
	delay(HAND_DELAY);
	myLCD.eraseBlock(CENTER_X - 4, CEN_BOX_Y - 4, CENTER_X + 4, CEN_BOX_Y + 4);
	
	myLCD.drawLine(CENTER_X, CEN_BOX_Y, CENTER_X + 4,	CEN_BOX_Y - 5,		0);
	delay(HAND_DELAY);
	myLCD.eraseBlock(CENTER_X - 4, CEN_BOX_Y - 4, CENTER_X + 4, CEN_BOX_Y + 4);
	
	myLCD.drawLine(CENTER_X, CEN_BOX_Y, CENTER_X + 5,	CEN_BOX_Y - 5,		0);
	delay(HAND_DELAY);
	myLCD.eraseBlock(CENTER_X - 4, CEN_BOX_Y - 4, CENTER_X + 4, CEN_BOX_Y + 4);
	

	myLCD.drawLine(CENTER_X, CEN_BOX_Y, CENTER_X + 5,	CEN_BOX_Y - 5 + 1,	0);															// top - right
	delay(HAND_DELAY);
	myLCD.eraseBlock(CENTER_X - 4, CEN_BOX_Y - 4, CENTER_X + 4, CEN_BOX_Y + 4);
	
	myLCD.drawLine(CENTER_X, CEN_BOX_Y, CENTER_X + 5,	CEN_BOX_Y - 5 + 2,	0);
	delay(HAND_DELAY);
	myLCD.eraseBlock(CENTER_X - 4, CEN_BOX_Y - 4, CENTER_X + 4, CEN_BOX_Y + 4);
	
	myLCD.drawLine(CENTER_X, CEN_BOX_Y, CENTER_X + 5,	CEN_BOX_Y - 5 + 3,	0);
	delay(HAND_DELAY);
	myLCD.eraseBlock(CENTER_X - 4, CEN_BOX_Y - 4, CENTER_X + 4, CEN_BOX_Y + 4);
	
	myLCD.drawLine(CENTER_X, CEN_BOX_Y, CENTER_X + 5,	CEN_BOX_Y - 5 + 4,	0);
	delay(HAND_DELAY);
	myLCD.eraseBlock(CENTER_X - 4, CEN_BOX_Y - 4, CENTER_X + 4, CEN_BOX_Y + 4);
	
	myLCD.drawLine(CENTER_X, CEN_BOX_Y, CENTER_X + 5,	CEN_BOX_Y - 5 + 5,	0);
	delay(HAND_DELAY);
	myLCD.eraseBlock(CENTER_X - 4, CEN_BOX_Y - 4, CENTER_X + 4, CEN_BOX_Y + 4);
	
	myLCD.drawLine(CENTER_X, CEN_BOX_Y, CENTER_X + 5,	CEN_BOX_Y - 5 + 6,	0);
	delay(HAND_DELAY);
	myLCD.eraseBlock(CENTER_X - 4, CEN_BOX_Y - 4, CENTER_X + 4, CEN_BOX_Y + 4);
	
	myLCD.drawLine(CENTER_X, CEN_BOX_Y, CENTER_X + 5,	CEN_BOX_Y - 5 + 7,	0);
	delay(HAND_DELAY);
	myLCD.eraseBlock(CENTER_X - 4, CEN_BOX_Y - 4, CENTER_X + 4, CEN_BOX_Y + 4);
	
	myLCD.drawLine(CENTER_X, CEN_BOX_Y, CENTER_X + 5,	CEN_BOX_Y - 5 + 8,	0);
	delay(HAND_DELAY);
	myLCD.eraseBlock(CENTER_X - 4, CEN_BOX_Y - 4, CENTER_X + 4, CEN_BOX_Y + 4);
	
	myLCD.drawLine(CENTER_X, CEN_BOX_Y, CENTER_X + 5,	CEN_BOX_Y - 5 + 9,	0);
	delay(HAND_DELAY);
	myLCD.eraseBlock(CENTER_X - 4, CEN_BOX_Y - 4, CENTER_X + 4, CEN_BOX_Y + 4);
	
	myLCD.drawLine(CENTER_X, CEN_BOX_Y, CENTER_X + 5,	CEN_BOX_Y - 5 + 10,	0);															// bottom - right
	delay(HAND_DELAY);
	myLCD.eraseBlock(CENTER_X - 4, CEN_BOX_Y - 4, CENTER_X + 4, CEN_BOX_Y + 4);
	
	
	myLCD.drawLine(CENTER_X, CEN_BOX_Y, CENTER_X + 4,	CEN_BOX_Y - 5 + 10,	0);
	delay(HAND_DELAY);
	myLCD.eraseBlock(CENTER_X - 4, CEN_BOX_Y - 4, CENTER_X + 4, CEN_BOX_Y + 4);
	
	myLCD.drawLine(CENTER_X, CEN_BOX_Y, CENTER_X + 3,	CEN_BOX_Y - 5 + 10, 0);
	delay(HAND_DELAY);
	myLCD.eraseBlock(CENTER_X - 4, CEN_BOX_Y - 4, CENTER_X + 4, CEN_BOX_Y + 4);
	
	myLCD.drawLine(CENTER_X, CEN_BOX_Y, CENTER_X + 2,	CEN_BOX_Y - 5 + 10, 0);
	delay(HAND_DELAY);
	myLCD.eraseBlock(CENTER_X - 4, CEN_BOX_Y - 4, CENTER_X + 4, CEN_BOX_Y + 4);
	
	myLCD.drawLine(CENTER_X, CEN_BOX_Y, CENTER_X + 1,	CEN_BOX_Y - 5 + 10, 0);
	delay(HAND_DELAY);
	myLCD.eraseBlock(CENTER_X - 4, CEN_BOX_Y - 4, CENTER_X + 4, CEN_BOX_Y + 4);
	
	myLCD.drawLine(CENTER_X, CEN_BOX_Y, CENTER_X,		CEN_BOX_Y - 5 + 10, 0);
	delay(HAND_DELAY);
	myLCD.eraseBlock(CENTER_X - 4, CEN_BOX_Y - 4, CENTER_X + 4, CEN_BOX_Y + 4);
	
	myLCD.drawLine(CENTER_X, CEN_BOX_Y, CENTER_X - 1,	CEN_BOX_Y - 5 + 10, 0);
	delay(HAND_DELAY);
	myLCD.eraseBlock(CENTER_X - 4, CEN_BOX_Y - 4, CENTER_X + 4, CEN_BOX_Y + 4);
	
	myLCD.drawLine(CENTER_X, CEN_BOX_Y, CENTER_X - 2,	CEN_BOX_Y - 5 + 10, 0);
	delay(HAND_DELAY);
	myLCD.eraseBlock(CENTER_X - 4, CEN_BOX_Y - 4, CENTER_X + 4, CEN_BOX_Y + 4);
	
	myLCD.drawLine(CENTER_X, CEN_BOX_Y, CENTER_X - 3,	CEN_BOX_Y - 5 + 10, 0);
	delay(HAND_DELAY);
	myLCD.eraseBlock(CENTER_X - 4, CEN_BOX_Y - 4, CENTER_X + 4, CEN_BOX_Y + 4);
	
	myLCD.drawLine(CENTER_X, CEN_BOX_Y, CENTER_X - 4,	CEN_BOX_Y - 5 + 10, 0);
	delay(HAND_DELAY);
	myLCD.eraseBlock(CENTER_X - 4, CEN_BOX_Y - 4, CENTER_X + 4, CEN_BOX_Y + 4);
	
	myLCD.drawLine(CENTER_X, CEN_BOX_Y, CENTER_X - 5,	CEN_BOX_Y - 5 + 10, 0);															// bottom - left
	delay(HAND_DELAY);
	myLCD.eraseBlock(CENTER_X - 4, CEN_BOX_Y - 4, CENTER_X + 4, CEN_BOX_Y + 4);
	
	
	myLCD.drawLine(CENTER_X, CEN_BOX_Y, CENTER_X - 5,	CEN_BOX_Y - 5 + 9,	0);
	delay(HAND_DELAY);
	myLCD.drawLine(CENTER_X, CEN_BOX_Y, CENTER_X - 5,	CEN_BOX_Y - 5 + 8,	0);
	
	myLCD.drawLine(CENTER_X, CEN_BOX_Y, CENTER_X - 5,	CEN_BOX_Y - 5 + 7,	0);
	delay(HAND_DELAY);
	myLCD.eraseBlock(CENTER_X - 4, CEN_BOX_Y - 4, CENTER_X + 4, CEN_BOX_Y + 4);
	
	myLCD.drawLine(CENTER_X, CEN_BOX_Y, CENTER_X - 5,	CEN_BOX_Y - 5 + 6,	0);
	delay(HAND_DELAY);
	myLCD.eraseBlock(CENTER_X - 4, CEN_BOX_Y - 4, CENTER_X + 4, CEN_BOX_Y + 4);
	
	myLCD.drawLine(CENTER_X, CEN_BOX_Y, CENTER_X - 5,	CEN_BOX_Y - 5 + 5,	0);
	delay(HAND_DELAY);
	myLCD.eraseBlock(CENTER_X - 4, CEN_BOX_Y - 4, CENTER_X + 4, CEN_BOX_Y + 4);
	
	myLCD.drawLine(CENTER_X, CEN_BOX_Y, CENTER_X - 5,	CEN_BOX_Y - 5 + 4,	0);
	delay(HAND_DELAY);
	myLCD.eraseBlock(CENTER_X - 4, CEN_BOX_Y - 4, CENTER_X + 4, CEN_BOX_Y + 4);
	
	myLCD.drawLine(CENTER_X, CEN_BOX_Y, CENTER_X - 5,	CEN_BOX_Y - 5 + 3,	0);
	delay(HAND_DELAY);
	myLCD.eraseBlock(CENTER_X - 4, CEN_BOX_Y - 4, CENTER_X + 4, CEN_BOX_Y + 4);
	
	myLCD.drawLine(CENTER_X, CEN_BOX_Y, CENTER_X - 5,	CEN_BOX_Y - 5 + 2,	0);
	delay(HAND_DELAY);
	myLCD.eraseBlock(CENTER_X - 4, CEN_BOX_Y - 4, CENTER_X + 4, CEN_BOX_Y + 4);
	
	myLCD.drawLine(CENTER_X, CEN_BOX_Y, CENTER_X - 5,	CEN_BOX_Y - 5 + 1,	0);
	delay(HAND_DELAY);
	myLCD.eraseBlock(CENTER_X - 4, CEN_BOX_Y - 4, CENTER_X + 4, CEN_BOX_Y + 4);
	
	myLCD.drawLine(CENTER_X, CEN_BOX_Y, CENTER_X - 5,	CEN_BOX_Y - 5,		0);															// top - left
	delay(HAND_DELAY);
	myLCD.eraseBlock(CENTER_X - 4, CEN_BOX_Y - 4, CENTER_X + 4, CEN_BOX_Y + 4);
	

	myLCD.drawLine(CENTER_X, CEN_BOX_Y, CENTER_X - 5,	CEN_BOX_Y - 5 + 0,	0);
	delay(HAND_DELAY);
	myLCD.eraseBlock(CENTER_X - 4, CEN_BOX_Y - 4, CENTER_X + 4, CEN_BOX_Y + 4);
	
	myLCD.drawLine(CENTER_X, CEN_BOX_Y, CENTER_X - 4,	CEN_BOX_Y - 5 + 0,	0);
	delay(HAND_DELAY);
	myLCD.eraseBlock(CENTER_X - 4, CEN_BOX_Y - 4, CENTER_X + 4, CEN_BOX_Y + 4);
	
	myLCD.drawLine(CENTER_X, CEN_BOX_Y, CENTER_X - 3,	CEN_BOX_Y - 5 + 0,	0);
	delay(HAND_DELAY);
	myLCD.eraseBlock(CENTER_X - 4, CEN_BOX_Y - 4, CENTER_X + 4, CEN_BOX_Y + 4);
	
	myLCD.drawLine(CENTER_X, CEN_BOX_Y, CENTER_X - 2,	CEN_BOX_Y - 5 + 0,	0);
	delay(HAND_DELAY);
	myLCD.eraseBlock(CENTER_X - 4, CEN_BOX_Y - 4, CENTER_X + 4, CEN_BOX_Y + 4);
	
	myLCD.drawLine(CENTER_X, CEN_BOX_Y, CENTER_X - 1,	CEN_BOX_Y - 5 + 0,	0);
	delay(HAND_DELAY);
	myLCD.eraseBlock(CENTER_X - 4, CEN_BOX_Y - 4, CENTER_X + 4, CEN_BOX_Y + 4);
	
	// if not looping it should stay on the top
	myLCD.drawLine(CENTER_X, CEN_BOX_Y, CENTER_X, CEN_BOX_Y - 5, 0);																// top



	#undef SIZE_OF_BOX_X
	#undef SIZE_OF_BOX_Y
	#undef CEN_CIRC_Y
	#undef HAND_DELAY
}

void thermometer_print()
{
	myLCD.drawCircle(CENTER_X, MAX_Y - 15, 6, 0);
	myLCD.drawBox(CENTER_X - 3, MAX_Y - 20, CENTER_X + 3, MAX_Y - 50, 0);

	myLCD.drawCircle(CENTER_X, MAX_Y - 15, 5, 0);
	myLCD.drawCircle(CENTER_X, MAX_Y - 15, 4, 0);
	myLCD.drawCircle(CENTER_X, MAX_Y - 15, 3, 0);
	myLCD.drawCircle(CENTER_X, MAX_Y - 15, 2, 0);
	myLCD.drawCircle(CENTER_X, MAX_Y - 15, 1, 0);
	
	myLCD.drawLine(CENTER_X - 3, MAX_Y - 21, CENTER_X + 3, MAX_Y - 21, 0);
	myLCD.drawLine(CENTER_X - 3, MAX_Y - 22, CENTER_X + 3, MAX_Y - 22, 0);
	myLCD.drawLine(CENTER_X - 3, MAX_Y - 23, CENTER_X + 3, MAX_Y - 23, 0);
	myLCD.drawLine(CENTER_X - 3, MAX_Y - 24, CENTER_X + 3, MAX_Y - 24, 0);
	myLCD.drawLine(CENTER_X - 3, MAX_Y - 25, CENTER_X + 3, MAX_Y - 25, 0);
	myLCD.drawLine(CENTER_X - 3, MAX_Y - 26, CENTER_X + 3, MAX_Y - 26, 0);
}

void snowflake_print(int x, int y)
{
	myLCD.drawLine(x - 10, y, x + 10, y, 0);
	myLCD.drawLine(x, y - 10, x, y + 10, 0);

	myLCD.drawLine(x, y + 5, x + 5, y + 10, 0);
	myLCD.drawLine(x, y + 5, x - 5, y + 10, 0);

	myLCD.drawLine(x, y - 5, x + 5, y - 10, 0);
	myLCD.drawLine(x, y - 5, x - 5, y - 10, 0);

	myLCD.drawLine(x - 5, y, x - 10, y + 5, 0);
	myLCD.drawLine(x - 5, y, x - 10, y - 5, 0);

	myLCD.drawLine(x + 5, y, x + 10, y + 5, 0);
	myLCD.drawLine(x + 5, y, x + 10, y - 5, 0);
}

void target_print()
{
	#define C1_X 30
	#define C2_X 90
	#define delay_time 750

	circle_time = millis();
	if (circle_time - circle_last_time < delay_time)
	{
		return;	
	}
	else
	{
		circle_step++;
		circle_last_time = circle_time;
	}
	switch (circle_step)
	{
	case 0:
		myLCD.drawCircle(C1_X, CENTER_Y, 20, 0);
		myLCD.drawCircle(C2_X, CENTER_Y, 20, 0);
		break;
	case 1:
		myLCD.drawCircle(C1_X, CENTER_Y, 15, 0);
		myLCD.drawCircle(C2_X, CENTER_Y, 15, 0);
		break;
	case 2:
		myLCD.drawCircle(C1_X, CENTER_Y, 10, 0);
		myLCD.drawCircle(C2_X, CENTER_Y, 10, 0);
		break;
	case 3:
		myLCD.drawCircle(C1_X, CENTER_Y, 5, 0);
		myLCD.drawCircle(C2_X, CENTER_Y, 5, 0);
		break;
	case 4:
		myLCD.drawCircle(C1_X, CENTER_Y, 1, 0);
		myLCD.drawCircle(C2_X, CENTER_Y, 1, 0);
		break;
	case 5:
		myLCD.clearScreen();
		circle_step = 0;
		break;
		
	}

	#undef C1_X
	#undef C2_X
}


void lcd_clear()
{
	myLCD.clearScreen();
}

void print_step_to_lcd(int step)
{
	myLCD.setHome();
	myLCD.printNum(step);
}
