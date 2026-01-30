#ifndef DYNAMIXEL_H
#define DYNAMIXEL_H

#define TTL_NUM 2

extern unsigned char Armdata_L[30];
extern unsigned char Armdata_R[30];

/////ControlTable-Address/////
#define AX_ID                       3
#define AX_BAUD_RATE                4
#define AX_RETURN_DELAY_TIME        5
#define AX_CW_ANGLE_LIMIT_L         6
#define AX_CW_ANGLE_LIMIT_H         7
#define AX_CCW_ANGLE_LIMIT_L        8
#define AX_CCW_ANGLE_LIMIT_H        9
#define AX_LIMIT_TEMPERATURE        11
#define AX_LOWEST_LIMIT_VOLTAGE     12
#define AX_HIGHEST_LIMIT_VOLTAGE    13
#define AX_MAX_TORQUE_L             14
#define AX_MAX_TORQUE_H             15
#define AX_RETURN_LEVEL             16
#define AX_ALARM_LED                17
#define AX_ALARM_SHUTDOWN           18
#define AX_TORQUE_ENABLE            24
#define AX_CW_COMPLIANCE_MARGIN     26
#define AX_CCW_COMPLIANCE_MARGIN    27
#define AX_CW_COMPLIANCE_SLOPE      28
#define AX_CCW_COMPLIANCE_SLOPE     29
#define AX_GOAL_POSITION_L          30
#define AX_GOAL_POSITION_H          31
#define AX_GOAL_SPEED_L             32
#define AX_GOAL_SPEED_H             33
#define AX_PRESENT_POSITION_L       36
#define AX_PRESENT_POSITION_H       37
#define AX_PRESENT_SPEED_L          38
#define AX_PRESENT_SPEED_H          39
#define AX_PRESENT_LOAD_L           40
#define AX_PRESENT_LOAD_H           41
#define AX_PRESENT_VOLTAGE          42
#define AX_PRESENT_TEMPERATURE      43
#define AX_REGISTERED_INSTRUCTION   44
#define AX_MOVING                   46
#define AX_LOCK                     47

/////Instruction/////
#define AX_PING         0x01
#define AX_READ_DATA    0x02
#define AX_WRITE_DATA   0x03
#define AX_REG_WRITE    0x04
#define AX_ACTION       0x05
#define AX_RESET        0x06
#define AX_SYNC_WRITE   0x83

/////Length/////
#define AX_PING_LENGTH          0x02
#define AX_TEMPERATURE_LENGTH   0x04
#define AX_POSITION_LENGTH      0x04
#define AX_VOLTAGE_LENGTH       0x04
#define AX_MOVING_LENGTH        0x04
#define AX_RWS_LENGTH           0x04
#define AX_LOAD_LENGTH          0x04
#define AX_ID_LENGTH            0x04
#define AX_BR_LENGTH            0x04
#define AX_GOAL_LENGTH          0x05
#define AX_SPEED_LENGTH         0x05
#define AX_GOAL_SP_LENGTH       0x07
#define AX_TORQUE_LENGTH        0x04
#define AX_TL_LENGTH            0x04
#define AX_VL_LENGTH            0x06
#define AX_CCW_CW_LENGTH        0x07
#define AX_MT_LENGTH            0x05
#define AX_SRL_LENGTH           0x04
#define AX_RDT_LENGTH           0x04
#define AX_LEDALARM_LENGTH      0x04
#define AX_SALARM_LENGTH        0x04
#define AX_CM_LENGTH            0x06
#define AX_CS_LENGTH            0x06
#define AX_LOCK_LENGTH          0x04
#define AX_ACTION_LENGTH        0x02
#define AX_RESET_LENGTH         0x02
#define AX_SYNC_GOAL_LENGTH		0x10
#define AX_SYNC_GOAL_SP_LENGTH	0x18

