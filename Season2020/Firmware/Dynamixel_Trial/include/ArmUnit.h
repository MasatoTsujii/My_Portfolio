#ifndef ARMUNIT_H
#define ARMUNIT_H

#define NEW_ID      0x10
#define ARM_NUM     4
#define TimeLimit   5
#define Smooth_Arm  2
#define WAIT_TIME   3000

extern unsigned char ArmID_L[4];
extern unsigned char ArmID_R[4];    //上から順番に
extern const short CWAngleLimit_ArmPosition_L[4];
extern const short CWWAngleLimit_ArmPosition_L[4];
extern const short CWAngleLimit_ArmPosition_R[4];
extern const short CWWAngleLimit_ArmPosition_R[4];
extern const short ArmPosition_L[10][5][4];
extern const short ArmPosition_R[10][5][4];
extern short Goal_ArmPosition_L[4];
extern short Goal_ArmPosition_R[4];
extern short Next_ArmPosition_L[4];
extern short Next_ArmPosition_R[4];
extern short Now_ArmPosition_L[4];
extern short Now_ArmPosition_R[4];
extern short phase;
extern short move_command;
extern bool finishFlag;
extern bool ActiveFlag;
extern bool Check_L, Check_R, Check_Time;

extern short DT_ArmPosition_L[6][9][4];
extern short DT_ArmPosition_R[6][9][4];
extern short DT_PhaseNum[6];
extern short DT_Speed[4];
extern short DT_SpeedMagnification;
extern short DT_ProcessNumber;
extern short DT_Lock[4];
extern short DT_phase;
extern bool DT_Next_ButtonFlag;
extern bool DT_Prev_ButtonFlag;
extern bool DT_Point_ButtonFlag;
extern bool DT_Action_ButtonFlag;
extern bool DT_SpeedChangMode;
extern bool DT_OperationFirst;
extern bool DT_PointButton;
extern bool DT_NumberNext;
extern bool DT_NumberPrev;
extern bool DT_Action;
extern bool DT_Reset;
extern bool DT_Mode;

void Setting(void);
void DirectTeaching(void);
bool Nextphase_ArmChack(short GoalPosition[], short NowPosition[], short dif);
void ArmUnitInit(void);
void LED_OutPut(int Number);

#endif