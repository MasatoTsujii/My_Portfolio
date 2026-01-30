#include "init.h"
#include "iodefine.h"
void init_io(){
	PORTA.DDR.BIT.B2 = 1;
	
	PORTA.DDR.BIT.B3 = 1;
	
	PORTA.DDR.BIT.B4 = 1;
	
	PORT9.DDR.BIT.B0 = 1;
	
	PORT9.DDR.BIT.B2 = 1;
	
	PORT9.DDR.BIT.B3 = 1;
	
	PORT9.DDR.BIT.B5 = 1;
	
	PORT9.DDR.BIT.B6 = 1;
	
	PORT7.DDR.BIT.B1 = 1;
	
	PORT7.DDR.BIT.B4 = 1;
	
	PORT2.DDR.BIT.B3 = 1;
}
void init_cmt0(){
	CMT.CMSTR0.BIT.STR0 = 0;
	SYSTEM.MSTPCRA.BIT.MSTPA15 = 0;
	CMT0.CMCR.WORD = 0;
}

void init_mtu(){
	SYSTEM.MSTPCRA.BIT.MSTPA9 = 0;
	MTU.TSTRB.BIT.CST7 = 0;
	MTU7.TCR.BIT.CCLR = 6;
	MTU7.TMDR1.BIT.MD = 2;
	MTU.TOERA.BYTE = 0xff;
	MTU.TOERB.BYTE = 0xff;
	MTU7.TIORH.BIT.IOA = 5;
	MTU7.TIORH.BIT.IOB = 6;
	MTU7.TIORL.BIT.IOC = 5;
	MTU7.TIORL.BIT.IOD = 6;
	MTU7.TGRA = 0;
	MTU7.TGRB = 1920;
	MTU7.TGRC = 0;
	MTU7.TGRD = 1920;
	MTU.TSTRB.BIT.CST7 = 1;
	
	/*SYSTEM.MSTPCRA.BIT.MSTPA9 = 0;
	MTU.TSTRB.BIT.CST6 = 0;
	MTU6.TCR.BIT.CCLR = 6;
	MTU6.TMDR1.BIT.MD = 2;
	MTU.TOERA.BYTE = 0xff;
	MTU.TOERB.BYTE = 0xff;*/
	MTU.TSTRB.BIT.CST6 = 0;
	MTU6.TCR.BIT.CCLR = 6;
	MTU6.TMDR1.BIT.MD = 2;
	MTU6.TIORH.BIT.IOA = 5;
	MTU6.TIORH.BIT.IOB = 6;
	MTU6.TIORL.BIT.IOC = 5;
	MTU6.TIORL.BIT.IOD = 6;
	MTU6.TGRA = 0;
	MTU6.TGRB = 1920;
	MTU6.TGRC = 0;
	MTU6.TGRD = 1920;
	MTU.TSTRB.BIT.CST6 = 1;
	
	/*SYSTEM.MSTPCRA.BIT.MSTPA9 = 0;
	MTU.TSTRA.BIT.CST0 = 0;
	//IOPORT.PFCMTU.BIT.MTUS1 = 0;*/
	MTU.TSTRA.BIT.CST0 = 0;
	MTU0.TCR.BIT.CCLR = 6;
	MTU0.TMDR1.BIT.MD = 3;
	MTU0.TIORH.BIT.IOA = 5;
	MTU0.TIORH.BIT.IOB = 5;
	MTU0.TIORL.BIT.IOC = 5;
	MTU0.TIORL.BIT.IOD = 6;
	MTU0.TGRA = 0;
	MTU0.TGRB = 0;
	MTU0.TGRC = 0;
	MTU0.TGRD = 1920;
	MTU.TOERA.BYTE = 0xff;
	MTU.TOERB.BYTE = 0xff;
	MTU.TSTRA.BIT.CST0 = 1;
}
void wait(int time){
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
void init_ad(){
	SYSTEM.MSTPCRA.BIT.MSTPA23 = 0;
	PORT6.ICR.BIT.B0 = 1;
	AD0.ADCSR.BIT.ADST = 0;
	AD0.ADCR.BIT.MODE = 2;
	AD0.ADCSR.BIT.CH = 0;
	AD0.ADSSTR = 0xff;
	AD0.ADCSR.BIT.ADST = 1;
}

void init_timerinterrupt(){
	SYSTEM.MSTPCRA.BIT.MSTPA15 = 0;
	CMT.CMSTR0.BIT.STR1 = 0;
	CMT1.CMCR.WORD = 0;
	CMT1.CMCR.BIT.CMIE = 1;
	ICU.IER[0x03].BIT.IEN5 = 1;
	ICU.IPR[0x05].BIT.IPR = 0xd;
	CMT1.CMCOR = 5999;
}


void init_disp(){
	int i;
	SYSTEM.MSTPCRB.BIT.MSTPB30 = 0;
	SCI1.SCR.BIT.RE = 0;
	SCI1.SCR.BIT.TE = 0;
	PORTD.ICR.BIT.B5 = 1;
	SCI1.BRR = 38;
	for(i = 0; i < 10000; i++);
	SCI1.SCR.BIT.RE = 1;
	SCI1.SCR.BIT.TE = 1;
	
}



void init_sci2(){
	int i;
	SYSTEM.MSTPCRB.BIT.MSTPB29 = 0;
	SCI2.SCR.BYTE = 0;
	PORTB.ICR.BIT.B6 = 1;
	IOPORT.PFFSCI.BIT.SCI2S = 0;
	SCI2.SCR.BIT.CKE = 0;
	SCI2.SMR.BIT.STOP = 0;
	SCI2.SMR.BIT.PM = 0;
	SCI2.SMR.BIT.PE = 0;
	SCI2.SMR.BIT.CHR = 0;
	SCI2.SMR.BIT.CM = 0;
	SCI2.BRR =  (48 * 1000000) / (32 * 38400) - 1;
	for(i = 0;i < 1000;i++);
	ICU.IER[0x1B].BIT.IEN7 = 1;
	ICU.IPR[0x82].BIT.IPR = 0xe;
	
	SCI2.SCR.BIT.RIE = 1;
	SCI2.SCR.BIT.TE = 1;
	SCI2.SCR.BIT.RE = 1;
	
	//SCI2.SSR.BIT.RDRF = 0;
}



void init(){
	init_io();
	init_cmt0();
	init_mtu();
	init_ad();
	init_timerinterrupt();
	init_disp();
	init_sci2();
}