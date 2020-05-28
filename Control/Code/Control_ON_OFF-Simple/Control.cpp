#include "Control.h"
#include "Arduino.h"


int ControlOnOff_Simple(float currentTemp, int controlOut) {

  Serial.println("Control_ON-OFF_Simple");
  if (currentTemp > CONTROL_MAX_TEMP) {

    controlOut = CONTROL_ON;
    Serial.println("Relay on");
  }
  else {
    Serial.println("Relay off");
    controlOut = CONTROL_OFF;
  }
  return controlOut;
}

int ControlOnOff_Hysteresis(float currentTemp, int controlOut) {
  Serial.println("Control_ON-OFF_Hysteresis");

  if (currentTemp > CONTROL_MAX_TEMP) {
    
    Serial.println("Relay on");
    controlOut = CONTROL_ON;
  }
  else if (currentTemp < CONTROL_MIN_TEMP) {
    
    Serial.println("Relay off");
    controlOut = CONTROL_OFF;
  }
  else {
    //nu facem nimic- isi parstreaza starea anterioara
  }
  return controlOut;
}
