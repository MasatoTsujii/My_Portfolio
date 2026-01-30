#include"debuger.h"

bool start_sigh_flg = false;
bool debug_request_flg = false;
bool debug_flg = false;
int debug_call_count[4] = {};
double *gain_addres[4][4][4];
int c=0;

void DebugToW(double *motor1 ,double *motor2){
	if(RangeFlood(*motor1))return;
	if(RangeFlood(*motor2))return;
	if(debug_flg){
		if(start_sigh_flg){
			Txd(0xA0);
			start_sigh_flg = false;
		}
		Txd(0x00);
		FractionTx(*motor1);
		FractionTx(*motor2);
	}
	
	gain_addres[0][0][0] = motor1;
	gain_addres[0][0][1] = motor2;
}

void DebugThW(double *motor1 ,double *motor2 ,double *motor3){
	
	if(RangeFlood(*motor1))return;
	if(RangeFlood(*motor2))return;
	if(RangeFlood(*motor3))return;
	
	if(debug_flg){
		if(start_sigh_flg){
			Txd(0xA0);
			start_sigh_flg = false;
		}
		Txd(10);
		FractionTx(*motor1);
		FractionTx(*motor2);
		FractionTx(*motor3);
	}
	
	gain_addres[1][0][0] = motor1;
	gain_addres[1][0][1] = motor2;
	gain_addres[1][0][2] = motor3;
}

void DebugFW(double *motor1 ,double *motor2 ,double *motor3 ,double *motor4){
	
	if(RangeFlood(*motor1))return;
	if(RangeFlood(*motor2))return;
	if(RangeFlood(*motor3))return;
	if(RangeFlood(*motor4))return;
	
	if(debug_flg){
		if(start_sigh_flg){
			Txd(0xA0);
			start_sigh_flg = false;
		}
		Txd(20);
		FractionTx(*motor1);
		FractionTx(*motor2);
		FractionTx(*motor3);
		FractionTx(*motor4);
	}
	
	gain_addres[2][0][0] = motor1;
	gain_addres[2][0][1] = motor2;
	gain_addres[2][0][2] = motor3;
	gain_addres[2][0][3] = motor4;
}

void DebugPID(double *Pgain ,double *Igain ,double *Dgain){
	
	if(debug_call_count[3] > 2){
		debug_call_count[3] = 183;
		return;
	}
	if(RangeFlood(*Pgain))return;
	if(RangeFlood(*Igain))return;
	if(RangeFlood(*Dgain))return;
	if(debug_flg){
		if(start_sigh_flg){
			Txd(0xA0);
			start_sigh_flg = false;
		}
		Txd(30 + debug_call_count[3]);
		FractionTx(*Pgain);
		FractionTx(*Igain);
		FractionTx(*Dgain);
	}
	
	gain_addres[3][debug_call_count[3]][0] = Pgain;
	gain_addres[3][debug_call_count[3]][1] = Igain;
	gain_addres[3][debug_call_count[3]][2] = Dgain;
	debug_call_count[3]++;
}

void DebugEnd(){
	int i = 0;
	static bool end = false;
	if(end)Txd(0xED);
	if(!(start_sigh_flg)){
		//debug_request_flg = false;
		debug_flg = false;
		end = false;
	}
	if(debug_request_flg){
		debug_request_flg = false;
		start_sigh_flg = true;
		debug_flg = true;
		end = true;
	}
	for(i = 0;i < 4;i++){
		debug_call_count[i] = 0;
	}
}

int RangeFlood(double value){
	//if(value < 0) return 0;
	value = fabs(value);
	if((int)value > INTLIMIT) return 1;
	value = (value - (int)value) * 100000;
	if(value > DECLIMIT) return 1;
	return 0;
}

void FractionTx(double value){
	//while(!(SCI.readable()));
	if(value < 0){
		txd(0x2D);
		value *= -1;
	}else txd(0x2E);
	Txd((int)value);
	int val = (value - (int)value) * 100000;
	Txd(val >> 8);
	Txd(val & 0xff);
	return;
}

void Txd(int D){	
	//while(!(SCI.readable()));
	SCI.write(&D, 1);
	return;
}

void getGain(char *G){
	//static bool firstgain = true;
	if(G[0] == 0xA0){
		 *gain_addres[(int)G[1]][(int)G[2]][(int)G[3]] = ((G[4] == 0x2D)?-1:1)*((double)G[5] + ((double)((G[6]<<8) + G[7])/10000));
	}
	debug_request_flg = true;
}
