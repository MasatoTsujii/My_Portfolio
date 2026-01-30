#include "iodefine.h"
#include "disp.h"
#include "tsusin.h"
#include "define.h"
#include "relay.h"
#include "omnidirectionaldriver.h"
#include "init.h"
int cnt = 0;
int air_cnt = 0;
int rx_cnt = 0;
int rx[10] = {0};

void timer();
void RXI2();
void js(int js_val,int* js_omni,int val_wid);

int main(){
	int jslx_omni = 0;
	int jsly_omni = 0;
	int jsrx_omni = 0;
	int motor[7] = {0};
	int roler_flug = 0;
	//int air_flug = 0;
	int i;
	init();
	air = 1;
	SYSTEM.SCKCR.BIT.PCK = 1;
	SYSTEM.SCKCR.BIT.ICK = 0;
	CMT.CMSTR0.BIT.STR1 = 1;
	
	while(1){
		js(jslx,&jslx_omni,js_constant);
		js(jsly,&jsly_omni,js_constant);
		js(jsrx,&jsrx_omni,js_constant);
		
		
		anomalyOmnidirectionalDriver(jslx_omni,jsly_omni,jsrx_omni,motor);
		
		if(square){
			roler_flug = !roler_flug;
		}else if(roler_flug){
			motor[5] = 1800;
			motor[6] = 1919;
			
		}else{
			motor[5] = 0;
			motor[6] = 0;
		}
		if(l1 && l2){
			motor[4] = 0;
		}else if(l1){
			motor[4] = 400;
		}else if(l2){
			motor[4] = -350;
		}else{
			motor[4] = 0;
		}
		
		if(cross){
			air = 0;
			air_cnt = 0;
		}
		if(air_cnt >= 200){
			air = 1;
		}
		
		if(rx_cnt >= 500){
			for(i = 0;i < 7;i++){
				motor[i] = 0;
			}
		}
		
		//relay(&motor);
		jslx = 100;
		disp(jslx);
		/*disp(motor[0]);
		disp(motor[1]);
		disp(motor[2]);
		disp(motor[3]);
		disp(motor[4]);
		disp(motor[5]);
		disp(motor[6]);
		disp(PWM_dozer);
		disp(STG_dozer1);
		disp(STG_dozer2);*/
		disp(rx_cnt);
		dnl();
	}
	
	
}

void timer(){
	cnt++;
	air_cnt++;
	rx_cnt++;
}

void RXI2(){
	//static int rx[10] = {0};
	static int No = 0;
	if(SCI2.RDR == 0x80){
		No = 0;
		rx[No++] = 0x80;
	}else if(No > 0){
		rx[No++] = SCI2.RDR;
		if(No > 7){
			updateState(rx);
			No = 0;
		}
	}
	rx_cnt = 0;
	SCI2.SSR.BIT.RDRF = 0;
}
void js(int js_val,int* js_omni,int val_wid){
	if(js_val <= 10 && js_val >= -10){
		js_val = 0;
	}else{
		js_val = (js_val >= 0) ? js_val - 10 : js_val + 10;
	}
	if(js_val > *js_omni){
		*js_omni += val_wid;
		if(js_val < *js_omni){
			*js_omni = js_val;
		}
	}
	if(js_val < *js_omni){
		*js_omni -= val_wid;
		if(js_val > *js_omni){
			*js_omni = js_val;
		}
	}
	
}
