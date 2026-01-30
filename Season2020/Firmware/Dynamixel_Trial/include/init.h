#ifndef __INIT__H
#define __INIT__H
#include "mbed.h"

extern UnbufferedSerial DualShock;
extern UnbufferedSerial Arm_L;
extern UnbufferedSerial Arm_R;
extern DigitalOut UartChange;
extern DigitalIn DT_Switch;
extern DigitalIn DT_SpeedSwitch;
extern DigitalIn DT_ActionButton;
extern DigitalIn PointButton;
extern DigitalIn DT_ResetButton;
extern DigitalIn Change_Next;
extern DigitalIn Change_Prev;
extern DigitalOut LED_7seg[7];
extern DigitalIn DIP_INPUT[4];
extern AnalogIn Arm_volume;
extern PwmOut pwm_Arm;
extern DigitalOut sig_Arm[2];

extern int circle;
extern int cross;
extern int triangle;
extern int square;
extern int l;
extern int r;
extern int up;
extern int down;
extern int l1;
extern int l2;
extern int l3;
extern int r1;
extern int r2;
extern int r3;
extern int ps;
extern int start;
extern int slct;
extern int jsrx;
extern int jsry;
extern int jslx;
extern int jsly;

void init(void);
void Button_JoyStick(void);

#endif