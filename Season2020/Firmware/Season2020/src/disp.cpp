#include "disp.h"

void txd(char D)
{
	SCI.write(&D, 1);
	return;
}

void txvalue(unsigned char D)
{
	if(D>=10)txd(0x3F);
	D = D+48;
	txd(D);
	return;
}

void dnl()
{
	txd((char)0x20);
	txd((char)0x0D);
	txd((char)0x0A);
	return;
}

void putstr(char *TXDATA)
{
	while(*TXDATA != '\0'){
		txd(*TXDATA);
		TXDATA++;
	}
	return;
}

void disp(long int D)
{
	unsigned char TD[5];
	int X=4;
	txd((char)0x20);
	if(D<0)txd((char)0x2D);
	else txd((char)0x2B);
	D = abs(D);
	while(X+1){
		TD[X] = D%10;
		D /= 10;
		X--;
	}
	for(X=0;X<5;X++)txvalue(TD[X]);
	return;
}

void comma()
{
	txd(',');
}

int advancedDisp(double opr, int pre)
{
	unsigned char digitNum[15], i;
	double scanningDigit = 10000.0;
	if(100000 < opr || opr < -100000 || 15 < pre)return -1;
	txd((char)0x20);
	if(opr < 0){
		txd((char)0x2D);
		opr *= -1;
	}
	while(((opr/scanningDigit)<1) && (scanningDigit != 1))scanningDigit /= 10.0;
	for(i=0;i<pre;i++){
		if(scanningDigit == 0.1)txd(0x2E);
		digitNum[i] = opr/scanningDigit;
		opr -= digitNum[i]*scanningDigit;
		txvalue(digitNum[i]);
		scanningDigit /= 10.0;
	}
	while(1 <= scanningDigit){
		txvalue(0);
		scanningDigit /= 10.0;
	}
	return 0;
}
