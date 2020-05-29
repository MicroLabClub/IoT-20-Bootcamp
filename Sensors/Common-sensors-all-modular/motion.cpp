#include "motion.h"



//==================================
// PIR virtual device driver
//==================================

void SetupPIR() {
  pinMode(PIR_PIN, INPUT);
}

float ReadPIR() {
  // read the state of the sensor/digital input
  int sensorState = digitalRead(PIR_PIN);
  return sensorState;
}
//==================================//
