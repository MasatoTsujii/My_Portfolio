#ifndef _PID_H_
#define _PID_H_

#define ACTUATE_COUNT 3
static double Pgain[ACTUATE_COUNT] = {16.00000, 15.00000, 20.00000/*, 20.00000*/};
static double Igain[ACTUATE_COUNT] = {0.004000, 0.004000, 0.009000/*, 0.000001*/};
static double Dgain[ACTUATE_COUNT] = {1.000000, 1.000000, 1.000000/*, 1.000000*/};

double PID(int, int, int);

#endif