#include <mbed.h>
#include "IM920s.h"

IM920sDriver IM920s(PA_0, PA_1, PB_0);

//char node1[4] = {0x41, 0x42, 0x45, 0x39};
//char node1[4] = {0x30, 0x46, 0x41, 0x39};
//char node1[4] = {0x30, 0x30, 0x30, 0x31};
char Chan[2] = {0x31, 0x39};

int main(void)
{
  HAL_Delay(500);
  IM920s.setEnableWriting();
  //IM920s.setGroup();
  //IM920s.setNode(node1);
  //IM920s.setOutput(0x32);
  //IM920s.setChannel(Chan);
  //IM920s.setEnableCharacterIO();
  // IM920s.setDisableWriting();
  IM920s.setBaudRate(0x39, 460800);
  while(1)
  {
    IM920s.getID();
    HAL_Delay(10);
    IM920s.getNode();
    HAL_Delay(10);
    IM920s.getGroup();
    HAL_Delay(10);
    IM920s.getChannel();
    HAL_Delay(10);
    IM920s.getOutput();
    HAL_Delay(10);
    IM920s.getNetWork();
    HAL_Delay(10);
    IM920s.getHopCount();
    HAL_Delay(10);
    IM920s.getThreshold();
    HAL_Delay(10);
    //IM920s.getParameter();

    printf("loop\n");
    HAL_Delay(1500);
  }
}