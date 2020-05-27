#include "myservo.h"
void setup() {
  Serial.begin(9600);
  ServoSetup();
  ServoSetAngle(0);

}
#define DELTA_ANGLE 5
void loop() {
//  for (int i = 0; i <= 180; i++)
//  {
//    ServoSetAngle(i);
//    delay(20);
//  }
//  for (int i = 180; i >= 0; i--)
//  {
//    ServoSetAngle(i);
//    delay(20);
//  }

if (Serial.available()) {
    char cmd = Serial.read();
    int myAngle;
    switch (cmd) {
    case 'w':
      myAngle = ServoGetAngle();
      myAngle+=DELTA_ANGLE;
      ServoSetAngle(myAngle);
      Serial.println("Actuator step up");
      delay(200);
      break;
    case 's':
      myAngle = ServoGetAngle();
      myAngle-=DELTA_ANGLE;
      ServoSetAngle(myAngle);
      Serial.println("Actuator step down");
      delay(200);
      break;

    }


  }

}
