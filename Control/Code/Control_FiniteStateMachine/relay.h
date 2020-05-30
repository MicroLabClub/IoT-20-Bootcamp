#ifndef RELAY_H_
//exludem includerea multipla
#define RELAY_H_

#define RELAY_VAL_MAX 1
#define RELAY_VAL_MIN 0
#define RELAY_OFF 0
#define RELAY_ON 1
#define RELAY_PIN 2

void RelaySetup();
void RelaySetValue(int value);
int RelayGetValue(void);

#endif
