#ifndef CONTROL_H_
#define CONTROL_H_

#define CONTROL_ON 1
#define CONTROL_OFF 0
#define CONTROL_MAX_TEMP 30
#define CONTROL_MIN_TEMP 28

int ControlOnOff_Hysteresis(float currentTemp, int controlOut);
int ControlOnOff_Simple(float currentTemp, int controlOut);

#endif
