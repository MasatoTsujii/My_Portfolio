#include <mbed.h>
#include "init.h"
#include <stdlib.h>
#include "ArmUnit.h"
#include "ArmPitchUnit.h"

int read_vol=0;
int velocity_ArmPitch = 0;

const unsigned short CWAngleLimit_ArmPosition = 0;
const unsigned short CWWAngleLimit_ArmPosition = 0;

const unsigned short Start_ArmPitchPosition = 33750;    //34300     27000
const unsigned short ArmPitchPosition[20][10] = {{33000,     0,     0,     0,     0,     0,     0,     0,     0,     0},   //最速ちゃぶ台返し
                                                 {33750, 33750, 33750, 26800, 26800,     0,     0,     0,     0,     0},   //アルティメットちゃぶ台返し1
                                                 {33750, 33750, 33750, 26800, 26800,     0,     0,     0,     0,     0},   //アルティメットちゃぶ台返し2
                                                 {31400, 31400, 31400, 31400, 31400, 31400, 31400, 31400, 31400, 33750},   //消毒 決勝
                                                 {33750, 33750, 33750, 33750, 26800, 26800,     0,     0,     0,     0},   //ボーナスちゃぶ台返し
                                                 {31400, 31400, 31400, 31400, 31400, 33750,     0,     0,     0,     0},   //消毒
                                                 {33750, 33750, 33750, 33400, 33750, 33750, 33750,     0,     0,     0},   //ひよこ
                                                 {33750, 33750, 33750, 33750, 26800, 26800,     0,     0,     0,     0},   //破壊
                                                 {33000, 33000, 33750, 33750, 33750, 28500,     0,     0,     0,     0},   //こたつ
                                                 {33750, 32000, 33750, 33750, 33750, 33750, 26800, 26800,     0,     0},   //オセロ
                                                 {33750, 32000, 33750, 33750, 33750,     0,     0,     0,     0,     0},   //チェス
                                                 {33750, 33000,     0,     0,     0,     0,     0,     0,     0,     0},   //将棋
                                                 {33750, 33750, 33750, 31900, 31900,     0,     0,     0,     0,     0},   //輪花繚乱　持つ
                                                 {31900, 31900, 33750,     0,     0,     0,     0,     0,     0,     0},   //輪花繚乱　投げる
                                                 {33750, 33750, 33750, 33000,     0,     0,     0,     0,     0,     0},   //出前迅速　持つ
                                                 {33750, 33750, 33750, 33750, 26800, 26800,     0,     0,     0,     0},   //出前迅速　置く
                                                 {33750, 33750, 33750, 33750, 33000, 27400,     0,     0,     0,     0},   //大江戸　持つ
                                                 {27400, 33500, 27400, 27400,     0,     0,     0,     0,     0,     0},   //大江戸　斬る
                                                 {27400, 33750, 33750, 28500, 28500, 28500, 28500, 28500,     0,     0},   //ボーナス斬り
                                                 {33750, 33750,     0,     0,     0,     0,     0,     0,     0,     0}};  //停止
                                               
const unsigned short ArmPitchSpeed[20][10] = {{5, 3, 3, 3, 3, 3, 3, 3, 3, 3},   //最速ちゃぶ台返し
                                              {3, 3, 3, 6, 4, 3, 3, 3, 3, 3},   //アルティメットちゃぶ台返し1
                                              {3, 3, 3, 6, 4, 3, 3, 3, 3, 3},   //アルティメットちゃぶ台返し2
                                              {3, 3, 3, 3, 3, 3, 3, 3, 3, 4},   //消毒 決勝
                                              {3, 3, 3, 3, 7, 4, 3, 3, 3, 3},   //ボーナスちゃぶ台返し
                                              {3, 3, 3, 3, 3, 4, 3, 3, 3, 3},   //消毒
                                              {3, 3, 3, 3, 3, 3, 3, 3, 3, 3},   //ひよこ
                                              {3, 3, 3, 3, 6, 4, 3, 3, 3, 3},   //破壊
                                              {3, 3, 3, 3, 3, 5, 3, 3, 3, 3},   //こたつ
                                              {3, 3, 3, 3, 3, 3, 6, 4, 3, 3},   //オセロ
                                              {3, 3, 3, 3, 3, 3, 6, 4, 3, 3},   //チェス
                                              {5, 3, 3, 6, 4, 3, 3, 3, 3, 3},   //将棋
                                              {3, 3, 3, 3, 3, 3, 3, 3, 3, 3},   //輪花繚乱　持つ
                                              {5, 3, 3, 3, 3, 3, 3, 3, 3, 3},   //輪花繚乱　投げる
                                              {3, 3, 3, 3, 4, 3, 3, 3, 3, 3},   //出前迅速　持つ
                                              {3, 3, 3, 3, 6, 3, 3, 3, 3, 3},   //出前迅速　置く
                                              {3, 3, 3, 3, 4, 5, 3, 3, 3, 3},   //大江戸　持つ
                                              {6, 22, 6, 6, 3, 3, 3, 3, 3, 3},  //大江戸　斬る
                                              {6, 22, 3, 5, 3, 3, 3, 3, 3, 3},  //ボーナス斬り
                                              {3,  3, 3, 3, 3, 3, 3, 3, 3, 3}};  //停止

unsigned short DT_ArmPitchPosition[6][5] = {0};
unsigned short Goal_ArmPitchPosition = 0;
unsigned short Goal_ArmPitchSpeed = 0;

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

    if(!Check_Pitch){
        
        if( NowPosition+SLOW_WIDTH1<=GoalPosition )       velocity_ArmPitch = -300*SpeedLevel;
        else if( GoalPosition<=NowPosition-SLOW_WIDTH2 )  velocity_ArmPitch = 1500*SpeedLevel;
        else if(NowPosition<=GoalPosition)                              velocity_ArmPitch = -500;
        else if(GoalPosition<=NowPosition)                              velocity_ArmPitch = 2600;
    }else velocity_ArmPitch = 0;

    if(LockMode)    velocity_ArmPitch = 0;
}

bool Nextphase_PitchChack(int GoalPosition, int NowPosition, int dis){

    bool NoGoal = 0;
    
    if( ( (GoalPosition+dis)<=NowPosition) || (NowPosition<=(GoalPosition-dis) ) )  NoGoal = 1;
    if(NoGoal)  return !NoGoal;
    else        return 1;
}