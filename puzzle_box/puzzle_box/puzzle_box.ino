/*
 Name:		puzzle_box.ino
 Created:	1/21/2018 1:46:59 PM
 Author:	mc
*/
/*------------------------------------------
includes 
-----------------------------------------=*/
#include <C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\SoftwareSerial\src\SoftwareSerial.h>
#include <C:\Users\mc\OneDrive\projects\puzzle_box\puzzle_box\LCD\serialGLCDlib.h>

SoftwareSerial LCD = SoftwareSerial(2, 3);

// the setup function runs once when you press reset or power the board
void setup() 
{
	pinMode(13, OUTPUT);

}

// the loop function runs over and over again until power down or reset
void loop() 
{
	digitalWrite(13, HIGH);
	delay(500);
	digitalWrite(13, LOW);
	delay(500);
}
