#include "light.h"


void LightSensorSetup() {
  pinMode(LDR_PIN, INPUT);
}

float GetLight() {
  int rawData = analogRead(LDR_PIN);
  float voltage = map(rawData, ADC_MIN, ADC_MAX, VOLT_MIN, VOLT_MAX);
  float light = map(voltage, VOLT_MIN, VOLT_MAX, LIGHT_MIN, LIGHT_MAX);
  
  return light;
}
