/**
 * 1. Identificam device driver (libraria Arduino de pe net)
 * 2. Definim virtual device driver (functie generala cu prototip identic la toti sensorii)
 * 3. Definim structura sensorType cu cimpurile referinta la functie si unitate de masura
 * 4. Definim un tablou de sensori sensorList
 * 5. Definim functia generala de extragere a valorii dupa id (pozitia in tablou)
 */

typedef struct sensor_t {
  float (*get) (void);
  char paramName[20];
  char unitName[10];
} sensorType;

enum { SENSOR_TEMP, SENSOR_NR_OF };




//==================================
// TMP36 virtual device driver
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


void SetupTMP36() {
  pinMode(TEMPERATURE_TMP36_PIN, INPUT);
}


float GetTemperatureTMP36(void) { 
  float celsius = map(((rawData - 20) * 3.04), ADC_MIN, ADC_MAX, TEMP_MIN, TEMP_MAX);

  return celsius;
}
//==================================//


//==================================
// Other sensors
//==================================

//==================================//

sensorType sensorList[SENSOR_NR_OF] = {
  {
    GetTemperatureTMP36,
    "Temperature", 
    "celsius"
  }
 };

float SensorGetValue(int id) {
    if(id < SENSOR_NR_OF) {
      return sensorList[id].get();
    }
}

char * SensorGetUnit(int id) {
    if(id < SENSOR_NR_OF) {
      return sensorList[id].unitName;
    }
}

char * SensorGetParamName(int id) {
    if(id < SENSOR_NR_OF) {
      return sensorList[id].paramName;
    }
}


void setup() {
  Serial.begin(9600);
  SetupTMP36();
}

void loop() {
//  float value = SensorGetValue(SENSOR_TEMP);  
//  Serial.print(value);
//  
//  char * unit = SensorGetUnit(SENSOR_TEMP);
//  Serial.print(" ");
//  Serial.print(unit);

  for(int i=0; i<SENSOR_NR_OF; i++) {
    char * paramName = SensorGetParamName(i);
    Serial.print(paramName);
    Serial.print(": ");
    
    float value = SensorGetValue(i);  
    Serial.print(value);

    char * unit = SensorGetUnit(i);
    Serial.print(" ");
    Serial.print(unit);
    Serial.print(" , ");
  }
  Serial.println();
  delay(200);
  
}
