/*
TM16XX.h - Library for TM1638.

Copyright (C) 2011 Ricardo Batista <rjbatista at gmail dot com>

This program is free software: you can redistribute it and/or modify
it under the terms of the version 3 GNU General Public License as
published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef TM16XX_h
#define TM16XX_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "TM16XXFonts.h"

class TM16XX
{
  public:
    /**
     * Instantiate a tm16xx module specifying the number of displays, display state,
     * the starting intensity (0-7) data, clock and stobe pins.
     */
    TM16XX(byte dataPin, byte clockPin, byte strobePin, byte displays, boolean activateDisplay = true,
    	byte intensity = 7);

    /** Set the display (segments and LEDs) active or off and intensity (range from 0-7). */
    virtual void setupDisplay(boolean active, byte intensity);

    /** Set a single display at pos (starting at 0) to a digit (left to right) */
    virtual void setDisplayDigit(byte digit, byte pos, boolean dot, const byte numberFont[] = NUMBER_FONT);
	/** Set the display to an error message */
	virtual void setDisplayToError();
	/** Clear  a single display at pos (starting at 0, left to right) */ 
    virtual void clearDisplayDigit(byte pos, boolean dot);
    /** Set the display to the values (left to right) */
    virtual void setDisplay(const byte values[], unsigned int length = 8);
    /** Clear the display */
	virtual void clearDisplay();

    /** Set the display to the string (defaults to built in font) */
	virtual void setDisplayToString(const char* string, const word dots = 0, const byte pos = 0,
		const byte font[] = FONT_DEFAULT);
    /** Set the display to the String (defaults to built in font) */
	virtual void setDisplayToString(String string, const word dots = 0, const byte pos = 0,
		const byte font[] = FONT_DEFAULT);

  protected:
	#if defined(ARDUINO) && ARDUINO >= 100
		// pure virtual is NOT supported in older Arduino IDE
		virtual void sendChar(byte pos, byte data, boolean dot) = 0;
	#else
		virtual void sendChar(byte pos, byte data, boolean dot);
	#endif
	
	
    virtual void sendCommand(byte led);
    virtual void sendData(byte add, byte data);
    virtual void send(byte data);
    virtual byte receive();

    byte displays;
    byte dataPin;
    byte clockPin;
    byte strobePin;
};

#endif
