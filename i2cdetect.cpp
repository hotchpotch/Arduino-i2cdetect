
#include <Wire.h>
#include <Arduino.h>
#include "i2cdetect.h"

// _printf base code: http://playground.arduino.cc/Main/Printf
#include <stdarg.h>
#define PRINTF_BUF 80 // define the tmp buffer size (change if desired)
void _printf(const char *format, ...)
{
  char buf[PRINTF_BUF];
  va_list ap;
  va_start(ap, format);
  vsnprintf(buf, sizeof(buf), format, ap);
  for(char *p = &buf[0]; *p; p++) // emulate cooked mode for newlines
  {
    if(*p == '\n')
      Serial.write('\r');
    Serial.write(*p);
  }
  va_end(ap);
}

void i2cdetect(uint8_t first, uint8_t last) {
  uint8_t i, j, address, error;

  // header
  Serial.print("   ");
  for (i = 0; i < 16; i++) {
    printf("%3x", i);
  }
  Serial.println("");

  for (j = 0; j < 8; j++) {
    _printf("%02d:", j*10);
    for (i = 0; i < 16; i++) {
      address = i + j*16;
      if (address >= first && address <= last) {
        Wire.beginTransmission(address);
        error = Wire.endTransmission();
        if (error) {
          Serial.print(" --");
        } else {
          _printf(" %02x", address);
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

