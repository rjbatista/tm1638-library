# setLED Reference (TM1638) #

Controls a LED.

```
void setLED(byte color, byte pos);
```

| Argument | Detail | Default |
|:---------|:-------|:--------|
| color    | The color of the LED. Can be set to _TM1638\_COLOR\_RED_ (for red), _TM1638\_COLOR\_GREEN_ (for green) or both. Can be set to TM1638\_COLOR\_NONE to clear the LED. | _required_ |
| pos      | The LED to set. 0 for the leftmost, 7 for the rightmost	 | _required_ |

# Example #

Sets the leftmost LED to green:
```
module1.setLED(TM1638_COLOR_GREEN, 0);
```


Sets the leftmost LED to green **and** red:
```
module1.setLED(TM1638_COLOR_GREEN + TM1638_COLOR_RED, 0);
```



Clears the leftmost LED:
```
module1.setLED(TM1638_COLOR_NONE, 0);
```