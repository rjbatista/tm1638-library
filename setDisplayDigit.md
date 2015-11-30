# setDisplayDigit Reference (TM1638/TM1640) #

Set a single display to a digit.

```
void setDisplayDigit(byte digit, byte pos, boolean dot, const byte numberFont[]);
```

| Argument | Detail | Default | Since |
|:---------|:-------|:--------|:------|
| digit    | The digit to set | _required_ |       |
| pos      | The 7-segment display to set. 0 for the leftmost, 7 for the rightmost | _required_ |       |
| dot      | The dot status for the display | _required_ |       |
| numberFont | The font (segment data) to use for numbers, defaulting to the built-in font. | NUMBER\_FONT, the built-in number font | v1.5.0 |

# Example #

Set the leftmost display to a "6.":
```
module1.setDisplayDigit(6, 0, true);
```