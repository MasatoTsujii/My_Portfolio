/**
 * omnidirectionaldriver.c
 *
 *  Ver.3.0     2017.09.19
 *
 *  Abouters,Inc.  mrtb
 */
     
#include <stdlib.h>
#include <math.h>
#include "omnidirectionaldriver.h"
     
void anomalyOmnidirectionalDriver(double x, double y, double r, int* velocity){
     
    ////option///////////////////////////////////////////////////////////////
     
    #define WHEEL_COUNT     4
     
    #define TRANSLATIONAL_VELOCITY_RATIO    12.0
    #define ROTATIONAL_VELOCITY_RATIO       2.0
     
    #define SPEED_LIMIT     1919.0
     
    const double gainx[WHEEL_COUNT] = {1.21,-1.00,  1.00,  -1.00};
    const double gainy[WHEEL_COUNT] ={-1.10,-1.00, 1.00,   0.90};
 
    const  double gainr[WHEEL_COUNT] = {-1.25,-1.00,-1.00, -1.00};
 
    /////////////////////////////////////////////////////////////////////////
     
    double spd[WHEEL_COUNT]={0};
    double max_spd = 0;
    int i;
    for(i=0; i<WHEEL_COUNT; i++){
        double fast;
        spd[i] = (x*gainx[i] + y*gainy[i]) * TRANSLATIONAL_VELOCITY_RATIO + r*gainr[i] * ROTATIONAL_VELOCITY_RATIO;
        fast = (spd[i]>0) ? spd[i] : -spd[i];
        if(fast>max_spd) max_spd = fast;
    }
    if(SPEED_LIMIT<max_spd){
        for(i=0;i<WHEEL_COUNT;i++){
            spd[i] *= SPEED_LIMIT/max_spd;
        }
    }
    for(i=0; i<WHEEL_COUNT; i++){
        velocity[i] = spd[i];
    }
}