#ifndef MYSERVO_H_
#define MYSERVO_H_

#define SERVO_PIN 9
#define SERVO_ANGLE_MAX 135
#define SERVO_ANGLE_MIN 30

void ServoSetup();
void ServoSetAngle(int value);
int ServoGetAngle(void);

#endif
