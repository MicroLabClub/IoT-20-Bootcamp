#ifndef ACTUATOR_H_
#define ACTUATOR_H_

typedef struct actuator_t {
  void (*set) (int value);
  int (*get) (void);
  char paramName[20];
  char unitName[10];
  int currentValue;
} actType;

enum { ACT_RELAY, ACT_SERVO, ACT_DC, ACT_NR_OF };

int ActGetValue(int id);
void ActSetValue(int id, int value);
char * ActGetUnit(int id);
char * ActGetParamName(int id);
#endif