/////opstion/////
#define AX_START                0xFF
#define LOCK_ON                 1
#define LOCK_OFF				0
#define BAUD_RATE               3  //500000bps	51 38400bps
#define MAXTORQUE				512
#define AX_CCW_AL_L             0xFF
#define AX_CCW_AL_H             0x03
#define BROADCAST_ID            0xFE
#define AX_ACTION_CHECKSUM      0xFA
#define AX_BYTE_READ            0x01
#define AX_BYTE_READ_POSITION   0x02
#define AX_SHUTDOWN_ALARM		0x04
#define AX_LED_ALARM			0x37

/////option/////
#define LFT            1

class AX12A{

private:
    unsigned char Checksum;
    unsigned char Direction_Pin;
	unsigned char Time_Counter;
	unsigned char Incoming_Byte;               
	unsigned char Position_High_Byte;
	unsigned char Position_Low_Byte;
	unsigned char Speed_High_Byte;
	unsigned char Speed_Low_Byte;
	unsigned char Load_High_Byte;
	unsigned char Load_Low_Byte;
	
	int Moving_Byte;
	int RWS_Byte;
	int Speed_Long_Byte;
	int Load_Long_Byte;
	int Position_Long_Byte;
	int Temperature_Byte;
	int Voltage_Byte;
	int Error_Byte;

public:
	/////data処理/////
    void send_AXdata(uint8_t ArmData[], unsigned short length, short Number);
    int receive_AXdata(unsigned short length, short Number);
	int statusReturn(unsigned char Data[], unsigned short length);
	//int read_error(void);

	/////
    void reset(unsigned char ID, short Number);
    void ping(unsigned char ID, short Number);

	//int ledStatus(unsigned char ID, bool Status);
    void move(unsigned char ID, short Position, short Number);
    void moveSpeed(unsigned char ID, short Position, short Speed, short Number);
	void move_SYNC(unsigned char ID[], short Position[], short Number);
	void moveSpeed_SYNC(unsigned char ID[], short Position[], short Speed[], short Number);
	void turn(unsigned char ID, bool SIDE, short speed, short Number);
    void torqueStatus(unsigned char ID, bool Status, short Number);
	void lockRegister(unsigned char ID, bool lock, short Number);

	/////setting/////
	void setID(unsigned char ID, unsigned char newID, short Number);
    void setBR(unsigned char ID, short Number);
    void setEndless(unsigned char ID, bool Status, short Number);
	void setTempLimit(unsigned char ID, unsigned char Temperature, short Number);
	void setVoltageLimit(unsigned char ID, unsigned char DVoltage, unsigned char UVoltage, short Number);
    void setAngleLimit(unsigned char ID, int CWLimit, int CCWLimit, short Number);
	void setMaxTorque(unsigned char ID, int MaxTorque, short Number);
	void setSRL(unsigned char ID, unsigned char SRL, short Number);
	void setRDT(unsigned char ID, unsigned char RDT, short Number);
	void setLEDAlarm(unsigned char ID, unsigned char LEDAlarm, short Number);
	void setShutdownAlarm(unsigned char ID, unsigned char SALARM, short Number);
	void setCMargin(unsigned char ID, unsigned char CWCMargin, unsigned char CCWCMargin, short Number);
	void setCSlope(unsigned char ID, unsigned char CWCSlope, unsigned char CCWCSlope, short Number);

	/////
    void moveRW(unsigned char ID, short Position, short Number);
    void moveSpeedRW(unsigned char ID, short Position, short Speed, short Number);
	int RWStatus(unsigned char ID, short Number);
	void action(short Number);

	/////
    int readTemperature(unsigned char ID, short Number);
	int readPosition(unsigned char ID, short Number);
	int readSpeed(unsigned char ID, short Number);
    int readVoltage(unsigned char ID, short Number);
	int readLoad(unsigned char ID, short Number);
	int moving(unsigned char ID, short Number);
};

#endif