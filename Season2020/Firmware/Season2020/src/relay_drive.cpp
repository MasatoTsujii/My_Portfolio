#include "relay_drive.h"
#include <mbed.h>
#include <math.h>
#include "init.h"
#include "omnidirectionaldriver.h"

void relay_drive(int* target){

	/*target[0] *= gainy[0];
	target[1] *= gainy[1];*/
	
	static int spd[4] = {0};
	int i;
	for(i=0; i<wheel_count; i++){
		target[i] = (abs(target[i])<100) ? 0 : target[i];

		if(spd[i]<=target[i]){
			spd[i]+=smooth;
			if(spd[i]>target[i]){
				spd[i] = target[i];
			}
		}else{
			spd[i]-=smooth;
			if(spd[i]<target[i]){
				spd[i] = target[i];
			}
		}

		if(speed_limit<abs(spd[i]))		spd[i] = (0<spd[i]) ? 10000:-10000;
		pwm_drive[i].write((double)(abs(spd[i]))/(double)(speed_limit));
		sig_drive[i*2] = (spd[i]>0);
		sig_drive[i*2+1] = (spd[i]<0);
	}
}