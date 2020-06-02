#ifndef I2CSENSOR_H_
#define I2CSENSOR_H_

#include <Wire.h>

class I2CSensor 
{

public:
    I2CSensor(uint8_t i2c_addr);

    /**
     * @brief Sensor dependent method for initialization
     * 
     * @return true  if sensor is initialized properly
     * @return false otherwise
     */
    virtual bool init() = 0;

    /**
     * @brief Write data to a sensor register
     * 
     * @param reg_addr sensor's register address
     * @param data data to be written
     * @return success or fail 
     */
    bool writeReg(uint8_t reg_addr, uint8_t data);

    /**
     * @brief Read data from a sensor register
     * 
     * @param reg_addr sensor's register address
     * @param dest pointer to a variable where data will be written to
     * @return sucess or fail 
     */
    bool readReg(uint8_t reg_addr, uint8_t *dest);

    /**
     * @brief  Read multiple registers from the sensor into the buffer
     * Note: it makes sense only in case the sensors support autoincrement of index on reading
     * 
     * @param addr address of the first register in the sequence
     * @param buff destination buffer
     * @param len  number of bytes to be read
     * @return succes or fail 
     */
    bool readMultiple(uint8_t addr, uint8_t buff[], uint8_t len);

private:
    uint8_t i2c_addr; 
};


#endif