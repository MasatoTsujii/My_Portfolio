#include "pid.h"

double PID(int target, int position, int address){

	double presentdef;
	static double pastdef[ACTUATE_COUNT];
	static double defsum[ACTUATE_COUNT];
	static short targetsave = 0;
	static short addresssave = 0;
	double operationvalue = 0;
	
	presentdef = (double)(target - position);
	defsum[address] += presentdef;
	if(target != targetsave && address != addresssave)defsum[address] = 0;
	
	operationvalue += Pgain[address]*presentdef;
	operationvalue += Igain[address]*defsum[address];
	operationvalue -= Dgain[address]*(presentdef - pastdef[address]);
	
	targetsave = target;
	addresssave = address;
	pastdef[address] = presentdef;
	
	return operationvalue;
}