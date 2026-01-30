#include "iodefine.h"

//SCI1：データ送信
void txd(char D)
{
	while(!SCI1.SSR.BIT.TEND);
	SCI1.TDR = D;
	return;
}

//SCI1：数値一桁をアスキーコードに変換し送信
void txvalue(unsigned char D)
{
	if(D>=10)txd(0x3F);
	D = D+48;
	txd(D);
	return;
}

//SCI1：DISP改行
void dnl(void)
{
	txd(0x0D);
	txd(0x0A);
	return;
}

//SCI1：引数の文字をそのまま送る
void putstr(char *TXDATA)
{
	while(*TXDATA != '\0'){
		txd(*TXDATA);
		TXDATA++;
	}
	return;
}

//SCI1：DISP（マイナスも可）
void disp(long int D)
{
	unsigned char TD[5];
	int X=4;
	txd(0x20);
	if(D<0)txd(0x2D);
	else txd(0x2B);
	D = abs(D);
	while(X+1){
		TD[X] = D%10;
		D /= 10;
		X--; 
	}
	for(X=0;X<5;X++)txvalue(TD[X]);
	return;
}

//SCI1：カンマ送信
void comma(void)
{
	txd(',');
}

//小数可disp(表示する変数, 精度(表示する桁数))
int advancedDisp(double opr, int pre)
{
	unsigned char digitNum[15], i;
	double scanningDigit = 10000.0;
	if(100000 < opr || opr < -100000 || 15 < pre)return -1;
	txd(0x20);
	if(opr < 0){
		txd(0x2D);//マイナス符号送信
		opr *= -1;
	}
	while(((opr/scanningDigit)<1) && (scanningDigit != 1))scanningDigit /= 10.0;
	for(i=0;i<pre;i++){
		if(scanningDigit == 0.1)txd(0x2E);//小数点送信
		digitNum[i] = opr/scanningDigit;
		opr -= digitNum[i]*scanningDigit;
		txvalue(digitNum[i]);//1桁数値送信関数(digitNum[i]);
		scanningDigit /= 10.0;
	}
	while(1 <= scanningDigit){
		txvalue(0);
		scanningDigit /= 10.0;
	}
	return 0;
}