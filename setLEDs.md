# setLEDs Reference (TM1638) #

Set all the LEDs.

```
void setLEDs(word led);
```

| Argument | Detail | Default |
|:---------|:-------|:--------|
| led      | The LEDs to set. MSB byte for the green LEDs, LSB for the red LEDs. | _required_ |

# Example #

Light up all the red LEDs.
```
module1.setLEDs(0x00FF);
```

Light up all the green LEDs.
```
module1.setLEDs(0xFF00);
```

Light up all the LEDs.
```
module1.setLEDs(0xFFFF);
```