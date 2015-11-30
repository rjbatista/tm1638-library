# TM1638/TM1640 library #

This is a library for interacting an arduino with a TM1638/TM1640 module.

The [TM1638 module](http://www.dealextreme.com/p/81873?r=68099021) is a module with 8x 7-segment display (8 digits), 8x 2 color (red and green) LED and 8x buttons and is controlled using serial commands.

The TM1638 module is designed to be chainable. It uses only one pin for _clock_, one pin for _data_ and an additional pin (_strobe_) for each module you chain up to 6... that's a total of 8 pins for controlling 48 (8x6) 7-segment digits, 48 buttons and 96 LEDs (48 red and 48 green).

Great to use as a "helper/debugging" module.

The [TM1640 module](http://www.dealextreme.com/p/104311?r=68099021) is a module with 16x 7-segment display (8 digits) and is controlled using serial commands.


# Usage #

This library is designed to allow usage of simultaneous independent modules (chained or unchained).

Basic usage is (after including "TM1638.h"):
```
TM1638 module(8, 9, 7);
```

This defines a module with data on pin 8, clock on pin 9 and strobe on pin 7.

Chaining modules is as easy as:
```
TM1638 module1(8, 9, 7);
TM1638 module2(8, 9, 6);
```

This defines two modules with data on pin 8, clock on pin 9 and strobes on pin 6 and 7.

There is also support for inverted TM1638 modules. They are used just like regular TM1638 and can be instantiated (after including "InvertedTM1638.h") with:
```
InvertedTM1638 module(8, 9, 7);
```

The TM1640 modules are used just like regular TM1638 and can be instantiated (after including "TM1640.h") with:
```
TM1640 module(8, 9);
```


# Library Reference #

[Full Reference](TableOfContents.md)

## Constructors ##

[Default Constructor](DefaultConstrutor.md)

## Methods ##

| **Method** | **Description** |
|:-----------|:----------------|
| [clearDisplay](clearDisplay.md) | Clears the display. (TM1638/TM1640) |
| [clearDisplayDigit](clearDisplayDigit.md) | Clear a single 7-segment display. (TM1638/TM1640) |
| [getButtons](getButtons.md) | Returns the pressed buttons as a bit set (left to right). (TM1638) |
| [setDisplay](setDisplay.md) | Set the 7-segment displays to the 8 values (left to right). (TM1638/TM1640) |
| [setDisplayDigit](setDisplayDigit.md) | Set a single display to a digit. (TM1638/TM1640) |
| [setDisplayToBinNumber](setDisplayToBinNumber.md) | Set the display to a binary number. (TM1638) |
| [setDisplayToDecNumber](setDisplayToDecNumber.md) | Set the display to a unsigned decimal number, with or without leading zeros. (TM1638) |
| [setDisplayToSignedDecNumber](setDisplayToSignedDecNumber.md) | Set the display to a signed decimal number, with or without leading zeros. (TM1638) |
| [setDisplayToError](setDisplayToError.md) | Set the display to an error message. (TM1638/TM1640) |
| [setDisplayToHexNumber](setDisplayToHexNumber.md) | Set the display to a unsigned hexadecimal number, with or without leading zeros. (TM1638) |
| [setDisplayToString(char\*)](setDisplayToString.md) | Set the display to the string. (TM1638/TM1640) |
| [setDisplayToString(String)](setDisplayToString2.md) | Set the display to the string. (TM1638/TM1640) |
| [setLED](setLED.md) | Controls a LED. (TM1638) |
| [setLEDs](setLEDs.md) | Set all the LEDs. (TM1638) |
| [setupDisplay](setupDisplay.md) | Set the display (all 7-segments) and LEDs on or off and the specifies the intensity. (TM1638/TM1640) |