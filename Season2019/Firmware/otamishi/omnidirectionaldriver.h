#ifndef __OMNIDIRECTIONALDRIVER__H__
#define __OMNIDIRECTIONALDRIVER__H__

void smooth(int* control, int js);
void lipo_fire(int* x, int* y, int flag);
void anomalyOmnidirectionalDriver(double x, double y, double r, int* velocity, int slow_flag);
void relay_fet(int* velocity);
double to_deg(double r);

#endif