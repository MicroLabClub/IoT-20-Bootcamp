#ifndef AUTOMAT_H_
#define AUTOMAT_H_


#define READY 0
#define PERMIT 1
#define DENY 2

struct State {
  unsigned int Out;
  unsigned int Time;
  unsigned int Next[8];
};

typedef struct State STyp;

int automatInput(int controlOut, int TimeOutOnFlag, int TimeOutOffFlag);
int automatProcess(int controlOut, int TimeOutOnFlag, int TimeOutOffFlag);

#endif
