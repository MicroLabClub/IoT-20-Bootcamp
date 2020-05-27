#ifndef RELAY_H_ 
#define RELAY_H_ //exclude inluderea multipla a fisierului

#define RELAY_PIN 7
#define RELAY_VAL_MIN 0
#define RELAY_VAL_MAX 1
#define RELAY_ON 1
#define RELAY_OFF 0

void RelaySetup();
void RelaySetValue(int value);
int RelayGetValue(void);


#endif
