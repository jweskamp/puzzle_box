/*
 Name:		puzzle_box.ino
 Created:	1/21/2018 1:46:59 PM
 Author:	mc
*/

/*------------------------------------------
Includes 
------------------------------------------*/
#include <SoftwareSerial.h>
#include <SerialGraphicLCD.h>

/*------------------------------------------
Constants
------------------------------------------*/
#define card "00006A263D71"

/*------------------------------------------
Object Declarations
------------------------------------------*/
SoftwareSerial RFID = SoftwareSerial(5, 6);
LCD myLCD;

/*------------------------------------------
Global Variables
------------------------------------------*/
char c;
String msg;

// the setup function runs once when you press reset or power the board
void setup() 
{
	delay(1200);
	pinMode(13, OUTPUT);
	digitalWrite(13, LOW);

	myLCD.setHome();
	myLCD.printStr("here");


	Serial.begin(9600);
	RFID.begin(9600);

}

// the loop function runs over and over again until power down or reset
void loop() 
{
	while (RFID.available() > 0 && msg.length() < 13)
	{
		c = RFID.read();
		msg += c;
		Serial.print(msg.length());
		Serial.print("   ");
		Serial.println(msg);
	}
	if (msg.length() == 13)
	{
		Serial.println("---FINAL CARD---");
		Serial.println(msg);
		if (msg.equals(card))
		{
			digitalWrite(13, HIGH);
			Serial.println("here");
		}
		RFID.end();
		delay(2000);
		RFID.begin(9600);
		msg = "";
	}
}
