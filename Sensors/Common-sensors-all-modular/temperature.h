#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <Arduino.h>

//==================================
// TMP36 temperature virtual device driver
//==================================
// Sensor pin map
#define TEMPERATURE_TMP36_PIN A1
// ADC range
#define ADC_MIN 0
#define ADC_MAX 1023
// Voltage range
#define VOLT_MIN 0
#define VOLT_MAX 5
// Temperature range
#define TEMP_MIN -40
#define TEMP_MAX 125


// Prototipurile functiilor
void SetupTMP36();
float GetTemperatureTMP36(); 

#endif
