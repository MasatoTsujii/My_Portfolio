#include <mbed.h>
#include "init.h"
#include "ArmUnit.h"
#include "interrupt.h"
#include "Dynamixel.h"

Timer sendWait;

unsigned char Armdata_L[30] = {0};
unsigned char Armdata_R[30] = {0};

void AX12A::send_AXdata(uint8_t ArmData[], unsigned short length, short Number){

	uint8_t sendData[30] = {0};
	short ElapsedTime = 0, WaitTime = 0;

	length += 2;
	WaitTime = (length+10)*16;
	sendData[0] = (uint8_t)(AX_START);
	sendData[1] = (uint8_t)(AX_START);
	for(unsigned short i=2; i<length; i++)		sendData[i] = ArmData[i-2];
	
	UartChange.write(1);
	sendWait.reset();
	sendWait.start();
	if(Number==0)		Arm_L.write(sendData, length);
	else if(Number==1)	Arm_R.write(sendData, length);
	/*wait_us(WaitTime);
	UartChange.write(0);*/
	if(length<15){
		ElapsedTime = sendWait.elapsed_time().count();
		while(ElapsedTime<WaitTime)		ElapsedTime = sendWait.elapsed_time().count();
		sendWait.stop();
		UartChange.write(0);
	}else{
		sendWait.stop();
	}
}

int AX12A::receive_AXdata(unsigned short length, short Number){
	
	short readPossible = 0;
	unsigned char receive_L, receive_R;
	int i=0;
	bool DataNoget=0;

	monitoring_Dynamixel = 0;
	while(!readPossible){

		if(Number==0)		readPossible = Arm_L.readable();
		else if(Number==1)	readPossible = Arm_R.readable();

		if(3<=monitoring_Dynamixel)	return -1;
	}

	if( (Number==0) && (!DataNoget) ){

		while(i<length+6){
			
			if(3<=monitoring_Dynamixel) return -1;

			Arm_L.read(&receive_L, 1);
			Armdata_L[i++] = receive_L;
		}
		return (statusReturn(Armdata_L, length));
	}else if( (Number==1) && (!DataNoget) ){
		
		while(i<length+6){

			if(3<=monitoring_Dynamixel) return -1;

			Arm_R.read(&receive_R, 1);
			Armdata_R[i++] = receive_R;
		}
		return (statusReturn(Armdata_R, length));
	}else{
		return -1;
	}

	return -1;
}

int AX12A::statusReturn(unsigned char Data[], unsigned short length){

	short return_Byte;

	if((Data[0]==0xFF) && (Data[1]==0xFF)){

		Error_Byte = Data[4];
		if( (Error_Byte!=0) || (length==0) )  return (Error_Byte*(-1));

		if(length==1){
			return_Byte = Data[5];
		}else{
			return_Byte = Data[5];
			return_Byte += Data[6]<<8;
		}
		return return_Byte;
	}else{
		return -1;
	}
}
/*int AX12A::read_error(void){
	
	while (availableData() > 0){
		Incoming_Byte = readData();
		if ( (Incoming_Byte == 255) & (peekData() == 255) ){

			readData();                                    // Start Bytes
			readData();                                    // Ax-12 ID
			readData();                                    // Length
			Error_Byte = readData();                       // Error
				return (Error_Byte);
		}
	}
	return (-1);											 // No Ax Response
}*/

/////
void AX12A::reset(unsigned char ID, short Number){     //デバイスの初期化

	const unsigned int length = 4;
	uint8_t packet[length];
	
	Checksum = (~(ID + AX_RESET_LENGTH + AX_RESET)) & 0xFF;

	packet[0] = ID;
	packet[1] = AX_RESET_LENGTH;    //0x02
	packet[2] = AX_RESET;           //0x06
	packet[3] = Checksum;

	send_AXdata(packet, length, Number);
}

void AX12A::ping(unsigned char ID, short Number){

	const unsigned int length = 4;
	uint8_t packet[length];

	Checksum = (~(ID + AX_PING_LENGTH + AX_PING)) & 0xFF;
	
	packet[0] = ID;
	packet[1] = AX_PING_LENGTH;
	packet[2] = AX_PING;
	packet[3] = Checksum;

	send_AXdata(packet, length, Number);
}

