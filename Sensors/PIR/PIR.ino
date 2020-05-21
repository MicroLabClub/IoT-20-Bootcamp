// https://www.instructables.com/id/PIR-Motion-Sensor-With-Arduino-in-Tinkercad/

#define PIR_PIN 3

void SetupPIR() {
  pinMode(PIR_PIN, INPUT);
}

int ReadPIR() {
  // read the state of the sensor/digital input
  int sensorState = digitalRead(PIR_PIN);
  return sensorState;
}

void setup()
{
  Serial.begin(9600);
  SetupPIR();
  // Init LED
  //  pinMode(13, OUTPUT);
}

void loop()
{
  
  
    Serial.print("PIR State: ");
    int state = ReadPIR();
    Serial.print(state);
    if (state == HIGH) {
      Serial.println();
      Serial.print("MOVED!");
    }
    Serial.println();

  // check if sensor pin is HIGH. if it is, set the
  // LED on.
  //  if (sensorState == HIGH) {
  //    digitalWrite(13, HIGH);
  //    Serial.println("Moved!");
  //    Serial.println("Sensor activated!");
  //  } else {
  //    digitalWrite(13, LOW);
  // 
  //}

    delay(300); // Delay a little bit to improve simulation performance
}
