#include "init.h"
#include <mbed.h>
#include "DualShock.h"
#include "PIDcontroller.h"

UnbufferedSerial DualShock(PC_10, PC_11, 9600);

UnbufferedSerial Arm_L(PA_9, PA_10, 500000);
UnbufferedSerial Arm_R(PA_0, PA_1, 500000);
DigitalOut UartChange(PA_4);

DigitalIn DT_Switch(PA_7, PullDown);
DigitalIn DT_SpeedSwitch(PB_6, PullDown);
DigitalIn DT_ActionButton(PC_7, PullUp);
DigitalIn DT_ResetButton(PB_1, PullUp);
DigitalIn PointButton(PC_4, PullUp);
DigitalIn Change_Next(PB_13, PullUp);
DigitalIn Change_Prev(PB_2, PullUp);
DigitalIn DIP_INPUT[4] = {
	DigitalIn(PC_8, PullUp),
	DigitalIn(PB_12, PullUp),
	DigitalIn(PC_6, PullUp),
	DigitalIn(PC_9, PullUp)
};
DigitalOut LED_7seg[7] = {
	DigitalOut(PA_5),
	DigitalOut(PA_6),
	DigitalOut(PC_3),
	DigitalOut(PA_15),
	DigitalOut(PC_2),
	DigitalOut(PH_1),
	DigitalOut(PB_7)
};

AnalogIn Arm_volume(PB_0);
AnalogIn line_sensor[2] = {
	AnalogIn(PC_1),
	AnalogIn(PC_0)
};

PwmOut pwm_Arm(PA_8);
DigitalOut sig_Arm[2] = {
	DigitalOut(PB_10),
	DigitalOut(PB_4)
};
PwmOut pwm_drive[2] = {
	PwmOut(PA_11),
	PwmOut(PB_5)
};
DigitalOut sig_drive[4] = {
	DigitalOut(PA_12),
	DigitalOut(PC_5),
	DigitalOut(PB_14),
	DigitalOut(PB_15)
};

Ticker Timer_interrupt;
PID trace(0,0,0,1000);

int circle = 0;
int cross = 0;
int triangle = 0;
int square = 0;
int l = 0;
int r = 0;
int up = 0;
int down = 0;
int l1 = 0;
int l2 = 0;
int l3 = 0;
int r1 = 0;
int r2 = 0;
int r3 = 0;
int ps = 0;
int start = 0;
int slct = 0;
int jsrx = 0;
int jsry = 0;
int jslx = 0;
int jsly = 0;

void init(void){

	pwm_Arm.period_us(20);
	for(int i=0; i<2; i++){
		pwm_drive[i].period_us(20);
	}
}

void Button_JoyStick(void){
	circle = circle_button;
	cross = cross_button;
	triangle = triangle_button;
	square = square_button;
	l = left_button;
	r = right_button;
	up = up_button;
	down = down_button;
	l1 = l1_button;
	l2 = l2_button;
	l3 = l3_button;
	r1 = r1_button;
	r2 = r2_button;
	r3 = r3_button;
	ps = ps_button;
	start = start_button;
	slct = select_button;
	jslx = joystick_lx;
	jsly = joystick_ly;
	jsrx = joystick_rx;
	jsry = joystick_ry;
}