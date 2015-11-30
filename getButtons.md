# getButtons Reference (TM1638) #

Returns the pressed buttons as a bit set (left to right).

```
byte getButtons();
```

| Argument | Detail | Default |
|:---------|:-------|:--------|
|          |        |         |

# Example #

The expression is true if the leftmost button is pressed:
```
module1.getButtons() == 0b00000001
```

The expression is true if the rightmost button is pressed:
```
module1.getButtons() == 0b10000000
```

The expression is true if both middle buttons are pressed:
```
module1.getButtons() == 0b00011000
```