/*
 *  serialGLCDlib.cpp
 *  serialGLCDlib
 *
 *  Created by Øyvind Schei on 15.05.11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "serialGLCDlib.h"
#include "WProgram.h"

serialGLCD::serialGLCD()
{	/* Constructor.
	 Example: serialGLCD lcd;
	 */
}

void serialGLCD::clearLCD() 
{   /* Clears the display, eraseBlock is probably faster if you dont need to erase the entire screen.
	 Example: lcd.clearLCD();
	 */  
	Serial.print(0x7C,BYTE);
	Serial.print(0x00,BYTE);
}
void serialGLCD::setDebug(int l)
{	/*
	 0 = no messages
	 1 = binary messages, the display will echo a byte = command when the command is started and a byte = 0x00 when the command is finished
	 2 = text messages, useful when using a terminal. will echo "Entered Command n" when command n is started
	 and will echo "Exited Command n, RX_buffer=y" when the command is done, and will report how many bytes are in the recieve buffer
	 Example: lcd.setDebug(1);
	 */
	Serial.print(0x7C,BYTE);
	Serial.print(0x01,BYTE);
	relayHex(l);
}
void serialGLCD::backLight(int x) 
{   /* Sets backlight duty cycle. 0-100, 0=off.
	 Example: lcd.backLight(50);
	 */
	Serial.print(0x7C,BYTE);
	Serial.print(0x02,BYTE);
	relayHex(x);
}
void serialGLCD::drawCircle(int x, int y, int r, int z) 
{   /* Draws a circle at (x,y) with radius r, draw/erase 
	 Example: lcd.drawCircle(30,30,10,1);
	 */
	Serial.print(0x7C,BYTE);
	Serial.print(0x03,BYTE);
	relayHex(x);
	relayHex(y);
	relayHex(r);
	relayHex(z);
}
void serialGLCD::toggleCRLF()
{	/* Toggles CR/LF. each time this command is sent, 
	 wheather or not a CR automatically executes a LF is toggled. 
	 this is saved to EEPROM and is persistant over power cycles.
	 Example: lcd.toggleCRLF();
	 */
	Serial.print(0x7C,BYTE);
	Serial.print(0x04,BYTE);
}
void serialGLCD::eraseBlock(int x1, int y1, int x2, int y2) 
{	/* Draws a block on the screen with clear or set pixels (depending on if the screen is inverted or not)
	 Example: lcd.eraseBlock(10,10,20,20);
	 */
	Serial.print(0x7C,BYTE);
	Serial.print(0x05,BYTE);
	Serial.write(x1);
	Serial.write(y1);
	Serial.write(x2);
	Serial.write(y2);
}
void serialGLCD::resetLCD() 
{	/* Resets the LCD, clears the screen and resets x,y offsets to 0,0
	 Example: lcd.resetLCD();
	 */
	Serial.print(0x7C,BYTE);
	Serial.print(0x06,BYTE);
}
void serialGLCD::changeBaud(int x)
{	/* Changes the baudrate.
	 1=4800
	 2=9600
	 3=19200
	 4=38400
	 5=57600
	 6=115200
	 Persistant over power-cycles. Transmitting to the screen during splash resets the baudrate to 115200
	 Example: lcd.changeBaud(2); // (9600)
	 */
	if(x<1) {
		x=1;
	}
	if(x>6) {
		x=6;
	}
	Serial.print(0x7C,BYTE);
	Serial.print(0x07,BYTE);
	relayHex(x);
}
void serialGLCD::toggleFont()
{	/* Toggles between the standard and AUX font. Only affects text written after the command.
	 Example: lcd.toggleFont();
	 */
	Serial.print(0x7C,BYTE);
	Serial.print(0x08,BYTE);
}
void serialGLCD::setFontMode(int x)
{	/* Sets the mode for which text is written to the text.
	 0= AND
	 1= NAND
	 2= OR
	 3= NOR
	 4= XOR
	 5= NXOR
	 6= don't uses this one, will result in corrupted characters
	 7= COPY (this is the default, overwrites whatever is in the background, and is the only one that respects reverse)
	 Example: lcd.setFontMode(2); // (AND)
	 */
	Serial.print(0x7C,BYTE);
	Serial.print(0x0A,BYTE);
	relayHex(x);
}
void serialGLCD::drawSprite(int x, int y, int n, int mode)
{	/* Draws a sprite saved in the backpack. x and y sets the upper left corner, 
	 n is the number of the stored sprite, n sets the mode (same modes ad text).
	 sprite 0 is the sparkfun logo, other uploaded sprites will be deleted if power is removed.
	 Example: lcd.drawSprite(10,10,0,7); // Draws the sparkfun logo
	 */
	Serial.print(0x7C,BYTE);
	Serial.print(0x0B,BYTE);
	relayHex(x);
	relayHex(y);
	relayHex(n);
	relayHex(mode);
}
void serialGLCD::drawLine(int x1, int y1, int x2, int y2, int z) 
{	/* Draws a line from x1,y1 to x2,y2. z=1 to draw, z=0 to erase.
	 Example: lcd.drawLine(10,10,20,20,1); 
	 */
	Serial.print(0x7C,BYTE);
	Serial.print(0x0C,BYTE);
	relayHex(x1);
	relayHex(y1);
	relayHex(x2);
	relayHex(y2);
	relayHex(z);
}
void serialGLCD::uploadSprite(int n, int w, int h, byte *data)
{	/* Uploads a sprite to the backpack, data must be 32 bytes long. 8 sprites can be stored (0-7).
	 The sparkfun logo is number 0, can be overwritten but reverts when power is removed. 
	 All uploaded sprites will be erased upon removal of power
	 Consult with firmware README for more info
	 Example: byte logo[] = {
	 0x80,0xc0,0x40,0x0c,0x3e,0xfe,0xf2,0xe0,0xf0,0xe0,
	 0xff,0x7f,0x3f,0x1f,0x1f,0x1f,0x1f,0x0f,0x07,0x03,
	 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	 0x00,0x00};
	 lcd.uploadSprite(7,10,16,logo); // Uploads the sparkfun logo as sprite number 7
	 */
	Serial.print(0x7C,BYTE);
	Serial.print(0x0D,BYTE);
	relayHex(n);
	relayHex(w);
	relayHex(h);
	for(int x = 0; x < 32;x++)
	{
		Serial.print(data[x],BYTE);
	}
}
void serialGLCD::drawBox(int x1, int y1, int x2, int y2, int z) 
{	/* Draws a rectangle starting from x1,y1 to x2,y2. z=1 for draw, z=0 for erase.
	 Example: lcd.drawBox(10,10,20,20,1);
	 */
	Serial.print(0x7C,BYTE);
	Serial.print(0x0F,BYTE);
	relayHex(x1);
	relayHex(y1);
	relayHex(x2);
	relayHex(y2);
	relayHex(z);
}
void serialGLCD::togglePixel(int x, int y, int z) 
{     /* Toggles a pixel. x and y for coord, z=1 sets, z=0 erases.
	   Example: lcd.togglePixel(30,30,1);
	   */
	Serial.print(0x7C,BYTE);
	Serial.print(0x10,BYTE);
	if(x > 127) {
		relayHex(127);
	}
	else if(x < 1) {
		relayHex(1);
	}
	else {
		relayHex(x);
	}
	if(y > 63) {
		relayHex(63);
	}
	else if(y < 1) {
		relayHex(1);
	}
	else {
		relayHex(y);
	}
	if(z != 1 && z != 0) {
		relayHex(1);
	}
	else {
		relayHex(z);
	}
}
void serialGLCD::drawFilledBox(int x1, int y1, int x2, int y2, byte fill)
{	/* Same as drawBox, but accepts a fill byte. 0xFF for black, 0x00 for white. 
	 Other values can be used to create patterns (like 0x55). 
	 Example: drawFilledBox(10,10,20,20,0xFF);
	 */
	Serial.print(0x7C,BYTE);
	Serial.print(0x12,BYTE);
	relayHex(x1);
	relayHex(y1);
	relayHex(x2);
	relayHex(y2);
	Serial.print(fill,BYTE);
	
}
void serialGLCD::reverseColor() 
{	/* Reverses the "color" (black on white / white on black)
	 Example: lcd.reverseColor();
	 */
	Serial.print(0x7C,BYTE);
	Serial.print(0x14,BYTE);
}
void serialGLCD::toggleSplash()
{	/* Toggles the sparkfun logo during boot.
	 Example: lcd.toggleSplash();
	 */
	Serial.print(0x7C,BYTE);
	Serial.print(0x15,BYTE);
}
void serialGLCD::drawData(int x, int y, int mode, int w, int h, byte *data, int length)
{	/* Allows you to draw graphics to the screen like sprites, but the data doesn't have to be uploaded first, and there is no size
	 restrictions.(other than the drawable area of the display). 
	 Requires the length of the data array in addition to the data (found no other way of doing this..)
	 Consult with firmware README for more info
	 Example:
	 byte data[]={0x00,0x12.....};
	 int length = sizeof(sprite);
	 lcd.drawData(0,0,4,128,64,data,length); 
	 */
	Serial.print(0x7C,BYTE);
	Serial.print(0x16,BYTE);
	relayHex(x);
	relayHex(y);
	relayHex(mode);
	relayHex(w);
	relayHex(h);
	for(x = 0; x < length; x++) {
		Serial.print(data[x],BYTE);
	}
}
void serialGLCD::gotoPosition(int x, int y) 
{  	/* Sets the x and y offsets, text written after this command will start from x,y.
	 Example: lcd.gotoPosition(40,40);
	 */
	Serial.print(0x7C,BYTE);
	Serial.print(0x18,BYTE);
	relayHex(x);
	Serial.print(0x7C,BYTE);
	Serial.print(0x19,BYTE);
	relayHex(y);
}
void serialGLCD::gotoLine(int line)
{	/* Uses the gotoPosition function to select "line" 1-8 on the display. 
	 Text can be written between these lines using gotoPosition. This function makes it simpler.
	 Example: lcd.gotoLine(2);
	 */
	int y;
	if(line > 8) {
		line = 8;
	}
	else if(line < 1) {
		line = 1;
	}
	else {
		y = -8 + line * 8;
		gotoPosition(1,y);
	}
}
void serialGLCD::relayHex( int x ) 
{   /* Converts DEC to HEX, then prints it through serial. Used by the library*/
	byte hex[] = {
		0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 
		0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 
		0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F, 
		0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F, 
		0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 
		0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F, 
		0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F, 
		0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F, 
		0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 
		0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F, 
		0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5  };
	
	delayMicroseconds(650);
	Serial.print(hex[x],BYTE);
}



