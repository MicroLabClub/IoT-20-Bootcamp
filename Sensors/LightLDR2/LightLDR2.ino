#define LDR_PIN A0
#define LIGHT_MIN 10
#define LIGHT_MAX 100
#define ADC_MIN 0
#define ADC_MAX 1023
#define VOLT_MIN 0
#define VOLT_MAX 5
  

void LightSensorSetup() {
  pinMode(LDR_PIN, INPUT);
}

float GetLight() {
  int rawData = analogRead(LDR_PIN);
  float voltage = map(rawData, ADC_MIN, ADC_MAX, VOLT_MIN, VOLT_MAX);
  float light = map(voltage, VOLT_MIN, VOLT_MAX, LIGHT_MIN, LIGHT_MAX);
  
  return light;
}

void setup() {
  Serial.begin(9600);
  LightSensorSetup();
}

void loop() {

  Serial.print("Light value: ");
  float light = GetLight();
  Serial.print(light);
  Serial.println();
  delay(200);

}
