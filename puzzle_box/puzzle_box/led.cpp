// LED Processing Function 
// 
// 

#include "led.h"
#include "dbg_print.h"
#include "lcd.h"

/*------------------------------------------
Constants
------------------------------------------*/
#define LED_PIN			13
#define DOT_LENGTH		500
#define DASH_LENGTH		1500
#define PAUSE_LENGTH	1000
#define OFF_LENGTH		500
#define RESTART_LENGTH	5000

/*------------------------------------------
Types
------------------------------------------*/

enum morse_code
{
	pause,
	dot,
	dash,
	end
};

/*------------------------------------------
Global Variables
------------------------------------------*/
String code;
int current_position;
unsigned long time;
unsigned long last_time;
boolean led_state;
morse_code letter[30];
boolean restart_wait;

/*------------------------------------------
Init Function
------------------------------------------*/
void led_init()
{
	pinMode(LED_PIN, OUTPUT);
	digitalWrite(LED_PIN, LOW);
	//led_state = false;
}

/*------------------------------------------
Proccessing Functions
------------------------------------------*/

void morse_init(String s)
{
	code = s;
	current_position = 0;
	for (int i = 0; i < code.length(); i++)
	{
		letter_to_morse(code.charAt(i));
		//Serial.println(i);
	}
	//Serial.print(current_position);
	Serial.print("pos of end: ");
	Serial.println(current_position);
	letter[--current_position] = end;
	current_position = 0;

	debug_print("Morse code:");
	morse_print_to_serial();
	last_time = millis();

	digitalWrite(LED_PIN, HIGH);
	led_state = true;
	restart_wait = false;
}

void morse_blink()
{
	time = millis();
	
	if (restart_wait)
	{
		if (time - last_time >= RESTART_LENGTH)
		{
			current_position = 0;
			digitalWrite(LED_PIN, HIGH);
			led_state = true;
			restart_wait = false;
			last_time = time;
			debug_print("restarting morse");
		}
		else
		{
			return;
		}
	}
	
	// if the LED is off it must be the start of a symbol 
	if (!led_state)
	{
		// if the LED is off we need to know if it is time to start a new symbol 
		if (letter[current_position] == pause)
		{
			// if we are on a space wait until that is done 
			if (time - last_time >= PAUSE_LENGTH)
			{
				digitalWrite(LED_PIN, HIGH);
				led_state = true;
				current_position++;
				last_time = time;
			}
		}
		// if we are not on space we must be inbetween blinks 
		else
		{
			if (time - last_time >= OFF_LENGTH)
			{
				current_position++;
				last_time = time;
				if (letter[current_position] != pause)
				{
					digitalWrite(LED_PIN, HIGH);
					led_state = true;
				}
			}
		}

	}
	// if the LED is on decide if it is time to turn it off
	else
	{
		// if the symbol is a dot then wait until it has been on a dot lengh before turning it off
		if (letter[current_position] == dot)
		{
			if (time - last_time >= DOT_LENGTH)
			{
				digitalWrite(LED_PIN, LOW);
				led_state = false;
				last_time = time;
				if (letter[current_position + 1] == end)
				{
					Serial.println("here_dot");
					restart_wait = true;
					return;
				}
			}
		}
		else if (letter[current_position] == dash)
		{
			if (time - last_time >= DASH_LENGTH)
			{
				digitalWrite(LED_PIN, LOW);
				led_state = false;
				last_time = time;
				if (letter[current_position + 1] == end)
				{
					Serial.println("here_dash");
					restart_wait = true;
					return;
				}
			}
		}
	}
}

