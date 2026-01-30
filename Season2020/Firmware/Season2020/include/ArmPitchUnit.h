#ifndef ARMPITCHUNIT_H
#define ARMPITCHUNIT_h

#define DIF_LOCK    10
#define SLOW_WIDTH1 1000
#define SLOW_WIDTH2 800
#define DIF_ASISST  12

extern int read_vol;
extern int velocity_ArmPitch;
extern const unsigned short CWAngleLimit_ArmPosition;
extern const unsigned short CWWAngleLimit_ArmPosition;
extern const unsigned short Start_ArmPitchPosition;
extern const unsigned short ArmPitchPosition[20][10];
extern const unsigned short ArmPitchSpeed[20][10];
extern unsigned short DT_ArmPitchPosition[6][5];
extern unsigned short Goal_ArmPitchPosition;
extern unsigned short Goal_ArmPitchSpeed;
extern unsigned short Next_ArmPitchPosition;
extern unsigned short Now_ArmPitchPosition;
extern short DT_PitchSpeed;
extern bool Check_Pitch;
extern bool LockMode;

void ArmPitchUnitInit(void);
void ArmPitch_Asisst(void);
void ArmPitch_move(unsigned short GoalPosition, unsigned short NowPosition, unsigned short SpeedLevel);
bool Nextphase_PitchChack(int GoalPosition, int NowPosition, int dis);

#endif