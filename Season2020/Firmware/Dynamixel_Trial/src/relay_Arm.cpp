#include "mbed.h"
#include "init.h"
#include "relay_Arm.h"

void relay_Arm(int target){

	static int spd = 0;
    const int speed_limit = 10000;

	target = (abs(target)<100) ? 0 : target;

	if(spd<=target){
		if(spd<0)	spd += Smooth*4;
		else		spd += Smooth;
		//spd+=Smooth;

		if(spd>target){
			spd = target;
		}
	}else{
		if(0<spd)	spd -= Smooth*4;
		else		spd -= Smooth;
		//spd+=Smooth;

		if(spd<target){
			spd = target;
		}
	}

	pwm_Arm.write((double)(abs(spd))/(double)(speed_limit));
	sig_Arm[0] = (spd>0);
	sig_Arm[1] = (spd<0);
}