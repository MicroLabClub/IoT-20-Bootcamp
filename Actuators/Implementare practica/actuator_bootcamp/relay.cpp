#include "relay.h"
#include "Arduino.h" 
int relayCurrentState;
void RelaySetup() {
  pinMode(RELAY_PIN, OUTPUT);
}

void RelaySetValue(int value) {
  //saturatie semnal de intrare
  if (value > RELAY_VAL_MAX) {
    //limitare la val. maxima
    value = RELAY_VAL_MAX;
  }
  else if (value < RELAY_VAL_MIN) {
    //limitare la val. minim
    value = RELAY_VAL_MIN;
  }
  //aplica valoare catre actuator
  if (value != RELAY_OFF) {
    digitalWrite(RELAY_PIN, HIGH) ;
  }
  else {
    digitalWrite(RELAY_PIN, LOW);
  }
  relayCurrentState = value;

}
int RelayGetValue(void){
  return relayCurrentState;
  }
