#ifndef LINETRACE_H
#define LINETRACE_H

#define STRAIGHT_VELOC 6000
#define FACE_DARK      0.8500
#define COMMAND_NUM    21       //予選:19　決勝:21

extern int s;
extern short StopCount;
extern double P, I, D;
extern double x;
extern float tclock;
extern float val[2];
extern int target[2];
extern float sp;
extern float balance_p;

void LineTrace_Setting(void);
void LineTrace(void);

#endif