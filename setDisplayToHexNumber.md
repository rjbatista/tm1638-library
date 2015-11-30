# setDisplayToHexNumber Reference (TM1638) #

Set the display to a unsigned hexadecimal number, with or without leading zeros.

```
void setDisplayToHexNumber(unsigned long number, byte dots, boolean leadingZeros, const byte numberFont[]);
```

| Argument | Detail | Default | Since |
|:---------|:-------|:--------|:------|
| number   | The number to display | _required_ |       |
| dots     | The dots to set (bitwise) | _required_ |       |
| leadingZeros | _true_ to display leading zeros, false otherwise | true    |       |
| numberFont | The font (segment data) to use for numbers, defaulting to the built-in font. | NUMBER\_FONT, the built-in number font | v1.5.0 |

# Example #

Display "00000A1A.":
```
module1.setDisplayToHexNumber(0x0a1a, 1);
```

Display 15 in hexadecimal with no dots and no leading zeroes:
```
module1.setDisplayToHexNumber(15, 0, false);
```