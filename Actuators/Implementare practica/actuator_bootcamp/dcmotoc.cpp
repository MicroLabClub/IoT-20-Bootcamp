#include "dcmotor.h"
#include "Arduino.h"

int motorCurrentPower; 

void MotorSetup() {
  pinMode(EN, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
}

void MotorSetPower(int power) {
  int direction = 0;
  //detectam directia
  if (power > 0 ) {
    direction = MOTOR_DIR_FWD;
  }
  else if (power < 0) {
    direction = MOTOR_DIR_BWD;
  }
  //reducem semnul (scoatem semnul negativ)
  power *= direction;
  //saturare
  if (power > MOTOR_POWER_MAX) {
    //limitare la val. maxima
    power = MOTOR_POWER_MAX;
  }
  else if (power < MOTOR_POWER_MIN) {
    //limitare la val. minim
    power = MOTOR_POWER_MIN;
  }
  
  //convertim puterea in factor de umplere a semnalului pwm din 0 - 100 in 0 - 255
  int pwmValue = map(power, MOTOR_POWER_MIN, MOTOR_POWER_MAX, MOTOR_PWM_MIN, MOTOR_PWM_MAX);
  
  //setam directia actuatorului inainte 
  if (direction == MOTOR_DIR_FWD) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  }
  //setam rotirea inapoi
  else if (direction == MOTOR_DIR_BWD) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
  }
  //oprim actuatorul
  else {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    }
    
  //aplicam valoare de putere la actuator
  analogWrite(EN, power);
  motorCurrentPower = power;
  
}


int MotorGetPower() {
  return motorCurrentPower;
  }