/////
/*int AX12A::ledStatus(unsigned char ID, bool Status){

	const unsigned int length = 6;
	uint8_t packet[length];

	Checksum = (~(ID + AX_LED_LENGTH + AX_WRITE_DATA + AX_LED + Status)) & 0xFF;

	packet[0] = ID;
	packet[1] = AX_LED_LENGTH;
	packet[2] = AX_WRITE_DATA;
	packet[3] = AX_LED;
	packet[4] = Status;
	packet[5] = Checksum;

	//return (sendAXPacket(packet, length)); // return error
}*/

void AX12A::move(unsigned char ID, short Position, short Number){

    char Position_H,Position_L;
    Position_H = Position >> 8;           // 16 bits - 2 x 8 bits variables
    Position_L = Position;

    const unsigned int length = 7;
    uint8_t packet[length];

	Checksum = (~(ID + AX_GOAL_LENGTH + AX_WRITE_DATA + AX_GOAL_POSITION_L + Position_L + Position_H)) & 0xFF;

    packet[0] = ID;
    packet[1] = AX_GOAL_LENGTH;
    packet[2] = AX_WRITE_DATA;
    packet[3] = AX_GOAL_POSITION_L;
    packet[4] = Position_L;
    packet[5] = Position_H;
    packet[6] = Checksum;

    send_AXdata(packet, length, Number);
}

void AX12A::moveSpeed(unsigned char ID, short Position, short Speed, short Number){

    char Position_H,Position_L,Speed_H,Speed_L;
    Position_H = Position >> 8;
    Position_L = Position;                // 16 bits - 2 x 8 bits variables
    Speed_H = Speed >> 8;
	Speed_L = Speed;                      // 16 bits - 2 x 8 bits variables

    const unsigned int length = 9;
    uint8_t packet[length];
    
    Checksum = (~(ID + AX_GOAL_SP_LENGTH + AX_WRITE_DATA + AX_GOAL_POSITION_L + Position_L + Position_H + Speed_L + Speed_H)) & 0xFF;

    packet[0] = ID;
    packet[1] = AX_GOAL_SP_LENGTH;
    packet[2] = AX_WRITE_DATA;
    packet[3] = AX_GOAL_POSITION_L;
    packet[4] = Position_L;
    packet[5] = Position_H;
    packet[6] = Speed_L;
    packet[7] = Speed_H;
    packet[8] = Checksum;

    send_AXdata(packet, length, Number);
}

void AX12A::move_SYNC(unsigned char ID[], short Position[], short Number){
	
    unsigned char Position_H,Position_L;
    const unsigned int length = 18;
    uint8_t packet[length];
	int Datasum;

	for(int i=0; i<4; i++){
	}

	Datasum = BROADCAST_ID + AX_SYNC_GOAL_LENGTH + AX_SYNC_WRITE + AX_GOAL_POSITION_L + 0x02;

    packet[0]  = BROADCAST_ID;
    packet[1]  = AX_SYNC_GOAL_LENGTH;
    packet[2]  = AX_SYNC_WRITE;
    packet[3]  = AX_GOAL_POSITION_L;
	packet[4]  = 0x02;
	for(short i=0; i<4; i++){

    	Position_L = Position[i];
		Position_H = Position[i] >> 8;
		Datasum += ID[i];
		Datasum += Position_L;
		Datasum += Position_H;
		packet[5+i*3]  = ID[i];
		packet[5+i*3+1]  = Position_L;
		packet[5+i*3+2]  = Position_H;
	}
	Checksum = (~Datasum) & 0xFF;
    packet[17] = Checksum;

    send_AXdata(packet, length, Number);
}

