/*
TM1638.h - Library for TM1638.

Copyright (C) 2011 Ricardo Batista <rjbatista at gmail dot com>

Based on a sketch by: Martin Hubacek (http://www.martinhubacek.cz)

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

#ifndef TM1638_h
#define TM1638_h

#include <WProgram.h>
#include "TM1638Fonts.h"

#define TM1638_COLOR_RED    1
#define TM1638_COLOR_GREEN  2

class TM1638
{
  public:
    /** Instantiate a tm1638 module specifying the display state, the starting intensity (0-7) data, clock and stobe pins. */
    TM1638(byte dataPin, byte clockPin, byte strobePin, boolean activateDisplay = true, byte intensity = 7);

    /** Set the display (segments and LEDs) active or off and intensity (range from 0-7). */
    void setupDisplay(boolean active, byte intensity);

    /** Set the display to a unsigned hexadecimal number */
    void setDisplayToHexNumber(unsigned long number, byte dots);
    /** Set the display to a unsigned decimal number */
    void setDisplayToDecNumber(unsigned long number, byte dots);
    /** Set the display to a unsigned binary number */
    void setDisplayToBinNumber(byte number, byte dots);
    /** Set a single display at pos (starting at 0) to a digit (left to right) */ 
    void setDisplayDigit(byte digit, byte pos, boolean dot);
    /** Set the display to the 8 values (left to right) */
    void setDisplay(const byte values[]);
    /** Clear the display */
	void clearDisplay();
    /** Set the display to the string (defaults to built in font) */
	void setDisplayToString(const char* string, const byte font[] = FONT_DEFAULT);

    /** Set the LED at pos to color (TM1638_COLOR_RED, TM1638_COLOR_GREEN or both) */
    void setLED(byte color, byte pos);
    /** Set the LEDs. MSB byte for the green LEDs, LSB for the red LEDs */
    void setLEDs(word led);

    /** Returns the pressed buttons as a bit set (left to right). */
    byte getButtons();

  protected:
    void sendCommand(byte led);
    void sendData(byte add, byte data);
    void send(byte data);
    byte receive();

  private:
    byte dataPin;
    byte clockPin;
    byte strobePin;
};

#endif

