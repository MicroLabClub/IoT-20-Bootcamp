/**
 * 1. Identificam device driver (libraria Arduino de pe net)
 * 2. Definim virtual device driver (functie generala cu prototip identic la toti sensorii)
 * 3. Definim structura sensorType cu cimpurile referinta la functie si unitate de masura
 * 4. Definim un tablou de sensori sensorList
 * 5. Definim functia generala de extragere a valorii dupa id (pozitia in tablou)
 */
typedef float phySignal;
typedef int idType ;
typedef phySignal (*getSensorType) (void);

typedef struct sensor_t {
  getSensorType get;
  char paramName[20];
  char unitName[10];
} sensorType;

enum { SENSOR_TEMP, SENSOR_NR_OF };




//==================================
// TMP36 virtual device driver
//==================================
// Sensor pin map
#define TEMPERATURE_TMP36_PIN A0
// ADC range
#define ADC_MIN 0
#define ADC_MAX 1023
// Voltage range
#define VOLT_MIN 0
#define VOLT_MAX 5
// Temperature range
#define TEMP_MIN 0
#define TEMP_MAX 10


void SetupTMP36() {
  pinMode(TEMPERATURE_TMP36_PIN, INPUT);
}


phySignal GetTemperatureTMP36(void) {
  int rawTemp = analogRead(TEMPERATURE_TMP36_PIN);
  phySignal voltage = map(rawTemp, VOLT_MIN, VOLT_MAX, ADC_MIN, ADC_MAX);
  phySignal temperature = map(rawTemp, TEMP_MIN, TEMP_MAX, VOLT_MIN, VOLT_MAX);
  return temperature;
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

phySignal SensorGetValue(idType id) {
    if(id < SENSOR_NR_OF) {
      return sensorList[id].get();
    }
}

char * SensorGetUnit(idType id) {
    if(id < SENSOR_NR_OF) {
      return sensorList[id].unitName;
    }
}

char * SensorGetParamName(idType id) {
    if(id < SENSOR_NR_OF) {
      return sensorList[id].paramName;
    }
}


void setup() {
  Serial.begin(9600);
  SetupTMP36();
}

void loop() {
//  phySignal value = SensorGetValue(SENSOR_TEMP);  
//  Serial.print(value);
//  
//  char * unit = SensorGetUnit(SENSOR_TEMP);
//  Serial.print(" ");
//  Serial.print(unit);

  for(int i=0; i<SENSOR_NR_OF; i++) {
    char * paramName = SensorGetParamName(i);
    Serial.print(paramName);
    Serial.print(": ");
    
    phySignal value = SensorGetValue(i);  
    Serial.print(value);

    char * unit = SensorGetUnit(i);
    Serial.print(" ");
    Serial.print(unit);
    Serial.print(" , ");
  }
  Serial.println();
  delay(200);
  
}