void AX12A::moveSpeed_SYNC(unsigned char ID[], short Position[], short Speed[], short Number){

	unsigned char Position_H,Position_L,Speed_H,Speed_L;
    const unsigned int length = 26;
    uint8_t packet[length];
	int Datasum;
    
    Datasum = BROADCAST_ID + AX_SYNC_GOAL_SP_LENGTH + AX_SYNC_WRITE + AX_GOAL_POSITION_L + 0x04;

    packet[0]  = BROADCAST_ID;
    packet[1]  = AX_SYNC_GOAL_SP_LENGTH;
    packet[2]  = AX_SYNC_WRITE;
    packet[3]  = AX_GOAL_POSITION_L;
	packet[4]  = 0x04;
	for(short i=0; i<4; i++){

    	Position_L = Position[i];
		Position_H = Position[i] >> 8;
		Speed_L = Speed[i];
		Speed_H = Speed[i] >> 8;
		Datasum += ID[i];
		Datasum += Position_L;
		Datasum += Position_H;
		Datasum += Speed_L;
		Datasum += Speed_H;
		packet[5+i*5]  = ID[i];
		packet[5+i*5+1]  = Position_L;
		packet[5+i*5+2]  = Position_H;
		packet[5+i*5+3]  = Speed_L;
		packet[5+i*5+4]  = Speed_H;
	}
	Checksum = (~Datasum) & 0xFF;
	packet[25] = Checksum;
	
    send_AXdata(packet, length, Number);
}

void AX12A::turn(unsigned char ID, bool SIDE, short Speed, short Number){

		if(SIDE == LFT){
			char Speed_H,Speed_L;
			Speed_H = Speed >> 8;
			Speed_L = Speed;                     // 16 bits - 2 x 8 bits variables
			
			const unsigned int length = 7;
			uint8_t packet[length];
			
			Checksum = (~(ID + AX_SPEED_LENGTH + AX_WRITE_DATA + AX_GOAL_SPEED_L + Speed_L + Speed_H)) & 0xFF;

		    packet[0] = ID;
		    packet[1] = AX_SPEED_LENGTH;
		    packet[2] = AX_WRITE_DATA;
		    packet[3] = AX_GOAL_SPEED_L;
		    packet[4] = Speed_L;
		    packet[5] = Speed_H;
		    packet[6] = Checksum;

		    send_AXdata(packet, length, Number);
		}else{

			char Speed_H,Speed_L;
			Speed_H = (Speed >> 8) + 4;
			Speed_L = Speed;                     // 16 bits - 2 x 8 bits variables
			
			const unsigned int length = 7;
			uint8_t packet[length];

			Checksum = (~(ID + AX_SPEED_LENGTH + AX_WRITE_DATA + AX_GOAL_SPEED_L + Speed_L + Speed_H)) & 0xFF;
			
		    packet[0] = ID;
		    packet[1] = AX_SPEED_LENGTH;
		    packet[2] = AX_WRITE_DATA;
		    packet[3] = AX_GOAL_SPEED_L;
		    packet[4] = Speed_L;
		    packet[5] = Speed_H;
		    packet[6] = Checksum;

		    send_AXdata(packet, length, Number);
		}
}

void AX12A::torqueStatus( unsigned char ID, bool Status, short Number){

	const unsigned int length = 6;
	uint8_t packet[length];

	Checksum = (~(ID + AX_TORQUE_LENGTH + AX_WRITE_DATA + AX_TORQUE_ENABLE + Status)) & 0xFF;

    packet[0] = ID;
    packet[1] = AX_TORQUE_LENGTH;
    packet[2] = AX_WRITE_DATA;
    packet[3] = AX_TORQUE_ENABLE;
    packet[4] = Status;
    packet[5] = Checksum;
    
    send_AXdata(packet, length, Number);
}

void AX12A::lockRegister(unsigned char ID, bool lock, short Number){

	const unsigned int length = 6;
	uint8_t packet[length];
	
	Checksum = (~(ID + AX_LOCK_LENGTH + AX_WRITE_DATA + AX_LOCK + lock)) & 0xFF;
    
	packet[0] = ID;
	packet[1] = AX_LOCK_LENGTH;
	packet[2] = AX_WRITE_DATA;
	packet[3] = AX_LOCK;
	packet[4] = lock;
	packet[5] = Checksum;

	send_AXdata(packet, length, Number);
}

/////
void AX12A::setID(unsigned char ID, unsigned char newID, short Number){    //ID書き換え

	const unsigned int length = 6;
	uint8_t packet[length];

	Checksum = (~(ID + AX_ID_LENGTH + AX_WRITE_DATA + AX_ID + newID)) & 0xFF;

	packet[0] = ID;
	packet[1] = AX_ID_LENGTH;
	packet[2] = AX_WRITE_DATA;
	packet[3] = AX_ID;
	packet[4] = newID;
	packet[5] = Checksum;

    send_AXdata(packet, length, Number);
}

