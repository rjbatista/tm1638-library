# setDisplayToBinNumber Reference (TM1638) #

Set the display to a binary number.

```
void setDisplayToBinNumber(byte number, byte dots, const byte numberFont[]);
```

| Argument | Detail | Default | Since |
|:---------|:-------|:--------|:------|
| number   | The number to display | _required_ |       |
| dots     | The dots to set (bitwise) | _required_ |       |
| numberFont | The font (segment data) to use for numbers, defaulting to the built-in font. | NUMBER\_FONT, the built-in number font | v1.5.0 |

# Example #

Display "1.0.1.0.1.0.1.0.":
```
module1.setDisplayToBinNumber(0b10101010, 0xFF);
```

Display 15 in binary with no dots:
```
module1.setDisplayToBinNumber(15, 0);
```