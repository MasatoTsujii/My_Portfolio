#include "init.h"
#include "iodefine.h"

void init_driving_io(void){
	PORT9.DDR.BIT.B0 = 1;
	PORT9.DDR.BIT.B2 = 1;
	PORT9.DDR.BIT.B3 = 1;
	PORT9.DDR.BIT.B5 = 1;
	PORT9.DDR.BIT.B6 = 1;
	PORTA.DDR.BIT.B2 = 1;
	PORTA.DDR.BIT.B3 = 1;
	PORTA.DDR.BIT.B4 = 1;
}

void init_driving_mtu(void){
	SYSTEM.MSTPCRA.BIT.MSTPA9 = 0;
	MTU.TSTRB.BIT.CST6 = 0;
	MTU6.TCR.BIT.CCLR = 6;
	MTU6.TMDR1.BIT.MD = 2;
	MTU.TOERA.BYTE = 0xff;
	MTU.TOERB.BYTE = 0xff;
	MTU6.TIORH.BIT.IOA = 5;
	MTU6.TIORH.BIT.IOB = 6;
	MTU6.TIORL.BIT.IOC = 5;
	MTU6.TIORL.BIT.IOD = 6;
	MTU6.TGRA = 0;
	MTU6.TGRB = 1920;
	MTU6.TGRC = 0;
	MTU6.TGRD = 1920;
	MTU.TSTRB.BIT.CST6 = 1;
	
	MTU.TSTRB.BIT.CST7 = 0;
	MTU7.TCR.BIT.CCLR = 6;
	MTU7.TMDR1.BIT.MD = 2;
	MTU7.TIORH.BIT.IOA = 5;
	MTU7.TIORH.BIT.IOB = 6;
	MTU7.TIORL.BIT.IOC = 5;
	MTU7.TIORL.BIT.IOD = 6;
	MTU7.TGRA = 0;
	MTU7.TGRB = 1920;
	MTU7.TGRC = 0;
	MTU7.TGRD = 1920;
	MTU.TSTRB.BIT.CST7 = 1;
}

void init_cmt(void){
	SYSTEM.MSTPCRA.BIT.MSTPA15 = 0;
	CMT.CMSTR0.BIT.STR0 = 0;
	CMT0.CMCR.WORD = 0;
}

void init_delay(int time){
	int count = 0;
	CMT.CMSTR0.BIT.STR0 = 1;
	while(time >= count){
		if(CMT0.CMCNT >= 6000){
			count++;
			CMT0.CMCNT = 0;
		}
	}
	CMT.CMSTR0.BIT.STR0 = 0;
}

void init_timerinterrupt(void){
	SYSTEM.MSTPCRA.BIT.MSTPA15 = 0;
	CMT.CMSTR0.BIT.STR1 = 0;
	CMT1.CMCR.WORD = 0;
	CMT1.CMCR.BIT.CMIE = 1;
	ICU.IER[0x03].BIT.IEN5 = 1;
	ICU.IPR[0x05].BIT.IPR = 0xd;
	CMT1.CMCOR = 5999;
}

void init_disp(void){
	int i;
	SYSTEM.MSTPCRB.BIT.MSTPB30 = 0;
	SCI1.SCR.BIT.RE = 0;
	SCI1.SCR.BIT.TE = 0;
	PORTD.ICR.BIT.B5 = 1;
	SCI1.BRR = 38;
	for(i = 0; i < 5000; i++);
	SCI1.SCR.BIT.RE = 1;
	SCI1.SCR.BIT.TE = 1;
}


void init_control(void){
	int i;
	SYSTEM.MSTPCRB.BIT.MSTPB29 = 0;
	IOPORT.PFFSCI.BIT.SCI2S = 0;
	PORTB.ICR.BIT.B6 = 1;
	ICU.IER[0x1B].BIT.IEN7 = 1;
	ICU.IPR[0x82].BIT.IPR = 12;
	SCI2.SCR.BYTE = 0;
	SCI2.SMR.BYTE = 0X00;
	SCI2.BRR = (48000000 / (16 * 9600)) / 2 - 1;
	for(i = 0; i < 10000; i++);
	
	SCI2.SCR.BIT.TIE = 0;
	SCI2.SCR.BIT.RIE = 1;
	SCI2.SCR.BIT.TE = 0;
	SCI2.SCR.BIT.RE = 1;
}

void init_jouge(void){
	
	MTU.TSTRA.BIT.CST0 = 0;		//タイマ停止
	MTU0.TCR.BIT.CCLR = 6;		//TCNTクリア
	MTU0.TMDR1.BIT.MD = 3;		//PWMモード2の設定
	
	MTU0.TIORH.BIT.IOA = 5;
	MTU0.TIORH.BIT.IOB = 5;
	MTU0.TIORL.BIT.IOC = 5;
	MTU0.TIORL.BIT.IOD = 6;		//PWMの天井の設定
	
	MTU0.TGRA = 0;			//PB3
	MTU0.TGRB = 0;			//PB2
	MTU0.TGRC = 0;			//PB1
	MTU0.TGRD = 1920;		//PB0
	
	MTU.TOERA.BYTE = 0xff;		//MTUが使えるように
	MTU.TOERB.BYTE = 0xff;
	MTU.TSTRA.BIT.CST0 = 1;		//タイマ開始
}

