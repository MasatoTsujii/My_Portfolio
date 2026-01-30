#ifndef __INTRRUPT__H
#define __INTRRUPT__H

extern int data[10];
extern int monitoring;
extern int monitoring_Dynamixel;
extern int monitoring_ArmUnit;
extern int Wait_ArmUnit;

void ArmData_Switch_L(void);
void timer(void);
void data_receive(void);
void attachInterrupt(void);

#endif