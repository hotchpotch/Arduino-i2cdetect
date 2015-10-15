
#include <Wire.h>
#include <Arduino.h>
#include "i2cdetect.h"

void i2cdetect(uint8_t first, uint8_t last) {
  uint8_t i, j, address, error;

  // header
  Serial.print("   ");
  for (i = 0; i < 16; i++) {
    Serial.printf("%3x", i);
  }
  Serial.println("");

  for (j = 0; j < 8; j++) {
    Serial.printf("%02d:", j*10);
    for (i = 0; i < 16; i++) {
      address = i + j*16;
      if (address >= first && address <= last) {
        Wire.beginTransmission(address);
        error = Wire.endTransmission();
        if (error) {
          Serial.print(" --");
        } else {
          Serial.printf(" %02x", address);
        }
      } else {
        Serial.print("   ");
      }
    }
    Serial.println("");
  }
}

void i2cdetect() {
  i2cdetect(0x03, 0x77);
}

