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

enum { SENSOR_TEMP,SENSOR_LIGHT, SENSOR_PIR, SENSOR_ULTRASONIC, SENSOR_NR_OF };




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
  
  
void SetupTMP36() {
  pinMode(TEMPERATURE_TMP36_PIN, INPUT);
}
  
  
float GetTemperatureTMP36(void) {
  int rawData = analogRead(TEMPERATURE_TMP36_PIN);
  float celsius = map(((rawData - 20) * 3.04), ADC_MIN, ADC_MAX, TEMP_MIN, TEMP_MAX);
  
  //return temperature;
  return celsius;
}
  
//==================================//


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
  

void LightSensorSetup() {
  pinMode(LDR_PIN, INPUT);
}

float GetLight() {
  int rawData = analogRead(LDR_PIN);
  float voltage = map(rawData, ADC_MIN, ADC_MAX, VOLT_MIN, VOLT_MAX);
  float light = map(voltage, VOLT_MIN, VOLT_MAX, LIGHT_MIN, LIGHT_MAX);
  
  return light;
}

//==================================//


//==================================
// PIR virtual device driver
//==================================

#define PIR_PIN 3

void SetupPIR() {
  pinMode(PIR_PIN, INPUT);
}

float ReadPIR() {
  // read the state of the sensor/digital input
  int sensorState = digitalRead(PIR_PIN);
  return sensorState;
}
//==================================//


//==================================
// Ultrasonic virtual device driver
//==================================

// defines pins numbers
#define TRIG_PIN 7
#define ECHO_PIN 6

// defines variables
long duration;
int distance;

void UltrasonicSetup() {
  pinMode(TRIG_PIN, OUTPUT); // Sets the TRIG_PIN as an Output
  pinMode(ECHO_PIN, INPUT); // Sets the ECHO_PIN as an Input
}

float GetDistance() {
  // Clears the TRIG_PIN
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  // Sets the TRIG_PIN on HIGH state for 10 micro seconds
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  // Reads the ECHO_PIN, returns the sound wave travel time in microseconds
  duration = pulseIn(ECHO_PIN, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  return distance;
}

//==================================//


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
