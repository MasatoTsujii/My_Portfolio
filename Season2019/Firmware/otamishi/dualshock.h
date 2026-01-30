#ifndef __DUALSHOK__H__
#define __DUALSHOK__H__

#define CIRCLE		0x8000
#define TRIANGLE	0x4000
#define SQUARE		0x2000
#define CROSS		0x1000
#define RIGHT		0x0800
#define UP		0x0400
#define LEFT		0x0200
#define DOWN		0x0080
#define R1		0x0040
#define R2		0x0020
#define L1		0x0010
#define L2		0x0008
#define SLEEP		0x0004
#define MODE		0x0002

extern int circle;
extern int triangle;
extern int square;
extern int cross;
extern int right;
extern int up;
extern int left;
extern int down;
extern int r1;
extern int r2;
extern int l1;
extern int l2;
extern int sleep;
extern int mode;

extern int jsrx;
extern int jsry;
extern int jslx;
extern int jsly;

int updataState(int *rcv);
void updateButtonState(int button_state_higher, int button_state_lower);
void updateJoyStickState(int _jsrx, int _jsry, int _jslx, int _jsly);
int checkSum(int *rcv);
int is(int n);

#endif