#include "I2CSensor.h"
#include <Arduino.h>

I2CSensor::I2CSensor(uint8_t i2c_addr) {
    this->i2c_addr = i2c_addr;
}

/* Write data to a sensor register reg_addr */
bool I2CSensor::writeReg(uint8_t reg_addr, uint8_t data)
{
    Wire.beginTransmission(i2c_addr);
    Wire.write(reg_addr);
    Wire.write(data);
    return (Wire.endTransmission() == 0); // success
}

/* Read a register from the sensor */
bool I2CSensor::readReg(uint8_t reg_addr, uint8_t *dest)
{
    bool success;
    Wire.beginTransmission(i2c_addr); 
    Wire.write(reg_addr);
    success = (Wire.endTransmission() == 0);
    if (!success) {
        return false;
    }

    Wire.requestFrom(i2c_addr, 1);
    *dest = Wire.read();
    return true;
}

/* Read multiple registers from the sensor into the buffer
    Note: it makes sense only in case the sensors support autoincrement of index on reading */
bool I2CSensor::readMultiple(uint8_t addr, uint8_t buff[], uint8_t len)
{
    uint8_t i;
    for (i = 0; i < len; i++) {
        readReg(addr + i, &buff[i]);
    }
    
    return true;
}
