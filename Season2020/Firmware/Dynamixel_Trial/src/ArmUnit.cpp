#include "mbed.h"
#include "init.h"
#include "ArmUnit.h"
#include "interrupt.h"
#include "Dynamixel.h"
#include "ArmPitchUnit.h"

AX12A RobotArm;
Timer ActionTimer;

unsigned char ArmID_L[4] = {0x40, 0x10, 0x04, 0x01};
unsigned char ArmID_R[4] = {0x80, 0x20, 0x08, 0x02};    //上から順番に
const short CWAngleLimit_ArmPosition_L[4] = {210, 200, 150, 480};
const short CWWAngleLimit_ArmPosition_L[4] = {820, 840, 900, 600};
const short CWAngleLimit_ArmPosition_R[4] = {150, 160, 150, 420};
const short CWWAngleLimit_ArmPosition_R[4] = {830, 800, 990, 535};
const short ArmPosition_L[10][5][4] = {0};
const short ArmPosition_R[10][5][4] = {0};
short Goal_ArmPosition_L[4] = {0};
short Goal_ArmPosition_R[4] = {0};
short Next_ArmPosition_L[4] = {0};
short Next_ArmPosition_R[4] = {0};
short Now_ArmPosition_L[4] = {0};
short Now_ArmPosition_R[4] = {0};
short phase = 0;
short move_command;
bool finishFlag = 0;
bool ActiveFlag = 0;
bool Check_L, Check_R, Check_Time;

short DT_ArmPosition_L[6][9][4] = {0};
short DT_ArmPosition_R[6][9][4] = {0};
short DT_PhaseNum[6] = {-1, -1, -1, -1, -1, -1};
short DT_Speed[4] = {100, 100, 100, 100};
short DT_WaitTime[6] = {1500, 1500, 1000, 1000, 500, 500};
short DT_SpeedMagnification = 3;
short DT_ProcessNumber = 1;
short DT_Lock[4] = {0};
short DT_phase = 0;
bool DT_Next_ButtonFlag = 0;
bool DT_Prev_ButtonFlag = 0;
bool DT_Point_ButtonFlag = 0;
bool DT_Action_ButtonFlag = 0;
bool DT_SpeedChangMode = 0;
bool DT_OperationFirst;
bool DT_PointButton;
bool DT_NumberNext;
bool DT_NumberPrev;
bool DT_Action;
bool DT_Reset;
bool DT_Mode;

bool TurnTable_Mode = 0;

int i, j;

void Setting(void){

    //RobotArm.setRDT(BROADCAST_ID, 250, 0, 0);
    //RobotArm.torqueStatus(BROADCAST_ID, 0, 0, 0);
    //RobotArm.setBR(BROADCAST_ID, 0, 0);
    //RobotArm.setBR(BROADCAST_ID, 1, 0);
    //RobotArm.setID(BROADCAST_ID, NEW_ID, 0, 0);
    /*RobotArm.setMaxTorque(BROADCAST_ID, MAXTORQUE, 0, 0);
    RobotArm.setMaxTorque(BROADCAST_ID, MAXTORQUE, 1, 0);*/
    //RobotArm.setShutdownAlarm(BROADCAST_ID, AX_ALARM, 0, 0);
    //RobotArm.setShutdownAlarm(BROADCAST_ID, AX_ALARM, 1, 0);
    //RobotArm.lockRegister(BROADCAST_ID, 1);
    /*for(i=0; i<4; i++){
        RobotArm.setAngleLimit(ArmID_L[i], CWAngleLimit_ArmPosition_L[i], CWWAngleLimit_ArmPosition_L[i], 0, 0);
        RobotArm.setAngleLimit(ArmID_R[i], CWAngleLimit_ArmPosition_R[i], CWWAngleLimit_ArmPosition_R[i], 1, 0);
    }*/
    Now_ArmPitchPosition = Arm_volume.read_u16();
    for(i=0; i<7; i++){
        LED_7seg[i] = 1;
    }
}

