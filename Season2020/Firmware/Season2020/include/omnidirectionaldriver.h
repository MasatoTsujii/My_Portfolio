#ifndef __OMNIDIRECTIONALDRIVER_H
#define __OMNIDIRECTIONALDRIVER_H

extern const int speed_limit;
extern const int wheel_count;
extern const int smooth;
extern double gainx[];  
extern double gainy[];
extern double gainr[];

void anomalyOmnidirectionalDriver(double x, double y, double r, int* velocity);
 
#endif