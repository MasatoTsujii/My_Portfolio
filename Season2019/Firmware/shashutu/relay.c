#include "relay.h"
#include "iodefine.h"
void relay(int* motor){
	static int motor_val[7] = {0};
	int i;
	for(i = 0;i < 7;i++){
		motor[i] = costrain(motor[i],1919,-1919); 
		motor[i] = (abs(motor[i]) < 150) ? 0 : motor[i];
		
	}
	for(i = 0;i <= 3;i++){
		motor_val[i] = motor[i];
	}
	
	for(i = 4;i < 7;i++){
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
		
	
	pwm_f = abs(motor_val[0]);
	STG_f1 = (motor_val[0] > 0);
	STG_f2 = (motor_val[0] < 0);
	
	pwm_r = abs(motor_val[1]);
	STG_r1 = (motor_val[1] > 0);
	STG_r2 = (motor_val[1] < 0);
	
	pwm_b = abs(motor_val[2]);
	STG_b1 = (motor_val[2] > 0);
	STG_b2 = (motor_val[2] < 0);
	
	pwm_l = abs(motor_val[3]);
	STG_l1 = (motor_val[3] > 0);
	STG_l2 = (motor_val[3] < 0);
	
	
	PWM_dozer = abs(motor_val[4]);
	STG_dozer1 = (motor_val[4] > 0);
	STG_dozer2 = (motor_val[4] < 0);
	
	PWM_roller1 = abs(motor_val[5]);
	
	
	PWM_roller2 = abs(motor_val[6]);
	
	
}
int costrain(int value,int best ,int worst){
	value = (best < value) ? best : value;
	value = (worst > value) ? worst : value;
	return value;
}