void DirectTeaching(void){

    if( (DT_Mode) && (!ActiveFlag) ){

        RobotArm.torqueStatus(BROADCAST_ID, 0, 0);
        RobotArm.torqueStatus(BROADCAST_ID, 0, 1);
        if( (DT_PointButton) && (DT_Point_ButtonFlag) && (!DT_Lock[DT_ProcessNumber-1]) ){

            for(i=0; i<4; i++){
                DT_ArmPosition_L[DT_ProcessNumber-1][DT_phase][i] = Now_ArmPosition_L[i];
                DT_ArmPosition_R[DT_ProcessNumber-1][DT_phase][i] = Now_ArmPosition_R[i];
            }
            DT_ArmPitchPosition[DT_ProcessNumber-1][DT_phase] = Now_ArmPitchPosition;
            DT_phase++;
            DT_PhaseNum[DT_ProcessNumber-1]++;
        }
        DT_Point_ButtonFlag = !DT_PointButton;
    }else if( (DT_Mode) && (ActiveFlag) ){

        move_command = DT_ProcessNumber-1;
        if(DT_PhaseNum[move_command]!=-1){
            for(i=0; i<4; i++){
                Next_ArmPosition_L[i] = DT_ArmPosition_L[move_command][DT_phase][i];
                Next_ArmPosition_R[i] = DT_ArmPosition_R[move_command][DT_phase][i];
            }
            Next_ArmPitchPosition = DT_ArmPitchPosition[move_command][DT_phase];

            if(!Check_L)        Check_L = Nextphase_ArmChack(Goal_ArmPosition_L, Now_ArmPosition_L, 2);
            if(!Check_R)        Check_R = Nextphase_ArmChack(Goal_ArmPosition_R, Now_ArmPosition_R, 2);
            if(!Check_Pitch)    Check_Pitch = Nextphase_PitchChack(Goal_ArmPitchPosition, Now_ArmPitchPosition, 10);
            /*Check_L = 1;
            Check_R = 1;*/
            //Check_Pitch = 1;
            
            if(DT_OperationFirst){
            Check_L = 1;
            Check_R = 1;
            Check_Pitch = 1;
            Check_Time = 1;
            DT_OperationFirst = 0;
            Wait_ArmUnit = 0;
            monitoring_ArmUnit = 0;
            }else if( (!Check_L) || (!Check_R) || (!Check_Pitch) ){
                Wait_ArmUnit = 0;
                if( 3000/*(5000-( (DT_SpeedMagnification-1)*500) )*/<monitoring_ArmUnit ){
                    Check_L = 1;
                    Check_R = 1;
                    Check_Pitch = 1;
                }
            }
            if( (Check_L) && (Check_R) && (Check_Pitch) && (DT_WaitTime[move_command]<=Wait_ArmUnit) )    Check_Time = 1;

            if( (Check_L) && (Check_R) && (Check_Pitch) && (Check_Time) ){

                for(i=0; i<4; i++){
                    Goal_ArmPosition_L[i] = Next_ArmPosition_L[i];
                    Goal_ArmPosition_R[i] = Next_ArmPosition_R[i];
                    DT_Speed[i] = 50*DT_SpeedMagnification;
                }
                Goal_ArmPitchPosition = Next_ArmPitchPosition;
                RobotArm.moveSpeed_SYNC(ArmID_L, Next_ArmPosition_L, DT_Speed, 0);
                RobotArm.moveSpeed_SYNC(ArmID_R, Next_ArmPosition_R, DT_Speed, 1);
                DT_phase = (DT_phase==DT_PhaseNum[move_command]) ? 0 : DT_phase+1;
                Check_L = 0;
                Check_R = 0;
                Check_Pitch = 0;
                Check_Time = 0;
                LockMode = 0;
                Wait_ArmUnit = 0;
                monitoring_ArmUnit = 0;
            }
            ArmPitch_move(Goal_ArmPitchPosition, Now_ArmPitchPosition, DT_SpeedMagnification);
        }else{
            DT_phase = 0;
            ActiveFlag = 0;
            DT_OperationFirst = 0;
            for(i=0; i<4; i++){
                Goal_ArmPosition_L[i] = 0;
                Goal_ArmPosition_R[i] = 0;
            }
            Goal_ArmPitchPosition = 0;
            velocity_ArmPitch = 0;
        }
    }
}