void AX12A::setBR(unsigned char ID, short Number/*, long baud*/){      //ボーレート設定

	const unsigned int length = 6;
	uint8_t packet[length];

	//unsigned char Baud_Rate = (2000000/baud) - 1;
	Checksum = (~(ID + AX_BR_LENGTH + AX_WRITE_DATA + AX_BAUD_RATE + BAUD_RATE)) & 0xFF;

	packet[0] = ID;
	packet[1] = AX_BR_LENGTH;
	packet[2] = AX_WRITE_DATA;
	packet[3] = AX_BAUD_RATE;
	packet[4] = BAUD_RATE;
	packet[5] = Checksum;
    
	send_AXdata(packet, length, Number);
}

void AX12A::setEndless(unsigned char ID, bool Status, short Number){

	if ( Status )
	{
		const unsigned int length = 7;
		uint8_t packet[length];

		Checksum = (~(ID + AX_GOAL_LENGTH + AX_WRITE_DATA + AX_CCW_ANGLE_LIMIT_L)) & 0xFF;

	    packet[0] = ID;
	    packet[1] = AX_GOAL_LENGTH;
	    packet[2] = AX_WRITE_DATA;
	    packet[3] = AX_CCW_ANGLE_LIMIT_L;
	    packet[4] = 0; 						// full rotation
	    packet[5] = 0;						// full rotation
	    packet[6] = Checksum;

	    send_AXdata(packet, length, Number);
	}else{
		
		turn(ID,0,0, Number);

		const unsigned int length = 7;
		uint8_t packet[length];

		Checksum = (~(ID + AX_GOAL_LENGTH + AX_WRITE_DATA + AX_CCW_ANGLE_LIMIT_L + AX_CCW_AL_L + AX_CCW_AL_H)) & 0xFF;

	    packet[0] = ID;
	    packet[1] = AX_GOAL_LENGTH;
	    packet[2] = AX_WRITE_DATA;
	    packet[3] = AX_CCW_ANGLE_LIMIT_L;
	    packet[4] = AX_CCW_AL_L;
	    packet[5] = AX_CCW_AL_H;
	    packet[6] = Checksum;

	    send_AXdata(packet, length, Number);
	}
}

void AX12A::setTempLimit(unsigned char ID, unsigned char Temperature, short Number){

	const unsigned int length = 6;
	uint8_t packet[length];

	Checksum = (~(ID + AX_TL_LENGTH + AX_WRITE_DATA + AX_LIMIT_TEMPERATURE + Temperature)) & 0xFF;
	
	packet[0] = ID;
	packet[1] = AX_TL_LENGTH;
	packet[2] = AX_WRITE_DATA;
	packet[3] = AX_LIMIT_TEMPERATURE;
	packet[4] = Temperature;
	packet[5] = Checksum;
	
	send_AXdata(packet, length, Number);
}

void AX12A::setVoltageLimit(unsigned char ID, unsigned char DVoltage, unsigned char UVoltage, short Number){

	const unsigned int length = 7;
	uint8_t packet[length];

	Checksum = (~(ID + AX_VL_LENGTH + AX_WRITE_DATA + AX_LOWEST_LIMIT_VOLTAGE + DVoltage + UVoltage)) & 0xFF;
	
	packet[0] = ID;
	packet[1] = AX_VL_LENGTH;
	packet[2] = AX_WRITE_DATA;
	packet[3] = AX_LOWEST_LIMIT_VOLTAGE;
	packet[4] = DVoltage;
	packet[5] = UVoltage;
	packet[6] = Checksum;
	
	send_AXdata(packet, length, Number);
}

void AX12A::setAngleLimit(unsigned char ID, int CWLimit, int CCWLimit, short Number){

	unsigned char CW_H,CW_L,CCW_H,CCW_L;
    CW_H = CWLimit >> 8;    
    CW_L = CWLimit;                // 16 bits - 2 x 8 bits variables
    CCW_H = CCWLimit >> 8;
    CCW_L = CCWLimit;  

	const unsigned int length = 9;
	uint8_t packet[length];
	
	Checksum = (~(ID + AX_CCW_CW_LENGTH + AX_WRITE_DATA + AX_CW_ANGLE_LIMIT_L + CW_H + CW_L/*+ AX_CCW_ANGLE_LIMIT_L*/ + CCW_H + CCW_L)) & 0xFF;
	
	packet[0] = ID;
	packet[1] = AX_CCW_CW_LENGTH;
	packet[2] = AX_WRITE_DATA;
	packet[3] = AX_CW_ANGLE_LIMIT_L;
	packet[4] = CW_L;
	packet[5] = CW_H;
	//packet[6] = AX_CCW_ANGLE_LIMIT_L;
	packet[6] = CCW_L;
	packet[7] = CCW_H;
	packet[8] = Checksum;

	send_AXdata(packet, length, Number);
}

