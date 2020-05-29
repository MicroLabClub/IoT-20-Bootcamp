#include "temperature.h"
  
  
void SetupTMP36() {
  pinMode(TEMPERATURE_TMP36_PIN, INPUT);
}
  
  
float GetTemperatureTMP36() {
  int rawData = analogRead(TEMPERATURE_TMP36_PIN);
  float celsius = map(((rawData - 20) * 3.04), ADC_MIN, ADC_MAX, TEMP_MIN, TEMP_MAX);
  
  return celsius;
}
  