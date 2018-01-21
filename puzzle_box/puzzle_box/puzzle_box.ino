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
#define CARD "00006A263D71"
#define DEBUG_BUILD true
#define THERMISTOR 0

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
Object Declarations
------------------------------------------*/
SoftwareSerial RFID = SoftwareSerial(5, 6);
LCD myLCD;

/*------------------------------------------
Global Variables
------------------------------------------*/
puzzle_state status;
String msg;
int ambient_temp;

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
	while (1);
}

/*------------------------------------------
Processing Loop 
------------------------------------------*/
void loop() 
{
	//if (RFID_process())
	//{
		// do something
	//}
	if (temp_process())
	{
		digitalWrite(13, HIGH);
	}

}

/*------------------------------------------
Init Functions 
------------------------------------------*/
void LCD_init()
{
	delay(1200);
	myLCD.setHome();
}

void RFID_init()
{
	Serial.begin(9600);
	RFID.begin(9600);
}

void GPIO_init()
{
	pinMode(13, OUTPUT);
	digitalWrite(13, LOW);
}

void data_init()
{
	status = STEP1;
}

void ambient_temp_init()
{
	// Local Variables
	unsigned long temp = 0;
	int x;

	for (x = 0; x < 100; x++)
	{
		temp += analogRead(THERMISTOR);
	}
	ambient_temp = temp / 100;
	if (DEBUG_BUILD)
	{
		Serial.print("ambient temperature: ");
		Serial.println(ambient_temp);
	}
}

/*------------------------------------------
Proccessing Functions 
------------------------------------------*/
boolean RFID_process()
{
	RFID_get();
	return RFID_data_check( );
}

boolean temp_process()
{
	// Local Variables 
	int temp;

	// Temperature Processing 
	temp = analogRead(THERMISTOR);
	if (DEBUG_BUILD)
	{
		Serial.println("temperature: " + temp);
	}
	if (temp > ambient_temp + 20)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*------------------------------------------
Supporting Functions
------------------------------------------*/
void RFID_get()
{
	// Local Variables
	char c;

	// Read in RFID input
	while (RFID.available() > 0 && msg.length() < 13)
	{
		c = RFID.read();
		msg += c;
		if (DEBUG_BUILD)
		{
			Serial.print(msg.length());
			Serial.print("   ");
			Serial.println(msg);
		}
	}
}

boolean RFID_data_check()
{
	// local Variables
	boolean ret_val = false;

	// Check if RFID data matches saved card
	if (msg.length() == 13 )
	{
		if (DEBUG_BUILD)
		{
			Serial.println("---FINAL CARD---");
			Serial.println(msg);
		}
		
		if (msg.equals(CARD))
		{
			if (DEBUG_BUILD)
			{
				Serial.println("matching card");
			}
			ret_val = true;
		}
		RFID.end();
		delay(2000);
		RFID.begin(9600);
		msg = "";
	}
	return ret_val;
}

