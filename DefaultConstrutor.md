# Default Construtor Reference #

Instantiate a TM1638 module specifying the display state, the starting intensity and the _data_, _clock_ and _stobe_ pins.

```
TM1638(byte dataPin, byte clockPin, byte strobePin, boolean activateDisplay, byte intensity);
```

For the inverted module

```
InvertedTM1638(byte dataPin, byte clockPin, byte strobePin, boolean activateDisplay, byte intensity);
```

For the TM1640 module

```
TM1640(byte dataPin, byte clockPin, boolean activateDisplay, byte intensity);
```

| Argument | Detail | Default |
|:---------|:-------|:--------|
| dataPin  | The pin to use for Data I/O | _required_ |
| clockPin  | The pin to use for Clock | _required_ |
| strobePin | The pin to use for Strobe (selector) | _required_ |
| activateDisplay | True to activate display on constructing, false otherwise. | true    |
| intensity | The starting intensity from 0 (lowest) to 7 (highest) | 7       |


# Example #

Define a module on data pin 8, clock pin 9 and strobe pin 7:
```
TM1638 module1(8, 9, 7);
```

Define a module on data pin 8, clock pin 9 and strobe pin 6, with the display inactive at start:
```
TM1638 module2(8, 9, 6, false);
```

Define a module on data pin 8, clock pin 9 and strobe pin 5, with the display active and the starting intensity at 1:
```
TM1638 module3(8, 9, 5, true, 1);
```

Define an inverted module on data pin 8, clock pin 9 and strobe pin 4, with the display active and the starting intensity at 1:
```
InvertedTM1638 module4(8, 9, 4, true, 1);
```

Define an TM1640 module on data pin 8 and clock pin 9 with the display active and the starting intensity at 1:
```
TM1640 module5(8, 9, true, 1);
```