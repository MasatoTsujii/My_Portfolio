#include <mbed.h>
#include "init.h"
#include "ArmUnit.h"
#include "function.h"
#include "relay_Arm.h"
#include "SerialSet.h"
#include "interrupt.h"
#include "Dynamixel.h"
#include "LineTrace.h"
#include "relay_drive.h"
#include "ArmPitchUnit.h"

//void trace_PID();
void disp_term();
void disp_pc();

int main(void){

  init();
  dispSet();
  attachInterrupt();
  LineTrace_Setting();
  Setting();
  ThisThread::sleep_for(2s);
  while(1){

    // Button_JoyStick();
    ArmUnitInit();
    ArmPitchUnitInit();
    DirectTeaching();
    LineTrace();
    ArmDriver();
    ArmCheck();
    ArmPitch_move(Goal_ArmPitchPosition, Now_ArmPitchPosition, Goal_ArmPitchSpeed);
    ArmPitch_Asisst();
    relay_Arm(velocity_ArmPitch);
    relay_drive(target);
    // disp_term();
    disp_pc();
  }
  return 0;
}

void disp_term(void){

  /*advancedDisp(P,5);
  advancedDisp(D,5);
  advancedDisp(sp,5);*/
  //advancedDisp(line_sensor[0].read(),4);
  //advancedDisp(line_sensor[1].read(),4);
  /*advancedDisp(target[1]/gainy[1],4);
  advancedDisp(target[0]/gainy[0],4);*/
  //disp(Wait_ArmUnit);
  //disp(monitoring_ArmUnit);
  //disp(phase);
  //disp(Goal_ArmPitchSpeed);
  // disp(jslx);
  // disp(jsly);
  // disp(jsrx);
  // disp(jsry);
  // disp(circle);
  // disp(cross);
  // disp(triangle);
  // disp(square);
  // disp(l1);
  //disp(r1);
  /*if(!DT_Mode){
    //disp(ActiveFlag);
    //disp(finishFlag);
    disp(move_command+1);
    disp(StopCount+1);
    disp(DT_Lock[3]);
    //disp(velocity_ArmPitch);
    disp(Check_R);
    disp(Check_L);
    disp(Check_Pitch);
    //disp(Now_ArmPitchPosition);
    //disp(Goal_ArmPitchPosition);
  }else{
    for(int i=0; i<4; i++){
      disp(Now_ArmPosition_L[i]);
    }
    for(int i=0; i<4; i++){
      disp(Now_ArmPosition_R[i]);
    }
    disp(Now_ArmPitchPosition);
  }*/
  //advancedDisp(balance_p,5); 
  //disp(stf);
  // dnl();
  /*DebugPID(&P,&x,&D);
  DebugFW(&gainy[0],&gainy[1],&P,&I);
  DebugEnd();*/
}

void disp_pc(void){

  //disp(n);
  /*disp(m);*/
  for(int i=0; i<4; i++){
    disp(Now_ArmPosition_L[i]);
  }
  /*for(int i=0; i<4; i++){
    disp(Goal_ArmPosition_L[i]);
  }*/
  for(int i=0; i<4; i++){
    disp(Now_ArmPosition_R[i]);
  }
  /*for(int i=0; i<4; i++){
    disp(Goal_ArmPosition_R[i]);
  }*/
  /*for(int i=0; i<4; i++){
    disp(DT_ArmPosition_L[DT_ProcessNumber-1][DT_phase][i]);
  }*/
  /*for(int i=0; i<4; i++){
    disp(DT_ArmPosition_R[DT_ProcessNumber-1][DT_phase][i]);
  }*/
  /*disp(Now_ArmPitchPosition);
  disp(Goal_ArmPitchPosition);
  disp(velocity_ArmPitch);
  disp(Check_Pitch);
  disp(DT_phase);
  disp(DT_PhaseNum[DT_ProcessNumber-1]);
  disp(DT_ProcessNumber);
  disp(DT_SpeedMagnification);*/
  /*disp(DT_NumberNext);
  disp(DT_NumberPrev);
  disp(DT_Reset);
  disp(DT_PointButton);
  disp(DT_SpeedChangMode);*/
  //disp(ActiveFlag);
  //disp(100);
  //lb();
}