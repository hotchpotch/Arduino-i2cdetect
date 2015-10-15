
# Arduino-i2cdetect

Arduino-i2cdetect is scan an I2C bus for devices. Arduino-i2cdetect output same [i2cdetect command](http://www.lm-sensors.org/).

# example

```
#include <Wire.h>
#include <i2cdetect.h>

void setup() {
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  Serial.println("-- i2cdetect --");
  i2cdetect();
  delay(1000);
}
```

## output

```
-- i2cdetect --
     0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f
00:          -- -- -- -- -- -- -- -- -- -- -- -- --
10: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
20: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
30: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
40: 40 -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
50: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
60: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
70: -- -- -- -- -- -- -- --
```

