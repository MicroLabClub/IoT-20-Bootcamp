#include "relay.h"

void setup() {
  Serial.begin(9600);
  RelaySetup();

}

void loop() {
  //  RelaySetValue(RELAY_ON);
  //  Serial.println("Relay turns on");
  //  delay(2000);
  //  RelaySetValue(RELAY_OFF);
  //  Serial.println("Relay turns off");
  //  delay(2000);
  if (Serial.available()) {
    char cmd = Serial.read();
    switch (cmd) {
    case 'q':
      RelaySetValue(RELAY_ON);
      Serial.println("Relay turns on");
      break;
    case 'a':
      RelaySetValue(RELAY_OFF);
      Serial.println("Relay turns off");

    }


  }
}
