# setDisplay Reference (TM1638/TM1640) #

Set the 7-segment displays to the 8 values (left to right)

```
void setDisplay(const byte values[]);
```

| Argument | Detail | Default |
|:---------|:-------|:--------|
| values   | The values for each of the 8 7-segment displays from the the leftmost to the rightmost. | _required_ |

# Example #

Light a single segment on each of the 7-segment displays (and only the dot on the rightmost one):
```
byte values[] = { 1, 2, 4, 8, 16, 32, 64, 128 };

module1.setDisplay(values);
```