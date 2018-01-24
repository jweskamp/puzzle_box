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
void boot_splash()
{
	#define SIZE_OF_BOX_X	60
	#define SIZE_OF_BOX_Y	30
	#define CEN_BOX_Y		MAX_Y - 2 - (SIZE_OF_BOX_Y / 2)
	#define HAND_DELAY		100	

	myLCD.clearScreen();
    //myLCD.printStr("---------------------");
	myLCD.printStr("     puzzle box!     ");
	delay(100);

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




	#undef SIZE_OF_BOX_X
	#undef SIZE_OF_BOX_Y
	#undef CEN_CIRC_Y
	#undef HAND_DELAY
}

void print_step_to_lcd(int step)
{
	myLCD.setHome();
	myLCD.printNum(step);
}
