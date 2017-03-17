/*
i2cdetect.h - Arduino library for scanning I2C bus for devices
*/

#ifndef __I2CDETECT_H_
#define __I2CDETECT_H_

#include <Wire.h>

void i2cdetect(TwoWire &wire = Wire, uint8_t first = 0x03, uint8_t last = 0x77);

#endif
