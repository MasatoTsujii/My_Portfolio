#include <mbed.h>
#include "init.h"
#include "vs_disp.h"
#include "interrupt.h"
#include "DualShock.h"
#include "Dynamixel.h"
#include "LineTrace.h"
#include "PIDcontroller.h"

int data[10] = {0};
int monitoring = 0;
int monitoring_Dynamixel = 0;
int monitoring_ArmUnit = 0;
int Wait_ArmUnit = 0;

void data_receive(void){

	static int receive_byte = 0;
	unsigned char receive;

	monitoring = 0;
	DualShock.read(&receive, 1);
	switch(receive&0x07){
		
		case 0x01:
		data[2] = receive;
		break;
		case 0x02:
		data[3] = receive;
		break;
		case 0x03:
		data[4] = receive;
		break;
		case 0x04:
		data[5] = receive;
		break;
		case 0x05:
		data[6] = receive;
		break;
		case 0x06:
		data[7] = receive;
		break;
		case 0x07:
		data[8] = receive;
		break;
		case 0x00:
		if((receive&0x08)==0x08)	data[1] = receive;
		else						data[0] = receive;
		break;
	}
	receive_byte++;
	if(receive_byte==9){
		updataState(data);
		receive_byte = 0;
	}
}

void timer(void){

	monitoring++;
	Wait_ArmUnit++;
	monitoring_ArmUnit++;
	monitoring_Dynamixel++;
  	balance_p = trace.compute();
	if(1000<=monitoring){
		circle_button   = 0;
		cross_button    = 0;
		triangle_button = 0;
		square_button   = 0;
		left_button  = 0;
		right_button = 0;
		up_button    = 0;
		down_button  = 0;
		l1_button = 0;
		l2_button = 0;
		l3_button = 0;
		r1_button = 0;
		r2_button = 0;
		r3_button = 0;
		ps_button = 0;
		start_button  = 0;
		select_button = 0;
		joystick_rx = 0;
		joystick_ry = 0;
		joystick_lx = 0;
		joystick_ly = 0;
	}
}

void attachInterrupt(){
    DualShock.attach(data_receive, UnbufferedSerial::RxIrq);
    Timer_interrupt.attach(&timer, 1ms);
  	//traceControl.attach(&trace_PID, 0.001);
}