void AX12A::setMaxTorque(unsigned char ID, int MaxTorque, short Number){

    unsigned char MaxTorque_H,MaxTorque_L;
    MaxTorque_H = MaxTorque >> 8;           // 16 bits - 2 x 8 bits variables
    MaxTorque_L = MaxTorque;
    
	const unsigned int length = 7;
	uint8_t packet[length];

	Checksum = (~(ID + AX_MT_LENGTH + AX_WRITE_DATA + AX_MAX_TORQUE_L + MaxTorque_L + MaxTorque_H)) & 0xFF;

	packet[0] = ID;
	packet[1] = AX_MT_LENGTH;
	packet[2] = AX_WRITE_DATA;
	packet[3] = AX_MAX_TORQUE_L;
	packet[4] = MaxTorque_L;
	packet[5] = MaxTorque_H;
	packet[6] = Checksum;
	
	send_AXdata(packet, length, Number);
}

void AX12A::setSRL(unsigned char ID, unsigned char SRL, short Number){

	const unsigned int length = 6;
	uint8_t packet[length];

	Checksum = (~(ID + AX_SRL_LENGTH + AX_WRITE_DATA + AX_RETURN_LEVEL + SRL)) & 0xFF;

	packet[0] = ID;
	packet[1] = AX_SRL_LENGTH;
	packet[2] = AX_WRITE_DATA;
	packet[3] = AX_RETURN_LEVEL;
	packet[4] = SRL;
	packet[5] = Checksum;
	
	send_AXdata(packet, length, Number);
}

void AX12A::setRDT(unsigned char ID, unsigned char RDT, short Number){

	const unsigned int length = 6;
	uint8_t packet[length];
	
	Checksum = (~(ID + AX_RDT_LENGTH + AX_WRITE_DATA + AX_RETURN_DELAY_TIME + RDT)) & 0xFF;

	packet[0] = ID;
	packet[1] = AX_RDT_LENGTH;
	packet[2] = AX_WRITE_DATA;
	packet[3] = AX_RETURN_DELAY_TIME;
	packet[4] = RDT;
	packet[5] = Checksum;
    
	send_AXdata(packet, length, Number);
}

void AX12A::setLEDAlarm(unsigned char ID, unsigned char LEDAlarm, short Number){

	const unsigned int length = 6;
	uint8_t packet[length];

	Checksum = (~(ID + AX_LEDALARM_LENGTH + AX_WRITE_DATA + AX_ALARM_LED + LEDAlarm)) & 0xFF;

	packet[0] = ID;
	packet[1] = AX_LEDALARM_LENGTH;
	packet[2] = AX_WRITE_DATA;
	packet[3] = AX_ALARM_LED;
	packet[4] = LEDAlarm;
	packet[5] = Checksum;
	
	send_AXdata(packet, length, Number);
}

void AX12A::setShutdownAlarm(unsigned char ID, unsigned char SALARM, short Number){

	const unsigned int length = 6;
	uint8_t packet[length];
	
	Checksum = (~(ID + AX_SALARM_LENGTH + AX_ALARM_SHUTDOWN + AX_ALARM_LED + SALARM)) & 0xFF;

	packet[0] = ID;
	packet[1] = AX_SALARM_LENGTH;
	packet[2] = AX_WRITE_DATA;
	packet[3] = AX_ALARM_SHUTDOWN;
	packet[4] = SALARM;
	packet[5] = Checksum;
    
	send_AXdata(packet, length, Number);
}

