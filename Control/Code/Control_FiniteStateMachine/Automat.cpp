#include "Automat.h"
#include "Arduino.h"



int FSM_State = READY;

STyp FSM[3] = {
  {0, 10, {READY,  READY, READY, READY, PERMIT, PERMIT, PERMIT, PERMIT}},
  {1, 10, {DENY,   DENY,  DENY,  DENY,  PERMIT, PERMIT, DENY,   DENY}},
  {2, 10, {DENY,   READY, DENY,  READY, DENY,   READY,  DENY,   READY}}
};


int automatInput(int controlOut, int TimeOutOnFlag, int TimeOutOffFlag) {
  int result;

  if (controlOut == 0 && TimeOutOnFlag == 0 && TimeOutOffFlag == 0) {
    result = 0;
  }
  else if (controlOut == 0 && TimeOutOnFlag == 0 && TimeOutOffFlag == 1) {
    result = 1;
  }
  else if (controlOut == 0 && TimeOutOnFlag == 1 && TimeOutOffFlag == 0) {
    result = 2;
  }
  else if (controlOut == 0 && TimeOutOnFlag == 1 && TimeOutOffFlag == 1) {
    result = 3;
  }
  else if (controlOut == 1 && TimeOutOnFlag == 0 && TimeOutOffFlag == 0) {
    result = 4;
  }
  else if (controlOut == 1 && TimeOutOnFlag == 0 && TimeOutOffFlag == 1) {
    result = 5;
  }
  else if (controlOut == 1 && TimeOutOnFlag == 1 && TimeOutOffFlag == 0) {
    result = 6;
  }
  else if (controlOut == 1 && TimeOutOnFlag == 1 && TimeOutOffFlag == 1) {
    result = 7;
  }
  return result;


}

int automatProcess(int controlOut, int TimeOutOnFlag, int TimeOutOffFlag) {

  int output = FSM[FSM_State].Out;
  delay(FSM[FSM_State].Time * 10);
  int input = automatInput(controlOut, TimeOutOnFlag, TimeOutOffFlag);
  FSM_State = FSM[FSM_State].Next[input];

  return output;
}
