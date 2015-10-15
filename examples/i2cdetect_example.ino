
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

