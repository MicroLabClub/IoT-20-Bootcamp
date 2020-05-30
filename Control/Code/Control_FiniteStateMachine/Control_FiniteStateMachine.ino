#include "relay.h"
#include "control.h"
#include "timer-api.h"
#include "Automat.h"
#include "TMP36.h"

float currentTemp;
int relayState;
int controlOut;
int automatOut;


void setup() {

  Serial.begin(9600);
  RelaySetup();
  SetupTMP36();
  timer_init_ISR_1KHz(TIMER_DEFAULT);

}

#define SECOND 1000
#define TIMEOUT_ON (10*SECOND)
#define TIMEOUT_OFF (5*SECOND)
volatile unsigned long TimeOutOn = TIMEOUT_ON;
volatile unsigned long TimeOutOff = TIMEOUT_OFF;
int TimeOutOnFlag = 0;
int TimeOutOffFlag = 0;

void timer_handle_interrupts(int timer) {

  //evolutia timer-ului prin epuizarea timpului
  if (TimeOutOn > 0) TimeOutOn--;
  if (TimeOutOff > 0) TimeOutOff--;

  //detectare TimeOut
  TimeOutOnFlag = (TimeOutOn == 0) ? 1 : 0;
  TimeOutOffFlag = (TimeOutOff == 0) ? 1 : 0;

  //reinitializare
  if (automatOut == READY) {
    TimeOutOn = TIMEOUT_ON;
  }
  if (automatOut == PERMIT) {
    TimeOutOff = TIMEOUT_OFF;
  }
}

void loop() {
  //achizitii de la sensor
  currentTemp = GetTemperatureTMP36();

  //evaluarea functie de control on-off cu histereza
  controlOut = ControlOnOff_Hysteresis(currentTemp, controlOut);

  automatOut = automatProcess(controlOut, TimeOutOnFlag, TimeOutOffFlag);

  if (automatOut == PERMIT) {
    //aplicam valoarea pe actuator
    RelaySetValue(controlOut);
  }
  else {
    RelaySetValue(RELAY_OFF);
  }

  //raportare
  Serial.print("Temperature: ");
  Serial.println(currentTemp);
  relayState = RelayGetValue();
  Serial.print("Relay State: ");
  Serial.println(relayState);
  int input = automatInput(controlOut, TimeOutOnFlag, TimeOutOffFlag);
  Serial.print("Automat Input: ");
  Serial.println(input);
  Serial.print("Automat Output: ");
  Serial.println(automatOut);
  Serial.println();
  delay(500);
}
