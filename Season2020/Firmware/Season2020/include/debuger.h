#ifndef DEBUGER_H
#define DEBUGER_H

//#include "mbed.h"
#include "SerialSet.h"

#define INTLIMIT 255
#define DECLIMIT 65535

extern bool debug_request_flg;
extern bool start_sigh_flg;
extern bool debug_flg;
extern int c;

void DebugToW(double *motor1 ,double *motor2);
void DebugThW(double *motor1 ,double *motor2 ,double *motor3);
void DebugFW(double *motor1 ,double *motor2 ,double *motor3 ,double *motor4);
void DebugPID(double *Pgain ,double *Igain ,double *Dgain);
void DebugEnd();
void FractionTx(double value);
int RangeFlood(double value);
void Txd(int D);
void getGain(char *G);

#endif