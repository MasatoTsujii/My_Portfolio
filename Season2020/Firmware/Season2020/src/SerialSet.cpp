#include <USBSerial.h>
#include "SerialSet.h"

char rx_buff;/*
int n=-1;
long buff[500];*/

UnbufferedSerial SCI(Tx,Rx);
void dispSet(){
	SCI.format(BIT,PALITY,STOP_BIT);
	SCI.baud(BAUDRATE);
	SCI.attach(receiveInt, UnbufferedSerial::RxIrq);
}

void receiveInt(){
	int i;
	int m = 0;
	static short DGsw = 0;
	static short key_data_num = 1830;
	//static char rx_buff;
	static int data_num = 0;
	static char rx_data[10];
	static char receive[10];

	SCI.read(&rx_buff, 1);
	if(!(data_num)){
		if(rx_buff == 0x80){
			DGsw = 1;
		}else
		if(rx_buff == 0xA0 || rx_buff == 0xA1){
			DGsw = 2;
		}
		for(i=0;i<8;i++){
			receive[i] = 0;
			rx_data[i] = 0;
		}
	}
	if(DGsw == 1){
		receive[data_num] = rx_buff;
		if(data_num == 1)key_data_num = bitCount(receive[data_num]);
		if(data_num  > key_data_num){
			for(i=0;i<7;i++)if(receive[1] & 1 << i){
				rx_data[i+2] = receive[2+m++];
			}
			data_num = -1;
			key_data_num = 1830;
			getKey(rx_data);
		}
		data_num++;
	}
	else if(DGsw == 2){
		receive[data_num++] = rx_buff;
		if(data_num >= 8){
			for(i=0; i<8; i++){
				rx_data[i] = receive[i];
			}
			data_num = 0;
			getGain(rx_data);
        }
	}
}

int bitCount(int i){
	i = i - ((i >> 1) & 0x55);
    i = (i & 0x33) + ((i >> 2) & 0x33);
    i = (i + (i >> 4)) & 0x0f;
    return i & 0xf;
}