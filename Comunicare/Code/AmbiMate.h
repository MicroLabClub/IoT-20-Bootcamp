#ifndef AMBIMATE_H_
#define AMBIMATE_H_

#include "I2CSensor.h"
#include <string.h>

#define AMBIMATE_ADDR 0x2A

#define AMBIMATE_START_SCAN_REG 0xC0
#define AMBIMATE_SCANN_ALL      0xFF
#define AMBIMATE_VERS_REG       0x80
#define AMBIMATE_SUBVERS_REG    0x81 

#define AMBIMATE_DEFAULLT_VERS  28

class AmbiMate : public I2CSensor {

public:
    /**
     * @brief Construct a new AmbiMate object
     */
    AmbiMate();

    /**
     * @brief Initialize the sensor at startup
     * 
     * @return true   in case initialization succeeds
     * @return false  otherwise
     */
    bool init();

    /**
     * @brief A scan all command that tells the sensor to start measurements
     * 
     * @return true  the scan is successfull
     * @return false otherwise
     */
    bool scanAll();

    /**
     * @brief Sample all (read all values) from the sensor into local state.  Must be called after scan_all()
     * 
     * @return true  sampled successfully
     * @return false otherwise
     */
    bool sampleAll();

    /**
     * @brief Read event out pin and check if there is motion detected
     * 
     * @return true 
     * @return false 
     */

    /* Below are methods to get the state of the sensor and readings. 
     * Must be called after a sampleAll() method in order to get updated values
     */
    void    getRaw(uint8_t buff[15]);
    uint8_t getStatus();
    float   getTemperature();
    float   getHumidity();
    float   getLight();
    float   getAudio();
    float   getBattery();
    float   getECO2();
    float   getVOC();

private:

    uint8_t m_raw[15];
    uint8_t m_status;
    float m_temperature;
    float m_humidity;
    float m_light;
    float m_audio;
    float m_battery;
    float m_eco2;
    float m_voc;

    
};

#endif


