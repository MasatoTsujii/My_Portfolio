#include "mbed.h"
#include "init.h"
#include "stdlib.h"
#include "ArmUnit.h"
#include "ArmPitchUnit.h"

int read_vol=0;
int velocity_ArmPitch = 0;
const unsigned short CWAngleLimit_ArmPosition = 0;
const unsigned short CWWAngleLimit_ArmPosition = 0;
const unsigned short ArmPitchPosition[10][5] = {0};
unsigned short DT_ArmPitchPosition[6][5] = {0};
unsigned short Goal_ArmPitchPosition = 0;
unsigned short Next_ArmPitchPosition = 0;
unsigned short Prev_ArmPitchPosition = 0;
unsigned short Now_ArmPitchPosition = 0;
//short DT_PitchSpeed = 1000;
bool Check_Pitch;
bool LockMode = 0;

void ArmPitchUnitInit(void){
    
    read_vol = 0;
    for(int i=0; i<10; i++){
        read_vol += Arm_volume.read_u16();
    }
    Prev_ArmPitchPosition = Now_ArmPitchPosition;
    Now_ArmPitchPosition = Now_ArmPitchPosition*0.3 + (read_vol/10)*0.7;
}

void ArmPitch_Asisst(void){

    short Dif_ArmPitchPosition;
    Dif_ArmPitchPosition = abs(Now_ArmPitchPosition-Prev_ArmPitchPosition);
    if( (DT_Mode) && (!ActiveFlag) && (DIF_ASISST<Dif_ArmPitchPosition) ){
        
        if(Now_ArmPitchPosition<Prev_ArmPitchPosition){
            velocity_ArmPitch = 650;
        }else if(Prev_ArmPitchPosition<Now_ArmPitchPosition){
            velocity_ArmPitch = -120;
        }
    }
}

void ArmPitch_move(unsigned short GoalPosition, unsigned short NowPosition, unsigned short SpeedLevel){

    if(LockMode){
        
        /*if( (GoalPosition+DIF_LOCK)<=NowPosition ){
            velocity_ArmPitch = 500;
        }else if( NowPosition<=(GoalPosition-DIF_LOCK) ){
            velocity_ArmPitch = -500;
        }else{*/
            velocity_ArmPitch = 0;
        //}
    }else{

        if(Check_Pitch)                                     velocity_ArmPitch = 0;
        else if( (NowPosition+SLOW_WIDTH2)<=GoalPosition )  velocity_ArmPitch = -300*SpeedLevel;
        else if( GoalPosition<=(NowPosition-SLOW_WIDTH2) )  velocity_ArmPitch = 4000*SpeedLevel;
        else if( (NowPosition+SLOW_WIDTH1)<=GoalPosition )  velocity_ArmPitch = -300;
        else if( GoalPosition<=(NowPosition-SLOW_WIDTH1) )  velocity_ArmPitch = 3200;
        else if(NowPosition<=GoalPosition)                  velocity_ArmPitch = -200;
        else if(GoalPosition<=NowPosition)                  velocity_ArmPitch = 1000;
    }
}

bool Nextphase_PitchChack(int GoalPosition, int NowPosition, int dis){

    bool NoGoal = 0;
    
    if( ( (GoalPosition+dis)<=NowPosition) || (NowPosition<=(GoalPosition-dis) ) )  NoGoal = 1;
    if(NoGoal)  return !NoGoal;
    else        return 1;
}