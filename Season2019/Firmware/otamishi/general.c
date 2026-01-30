#include "general.h"

int i_abs(int num){
	return (num>=0) ? num:-num;
}

int is(int num){
	return !!num;
}

int map(double num, double from_min, double from_max, double to_min, double to_max){
	return (num - from_min) * (to_max - to_min) / (from_max - from_min) + to_min;
}