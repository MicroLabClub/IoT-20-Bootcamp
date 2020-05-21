
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

void setup() {
  Serial.begin(9600);
  UltrasonicSetup();
}

void loop() {
    float distance = GetDistance();
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println();
    delay(400);
}