void Turn_Table(void){

    /*unsigned short Turn_Position[]
    if( (!DT_Mode) && (!ActiveFlag) ){

    }*/
}
/*void ArmDriver(void){

    //short Check_L, Check_R;
    float time;

    if(ActiveFlag){

        if(DT_Mode){
            move_command = DT_ProcessNumber-1;
            for(i=0; i<4; i++){
                Next_ArmPosition_L[i] = DT_ArmPosition_L[move_command][phase][i];
                Next_ArmPosition_R[i] = DT_ArmPosition_R[move_command][phase][i];
                if( (Next_ArmPosition_L[i]==0) || (Next_ArmPosition_R[i]==0) ){
                    finishFlag = 1;
                    break;
                }
            }
        }else{
            move_command = command;
            for(i=0; i<4; i++){
                Next_ArmPosition_L[i] = ArmPosition_L[move_command][phase][i];
                Next_ArmPosition_R[i] = ArmPosition_R[move_command][phase][i];
                if( (Next_ArmPosition_L[i]==0) && (Next_ArmPosition_R[i]==0) ){
                    finishFlag = 1;
                    Operation_L = 0;
                    Operation_R = 0;
                    break;
                }else if(Next_ArmPosition_L[i]==0){
                    Operation_L = 0;
                    sendData_Num = 1;
                    break;
                }else if(Next_ArmPosition_R[i]==0){
                    Operation_R = 0;
                    sendData_Num = 1;
                    break;
                }
            }
        }
        if(phase==0){
            //Action_time.start();
            RobotArm.move_SYNC(ArmID_L, Next_ArmPosition_L, 0, 1);
            RobotArm.move_SYNC(ArmID_R, Next_ArmPosition_R, 1, 1);
            for(i=0; i<4; i++){
                Goal_ArmPosition_L[i] = Next_ArmPosition_L[i];
                Goal_ArmPosition_R[i] = Next_ArmPosition_R[i];
            }
            phase++;
        }
        Check_L = Nextphase_Chack(Goal_ArmPosition_L, Now_ArmPosition_L, 4);
        Check_R = Nextphase_Chack(Goal_ArmPosition_R, Now_ArmPosition_R, 4);

        if(TimeLimit<time){
            phase = 0;
            ActiveFlag = 0;
        }else if( (Check_L) && (Check_R) ){
            if(finishFlag){
                finishFlag = 0;
                phase = 0;
                ActiveFlag = 0;
            }else{
                RobotArm.move_SYNC(ArmID_L, Next_ArmPosition_L);
                RobotArm.move_SYNC(ArmID_R, Next_ArmPosition_R);
                for(i=0; i<4; i++){
                    Goal_ArmPosition_L[i] = Next_ArmPosition_L[i];
                    Goal_ArmPosition_R[i] = Next_ArmPosition_R[i];
                }
                phase++;
            }
        }
    }
}*/

bool Nextphase_ArmChack(short GoalPosition[], short NowPosition[], short dif){

    bool NoGoal = 0;
    for(i=0; i<4; i++){
        if( ( (GoalPosition[i]+dif)<=NowPosition[i]) || (NowPosition[i]<=(GoalPosition[i]-dif) ) ){
            NoGoal = 1;
            break;
        }
    }
    if(NoGoal)  return !NoGoal;
    else        return 1;
}

