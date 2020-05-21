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


void SetupTMP36() {
  pinMode(TEMPERATURE_TMP36_PIN, INPUT);
}


float GetTemperatureTMP36(void) {
  int rawData = analogRead(TEMPERATURE_TMP36_PIN);
  float celsius = map(((rawData - 20) * 3.04), ADC_MIN, ADC_MAX, TEMP_MIN, TEMP_MAX);

  //return temperature;
  return celsius;
}

void setup() {
  Serial.begin(9600);
  SetupTMP36();
}

void loop() {
  float temp = GetTemperatureTMP36();
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print("degrees celsius");
  Serial.println();
  delay(500);
}
