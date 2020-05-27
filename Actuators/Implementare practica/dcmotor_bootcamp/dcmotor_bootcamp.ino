#include "dcmotor.h"
#define DELTA_POWER 15
void setup()
{
  Serial.begin(9600);
  MotorSetup();
  MotorSetPower(0);
  Serial.println("DC Motor a fost configurat");
  Serial.println("Tasta E pentru -- rotire  motorul inainte.");
  Serial.println(" Tasta D pentru -- rotire inapoi");
}
void loop() {
//    for (int i = 0; i <= 180; i++)
//    {
//      ServoSetPower(i);
//      delay(15);
//    }
//    for (int i = 180; i >= 0; i--)
//    {
//      ServoSetPower(i);
//      delay(15);
//    }
  if (Serial.available()) {
    char cmd = Serial.read();
    int myPower;
    switch (cmd) {
      case 'e':
        myPower = MotorGetPower();
        myPower+=DELTA_POWER;
        MotorSetPower(myPower) ;
        Serial.print("Motor step up ");
        Serial.println(myPower);
        break;
      case 'd':
        myPower = MotorGetPower() ;
        myPower-=DELTA_POWER;
        MotorSetPower(myPower);
        Serial.print("Motor step down ");
        Serial.println(myPower);
        break;
    }
  }
}
