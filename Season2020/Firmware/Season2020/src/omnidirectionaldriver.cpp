#include "omnidirectionaldriver.h"
#include <mbed.h>
#include <stdlib.h>
#include <math.h>

#define TRANSLATIONAL_VELOCITY_RATIO    60
#define ROTATIONAL_VELOCITY_RATIO       60

const int speed_limit = 10000;
const int wheel_count = 2;
const int smooth = 5000;

////option///////////////////////////////////////////////////////////////
double gainx[2] = { 1.00, -1.00};
double gainy[2] = { 0.656 ,/*0.85*/1.38};
double gainr[2] = { 1.00, 1.00};
////////////////////////////////////////////////////////////////////////

void anomalyOmnidirectionalDriver(double x, double y, double r, int* velocity){
   
    double spd[wheel_count]={0};
    double max_spd = 0.0;
    double fast;
    int i;
    for(i=0; i<wheel_count; i++){
        spd[i] = (x*gainx[i] + y*gainy[i]) * TRANSLATIONAL_VELOCITY_RATIO + r*gainr[i] * ROTATIONAL_VELOCITY_RATIO;
        fast = (spd[i]>0) ? spd[i] : -spd[i];
        if(fast>max_spd) max_spd = fast;
    }
    if(speed_limit<max_spd){
        for(i=0;i<wheel_count;i++){
            spd[i] *= speed_limit/max_spd;
        }
    }
    for(i=0; i<wheel_count; i++){
        velocity[i] = spd[i];
    }
}