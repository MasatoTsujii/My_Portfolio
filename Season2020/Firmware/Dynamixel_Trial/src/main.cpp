#include "mbed.h"
#include "init.h"
#include "vs_disp.h"
#include "relay_Arm.h"
#include "ArmUnit.h"
#include "function.h"
#include "interrupt.h"
#include "Dynamixel.h"
#include "ArmPitchUnit.h"

//AX12A ax12a;
//Timer sendWait;
//int n=0, m=0;

void disp_pc(void){

  //disp(n);
  /*disp(m);*/
  /*for(int i=0; i<4; i++){
    disp(Now_ArmPosition_L[i]);
  }*/
  /*for(int i=0; i<4; i++){
    disp(Goal_ArmPosition_L[i]);
  }*/
  /*for(int i=0; i<4; i++){
    disp(Now_ArmPosition_R[i]);
  }*/
  /*for(int i=0; i<4; i++){
    disp(Goal_ArmPosition_R[i]);
  }*/
  /*for(int i=0; i<4; i++){
    disp(DT_ArmPosition_L[DT_ProcessNumber-1][DT_phase][i]);
  }*/
  /*for(int i=0; i<4; i++){
    disp(DT_ArmPosition_R[DT_ProcessNumber-1][DT_phase][i]);
  }*/
  disp(Now_ArmPitchPosition);
  disp(Goal_ArmPitchPosition);
  disp(velocity_ArmPitch);
  disp(Check_Pitch);
  disp(DT_phase);
  disp(DT_PhaseNum[DT_ProcessNumber-1]);
  disp(DT_ProcessNumber);
  disp(DT_SpeedMagnification);
  /*disp(DT_NumberNext);
  disp(DT_NumberPrev);
  disp(DT_Reset);
  disp(DT_PointButton);
  disp(DT_SpeedChangMode);*/
  disp(ActiveFlag);
  //disp(100);
  lb();
}

int main(void){

  init();
  Setting();
  attachInterrupt();
  ThisThread::sleep_for(5s);
  while(1){

    Button_JoyStick();
    ArmUnitInit();
    ArmPitchUnitInit();
    DirectTeaching();
    ArmPitch_Asisst();
    relay_Arm(velocity_ArmPitch);
    disp_pc();
  }
  return 0;
}