void letter_to_morse(char c)
{
	switch (c)
	{
	case 'a':
		letter[current_position++] = dot;
		letter[current_position++] = dash;
		letter[current_position++] = pause;
		break;
	case 'b':
		letter[current_position++] = dash;
		letter[current_position++] = dot;
		letter[current_position++] = dot;
		letter[current_position++] = dot;
		letter[current_position++] = pause;
		break;
	case 'c':
		letter[current_position++] = dash;
		letter[current_position++] = dot;
		letter[current_position++] = dash;
		letter[current_position++] = dot;
		letter[current_position++] = pause;
		break;
	case 'd':
		letter[current_position++] = dash;
		letter[current_position++] = dot;
		letter[current_position++] = dot;
		letter[current_position++] = pause;
		break;
	case 'e':
		letter[current_position++] = dot;
		letter[current_position++] = pause;
		break;
	case 'f':
		letter[current_position++] = dot;
		letter[current_position++] = dot;
		letter[current_position++] = dash;
		letter[current_position++] = dot;
		letter[current_position++] = pause;
		break;
	case 'g':
		letter[current_position++] = dash;
		letter[current_position++] = dash;
		letter[current_position++] = dot;
		letter[current_position++] = pause;
		break;
	case 'h':
		letter[current_position++] = dot;
		letter[current_position++] = dot;
		letter[current_position++] = dot;
		letter[current_position++] = dot;
		letter[current_position++] = pause;
		break;
	case 'i':
		letter[current_position++] = dot;
		letter[current_position++] = dot;
		letter[current_position++] = pause;
		break;
	case 'j':
		letter[current_position++] = dot;
		letter[current_position++] = dash;
		letter[current_position++] = dash;
		letter[current_position++] = dash;
		letter[current_position++] = pause;
		break;
	case 'k':
		letter[current_position++] = dash;
		letter[current_position++] = dot;
		letter[current_position++] = dash;
		letter[current_position++] = pause;
		break;
	case 'l':
		letter[current_position++] = dot;
		letter[current_position++] = dash;
		letter[current_position++] = dot;
		letter[current_position++] = dot;
		letter[current_position++] = pause;
		break;
	case 'm':
		letter[current_position++] = dash;
		letter[current_position++] = dash;
		letter[current_position++] = pause;
		break;
	case 'n':
		letter[current_position++] = dash;
		letter[current_position++] = dot;
		letter[current_position++] = pause;
		break;
	case 'o':
		letter[current_position++] = dash;
		letter[current_position++] = dash;
		letter[current_position++] = dash;
		letter[current_position++] = pause;
		break;
	case 'p':
		letter[current_position++] = dot;
		letter[current_position++] = dash;
		letter[current_position++] = dash;
		letter[current_position++] = dot;
		letter[current_position++] = pause;
		break;
	case 'q':
		letter[current_position++] = dash;
		letter[current_position++] = dash;
		letter[current_position++] = dot;
		letter[current_position++] = dash;
		letter[current_position++] = pause;
		break;
	case 'r':
		letter[current_position++] = dot;
		letter[current_position++] = dash;
		letter[current_position++] = dot;
		letter[current_position++] = pause;
		break;
	case 's':
		letter[current_position++] = dot;
		letter[current_position++] = dot;
		letter[current_position++] = dot;
		letter[current_position++] = pause;
		break;
	case 't':
		letter[current_position++] = dash;
		letter[current_position++] = pause;
		break;
	case 'u':
		letter[current_position++] = dot;
		letter[current_position++] = dot;
		letter[current_position++] = dash;
		letter[current_position++] = pause;
		break;
	case 'v':
		letter[current_position++] = dot;
		letter[current_position++] = dot;
		letter[current_position++] = dot;
		letter[current_position++] = dash;
		letter[current_position++] = pause;
		break;
	case 'w':
		letter[current_position++] = dot;
		letter[current_position++] = dash;
		letter[current_position++] = dash;
		letter[current_position++] = pause;
		break;
	case 'x':
		letter[current_position++] = dash;
		letter[current_position++] = dot;
		letter[current_position++] = dot;
		letter[current_position++] = dash;
		letter[current_position++] = pause;
		break;
	case 'y':
		letter[current_position++] = dash;
		letter[current_position++] = dot;
		letter[current_position++] = dash;
		letter[current_position++] = dash;
		letter[current_position++] = pause;
		break;
	case 'z':
		letter[current_position++] = dash;
		letter[current_position++] = dash;
		letter[current_position++] = dot;
		letter[current_position++] = dot;
		letter[current_position++] = pause;
		break;
	}
}

void morse_print_to_serial()
{
	for (int i = 0; i < (code.length() * 5) + 1; i++)
	{
		if (letter[i] == dot)
		{
			Serial.print(".");
		}
		else if (letter[i] == dash)
		{
			Serial.print("-");
		}
		else if (letter[i] == pause)
		{
			Serial.print(" ");
		}
		else if (letter[i] == end)
		{
			Serial.print("END");
			//return;
		}
		else
		{
			Serial.print("ERR");
		}
	}
}


void toggle_led(int led)
{
	if (!led_state)
	{
		digitalWrite(LED_PIN, HIGH);
		led_state = true;
		//debug_print("toggle-on");
	}
	else
	{
		digitalWrite(LED_PIN, LOW);
		led_state = false;
		//debug_print("toggle-off");
	}
}