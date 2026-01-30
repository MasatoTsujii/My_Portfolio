#include <math.h>
#include "iodefine.h"
#include "define.h"
#include "disp.h"
#include "general.h"
#include "OmnidirectionalDriver.h"

double to_deg(double r);
int i_abs(int num);
int map(double n, double from_min, double from_max, double to_min, double to_max);

void smooth(int* control, int js){
	int difference = 0;
	
	if(i_abs(*control)>50){
		difference = 5;
	}else if(i_abs(*control)>100){
		difference = 7;
	}else{
		difference = 10;
	}
	if(js>*control){
		*control += difference;
		if(js<*control)	*control = js;
	}
	if(js<*control){
		*control -= difference;
		if(js>*control)	*control = js;
	}
}

void lipo_fire(int* x, int* y, int flag){
	
	double rad;
	
	if(flag){
		if(x!=0)		rad = atan2((double)(*y), (double)(*x));
		
		if((0<*x) && (0<*y)){
			if(to_deg(rad)>=45.0)	*x = 0;
			else			*y = 0;
		}else if((*x<0) && (0<*y)){
			if(to_deg(rad)<=135.0)	*x = 0;
			else			*y = 0;
		}else if((0<*x) && (*y<0)){
			if(to_deg(rad)<=-45.0)	*x = 0;
			else			*y = 0;
		}else if((*x<0) && (*y<0)){
			if(to_deg(rad)>=-135.0)	*x = 0;
			else			*y = 0;
		}
	}
}

void anomalyOmnidirectionalDriver(double x, double y, double r, int* velocity, int slow_flag){
	
	//const double gainx_right_half[WHEEL_COUNT] = {1.000, 1.000, 1.000, 1.000};
	//const double gainx_left_half[WHEEL_COUNT] = {1.000, 1.000, 1.000, 1.000};
	const double gainy_progress_half[WHEEL_COUNT] = {1.058*1.092, 1.043*1.000, 1.000*1.092, 1.000*1.000};
	const double gainy_reverse_half[WHEEL_COUNT] = {1.055*1.100, 1.004*1.000, 1.000*1.100, 1.000*1.000};
	
	const double gainx_right[WHEEL_COUNT] = {1.058*1.100, -1.004*1.100, -1.000*1.000, 1.000*1.000};
	const double gainx_left[WHEEL_COUNT] = {1.055*1.130, -1.043*1.130, -1.000*1.000, 1.000*1.000};
	const double gainy_progress[WHEEL_COUNT] = {1.06*1.02, 1.00*1.00, 1.00*1.02, 1.00*1.00};
	const double gainy_reverse[WHEEL_COUNT] = {1.06*1.08, 1.00*1.00, 1.00*1.08, 1.00*1.00};
	const double gainr[WHEEL_COUNT] = {1.00, -1.00, 1.00, -1.00};
	
	double spd[WHEEL_COUNT]={0};
	double max_spd = 0.0;
	double fast;
	/*double stop = 0.0;
	double unit_circle = 0.0;
	double rad = 0.0;*/
	int i;
	
	for(i=0; i<WHEEL_COUNT; i++){
		if(slow_flag==1){
			if(x>0)			spd[i] = x*gainx_right/*_half*/[i];
			else if(x<0)		spd[i] = x*gainx_left/*_half*/[i];
			else			spd[i] = 0.0;
			if(y>0)			spd[i] += y*gainy_progress_half[i];
			else if(y<0)		spd[i] += y*gainy_reverse_half[i];
			else			spd[i] += 0.0;
		}else if(slow_flag==0){
			if(x>0)			spd[i] = x*gainx_right[i];
			else if(x<0)		spd[i] = x*gainx_left[i];
			else			spd[i] = 0.0;
			if(y>0)			spd[i] += y*gainy_progress[i];
			else if(y<0)		spd[i] += y*gainy_reverse[i];
			else			spd[i] += 0.0;
		}
		if(slow_flag==0)		spd[i] = spd[i] * TRANSLATIONAL_VELOCITY_RATIO + r*gainr[i] * ROTATIONAL_VELOCITY_RATIO;
		else if(slow_flag==1)		spd[i] = spd[i] * TRANSLATIONAL_VELOCITY_RATIO_HALF + r*gainr[i] * ROTATIONAL_VELOCITY_RATIO;
		else if(slow_flag==2)		spd[i] = 0.00;
		
		fast = (spd[i]>0) ? spd[i]:-spd[i];
		if(fast>max_spd) max_spd = fast;
	}
	
	if(SPEED_LIMIT<max_spd){
		for(i=0; i<WHEEL_COUNT; i++){
			spd[i] *= SPEED_LIMIT/max_spd;
		}
	}
	
	//unit_circle = sqrt(x*x + y*y);
	
	for(i=0; i<WHEEL_COUNT; i++){
		/*if(unit_circle!=0)	rad = asin(i_abs(y)/unit_circle);
		if(x>0)			stop = 200*sin(rad)*sin(rad)*gainx_right[i];
		else if(x<0)		stop = 200*sin(rad)*sin(rad)*gainx_left[i];
		else			stop = 0.0;
		if(y>0)			stop += 200*cos(rad)*cos(rad)*gainy_progress[i];
		else if(y<0)		stop += 200*cos(rad)*cos(rad)*gainy_reverse[i];
		else			stop += 0.0;*/
		
		velocity[i] = (i_abs(spd[i])<50) ? 0:spd[i];
	}
}

void relay_fet(int* velocity){
	
	pwm_FL = i_abs(velocity[0]);
	motor_FL_L = (velocity[0]>0);
	motor_FL_R = (velocity[0]<0);
	
	pwm_FR = i_abs(velocity[1]);
	motor_FR_L = (velocity[1]>0);
	motor_FR_R = (velocity[1]<0);
	
	pwm_BL = i_abs(velocity[2]);
	motor_BL_L = (velocity[2]>0);
	motor_BL_R = (velocity[2]<0);
	
	pwm_BR = i_abs(velocity[3]);
	motor_BR_L = (velocity[3]>0);
	motor_BR_R = (velocity[3]<0);
}

double to_deg(double r){
	return r * 180.0 / (atan(1.0) * 4.0);
}