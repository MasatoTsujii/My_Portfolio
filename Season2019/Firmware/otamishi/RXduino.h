#include"stdint.h"
//WAIT設定
void setupWait(){
	SYSTEM.MSTPCRA.BIT.MSTPA15 = 0;			//CMT0,1
	CMT.CMSTR0.BIT.STR0 = 0;
	CMT0.CMCR.WORD = 0x0000;
	CMT0.CMCOR = 10000;
}

//1msのタイマ割り込み設定
void setupTimerInterrupt(){
	SYSTEM.MSTPCRA.BIT.MSTPA15 = 0;			//CMT0,1
	CMT.CMSTR0.BIT.STR1 = 0;
	CMT1.CMCR.WORD = 0x0000;
	CMT1.CMCR.BIT.CKS = 0;
	CMT1.CMCR.BIT.CMIE = 1;
	ICU.IER[0x03].BIT.IEN5 = 1;
	ICU.IPR[0x05].BIT.IPR =12;
	CMT1.CMCOR = 5999;
	CMT.CMSTR0.BIT.STR1 = 1;
	
}

//DISP設定
void setupDisp(unsigned int bps){
	unsigned char X;
	SYSTEM.MSTPCRB.BIT.MSTPB30 = 0;			//SCI1
	PORTD.ICR.BIT.B5 = 1;
	ICU.IER[0x1B].BIT.IEN3 = 1;
	ICU.IPR[0x81].BIT.IPR = 13;
	SCI1.SCR.BIT.TIE = 0;
	SCI1.SCR.BIT.RIE = 1;
	SCI1.SCR.BIT.TE = 0;
	SCI1.SCR.BIT.RE = 0;
	SCI1.SCR.BIT.TEIE = 0;
	SCI1.SMR.BYTE = 0x00;
	SCI1.BRR = (48000000 / (16 * bps) + 1) / 2 - 1;
	for(X=0;X<250;X++);
	SCI1.SCR.BIT.TE = 1;
	SCI1.SCR.BIT.RE = 1;
}

//XDISP設定
void setupXdisp(unsigned char bps){
	unsigned char X;
	IOPORT.PFFSCI.BIT.SCI2S = 1;
	PORT8.ICR.BIT.B0 = 1;
	SCI2.SCR.BIT.TIE = 0;
	SCI2.SCR.BIT.RIE = 0;
	SCI2.SCR.BIT.TE = 0;
	SCI2.SCR.BIT.RE = 0;
	SCI2.SCR.BIT.TEIE = 0;
	SCI2.SMR.BYTE = 0x00;
	SCI2.BRR = (48000000 / (16 * bps) + 1) / 2 - 1;
	for(X=0;X<250;X++);
	SCI2.SCR.BIT.TE = 1;
	SCI2.SCR.BIT.RE = 1;
}
unsigned short ASCII_to_VALUE(unsigned char ascii){
	unsigned short	value;

	if(ascii >= 0x61){		//アルファベットが小文字なら
		ascii -= 0x20;		//大文字に変換
	}
	if(ascii >= 0x41){
		ascii -= 7;
	}
	value = ascii - 0x30;

	return value;	
}

//SCI1：データ送信
void txd(char D){

	while(!SCI1.SSR.BIT.TEND);
	SCI1.TDR = D;
	return;
}

//SCI2：XBeeデータ送信
void xtxd(char D){
	while(!SCI2.SSR.BIT.TEND);
	SCI2.TDR = D;
	return;
}

//SCI1：数値一桁をアスキーコードに変換し送信
void txvalue(unsigned char D){
	if(D>=10)txd(0x3F);
	D = D+48;
	txd(D);
	return;
	
}

//SCI2：数値一桁をアスキーコードに変換しXBee送信
void xtxvalue(unsigned char D){
	if(D>=10)xtxd(0x3F);
	D = D+48;
	xtxd(D);
	return;
}

//SCI1：DISP改行
void dnl(){
	txd(0x0D);
	txd(0x0A);
	return;
}

//SCI2：XBee_DISP改行
void xdnl(){
	xtxd(0x0D);
	xtxd(0x0A);
	return;
}

//SCI1：DISP（マイナスも可）
void disp(long int D){
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

//SCI2：XBee_DISP（マイナスも可）
void xdisp(long int D){
	unsigned char TD[5];
	int X=4;
	xtxd(0x20);
	if(D<0)xtxd(0x2D);
	else xtxd(0x2B);
	D = abs(D);
	while(X+1){
		TD[X] = D%10;
		D /= 10;
		X--; 
	}
	for(X=0;X<5;X++)xtxvalue(TD[X]);
	return;
}

//SCI1：文字列送信
void string(char *TXDATA){
	txd(0x20);
	while(*TXDATA != '\0'){
		txd(*TXDATA);
		TXDATA++;
	}
	return;
}

//小数可disp(表示する変数, 精度(表示する桁数))
int idealDisp(double opr, int pre){
	uint8_t digitNum[15], i;
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

//SCI2：XBeeで文字列送信
void xstring(char *TXDATA){
	xtxd(0x20);
	while(*TXDATA != '\0'){
		xtxd(*TXDATA);
		TXDATA++;
	}
	return;
}

void wait(long int T){
	long int X;
	CMT0.CMCNT = 0;
	CMT.CMSTR0.BIT.STR0 = 1;
	for(X=0;X<T;X++){
		while(CMT0.CMCNT<5999);
		CMT0.CMCNT = 0;
	}
	CMT.CMSTR0.BIT.STR0 = 0;
	CMT0.CMCNT = 0;
	return;
}