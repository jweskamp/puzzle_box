// RFID control functions 
// 
// 

#include "rfid.h"
#include "dbg_print.h"
#include <SoftwareSerial.h>

/*------------------------------------------
Constants
------------------------------------------*/
#define CARD "00006A263D71"

/*------------------------------------------
Object Declarations
------------------------------------------*/
SoftwareSerial RFID = SoftwareSerial(5, 6);

/*------------------------------------------
Global Variables
------------------------------------------*/
String msg;

/*------------------------------------------
Prototypes
------------------------------------------*/
void RFID_get();
boolean RFID_data_check();

/*------------------------------------------
Init Functions
------------------------------------------*/
void RFID_init()
{
	Serial.begin(9600);
	RFID.begin(9600);
}

/*------------------------------------------
Proccessing Functions
------------------------------------------*/
boolean RFID_process()
{
	RFID_get();
	return RFID_data_check();
}

void RFID_get()
{
	// Local Variables
	char c;

	// Read in RFID input
	while (RFID.available() > 0 && msg.length() < 13)
	{
		c = RFID.read();
		msg += c;
		debug_print("RFID message:", msg);
	}
}

boolean RFID_data_check()
{
	// local Variables
	boolean ret_val = false;

	// Check if RFID data matches saved card
	if (msg.length() == 13)
	{
		debug_print("___FINAL_CARD___");
		debug_print(msg);

		if (msg.equals(CARD))
		{
			debug_print("matching card");
			ret_val = true;
		}
		RFID.end();
		delay(2000);
		RFID.begin(9600);
		msg = "";
	}
	return ret_val;
}