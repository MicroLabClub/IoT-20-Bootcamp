#include "actuator.h"
#include "relay.h"
#include "myservo.h"
#include "dcmotor.h"


actType actList[ACT_NR_OF] = {
  {
    RelaySetValue,
    RelayGetValue,
    "State", 
    "",
    0
  },
  {
    ServoSetAngle,
    ServoGetAngle,
    "Angle",
    "grd" ,
    0   
  },
  {
    MotorSetPower,
    MotorGetPower,
    "Power",
    "%",
    0
  }
  
 };

int ActGetValue(int id) {
  if (id < ACT_NR_OF) {
    return actList[id].get();
  }
}

char * ActGetUnit(int id) {
  if (id < ACT_NR_OF) {
    return actList[id].unitName;
  }
}

char * ActGetParamName(int id) {
  if (id < ACT_NR_OF) {
    return actList[id].paramName;
  }
}

void ActSetValue(int id, int value) {
  if (id < ACT_NR_OF) {
    return actList[id].set(value);
  }
}
