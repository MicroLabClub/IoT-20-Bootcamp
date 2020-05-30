#ifndef TMP36_H_
#define TMP36_H_

#define TEMPERATURE_TMP36_PIN A0
// ADC range
#define ADC_MIN 0
#define ADC_MAX 1023
// Voltage range
#define VOLT_MIN 0
#define VOLT_MAX 5
// Temperature range
#define TEMP_MIN -40
#define TEMP_MAX 125

void SetupTMP36();
float GetTemperatureTMP36(void);

#endif