void AX12A::setCMargin(unsigned char ID, unsigned char CWCMargin, unsigned char CCWCMargin, short Number){

	const unsigned int length = 8;
	uint8_t packet[length];

	Checksum = (~(ID + AX_CM_LENGTH + AX_WRITE_DATA + AX_CW_COMPLIANCE_MARGIN + CWCMargin + AX_CCW_COMPLIANCE_MARGIN + CCWCMargin)) & 0xFF;
	
	packet[0] = ID;
	packet[1] = AX_CM_LENGTH;
	packet[2] = AX_WRITE_DATA;
	packet[3] = AX_CW_COMPLIANCE_MARGIN;
	packet[4] = CWCMargin;
	packet[5] = AX_CCW_COMPLIANCE_MARGIN;
	packet[6] = CCWCMargin;
	packet[7] = Checksum;
	
	send_AXdata(packet, length, Number);
}

void AX12A::setCSlope(unsigned char ID, unsigned char CWCSlope, unsigned char CCWCSlope, short Number){

	const unsigned int length = 8;
	uint8_t packet[length];

	Checksum = (~(ID + AX_CS_LENGTH + AX_WRITE_DATA + AX_CW_COMPLIANCE_SLOPE + CWCSlope + AX_CCW_COMPLIANCE_SLOPE + CCWCSlope)) & 0xFF;
	
	packet[0] = ID;
	packet[1] = AX_CS_LENGTH;
	packet[2] = AX_WRITE_DATA;
	packet[3] = AX_CW_COMPLIANCE_SLOPE;
	packet[4] = CWCSlope;
	packet[5] = AX_CCW_COMPLIANCE_SLOPE;
	packet[6] = CCWCSlope;
	packet[7] = Checksum;
	
	send_AXdata(packet, length, Number);
}

/////
void AX12A::moveRW(unsigned char ID, short Position, short Number){

    char Position_H,Position_L;
    Position_H = Position >> 8;           // 16 bits - 2 x 8 bits variables
    Position_L = Position;

	const unsigned int length = 7;
	uint8_t packet[length];

    Checksum = (~(ID + AX_GOAL_LENGTH + AX_REG_WRITE + AX_GOAL_POSITION_L + Position_L + Position_H)) & 0xFF;

    packet[0] = ID;
    packet[1] = AX_GOAL_LENGTH;
    packet[2] = AX_REG_WRITE;
    packet[3] = AX_GOAL_POSITION_L;
    packet[4] = Position_L;
    packet[5] = Position_H;
    packet[6] = Checksum;
	
    send_AXdata(packet, length, Number);
}

void AX12A::moveSpeedRW(unsigned char ID, short Position, short Speed, short Number){

    char Position_H,Position_L,Speed_H,Speed_L;
    Position_H = Position >> 8;    
    Position_L = Position;                // 16 bits - 2 x 8 bits variables
    Speed_H = Speed >> 8;
    Speed_L = Speed;                      // 16 bits - 2 x 8 bits variables

	const unsigned int length = 9;
	uint8_t packet[length];

    Checksum = (~(ID + AX_GOAL_SP_LENGTH + AX_REG_WRITE + AX_GOAL_POSITION_L + Position_L + Position_H + Speed_L + Speed_H)) & 0xFF;

    packet[0] = ID;
    packet[1] = AX_GOAL_SP_LENGTH;
    packet[2] = AX_REG_WRITE;
    packet[3] = AX_GOAL_POSITION_L;
    packet[4] = Position_L;
    packet[5] = Position_H;
    packet[6] = Speed_L;
    packet[7] = Speed_H;
    packet[8] = Checksum;
	
    send_AXdata(packet, length, Number);
}

int AX12A::RWStatus(unsigned char ID, short Number){

	const unsigned int length = 6;
	uint8_t packet[length];

	Checksum = (~(ID + AX_RWS_LENGTH + AX_READ_DATA + AX_REGISTERED_INSTRUCTION + AX_BYTE_READ)) & 0xFF;
    
	packet[0] = ID;
	packet[1] = AX_RWS_LENGTH;
	packet[2] = AX_READ_DATA;
	packet[3] = AX_REGISTERED_INSTRUCTION;
	packet[4] = AX_BYTE_READ;
	packet[5] = Checksum;
	
	send_AXdata(packet, length, Number);
	
    RWS_Byte = receive_AXdata(AX_BYTE_READ, Number);

	return (RWS_Byte);               				// Returns the read RWStatus
}

