//#include "sixaxis_ide.h"		// Additional Header

#include "dualshock.h"

int circle;
int triangle;
int square;
int cross;
int right;
int up;
int left;
int down;
int r1;
int r2;
int l1;
int l2;
int sleep;
int mode;

int jsrx;
int jsry;
int jslx;
int jsly;

int updataState(int *rcv)
{
	int err;
	err = checkSum(rcv);
	if(err != -1){
		updateButtonState(rcv[1], rcv[2]);
		updateJoyStickState(rcv[3], rcv[4], rcv[5], rcv[6]);
	}
	return err;
}

void updateButtonState(int button_state_higher, int button_state_lower)
{
	int button_state = 0x0000;
	button_state = (button_state_higher << 8) | button_state_lower;
	circle   = is(button_state & CIRCLE);
	triangle = is(button_state & TRIANGLE);
	square   = is(button_state & SQUARE);
	cross    = is(button_state & CROSS);
	right    = is(button_state & RIGHT);
	up       = is(button_state & UP);
	left     = is(button_state & LEFT);
	down     = is(button_state & DOWN);
	r1       = is(button_state & R1);
	r2       = is(button_state & R2);
	l1       = is(button_state & L1);
	l2       = is(button_state & L2);
	sleep    = is(button_state & SLEEP);
	mode     = is(button_state & MODE);
}

void updateJoyStickState(int _jsrx, int _jsry, int _jslx, int _jsly)
{
	jsrx = _jsrx - 127;
	jsry = _jsry - 127;
	jslx = _jslx - 127;
	jsly = _jsly - 127;
}

int checkSum(int *rcv)
{
	int i,sum = 0;
	for(i = 0;i < 7;i++){
		sum += rcv[i] >> 1;
	}
	return (((sum % 0xFF)|0x01) == rcv[7]) ? 0 : -1;
}


int is(int n)
{
	return !!n;
}
