#include "myservo.h"
#include "Servo.h"
int servoCurrentAngle = 0;
Servo myservo;

void ServoSetup(){
  myservo.attach(SERVO_PIN);
}

void ServoSetAngle(int value){
   //saturatie semnal de intrare
  if (value > SERVO_ANGLE_MAX) {
    //limitare la val. maxima
    value = SERVO_ANGLE_MAX;
  }
  else if (value < SERVO_ANGLE_MIN) {
    //limitare la val. minim
    value = SERVO_ANGLE_MIN;
  }
  //aplicam valoare catre actuator
  myservo.write(value);
  servoCurrentAngle = value;
  }

int ServoGetAngle(void){
  return servoCurrentAngle;
  }
