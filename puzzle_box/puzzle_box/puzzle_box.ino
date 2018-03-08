/*
 Name:		puzzle_box.ino
 Created:	1/21/2018 1:46:59 PM
 Author:	mc
*/

/*------------------------------------------
Includes 
------------------------------------------*/
#include "rfid2.h"
#include "servos.h"
#include "led.h"
#include "pressure.h"
#include "temperature.h"
#include "lcd.h"
#include "dbg_print.h"
#include <SoftwareSerial.h>
#include <EEPROM.h>

/*------------------------------------------
Constants
------------------------------------------*/
#define NVM_STATUS_ADDR 0
#define RESET_BUTTON	12
#define STEP_TO_LCD		true

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
boolean step_init;

/*------------------------------------------
System Initilizations 
------------------------------------------*/
void setup() 
{
	//servo_init();
	Serial.begin(9600);
	data_init();
	GPIO_init();
	led_init();
	RFID_init();
	LCD_init();
	ambient_temp_init();
	boot_splash(true);
	morse_init("chan");
}

/*------------------------------------------
Processing Loop 
------------------------------------------*/
void loop() 
{
	switch (status)
	{
	case STEP1:		// Piezo Sensor hold 
		if (!step_init)
		{
			// Show something on LCD
			start_step();
			lcd_clear();

		}
		target_print();
		if (pressure_check())
		{
			end_step();
		}
		break;
	
	case STEP2:		// Morse code key/Cipher/RFID
		if (!step_init)
		{
			// Show something on LCD
			start_step();
		}
		morse_blink();
		if (RFID_binary_check())
		{
			digitalWrite(13, LOW);
			end_step();
		}
		break;
	
	case STEP3:		// Temperature
		if (!step_init)
		{
			// Show something on LCD
			lcd_clear();
			start_step();
			thermometer_print();
			snowflake_print(20, 15);
			snowflake_print(100, 45);
		}
		if (temp_process())
		{
			end_step();
		}
		break;
	
	case SOLVED:	// Solution Reached
		if (!step_init)
		{
			// Show something on LCD
			start_step();
			
			//Freeze on success and set up to start over on reboot
			status = STEP1;
			EEPROM.write(NVM_STATUS_ADDR, status);
			servo_unlock();
			lcd_clear();
			boot_splash(true);
			while (1)
			{
				boot_splash(false);
			}
		}
		break;
	default:		// ERROR

		break;
	}
}

/*------------------------------------------
Init Functions 
------------------------------------------*/
void GPIO_init()
{
	pinMode(12, INPUT);
	delay(100);
	if (digitalRead(RESET_BUTTON) == HIGH)
	{
		status = STEP1;
		EEPROM.write(NVM_STATUS_ADDR, status);
	}
}

void data_init()
{
	status = (puzzle_state) EEPROM.read(NVM_STATUS_ADDR);
	step_init = false;
	Serial.print("State: ");
	Serial.println(status);
}

/*------------------------------------------
Helper Functions
------------------------------------------*/
void end_step()
{
	status = (puzzle_state) (status + 1);
	EEPROM.write(NVM_STATUS_ADDR, status);
	step_init = false;
}

void start_step()
{
	Serial.print("State: ");
	Serial.println(status);
	if (STEP_TO_LCD)
	{
		print_step_to_lcd(status);
	}
	step_init = true;
	
}
