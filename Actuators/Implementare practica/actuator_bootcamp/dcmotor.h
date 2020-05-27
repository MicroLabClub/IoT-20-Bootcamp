#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#define IN1 12
#define IN2 13
#define EN 11
#define MOTOR_POWER_MIN 0
#define MOTOR_POWER_MAX 100
#define MOTOR_PWM_MIN 0
#define MOTOR_PWM_MAX 255
#define MOTOR_DIR_FWD 1
#define MOTOR_DIR_BWD (-1)
// analogRead values go from 0 to 1023, analogWrite values from 0 to 255
void MotorSetup();
void MotorSetPower(int power);
int MotorGetPower(void);




#endif