void AX12A::action(short Number){

	const unsigned int length = 4;
	uint8_t packet[length];

    packet[0] = BROADCAST_ID;
    packet[1] = AX_ACTION_LENGTH;
    packet[2] = AX_ACTION;
    packet[3] = AX_ACTION_CHECKSUM;

    send_AXdata(packet, length, Number);
}

/////
int AX12A::readPosition(unsigned char ID, short Number){

	const unsigned int length = 6;
	uint8_t packet[length];

    Checksum = (~(ID + AX_POSITION_LENGTH + AX_READ_DATA + AX_PRESENT_POSITION_L + AX_BYTE_READ_POSITION)) & 0xFF;

	packet[0] = ID;
	packet[1] = AX_POSITION_LENGTH;
	packet[2] = AX_READ_DATA;
	packet[3] = AX_PRESENT_POSITION_L;
	packet[4] = AX_BYTE_READ_POSITION;
	packet[5] = Checksum;

	send_AXdata(packet, length, Number);
	
    Position_Long_Byte = receive_AXdata(AX_BYTE_READ_POSITION, Number);

	return (Position_Long_Byte);     // Returns the read position
}

int AX12A::readSpeed(unsigned char ID, short Number){

	const unsigned int length = 6;
	uint8_t packet[length];

	Checksum = (~(ID + AX_POSITION_LENGTH + AX_READ_DATA + AX_PRESENT_SPEED_L + AX_BYTE_READ_POSITION)) & 0xFF;
	
	packet[0] = ID;
	packet[1] = AX_POSITION_LENGTH;
	packet[2] = AX_READ_DATA;
	packet[3] = AX_PRESENT_SPEED_L;
	packet[4] = AX_BYTE_READ_POSITION;
	packet[5] = Checksum;
	
	send_AXdata(packet, length, Number);
	
    Speed_Long_Byte = receive_AXdata(AX_BYTE_READ_POSITION, Number);

	return (Speed_Long_Byte);     // Returns the read position
}

int AX12A::readVoltage(unsigned char ID, short Number){

	const unsigned int length = 6;
	uint8_t packet[length];

    Checksum = (~(ID + AX_VOLTAGE_LENGTH + AX_READ_DATA + AX_PRESENT_VOLTAGE + AX_BYTE_READ)) & 0xFF;

	packet[0] = ID;
	packet[1] = AX_VOLTAGE_LENGTH;
	packet[2] = AX_READ_DATA;
	packet[3] = AX_PRESENT_VOLTAGE;
	packet[4] = AX_BYTE_READ;
	packet[5] = Checksum;

    send_AXdata(packet, length, Number);
	
    Voltage_Byte = receive_AXdata(AX_BYTE_READ, Number);

	return (Voltage_Byte);               // Returns the read Voltage
}

int AX12A::readLoad(unsigned char ID, short Number){

	const unsigned int length = 6;
	uint8_t packet[length];

	Checksum = (~(ID + AX_LOAD_LENGTH + AX_READ_DATA + AX_PRESENT_LOAD_L + AX_BYTE_READ_POSITION)) & 0xFF;

	packet[0] = ID;
	packet[1] = AX_LOAD_LENGTH;
	packet[2] = AX_READ_DATA;
	packet[3] = AX_PRESENT_LOAD_L;
	packet[4] = AX_BYTE_READ_POSITION;
	packet[5] = Checksum;
	
	send_AXdata(packet, length , Number);
	
    Load_Long_Byte = receive_AXdata(AX_BYTE_READ_POSITION, Number);

	return (Load_Long_Byte);     // Returns the read position
}

int AX12A::moving(unsigned char ID, short Number){

	const unsigned int length = 6;
	uint8_t packet[length];

	Checksum = (~(ID + AX_MOVING_LENGTH + AX_READ_DATA + AX_MOVING + AX_BYTE_READ)) & 0xFF;
    
	packet[0] = ID;
	packet[1] = AX_MOVING_LENGTH;
	packet[2] = AX_READ_DATA;
	packet[3] = AX_MOVING;
	packet[4] = AX_BYTE_READ;
	packet[5] = Checksum;
	
	send_AXdata(packet, length, Number);
	
    Moving_Byte = receive_AXdata(AX_BYTE_READ, Number);

	return (Moving_Byte);              				// Returns the read Moving
}