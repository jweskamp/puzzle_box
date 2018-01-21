/*
 Name:		puzzle_box.ino
 Created:	1/21/2018 1:46:59 PM
 Author:	mc
*/
/*------------------------------------------
includes 
------------------------------------------*/
#include <SoftwareSerial.h>
#include <SerialGraphicLCD.h>

/*------------------------------------------
Object Declarations
------------------------------------------*/
//SoftwareSerial LCD_serial = SoftwareSerial(2, 3);

LCD myLCD;

// the setup function runs once when you press reset or power the board
void setup() 
{
	delay(1200);
	pinMode(13, OUTPUT);
	myLCD.setHome();
	myLCD.printStr("here");

}

// the loop function runs over and over again until power down or reset
void loop() 
{
	digitalWrite(13, HIGH);
	delay(500);
	digitalWrite(13, LOW);
	delay(500); 
}
