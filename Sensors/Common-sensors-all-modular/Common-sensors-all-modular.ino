/**
 * 1. Identificam device driver (libraria Arduino de pe net)
 * 2. Definim virtual device driver (functie generala cu prototip identic la toti sensorii)
 * 3. Definim structura sensorType cu cimpurile referinta la functie si unitate de masura
 * 4. Definim un tablou de sensori sensorList
 * 5. Definim functia generala de extragere a valorii dupa id (pozitia in tablou)
 */

#include "distance.h"
#include "light.h"
#include "motion.h"
#include "temperature.h"

typedef struct sensor_t {
  float (*get) (void);
  char paramName[20];
  char unitName[10];
} sensorType;

enum { SENSOR_TEMP,SENSOR_LIGHT, SENSOR_PIR, SENSOR_ULTRASONIC, SENSOR_NR_OF };


sensorType sensorList[SENSOR_NR_OF] = {
  {
    GetTemperatureTMP36,
    "Temperature", 
    "celsius"
  },
  {
    GetLight,
    "Light intensity",
    "points"    
  },
  {
    ReadPIR,
    "Motion",
    "yes/no",
  },
  {
    GetDistance,
    "Distance",
    "cm"
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
  LightSensorSetup();
  SetupPIR();
  UltrasonicSetup();
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
