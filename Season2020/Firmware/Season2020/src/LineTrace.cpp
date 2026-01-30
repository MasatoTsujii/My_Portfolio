#include <mbed.h>
#include "init.h"
#include "ArmUnit.h"
#include "interrupt.h"
#include "SerialSet.h"
#include "LineTrace.h"
#include "PIDcontroller.h"
#include "omnidirectionaldriver.h"

/*R:[0] L:[1]*/
int s=0;
short StopCount = -1;
double P=1.24,I=0,D=0.005;
double x = 0.000000;
float tclock = 100;
float val[2] = {};
int target[2] = {0};
float sp;
float balance_p = 0;
bool start_toggle = 0;
bool start_ButtonFlag = 1;
bool start_CircleFlag = 1;
bool activecheng = 0;

void LineTrace_Setting(void){

  sp = /*line_sense[0].read();*/0.85495;
  trace.setSetPoint(sp);
  trace.setInputLimits(0.74,1);
  trace.setOutputLimits(0,1);
}

void LineTrace(void){

    trace.setGain(P,I,D);
    trace.setProcessValue(line_sensor[0].read());
    //target[0] = target[1] = 0;
    if(/*stf*/1){
        target[0] = STRAIGHT_VELOC * (1+balance_p/2);
        target[1] = STRAIGHT_VELOC * (1-balance_p/2);
    }

    if(!DT_ActionButton.read()) start_toggle = 1;
    
    /*if( (!start_toggle) && (activecheng) && (start_ButtonFlag) ){
        start_toggle = 1;
    }else if( (start_toggle) && (activecheng) && (start_ButtonFlag) ){
        start_toggle = 0;
    }
    start_ButtonFlag = !activecheng;*/
    /*if( (!start_toggle) && (circle) && (start_CircleFlag) ){
        start_toggle = 1;
    }else if( (start_toggle) && (circle) && (start_CircleFlag) ){
        start_toggle = 0;
    }
    start_CircleFlag = !circle;*/

    if( (ActiveFlag) || (InitialFlag) || (StopCount+1==COMMAND_NUM) ){
        target[0] = target[1] = 0;
    }else if( (finishFlag) && (line_sensor[1].read()<FACE_DARK) ){
        target[0] = STRAIGHT_VELOC * (1+balance_p/2);
        target[1] = STRAIGHT_VELOC * (1-balance_p/2);
    }else if( (finishFlag) && (FACE_DARK<=line_sensor[1].read()) ){
        finishFlag = 0;
        target[0] = STRAIGHT_VELOC * (1+balance_p/2);
        target[1] = STRAIGHT_VELOC * (1-balance_p/2);
    }else if(line_sensor[1].read()<FACE_DARK){
        ActiveFlag = 1;
        Check_Move = 1;
        //move_command++;
        StopCount++;
        move_command = select_command[StopCount];
        monitoring_ArmUnit = 0;
        target[0] = target[1] = 0;
    }else if( (!shift.toggle) && (!start_toggle) ){
        target[0] = target[1] = I = 0;
    }
    else I = x;

    /*if( (select_command[StopCount+1]==8) || (select_command[StopCount+1]==9) || (select_command[StopCount+1]==10) || (select_command[StopCount+1]==11) || (select_command[StopCount+1]==10) || (select_command[StopCount+1]==12) || (select_command[StopCount+1]==14) || (select_command[StopCount+1]==15) ){
        target[0] /= 1.5;
        target[1] /= 1.5;
    }*/

    /*if( (key_a.press) && (!shift.toggle) )  target[0] = target[1] = 7500;
    if( (key_d.press) && (!shift.toggle) )  target[0] = target[1] = -7500;
    if( (key_w.press) && (!shift.toggle) ){
        target[0] = 5000;
        target[1] = -5000;
    }
    if( (key_s.press) && (!shift.toggle) ){
        target[0] = -5000;
        target[1] = 5000;
    }*/

    //if(StopCount==3)    StopCount = -1;
    //if(move_command>=12)     move_command = 10;
}