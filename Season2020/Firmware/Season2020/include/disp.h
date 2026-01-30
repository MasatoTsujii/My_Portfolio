#ifndef DISP_H
#define DISP_H
//#include "mbed.h"
#include "SerialSet.h"

void txd(char D);
void txvalue(unsigned char D);
void dnl();
void putstr(char *TXDATA);
void disp(long int D);
void comma();
int advancedDisp(double opr, int pre);

#endif