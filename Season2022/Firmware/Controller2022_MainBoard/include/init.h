#ifndef __INIT_H
#define __INIT_H

#include <mbed.h>
#include "IM920s.h"
#include "CRotaryEncoder.h"
#include "Adafruit_ILI9341.h"

#define ControlCycle 50000  //1000000 = 1.0s

extern DigitalIn TactSW[9];
extern DigitalIn ToggleSW[10];
extern DigitalIn changeSW;

//Speed Controller
extern AnalogIn SC[2];
extern AnalogIn JSL[2];
extern AnalogIn JSR[2];

extern CRotaryEncoder Pitch[2];

extern UnbufferedSerial LEDBus;

extern Timer t;

bool ControlFlg(void);
void init(void);
//extern CRotaryEncoder Pitch1;
//extern CRotaryEncoder Pitch2;
//extern CRotaryEncoder Yaw;
/*
extern bool ControlFlg;

void init(void);
void raiseFlg(void);*/

#endif