/*void init_kaisyuu(void){
	
	MTU.TOERA.BIT.OE4A = 1;		//MTUが使えるように(使うピンを)
	MTU.TOERA.BIT.OE4C = 1;
	
	MTU4.TCR.BIT.TPSC = 1;		//ICLK/4
	MTU4.TCR.BIT.CKEG = 0;		//立ち上がりでカウント
	MTU4.TCR.BIT.CCLR = 6;		//TCNTクリア
	
	MTU4.TMDR1.BIT.MD = 2;		//PWMモード1の設定
	
	MTU4.TIORH.BIT.IOA = 5;
	MTU4.TIORH.BIT.IOB = 6;		//PWMの天井の設定
	//4C,4DをPWMに使わないなら↓をコメントアウト
	//MTU4.TIORL.BIT.IOC = 5;
	//MTU4.TIORL.BIT.IOD = 6;		//PWMの天井の設定
	
	MTU4.TGRA = 0;			//4A
	MTU4.TGRB = 1920;
	//4C,4DをPWMに使わないなら↓をコメントアウト
	//MTU4.TGRC = 0;			//4C
	//MTU4.TGRD = 1920;
	
	MTU.TSTRA.BIT.CST4 = 1;		//タイマ開始
}*/

void init_kaisyuu(void){
	
	MTU.TSTRA.BIT.CST4 = 0;
	MTU4.TCR.BIT.CCLR = 6;
	MTU4.TMDR1.BIT.MD = 2;
	MTU.TOERA.BYTE = 0xff;
	MTU.TOERB.BYTE = 0xff;
	
	MTU4.TIORH.BIT.IOA = 5;
	MTU4.TIORH.BIT.IOB = 6;
	MTU4.TIORL.BIT.IOC = 5;
	MTU4.TIORL.BIT.IOD = 6;
	
	MTU4.TGRA = 0;
	MTU4.TGRB = 1920;
	MTU4.TGRC = 0;
	MTU4.TGRD = 1920;
	
	MTU.TSTRA.BIT.CST4 = 1;
}


void init_io(void){
	
	PORTA.DDR.BIT.B2 = 1;
	PORTA.DDR.BIT.B4 = 1;
	
	PORTA.DDR.BIT.B3 = 1;
	PORT9.DDR.BIT.B5 = 1;
	
	PORT9.DDR.BIT.B3 = 1;
	PORT9.DDR.BIT.B3 = 1;
	
	PORT9.DDR.BIT.B0 = 1;
	PORT9.DDR.BIT.B2 = 1;
	
	PORT3.DDR.BIT.B0 = 1;
	PORT3.DDR.BIT.B1 = 1;
	PORT3.DDR.BIT.B2 = 1;
	PORT3.DDR.BIT.B3 = 1;
	
	//PORT7.DDR.BIT.B1 = 1;		//P71(3B)を出力として設定
	//PORT7.DDR.BIT.B2 = 1;			//P72(4A)を出力として設定
	//PORT7.DDR.BIT.B3 = 1;			//P73(4B)を出力として設定
	//PORT7.DDR.BIT.B4 = 1;		//P74(3D)を出力として設定
	//PORT7.DDR.BIT.B5 = 1;			//P75(4C)を出力として設定
	//PORT7.DDR.BIT.B6 = 1;			//P76(4D)を出力として設定
	
	PORT2.DDR.BIT.B0 = 1;		//P20を出力として設定
	PORT2.DDR.BIT.B1 = 1;		//P21を出力として設定
	PORT2.DDR.BIT.B2 = 1;		//P22を出力として設定
	PORT2.DDR.BIT.B3 = 1;		//P23を出力として設定
	
	PORT4.ICR.BIT.B0 = 1;		//P40を入力として設定
	PORT4.ICR.BIT.B1 = 1;		//P41を入力として設定
	PORT4.ICR.BIT.B2 = 1;		//P42を入力として設定
	PORT4.ICR.BIT.B3 = 1;		//P43を入力として設定
	PORT7.ICR.BIT.B5 = 1;		//P75(4C)を入力として設定
	PORT7.ICR.BIT.B6 = 1;		//P76(4D)を入力として設定
	
	PORT6.ICR.BIT.B0 = 1;		//P60(AN0)をボリューム入力
	PORT6.ICR.BIT.B2 = 1;		//P62(AN2)をボリューム入力
	//PORT6.ICR.BIT.B3 = 1;			//P63(AN3)をボリューム入力
}

void init_ad(void){
	SYSTEM.MSTPCRA.BIT.MSTPA23 = 0;
	
	PORT6.ICR.BIT.B0 = 1;		//P60(AN0)をボリューム入力
	PORT6.ICR.BIT.B1 = 1;
	//PORT6.ICR.BIT.B2 = 1;		//P62(AN2)をボリューム入力
	//PORT6.ICR.BIT.B3 = 1;		//P63(AN3)をボリューム入力
	
	AD0.ADCSR.BIT.ADST = 0;		//変換停止
	AD0.ADCR.BIT.MODE = 2;		//連続スキャンモード
	AD0.ADCSR.BIT.CH = 1;		//AN0～AN3
	AD0.ADSSTR = 0xff;
	AD0.ADCSR.BIT.ADST = 1;		//変換開始
	
}

void init_all(void){
	init_driving_io();
	init_driving_mtu();
	init_cmt();
	init_timerinterrupt();
	init_disp();
	init_control();
	init_jouge();
	init_kaisyuu();
	init_io();
	init_ad();
}