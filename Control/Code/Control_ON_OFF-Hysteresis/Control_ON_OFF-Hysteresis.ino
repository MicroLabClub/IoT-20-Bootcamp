#include "Relay.h"
#include "TMP36.h"
#include "Control.h"

int controlOut;
float currentTemp;
int relayState;

void setup() {
  Serial.begin(9600);
  SetupTMP36();
  RelaySetup();
}

void loop() {
  
  //primim temperatura de la sensorul de temperatura TMP35
  currentTemp = GetTemperatureTMP36();

  //control on/off cu hystereza
  controlOut = ControlOnOff_Hysteresis(currentTemp, controlOut);

  RelaySetValue(controlOut);
  Serial.print("Temperature: ");
  Serial.println(currentTemp);
  delay(500);

}
