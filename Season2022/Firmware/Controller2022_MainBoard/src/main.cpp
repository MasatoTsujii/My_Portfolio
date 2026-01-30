#include <mbed.h>
#include "init.h"
//#include "IM920s.h"
#include "Controller.h"
//#include "Adafruit_ILI9341.h"

Adafruit_ILI9341 tft = Adafruit_ILI9341(PC_2, PC_3, PC_7, PB_7, PH_1, PC_13);
IM920sDriver IM920s(PC_10, PC_11, PD_2);
Thread thread;
//IM920sDriver IM920s(PA_0, PA_1, PB_0);

char controllerData[16] = {0};
char receivedData[40] = {0};
//char receivedData[35] = {0x30, 0x30, 0x2C, 0x30, 0x46, 0x41, 0x39, 0x2C, 0x90, 0x80, 0x3A, 0xF7, 0xF7, 0xF7, 0xF7, 0xF7, 0xE7, 0xF7, 0xF7, 0xF7, 0xF7, 0xF7, 0xF7, 0xF7, 0xD5, 0x03, 0xF7, 0x41, 0x42, 0x45, 0x39, 0xA0, 0x0D, 0x0D, 0x0A};
//                        1     2     3     4     5     6     7     8     9     10    11    12    13    14    15    16    17    18    19    20    21    22    23    24    25    26    27    28    29    30    31    32    33    334   35
//uint8_t 

// uint16_t Injection[2] = {16353, 16353};
// uint16_t pitchAngle[2] = {1023, 1023};
// int32_t Xposition = -1048575;
// int32_t Yposition = 1048575;
// int16_t Rposition = -180;

uint16_t Injection[2] = {0};
// double pitchAngle[2] = {400.0, 600.0};
//uint16_t pitchAngle[2] = {0};
int32_t Xposition = 0;
int32_t Yposition = 0;
int16_t Rposition = 0;

char node1[4] = {0x30, 0x46, 0x41, 0x39};
char node2[4] = {0x41, 0x42, 0x45, 0x39};

//uint8_t LEDdata[2] = {0};

//char myData1[16] = {0x07, 0xF0, 0x06, 0xF0, 0x07, 0xF0, 0x07, 0xA0, 0xE0, 0xB0, 0xC0, 0xE0, 0xB0, 0xD0, 0xF7, 0xE7};
//char myData2[16] = {0x01, 0xF7, 0xF6, 0xF7, 0xF7, 0xF7, 0xF7, 0xF7, 0xE7, 0xF7, 0xF7, 0xE7, 0xF7, 0xF7, 0xE7, 0xF7};
//                    1     2     3     4     5     6     7     8     9    10    11    12    13    14    15    16
//char group[8] = {0x34, 0x39, 0x31, 0x37, 0x37, 0x30, 0x31, 0x35};
//char conData[50] = {0};
int _count = 0;

void displayThread(void);
void LED_Controller(void);
//void getDisplayData(char _data[]);
//void getDisplayData(void);
void outDisplay(int16_t _x, int16_t _y, int _n, bool _signed);
// uint8_t bitShift_InData(uint8_t _data);

int main(void)
{
  HAL_Delay(1000);
  init();
  thread.start(displayThread);

  while(1)
  {
    if( ControlFlg() )
    {
      setControllerData(controllerData);
      //IM920s.write(controllerData);
      //IM920s.write(node1, myData2);
      IM920s.write(node1, controllerData);
      //IM920s.getNode();
      // for(int i=0; i<16; i++)
      // {
      //   printf("%x\t", controllerData[i]);
      // }
      // IM920s.read(conData);
      // for(size_t i=0; conData[i]!='\0'; i++)
      // {
      //   printf("%x ", conData[i]);
      // }
      // //printf("%d\n", _count);
      //printf("\n");
      //IM920s.getNode();
      //printf("\n");
      //IM920s.getGroup();
      //IM920s.write(node2, myData2);
      // IM920s.write(myData1);
      //IM920s.write(node2, myData2);
      //IM920s.getParameter();
      //IM920s.read(receivedData);
      //IM920s.write(node2, controllerData);
      //printf("\nasadf %d\n", IM920s.sa());
      //_count++;
    }
  }
/*
  while(1)
  {
    if( ControlFlg() )
    {
      for(int i=0; i<9; i++)
      {
        printf("Tact%d:%d  ", i, TactSW[i].read());
      }
      printf("\n");
      for(int i=0; i<10; i++)
      {
        printf("Togg%d:%d  ", i, ToggleSW[i].read());
      }
      printf("\n");
      printf("SC1:%d, SC2:%d\n", SC[0].read_u16(), SC[1].read_u16());
      //printf("JSLX:%d, JSLY:%d\n", JSL[0].read_u16(), JSL[1].read_u16());
      //printf("JSRX:%d, JSRY:%d\n", JSR[0].read_u16(), JSR[1].read_u16());
      printf("Pitch1:%d, Pitch2:%d\n", Pitch1, Pitch2);
    }
  }*/
}