void ArmUnitInit(void){

    DT_Mode = DT_Switch.read();
    DT_SpeedChangMode = DT_SpeedSwitch.read();
    DT_Reset = !DT_ResetButton.read();
    DT_Action = !DT_ActionButton.read();
    DT_NumberNext = !Change_Next.read();
    DT_NumberPrev = !Change_Prev.read();;
    DT_PointButton = !PointButton.read();
    for(i=0; i<4; i++){
        Now_ArmPosition_L[i] = RobotArm.readPosition(ArmID_L[i], 0);
        Now_ArmPosition_R[i] = RobotArm.readPosition(ArmID_R[i], 1);
        DT_Lock[i] = !DIP_INPUT[i].read();
    }
    if(DT_Mode){
        
        if( (DT_Action) && (!ActiveFlag) && (DT_Action_ButtonFlag) ){
            DT_phase = 0;
            ActiveFlag = 1;
            LockMode = 0;
            DT_OperationFirst = 1;
            DT_SpeedMagnification = 3;
            Goal_ArmPitchPosition = 0;
            velocity_ArmPitch = 0;
        }else if( (DT_Action) && (ActiveFlag) && (DT_Action_ButtonFlag) ){
            DT_phase = 0;
            ActiveFlag = 0;
            LockMode = 0;
            DT_OperationFirst = 0;
            DT_SpeedMagnification = 3;
            for(i=0; i<4; i++){
                Goal_ArmPosition_L[i] = 0;
                Goal_ArmPosition_R[i] = 0;
                Next_ArmPosition_L[i] = 0;
                Next_ArmPosition_R[i] = 0;
            }
            velocity_ArmPitch = 0;
            Goal_ArmPitchPosition = 0;
        }
        DT_Action_ButtonFlag = !DT_Action;

        if( (DT_SpeedChangMode) && (ActiveFlag) ){

            if( (DT_Next_ButtonFlag) && (DT_NumberNext) ){

                DT_SpeedMagnification++;
                DT_SpeedMagnification = (DT_SpeedMagnification==7) ? 1 : DT_SpeedMagnification;
            }else if( (DT_Prev_ButtonFlag) && (DT_NumberPrev) ){

                DT_SpeedMagnification--;
                DT_SpeedMagnification = (DT_SpeedMagnification==0) ? 6 : DT_SpeedMagnification;
            }
        }else if( (!DT_SpeedChangMode) && (!ActiveFlag) ){
            
            if( (DT_Next_ButtonFlag) && (DT_NumberNext) ){

                DT_phase = 0;
                DT_ProcessNumber++;
                DT_ProcessNumber = (DT_ProcessNumber==7) ? 1 : DT_ProcessNumber;
            }else if( (DT_Prev_ButtonFlag) && (DT_NumberPrev) ){

                DT_phase = 0;
                DT_ProcessNumber--;
                DT_ProcessNumber = (DT_ProcessNumber==0) ? 6 : DT_ProcessNumber;
            }
        }
        DT_Next_ButtonFlag = !DT_NumberNext;
        DT_Prev_ButtonFlag = !DT_NumberPrev;
        
        if( (DT_Reset) && (!DT_Lock[DT_ProcessNumber-1]) && (!ActiveFlag) ){

            DT_phase = 0;
            for(i=0; i<5; i++){
                for(j=0; j<4; j++){
                    DT_ArmPosition_L[DT_ProcessNumber-1][i][j] = 0;
                    DT_ArmPosition_R[DT_ProcessNumber-1][i][j] = 0;
                    DT_PhaseNum[DT_ProcessNumber-1] = -1;
                }
            }
        }

        if(DT_Lock[3]){
            LED_OutPut(DT_phase);
        }else if ( (DT_SpeedChangMode) && (ActiveFlag) ){
            LED_OutPut(DT_SpeedMagnification);
        }else{
            LED_OutPut(DT_ProcessNumber);
        }
    }else{

        DT_phase = 0;
        ActiveFlag = 0;
        DT_SpeedMagnification = 1;
        if( (DT_Action) && (!ActiveFlag) && (DT_Action_ButtonFlag) ){

            ActiveFlag = 1;
            if( (DT_SpeedChangMode) && (!ActiveFlag) )          TurnTable_Mode = 0;
            else if( (!DT_SpeedChangMode) && (!ActiveFlag) )    TurnTable_Mode = 1;
        }else if( (DT_Action) && (ActiveFlag) && (DT_Action_ButtonFlag) ){
            ActiveFlag = 0;
        }
        
        DT_Action_ButtonFlag = !DT_Action;
        for(i=0; i<4; i++){
            Goal_ArmPosition_L[i] = 0;
            Goal_ArmPosition_R[i] = 0;
            Next_ArmPosition_L[i] = 0;
            Next_ArmPosition_R[i] = 0;
        }
        if(DT_Lock[3]){
            LED_OutPut(phase+1);
        }else{
            LED_OutPut(-1);
        }
    }
}

void LED_OutPut(int Number){
                               //6  7  9 10  1  2  4
    bool LED7seg_Out[9][7] = {/*{1, 1, 1, 0, 1, 1, 1},*/   //0
                               {0, 1, 1, 0, 0, 0, 0},   //1
                               {1, 1, 0, 1, 1, 0, 1},   //2
                               {1, 1, 1, 1, 0, 0, 1},   //3
                               {0, 1, 1, 0, 0, 1, 1},   //4
                               {1, 0, 1, 1, 0, 1, 1},   //5
                               {1, 0, 1, 1, 1, 1, 1},   //6
                               {1, 1, 1, 0, 0, 0, 0},   //7
                               {1, 1, 1, 1, 1, 1, 1},   //8
                               {1, 1, 1, 1, 0, 1, 1}};  //9
    Number -= 1;
    for(i=0; i<7; i++){
        LED_7seg[i] = (-1<Number) ? !LED7seg_Out[Number][i] : 1;
    }
}