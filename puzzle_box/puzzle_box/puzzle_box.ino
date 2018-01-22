/*
 Name:		puzzle_box.ino
 Created:	1/21/2018 1:46:59 PM
 Author:	mc
*/

/*------------------------------------------
Includes 
------------------------------------------*/
#include "temperature.h"
#include "rfid.h"
#include "lcd.h"
#include "dbg_print.h"
#include <SoftwareSerial.h>

/*------------------------------------------
Types
------------------------------------------*/
enum puzzle_state
{
	STEP1,
	STEP2,
	STEP3,
	SOLVED
};

/*------------------------------------------
Global Variables
------------------------------------------*/
puzzle_state status;

/*------------------------------------------
System Initilizations 
------------------------------------------*/
void setup() 
{
	data_init();
	GPIO_init();
	RFID_init();
	LCD_init();
	ambient_temp_init();
}

/*------------------------------------------
Processing Loop 
------------------------------------------*/
void loop() 
{
	switch (status)
	{
	case STEP1:		// 

		break;
	case STEP2:		// Cipher/RFID
		if (RFID_process())
		{
			status = STEP3;
		}
		break;
	case STEP3:		// Temperature
		if (temp_process())
		{
			status = SOLVED;
		}
		break;
	case SOLVED:	// Solution Reached

		break;
	default:		// ERROR

	}
}

/*------------------------------------------
Init Functions 
------------------------------------------*/
void GPIO_init()
{
	pinMode(13, OUTPUT);
	digitalWrite(13, LOW);
}

void data_init()
{
	status = STEP1;
}
