# clearDisplayDigit Reference (TM1638/TM1640) #

Clear a single 7-segment display.

```
void clearDisplayDigit(byte pos, boolean dot);
```

| Argument | Detail | Default |
|:---------|:-------|:--------|
| pos      | The display to clear, starting at position 0 (leftmost). | _required_ |
| dot      | The dot state on the 7-segment display | _required_ |

# Example #

Clear the second 7-segment display (counting from the left), but leave the dot lit.
```
module1.clearDisplayDigit(1, true);
```

Clear the third 7-segment display (counting from the left), including the dot.
```
module1.clearDisplayDigit(2, false);
```