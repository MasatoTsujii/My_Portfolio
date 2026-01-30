#include "relay.h"
#include "iodefine.h"
void relay(int* motor){
	static int motor_val[4] = {0};
	int i;
	for(i = 0;i < 4;i++){
		motor[i] = costrain(motor[i],1919,-1919); 
		motor[i] = (abs(motor[i]) < 50) ? 0 : motor[i];
		
	}
	
	for(i = 0;i < 4;i++){
		if((i==2) && (motor_val[i]<motor[i])){
			motor_val[i] += constant_rol;
			if(motor_val[i] > motor[i]){
				motor_val[i] = motor[i];
			}
		}else{
			if(motor_val[i] > motor[i]){
				motor_val[i] -= constant;
				if(motor_val[i] < motor[i]){
					motor_val[i] = motor[i];
				}
			}
			if(motor_val[i] < motor[i]){
				motor_val[i] += constant;
				if(motor_val[i] > motor[i]){
					motor_val[i] = motor[i];
				}
			}
		}
	}
	
	PWM_VERTICAL = abs(motor_val[0]);
	SIG_VERTICAL1 = (motor_val[0] > 0);
	SIG_VERTICAL2 = (motor_val[0] < 0);
	
	PWM_ANGLE = abs(motor_val[1]);
	SIG_ANGLE1 = (motor_val[1] > 0);
	SIG_ANGLE2 = (motor_val[1] < 0);
	
	PWM_ROL = abs(motor_val[2]);
	SIG_ROL1 = abs(motor_val[2] > 0);
	SIG_ROL2 = abs(motor_val[2] < 0);
	
	PWM_BC = abs(motor_val[3]);
	SIG_BC1 = (motor_val[3] > 0);
	SIG_BC2 = (motor_val[3] < 0);
	
}
int costrain(int value,int best ,int worst){
	value = (best < value) ? best : value;
	value = (worst > value) ? worst : value;
	return value;
}