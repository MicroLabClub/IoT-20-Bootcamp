#include "actuator.h"
#include "relay.h"
#include "myservo.h"
#include "dcmotor.h"


extern actType actList[ACT_NR_OF];
#define DELTA_ANGLE 5
#define DELTA_POWER 10
void setup() {
  Serial.begin(9600);
  RelaySetup();
  ServoSetup();
  MotorSetup();

}

void loop() {
  if (Serial.available()) {
    char cmd = Serial.read();
    int myAngle;
    int myPower;
    //    switch (cmd) {
    //      case 'q':
    //        RelaySetValue(RELAY_ON) ;
    //        Serial.println("Relay turns on");
    //        break;
    //      case 'a':
    //        RelaySetValue(RELAY_OFF) ;
    //        Serial.println("Relay turns off");
    //        break;
    //      case 'w':
    //
    //        myAngle = ServoGetAngle();
    //        myAngle += DELTA_ANGLE;
    //        ServoSetAngle(myAngle) ;
    //        Serial.println("Servo Motor step up");
    //        delay(200);
    //        break;
    //      case 's':
    //        myAngle = ServoGetAngle() ;
    //        myAngle -= DELTA_ANGLE;
    //        ServoSetAngle(myAngle);
    //        Serial.println("Servo Motor step down");
    //        break;
    //       case 'e':
    //
    //        myPower = MotorGetPower();
    //        myPower+=DELTA_POWER;
    //        MotorSetPower(myPower) ;
    //        Serial.print("Motor step up ");
    //        Serial.println(myPower);
    //        break;
    //      case 'd':
    //        myPower = MotorGetPower() ;
    //        myPower-=DELTA_POWER;
    //        MotorSetPower(myPower);
    //        Serial.print("Motor step down ");
    //        Serial.println(myPower);
    //        break;
    //
    //    }
    switch (cmd) {
      case 'q':
        ActSetValue(ACT_RELAY, RELAY_ON) ;
        Serial.println("Relay turns on");
        break;
      case 'a':
        ActSetValue(ACT_RELAY, RELAY_OFF) ;
        Serial.println("Relay turns off");
        break;
      case 'w':

        myAngle = ServoGetAngle();
        myAngle += DELTA_ANGLE;
        ServoSetAngle(myAngle) ;
        Serial.println("Servo Motor step up");
        break;
      case 's':
        myAngle = ServoGetAngle() ;
        myAngle -= DELTA_ANGLE;
        ServoSetAngle(myAngle);
        Serial.println("Servo Motor step down");
        break;
      case 'e':

        myPower = MotorGetPower();
        myPower += DELTA_POWER;
        MotorSetPower(myPower) ;
        Serial.print("Motor step up ");
        Serial.println(myPower);
        break;
      case 'd':
        myPower = MotorGetPower() ;
        myPower -= DELTA_POWER;
        MotorSetPower(myPower);
        Serial.print("Motor step down ");
        Serial.println(myPower);
        break;

    }
    for (int i = 0; i < ACT_NR_OF; i++) {
      char * paramName = ActGetParamName(i);
      Serial.print(paramName);
      Serial.print(": ");

      float value = ActGetValue(i);
      Serial.print(value);

      char * unit = ActGetUnit(i);
      Serial.print(" ");
      Serial.print(unit);
      Serial.print(" , ");
    }

  }

}
