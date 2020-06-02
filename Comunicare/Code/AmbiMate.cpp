#include "AmbiMate.h"

AmbiMate::AmbiMate(): I2CSensor(AMBIMATE_ADDR) {
 
}


bool AmbiMate::init() 
{
    uint8_t   version;
    uint8_t   subversion;
    bool      success;

    success = readReg(AMBIMATE_VERS_REG, &version);
    success = readReg(AMBIMATE_SUBVERS_REG, &subversion) & success;
    
    // Example of initialization, version could be checked for example
    version = version * 10 + subversion;
    if (!success || (version != AMBIMATE_DEFAULLT_VERS)) {
        return false;  
    }
    return true;
}

bool AmbiMate::scanAll() 
{
    bool success;
    success = writeReg(AMBIMATE_START_SCAN_REG, AMBIMATE_SCANN_ALL);
    return success;
}

bool AmbiMate::sampleAll() 
{

    bool success;
    success = readMultiple(0x00, m_raw, 15);
    if (!success) {
        return false;
    }

    m_status      = m_raw[0];
    m_temperature = (m_raw[1] << 8 | m_raw[2])/10.0;
    m_humidity    = (m_raw[3] << 8 | m_raw[4])/10.0;
    m_light       = (float) (m_raw[5] << 8 | m_raw[6]);
    m_audio       = (float) (m_raw[7] << 8 | m_raw[8]);
    m_battery     = ((m_raw[9] << 8 | m_raw[10])/1024.0) * (3.3 / 0.330);
    m_eco2        = (float) (m_raw[11] << 8 | m_raw[12]);
    m_voc         = (float) (m_raw[13] << 8 | m_raw[14]);

    return true;
}

void AmbiMate::getRaw(uint8_t buff[15])
{
    memcpy(buff, m_raw, 16);
}

uint8_t AmbiMate::getStatus() {
    return m_status;
}

float AmbiMate::getTemperature() {
    return m_temperature;
}

float AmbiMate::getHumidity() {
    return m_humidity;
}

float AmbiMate::getLight() {
    return m_light;
}

float AmbiMate::getAudio() {
    return m_audio;
}

float AmbiMate::getBattery() {
    return m_battery;
}

float AmbiMate::getECO2() {
    return m_eco2;
}

float AmbiMate::getVOC() {
    return m_voc;
}
