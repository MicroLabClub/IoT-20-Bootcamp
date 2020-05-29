#ifndef LIGHT_H
#define LIGHT_H

#include <Arduino.h>

//==================================
// Light LDR virtual device driver
//==================================
#define LDR_PIN A0
#define LIGHT_MIN 10
#define LIGHT_MAX 100
#define ADC_MIN 0
#define ADC_MAX 1023
#define VOLT_MIN 0
#define VOLT_MAX 5


// Prototipurile functiilor
void LightSensorSetup();
float GetLight();

#endif
