# setupDisplay Reference (TM1638/TM1640) #

Set the display (all 7-segments) and LEDs on or off and the specifies the intensity.

```
void setupDisplay(boolean active, byte intensity);
```

| Argument | Detail | Default |
|:---------|:-------|:--------|
| active   | _true_ for on, _false_ for off | _required_ |
| intensity | The starting intensity from 0 (lowest) to 7 (highest)  | _required_ |

# Example #

Activate display at maximum intensity:
```
module1.setupDisplay(true, 7);
```


Inactivate the display and set the intensity to the lowest:
```
module1.setupDisplay(false, 0);
```