void displayThread(void)
{
  tft.begin();
  tft.fillScreen(ILI9341_BLACK);
  tft.setTextSize(3);
  tft.setRotation(-45);
  tft.setCursor(0,0);
  tft.print("Injection1      0");
  tft.print("Angle1          0");
  tft.print("\nInjection2      0");
  tft.print("Angle2          0");
  // tft.print("\nX               0");
  // tft.print("Y               0");
  // tft.print("R               0");

  while(1)
  {
    //IM920s.read(receivedData);
    //getDisplayData(receivedData);
    //getDisplayData();
    tft.fillRect(216, 0, 90, 117, ILI9341_BLACK);
    outDisplay(216, 0, (double)(SC1)/SC_MAX*5000, 0);
    outDisplay(234, 24, (double)(Pitch1), 0);
    outDisplay(216, 72, (double)(SC2)/SC_MAX*5000, 0);
    outDisplay(234, 96, (double)(Pitch2), 0);
    // tft.fillRect(162, 144, 144, 69, ILI9341_BLACK);
    // outDisplay(162, 144, Xposition, 1);
    // outDisplay(162, 168, Yposition, 1);
    // outDisplay(234, 192, Rposition, 1);
    //getDisplayData();
  }
}

void outDisplay(int16_t _x, int16_t _y, int _n, bool _signed)
{
  // int8_t spaceNum = _digitsNum - 1 - (int8_t)(log10(_n));
  int8_t spaceNum = 16 - _x/18 - (int8_t)(log10(abs(_n)));
  
  if( (_signed) && (_n<0) )   spaceNum--;
  tft.setCursor(_x, _y);

  //printf("%d\n", spaceNum);
  
  switch(spaceNum)
  {
    case 1:
    tft.print(" ");
    break;

    case 2:
    tft.print("  ");
    break;

    case 3:
    tft.print("   ");
    break;

    case 4:
    tft.print("    ");
    break;

    case 5:
    tft.print("     ");
    break;

    case 6:
    tft.print("      ");
    break;

    case 7:
    tft.print("       ");
    break;
  }
  tft.print(_n);
}

// void getDisplayData(void/*char _data[]*/)
// {
//   pitchAngle[0] = (double)(_Pitch1)/2000.0 + 400.0;
//   pitchAngle[1] = (double)(_Pitch2)/2000.0 + 600.0;
  //_Pitch1 = 0.0;
  //_Pitch2 = 0.0;
  //int8_t i;
  // if( checkNode() )
  // {
    //Injection[0] = (bitShift_InData(_data[11])<<7) + bitShift_InData(_data[12]);
    //Injection[1] = (bitShift_InData(_data[13])<<7) + bitShift_InData(_data[14]);
    //pitchAngle[0] = (bitShift_InData(_data[15])<<3) + ((_data[16]&0xE0)>>5);
    //pitchAngle[1] = ((_data[16]&0x07)<<7) + bitShift_InData(_data[17]);
    //Xposition = (bitShift_InData(_data[18]&0x77)<<14) + (bitShift_InData(_data[19])<<7) + bitShift_InData(_data[20]);
    //if( _data[18]&0x80 )  Xposition *= -1;
    //Yposition = (bitShift_InData(_data[21]&0x77)<<14) + (bitShift_InData(_data[22])<<7) + bitShift_InData(_data[23]);
    //if( _data[21]&0x80 )  Yposition *= -1;
    //Rposition = (bitShift_InData(_data[24]&0x77)<<2) + ((_data[25]&0xC0)>>6);
    //if( _data[24]&0x80 )  Rposition *= -1;
  //}
// }

void LED_Controller(void)
{
  //LEDdata[0] = 0;
  char LEDdata[2] = {0};

  LEDdata[0] = 0;
  LEDdata[1] = 1;
  
  LEDBus.write(LEDdata, strlen(LEDdata));
}

// uint8_t bitShift_InData(uint8_t _data)
// {
//   return (((_data>>1)&0x78) | (_data&0x07));
// }