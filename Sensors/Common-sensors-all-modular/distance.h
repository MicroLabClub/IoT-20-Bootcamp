#ifndef DISTANCE_H
#define DISTANCE_H

#include <Arduino.h>

// defines pins numbers
#define TRIG_PIN 7
#define ECHO_PIN 6

// Prototipurile functiilor
void UltrasonicSetup();
float GetDistance();

#endif
