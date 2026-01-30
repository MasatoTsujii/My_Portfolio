#include <mbed.h>
#include "init.h"
#include "ArmUnit.h"
#include "LineTrace.h"
#include "relay_Arm.h"
#include "interrupt.h"
#include "Dynamixel.h"
#include "ArmPitchUnit.h"

AX12A RobotArm;

unsigned char ArmID_L[4] = {0x40, 0x10, 0x04, 0x01};
unsigned char ArmID_R[4] = {0x80, 0x20, 0x08, 0x02};    //上から順番に
const short CWAngleLimit_ArmPosition_L[4] = {210, 200, 150, 480};
const short CWWAngleLimit_ArmPosition_L[4] = {820, 840, 900, 600};
const short CWAngleLimit_ArmPosition_R[4] = {150, 160, 150, 420};
const short CWWAngleLimit_ArmPosition_R[4] = {830, 800, 990, 535};

short Start_ArmPosition_L[4] = {515, 550, 500, 490};
short Start_ArmPosition_R[4] = {515, 470, 500, 530};
short Start_ArmSpeed_L[4] = {150, 150, 150, 150};
short Start_ArmSpeed_R[4] = {150, 150, 150, 150};

//short select_command[20] = {0, 0, 0, 0, 5, 0, 0, 0, 1, 2, 6, 0, 0, 9, 14, 15, 0, 0, 8, 0};            //予選
short select_command[24] = {3, 2, 2, 7, 2, 2, 9, 10, 11, 2, 2, 2, 12, 13, 2, 19, 2, 2, 16, 17, 18, 0, 0, 0};    //決勝
//short select_command[5] = {9, 10, 9, 10, 11};

const short ArmPosition_L[20][10][4] = {{{515, 810, 500, 490}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},        {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },   //1:最速ちゃぶ台返し
                                       {{400, 750, 815, 590}, {515, 750, 815, 590}, {515, 750, 815, 480}, {515, 780, 815, 480}, {515, 780, 815, 550}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },   //2:アルティメットちゃぶ台返し1
                                       {{400, 750, 815, 590}, {515, 750, 815, 590}, {515, 750, 815, 480}, {515, 780, 815, 480}, {515, 780, 815, 550}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },   //3:アルティメットちゃぶ台返し2
                                       {{530, 820, 815, 490}, {600, 750, 815, 490}, {600, 820, 815, 490}, {600, 750, 815, 490}, {600, 820, 815, 490}, {600, 750, 815, 490}, {600, 820, 815, 490}, {600, 750, 815, 490}, {530, 820, 815, 490}, {515, 550, 500, 490}},   //4:消毒 決勝
                                       {{340, 700, 650, 490}, {320, 750, 730, 590}, {515, 750, 815, 590}, {515, 750, 815, 480}, {515, 780, 815, 480}, {515, 780, 815, 550}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },   //5:ボーナスちゃぶ台返し
                                       {{530, 820, 815, 490}, {600, 750, 815, 490}, {600, 820, 815, 490}, {600, 750, 815, 490}, {530, 820, 815, 490}, {515, 550, 500, 490}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },   //6:消毒
                                       {{400, 750, 815, 590}, {515, 750, 815, 590}, {515, 750, 815, 480}, {515, 850, 815, 480}, {515, 750, 815, 480}, {380, 750, 815, 590}, {515, 550, 500, 490}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },   //7:ひよこ
                                       {{400, 750, 815, 590}, {515, 750, 815, 590}, {515, 750, 815, 480}, {450, 750, 815, 480}, {450, 780, 815, 480}, {450, 780, 815, 550}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },   //8:破壊
                                       {{340, 750, 500, 490}, {600, 750, 515, 490}, {280, 750, 500, 590}, {515, 740, 830, 590}, {515, 740, 830, 490}, {515, 800, 830, 490}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },   //9:こたつ
                                       {{400, 750, 500, 480}, {625, 850, 360, 480}, {350, 750, 500, 480}, {350, 750, 815, 580}, {515, 750, 815, 580}, {515, 750, 815, 490}, {515, 780, 815, 490}, {515, 780, 815, 550}, {0, 0, 0, 0},         {0, 0, 0, 0}        },   //10:オセロ
                                       {{400, 750, 500, 480}, {625, 850, 360, 480}, {350, 750, 500, 480}, {515, 550, 500, 490}, {515, 810, 500, 490}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },   //11:チェス
                                       {{515, 550, 500, 490}, {515, 810, 500, 490}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },   //12:将棋
                                       {{515, 550, 500, 490}, {515, 550, 500, 490}, {515, 550, 500, 490}, {600, 700, 500, 490}, {600, 700, 500, 490}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },   //13:輪花繚乱　持つ
                                       {{600, 650, 500, 490}, {600, 700, 500, 490}, {600, 620, 500, 490}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },   //14:輪花繚乱　投げる
                                       {{380, 750, 815, 590}, {515, 750, 815, 590}, {515, 750, 815, 480}, {515, 800, 815, 480}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },   //15:出前迅速　持つ
                                       {{515, 800, 815, 590}, {320, 790, 815, 590}, {515, 750, 815, 590}, {515, 750, 815, 480}, {515, 780, 815, 480}, {515, 780, 815, 550}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },   //16:出前迅速　置く
                                       {{515, 550, 500, 490}, {515, 550, 500, 490}, {515, 550, 500, 490}, {515, 550, 500, 490}, {630, 790, 580, 490}, {630, 770, 580, 490}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },   //17:大江戸　持つ
                                       {{630, 770, 580, 490}, {775, 600, 360, 490}, {630, 770, 580, 490}, {630, 770, 580, 490}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },   //18:大江戸　斬る
                                       {{630, 770, 580, 490}, {775, 600, 360, 490}, {775, 625, 360, 490}, {515, 750, 500, 590}, {415, 790, 500, 590}, {575, 790, 500, 590}, {415, 790, 500, 590}, {575, 790, 500, 590}, {0, 0, 0, 0},         {0, 0, 0, 0}        },   //19:ボーナス斬り
                                       {{515, 550, 500, 490}, {515, 550, 500, 490}, {515, 740, 500, 590}, {515, 740, 500, 540}, {515, 590, 500, 570}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        }};  //20:停止

const short ArmPosition_R[20][10][4] = {{{515, 205, 500, 530}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },   //最速ちゃぶ台返し
                                        {{625, 270, 195, 430}, {515, 270, 190, 430}, {515, 270, 190, 535}, {515, 230, 190, 535}, {515, 230, 190, 460}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },   //アルティメットちゃぶ台返し1
                                        {{625, 270, 195, 430}, {515, 270, 190, 430}, {515, 270, 190, 535}, {515, 230, 190, 535}, {515, 230, 190, 460}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },   //アルティメットちゃぶ台返し2
                                        {{470, 217, 205, 420}, {395, 217, 205, 420}, {395, 217, 205, 420}, {395, 217, 205, 420}, {395, 217, 205, 420}, {395, 217, 205, 420}, {395, 217, 205, 420}, {395, 217, 205, 420}, {470, 217, 205, 420}, {515, 470, 500, 530}},   //消毒 決勝
                                        {{660, 350, 330, 530}, {690, 270, 280, 430}, {515, 270, 190, 430}, {515, 270, 190, 530}, {515, 240, 190, 530}, {515, 240, 190, 460}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },   //ボーナスちゃぶ台返し
                                        {{470, 217, 205, 420}, {395, 217, 205, 420}, {395, 217, 205, 420}, {395, 217, 205, 420}, {470, 217, 205, 420}, {515, 470, 500, 530}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },   //消毒
                                        {{625, 270, 195, 430}, {515, 270, 190, 430}, {515, 270, 190, 535}, {515, 170, 190, 535}, {515, 270, 190, 535}, {645, 270, 195, 430}, {515, 470, 500, 530}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },   //ひよこ
                                        {{625, 270, 195, 430}, {515, 270, 190, 430}, {515, 270, 190, 535}, {575, 270, 190, 535}, {575, 230, 190, 535}, {575, 230, 190, 460}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },   //破壊
                                        {{710, 270, 500, 530}, {440, 270, 500, 530}, {730, 270, 500, 430}, {515, 280, 205, 450}, {515, 280, 205, 530}, {515, 180, 205, 530}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },   //こたつ
                                        {{700, 270, 500, 530}, {250, 260, 560, 530}, {730, 270, 500, 530}, {730, 270, 195, 440}, {515, 270, 195, 440}, {515, 270, 195, 535}, {515, 230, 195, 535}, {515, 230, 195, 460}, {0, 0, 0, 0},         {0, 0, 0, 0}        },   //オセロ
                                        {{700, 270, 500, 530}, {250, 260, 560, 530}, {730, 270, 500, 530}, {515, 470, 500, 530}, {515, 205, 500, 530}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },   //チェス
                                        {{515, 470, 500, 530}, {515, 205, 500, 530}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },   //将棋
                                        {{620, 260, 195, 430}, {515, 260, 195, 430}, {515, 260, 195, 500}, {400, 220, 195, 500}, {400, 220, 195, 500}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },   //輪花繚乱　持つ
                                        {{400, 270, 195, 500}, {400, 220, 195, 500}, {400, 350, 195, 430}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },   //輪花繚乱　投げる
                                        {{660, 270, 195, 430}, {515, 270, 190, 430}, {515, 270, 190, 540}, {515, 190, 190, 540}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },   //出前迅速　持つ
                                        {{515, 190, 190, 430}, {700, 200, 190, 430}, {515, 270, 190, 430}, {515, 270, 190, 535}, {515, 230, 190, 535}, {515, 230, 190, 460}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },   //出前迅速　置く
                                        {{660, 265, 195, 430}, {515, 265, 195, 430}, {515, 265, 195, 525}, {540, 230, 195, 525}, {400, 180, 600, 525}, {400, 180, 600, 525}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },   //大江戸　持つ
                                        {{400, 180, 600, 525}, {360, 380, 600, 525}, {400, 180, 550, 525}, {400, 180, 550, 525}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },   //大江戸　斬る
                                        {{400, 180, 550, 525}, {320, 380, 730, 525}, {320, 355, 730, 430}, {515, 260, 500, 430}, {615, 260, 500, 430}, {455, 260, 500, 430}, {615, 260, 500, 430}, {455, 260, 500, 430}, {0, 0, 0, 0},         {0, 0, 0, 0}        },   //ボーナス斬り
                                        {{515, 470, 500, 530}, {515, 470, 500, 530}, {515, 470, 500, 530}, {515, 470, 500, 530}, {515, 470, 500, 530}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        }};  //停止

const short ArmSpeed_L[20][10][4] = {{{150, 400, 150, 150}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },      //最速ちゃぶ台返し
                                     {{250, 250, 250, 250}, {250, 250, 250, 250}, {250, 250, 250, 250}, {250, 500, 250, 250}, {250, 250, 250, 250}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },      //アルティメットちゃぶ台返し1
                                     {{250, 250, 250, 250}, {250, 250, 250, 250}, {250, 250, 250, 250}, {250, 500, 250, 250}, {250, 250, 250, 250}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },      //アルティメットちゃぶ台返し2
                                     {{ 50, 150, 300, 100}, {300, 200, 250, 250}, {250, 200, 250, 250}, {250, 200, 250, 250}, {250, 200, 250, 250}, {250, 200, 250, 250}, {250, 200, 250, 250}, {250, 200, 250, 250}, { 50, 150, 250, 250}, {150, 150, 150, 150}},      //消毒 決勝
                                     {{300, 200, 250, 150}, {150, 150, 300, 150}, {250, 250, 250, 250}, {250, 250, 250, 250}, {250, 500, 250, 250}, {250, 250, 250, 250}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },      //ボーナスちゃぶ台返し
                                     {{ 50, 150, 300, 100}, {300, 200, 250, 250}, {250, 200, 250, 250}, {250, 200, 250, 250}, { 50, 150, 250, 250}, {150, 150, 150, 150}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },      //消毒
                                     {{250, 250, 250, 250}, {250, 250, 250, 250}, {250, 250, 250, 250}, {250,  50, 250, 250}, {250, 250, 250, 250}, {150, 150, 150, 150}, { 50, 300, 150, 150}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },      //ひよこ
                                     {{250, 250, 250, 250}, {250, 250, 250, 250}, {250, 250, 250, 250}, {500, 200, 250, 250}, {250, 500, 250, 250}, {250, 250, 250, 250}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },      //破壊
                                     {{250, 250, 250, 250}, {100, 300, 150, 150}, {270, 150, 150, 150}, { 50, 150, 500, 150}, {250, 250, 250, 250}, {250, 250, 250, 250}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },      //こたつ
                                     {{250, 250, 250, 250}, {150, 300, 150, 150}, {300, 150, 150, 150}, {150, 150, 300, 300}, {300, 150, 150, 150}, {150, 150, 150, 300}, {250, 500, 250, 250}, {250, 250, 250, 250}, {0, 0, 0, 0},         {0, 0, 0, 0}        },      //オセロ
                                     {{250, 250, 250, 250}, {150, 300, 150, 150}, {300, 150, 150, 150}, {150, 150, 300, 300}, {300, 150, 150, 150}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },      //チェス
                                     {{250, 250, 250, 250}, {150, 400, 150, 150}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },      //将棋
                                     {{250, 250, 250, 250}, {250, 250, 250, 150}, {250, 250, 250, 250}, {250, 250, 150, 150}, {150, 150, 150, 150}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },      //輪花繚乱　持つ
                                     {{250, 250, 250, 250}, {250, 250, 250, 250}, {250, 250, 250, 250}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },      //輪花繚乱　投げる
                                     {{250, 250, 250, 250}, {250, 250, 250, 250}, {250, 250, 250, 250}, {250, 100, 250, 250}, {250, 250, 250, 250}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },      //出前迅速　持つ
                                     {{250,  50, 250,  50}, {400,  50, 150, 150}, { 50, 300, 250, 250}, {250, 250, 250, 250}, {250, 250, 250, 250}, {250, 250, 250, 250}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },      //出前迅速　置く
                                     {{150, 150, 150, 150}, {150, 150, 150, 150}, {150, 150, 150, 150}, {100, 150, 100, 100}, {100, 150, 100, 100}, {150, 150, 150, 150}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },      //大江戸　持つ
                                     {{150, 150, 150, 150}, {150, 150, 150, 150}, {150, 150, 150, 150}, {150, 150, 150, 150}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },      //大江戸　斬る
                                     {{150, 150, 150, 150}, {150, 150, 150, 150}, {150, 150, 150, 150}, {250, 250, 250, 250}, {150, 150, 150, 150}, {150, 150, 150, 150}, {150, 150, 150, 150}, {150, 150, 150, 150}, {0, 0, 0, 0},         {0, 0, 0, 0}        },      //ボーナス斬り
                                     {{150, 150, 150, 150}, {150, 150, 150, 150}, {150, 150, 150, 150}, {150, 150, 150, 150}, {150, 150, 150, 150}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        }};     //停止

const short ArmSpeed_R[20][10][4] = {{{150, 1000, 150, 150}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },     //最速ちゃぶ台返し
                                     {{150, 400, 250, 250},  {250, 250, 250, 250}, {250, 250, 250, 250}, {250, 630, 250, 250}, {250, 250, 250, 250}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },     //アルティメットちゃぶ台返し1
                                     {{150, 400, 250, 250},  {250, 250, 250, 250}, {250, 250, 250, 250}, {250, 630, 250, 250}, {250, 250, 250, 250}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },     //アルティメットちゃぶ台返し2
                                     {{100, 300, 300, 300},  {150, 150, 150, 150}, {150, 150, 150, 150}, {150, 150, 150, 150}, {150, 150, 150, 150}, {150, 150, 150, 150}, {150, 150, 150, 150}, {150, 150, 150, 150}, { 50, 150, 150, 150}, {150, 150, 150, 150}},     //消毒 決勝
                                     {{300, 200, 250, 250},  {150, 150, 300, 150}, {250, 250, 250, 250}, {250, 250, 250, 250}, {250, 630, 250, 250}, {250, 250, 250, 250}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },     //ボーナスちゃぶ台返し
                                     {{100, 300, 300, 300},  {150, 150, 150, 150}, {150, 150, 150, 150}, {150, 150, 150, 150}, { 50, 150, 150, 150}, {150, 150, 150, 150}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },     //消毒
                                     {{250, 250, 250, 250},  {250, 250, 250, 250}, {250, 250, 250, 250}, {250,  50, 250, 250}, {250, 250, 250, 250}, {150, 150, 150, 150}, { 50, 300, 150, 150}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },     //ひよこ
                                     {{250, 250, 250, 250},  {250, 250, 250, 250}, {250, 250, 250, 250}, {500, 200, 250, 250}, {250, 630, 250, 250}, {250, 250, 250, 250}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },     //破壊
                                     {{250, 250, 250, 250},  {100, 300, 150, 150}, {150, 150, 150, 150}, { 65, 150, 500, 150}, {250, 150, 250, 250}, {250, 250, 250, 250}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },     //こたつ
                                     {{250, 250, 250, 250},  {300, 150, 150, 150}, {300, 150, 150, 150}, {150, 150, 300, 300}, {300, 150, 150, 150}, {150, 150, 150, 300}, {250, 250, 250, 250}, {250, 250, 250, 250}, {0, 0, 0, 0},         {0, 0, 0, 0}        },     //オセロ
                                     {{250, 250, 250, 250},  {300, 150, 150, 150}, {300, 150, 150, 150}, {150, 150, 300, 300}, {300, 150, 150, 150}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },     //チェス
                                     {{250, 250, 250, 250},  {150, 800, 150, 150}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },     //将棋
                                     {{150, 150, 150, 150},  {150, 150, 150, 150}, {150, 150, 150, 150}, {250, 250, 150, 150}, {150, 150, 150, 150}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },     //輪花繚乱　持つ
                                     {{250, 250, 250, 250},  {250, 250, 250, 250}, {150, 150, 150, 150}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },     //輪花繚乱　投げる
                                     {{250, 250, 250, 250},  {250, 250, 250, 250}, {250, 250, 250, 250}, {250, 100, 250, 250}, {250, 250, 250, 250}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },     //出前迅速　持つ
                                     {{250,  50, 250,  50},  {350,  50, 150, 150}, { 50, 300, 250, 250}, {250, 250, 250, 250}, {250, 250, 250, 250}, {250, 250, 250, 250}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },     //出前迅速　置く
                                     {{200, 150, 150, 100},  {250, 200, 200, 200}, {150, 150, 150, 250}, { 50, 100, 450, 150}, { 50,  80, 550, 150}, {150, 150, 150, 150}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },     //大江戸　持つ
                                     {{150, 150, 150, 150},  {150, 150, 150, 150}, {250, 250, 250, 250}, {250, 250, 250, 250}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        },     //大江戸　斬る
                                     {{150, 150, 150, 150},  {150, 150, 150, 150}, {150, 150, 150, 150}, {250, 250, 250, 250}, {150, 150, 150, 150}, {150, 150, 150, 150}, {150, 150, 150, 150}, {150, 150, 150, 150}, {0, 0, 0, 0},         {0, 0, 0, 0}        },     //ボーナス斬り
                                     {{150, 150, 150, 150},  {150, 150, 150, 150}, {150, 150, 150, 150}, {150, 150, 150, 150}, {150, 150, 150, 150}, {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0},         {0, 0, 0, 0}        }};    //停止

const short ArmWait[20][10] = {{ 400,    0,    0,    0,    0,    0,    0,    0,   0},    //最速ちゃぶ台返し
                               {  10,   10, 1500,   10,   10,    0,    0,    0,   0},    //アルティメットちゃぶ台返し1
                               {  10,   10,  500,   10,   10,    0,    0,    0,   0},    //アルティメットちゃぶ台返し2
                               {1000,   10,   10,   10,   10,   10,   10,   10, 100},    //消毒 決勝
                               {  10,   10,   10, 2000,   10,   10,    0,    0,   0},    //ボーナスちゃぶ台返し
                               {1000,  100,  100,  100,  500,    0,    0,    0,   0},    //消毒
                               { 100,  100,  100, 1900,  100,  100,  100,    0,   0},    //ひよこ
                               { 100,  100, 2000,  500,  100,  100,    0,    0,   0},    //破壊
                               { 100, 4000,  100,  100,  100, 3000,    0,    0,   0},    //こたつ
                               { 100, 3500,   50,   50,   50,   50,  500,   10,   0},    //オセロ
                               { 100, 2500,   50,  500,   50,    0,    0,    0,   0},    //チェス
                               {2000,   10,    0,    0,    0,    0,    0,    0,   0},    //将棋
                               { 100,  100,  100, 1000,  100,    0,    0,    0,   0},    //輪花繚乱　持つ
                               {1000, 1000, 1000,    0,    0,    0,    0,    0,   0},    //輪花繚乱　投げる
                               { 500,  500,  500,  500,    0,    0,    0,    0,   0},    //出前迅速　持つ
                               {2000,  500,  500,  500,  500,   10,    0,    0,   0},    //出前迅速　置く
                               { 100,  100,  100,  100,  500,  100,    0,    0,   0},    //大江戸　持つ
                               {1500, 1500,  100,  100,    0,    0,    0,    0,   0},    //大江戸　斬る
                               {2000, 3000,   10,  500,  500,  500,  500,  500,   0},    //ボーナス斬り
                               {2000,   10,    0,    0,    0,    0,    0,    0,   0}};   //停止

const short PhaseNum[20] =          {1, 5, 5, 10, 6, 6, 7, 6, 6, 8, 5, 2, 5, 3, 4, 6, 6, 4, 8, 2};
const bool Back_StartPosition[20] = {1, 1, 1,  1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0};

short Goal_ArmPosition_L[4] = {0};
short Goal_ArmPosition_R[4] = {0};
short Goal_ArmSpeed_L[4] = {0};
short Goal_ArmSpeed_R[4] = {0};

short Next_ArmPosition_L[4] = {0};
short Next_ArmPosition_R[4] = {0};
short Now_ArmPosition_L[4] = {0};
short Now_ArmPosition_R[4] = {0};

short move_command = 0;
short phase = 0;
short Wait = 0;
short Activetime = 0;
bool finishFlag = 0;
bool ActiveFlag = 0;
bool Check_L, Check_R, Check_Time;
bool Check_Move;
bool InitialFlag = 0;

short DT_ArmPosition_L[6][9][4] = {0};
short DT_ArmPosition_R[6][9][4] = {0};
short DT_PhaseNum[6] = {-1, -1, -1, -1, -1, -1};
short DT_Speed[4] = {100, 100, 100, 100};
short DT_WaitTime[6] = {3000, 2500, 2000, 1500, 1000, 500};
short DT_SpeedMagnification = 1;
short DT_ProcessNumber = 1;
short DT_Lock[4] = {0};
short DT_phase = 0;
bool DT_Next_ButtonFlag = 0;
bool DT_Prev_ButtonFlag = 0;
bool DT_Point_ButtonFlag = 0;
bool DT_Action_ButtonFlag = 0;
bool DT_SpeedChangMode = 0;
bool DT_Reset_Flag = 0;
bool DT_OperationFirst;
bool DT_PointButton;
bool DT_NumberNext;
bool DT_NumberPrev;
bool DT_Action;
bool DT_Reset;
bool DT_Mode;

int i, j;

void Setting(void){

    /*RobotArm.setShutdownAlarm(BROADCAST_ID, AX_SHUTDOWN_ALARM, 0);
    RobotArm.setShutdownAlarm(BROADCAST_ID, AX_SHUTDOWN_ALARM, 1);
    RobotArm.setLEDAlarm(BROADCAST_ID, AX_LED_ALARM, 0);
    RobotArm.setLEDAlarm(BROADCAST_ID, AX_LED_ALARM, 1);*/
    /*for(i=0; i<4; i++){
        RobotArm.setAngleLimit(ArmID_L[i], CWAngleLimit_ArmPosition_L[i], CWWAngleLimit_ArmPosition_L[i], 0, 0);
        RobotArm.setAngleLimit(ArmID_R[i], CWAngleLimit_ArmPosition_R[i], CWWAngleLimit_ArmPosition_R[i], 1, 0);
    }*/
    Now_ArmPitchPosition = Arm_volume.read_u16();
    for(i=0; i<7; i++){
        LED_7seg[i] = 1;
    }
    RobotArm.moveSpeed_SYNC(ArmID_L, Start_ArmPosition_L, Start_ArmSpeed_L, 0);
    RobotArm.moveSpeed_SYNC(ArmID_R, Start_ArmPosition_R, Start_ArmSpeed_R, 1);
    for(i=0; i<4; i++){
        Goal_ArmPosition_L[i] = Start_ArmPosition_L[i];
        Goal_ArmPosition_R[i] = Start_ArmPosition_R[i];
        Goal_ArmSpeed_L[i] = Start_ArmSpeed_L[i];
        Goal_ArmSpeed_R[i] = Start_ArmSpeed_R[i];
    }
    //ArmPitchUnitInit();
    while(Now_ArmPitchPosition<Start_ArmPitchPosition-200){
        ArmPitchUnitInit();
        relay_Arm(-450);
    }
    Check_Pitch = 1;
}

void ArmDriver(void){

    //DT_Mode = 0;
    if( (!DT_Mode) && (ActiveFlag) ){
        
        for(i=0; i<4; i++){
            Next_ArmPosition_L[i] = ArmPosition_L[move_command][phase][i];                
            Next_ArmPosition_R[i] = ArmPosition_R[move_command][phase][i];
        }
        Next_ArmPitchPosition = ArmPitchPosition[move_command][phase];

        if(Check_Move){

            for(i=0; i<4; i++){
                Goal_ArmPosition_L[i] = Next_ArmPosition_L[i];
                Goal_ArmPosition_R[i] = Next_ArmPosition_R[i];
                Goal_ArmSpeed_L[i] = ArmSpeed_L[move_command][phase][i];
                Goal_ArmSpeed_R[i] = ArmSpeed_R[move_command][phase][i];
            }
            Goal_ArmPitchSpeed = ArmPitchSpeed[move_command][phase];
            Goal_ArmPitchPosition = Next_ArmPitchPosition;
            Wait = ArmWait[move_command][phase];

            //RobotArm.moveSpeed_SYNC(ArmID_L, Goal_ArmPosition_L, Goal_ArmSpeed_L, 0);
            //RobotArm.moveSpeed_SYNC(ArmID_R, Goal_ArmPosition_R, Goal_ArmSpeed_R, 1);
            j++;
            Check_L = Check_R = Check_Pitch = Check_Move = 0;

            if(PhaseNum[move_command]==phase+1){

                phase = 0;
                if(move_command==18){
                    phase = 4;
                    ActiveFlag = 1;
                }else if(Back_StartPosition[move_command]){

                    InitialFlag = 1;
                    ActiveFlag = 0;
                }else{
                    
                    InitialFlag = 0;
                    finishFlag = 1;
                    ActiveFlag = 0;
                }
            }else{
                phase++;
            }
            Wait_ArmUnit = monitoring_ArmUnit = 0;
        }
    }else if( (!DT_Mode) && (Check_Move) && (InitialFlag) && (Wait<Wait_ArmUnit) ){
        
        //RobotArm.moveSpeed_SYNC(ArmID_L, Goal_ArmPosition_L, Goal_ArmSpeed_L, 0);
        //RobotArm.moveSpeed_SYNC(ArmID_R, Goal_ArmPosition_R, Goal_ArmSpeed_R, 1);
        for(i=0; i<4; i++){
            Goal_ArmPosition_L[i] = Start_ArmPosition_L[i];
            Goal_ArmPosition_R[i] = Start_ArmPosition_R[i];
            Goal_ArmSpeed_L[i] = Start_ArmSpeed_L[i];
            Goal_ArmSpeed_R[i] = Start_ArmSpeed_R[i];
        }
        Goal_ArmPitchPosition = Start_ArmPitchPosition;
        Goal_ArmPitchSpeed = 15;

        Check_L = Check_R = Check_Pitch = Check_Move = 0;
        InitialFlag = 0;
        finishFlag = 1;
        ActiveFlag = 0;
    }
    if( (!DT_Mode) ){
        RobotArm.moveSpeed_SYNC(ArmID_L, Goal_ArmPosition_L, Goal_ArmSpeed_L, 0);
        RobotArm.moveSpeed_SYNC(ArmID_R, Goal_ArmPosition_R, Goal_ArmSpeed_R, 1);
    }
}

void ArmCheck(void){
    
    if(!DT_Mode){
        if(!Check_L)        Check_L = Nextphase_ArmChack(Goal_ArmPosition_L, Now_ArmPosition_L, 10);
        if(!Check_R)        Check_R = Nextphase_ArmChack(Goal_ArmPosition_R, Now_ArmPosition_R, 7);
        if(!Check_Pitch)    Check_Pitch = Nextphase_PitchChack(Goal_ArmPitchPosition, Now_ArmPitchPosition, 200);

        if( ( (!Check_L) || (!Check_R) || (!Check_Pitch) ) && ( (ActiveFlag) || (InitialFlag) ) ){
            if(2000<monitoring_ArmUnit){
                Check_L = Check_R = Check_Pitch = 1;
                //j = -100;
                //Wait_ArmUnit = 0;
            }
        }

        if( (Check_L) && (Check_R) && (Check_Pitch) && (Wait<Wait_ArmUnit) )         Check_Move = 1;
        //Check_Move = 1;
    }
}

/////////////////////////////////////////////////////////////////////////////////////

void DirectTeaching(void){

    static bool Pitch_move = 0;
    if( (DT_Mode) && (!ActiveFlag) && (!DT_Lock[0]) ){

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

            if(!Check_L)        Check_L = Nextphase_ArmChack(Goal_ArmPosition_L, Now_ArmPosition_L, 4);
            if(!Check_R)        Check_R = Nextphase_ArmChack(Goal_ArmPosition_R, Now_ArmPosition_R, 4);
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
                monitoring_ArmUnit = 0;
            }else if( (!Check_L) || (!Check_R) || (!Check_Pitch) ){
                Wait_ArmUnit = 0;
                if( (5000-( (DT_SpeedMagnification-1)*500) )<monitoring_ArmUnit ){
                    Check_L = 1;
                    Check_R = 1;
                    Check_Pitch = 1;
                }
            }
            if( (!Check_Time) && (Check_L) && (Check_R) && (Check_Pitch) && (DT_WaitTime[move_command]<=Wait_ArmUnit) ){
                Check_Time = 1;
                Wait_ArmUnit = 0;
                monitoring_ArmUnit = 0;
            }

            if( (Check_L) && (Check_R) && (Check_Pitch) && (Check_Time) ){

                Goal_ArmPitchPosition = Next_ArmPitchPosition;
                Pitch_move = 1;
                Check_Pitch = 0;
            }
            
            if( (500<Wait_ArmUnit) && (Pitch_move) ){

                for(i=0; i<4; i++){
                    Goal_ArmPosition_L[i] = Next_ArmPosition_L[i];
                    Goal_ArmPosition_R[i] = Next_ArmPosition_R[i];
                    DT_Speed[i] = 140*DT_SpeedMagnification;
                }
                RobotArm.moveSpeed_SYNC(ArmID_L, Next_ArmPosition_L, DT_Speed, 0);
                RobotArm.moveSpeed_SYNC(ArmID_R, Next_ArmPosition_R, DT_Speed, 1);
                DT_phase = (DT_phase==DT_PhaseNum[move_command]) ? 0 : DT_phase+1;
                Check_L = 0;
                Check_R = 0;
                Check_Time = 0;
                Check_Pitch = 0;
                Wait_ArmUnit = 0;
                monitoring_ArmUnit = 0;
                //LockMode = 0;
                Pitch_move = 0;
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

    short readPosition;
    DT_Mode = DT_Switch.read();
    DT_NumberNext = !Change_Next.read();
    DT_NumberPrev = !Change_Prev.read();
    DT_Reset = !DT_ResetButton.read();
    DT_PointButton = !PointButton.read();
    for(i=0; i<4; i++){

        readPosition = RobotArm.readPosition(ArmID_L[i], 0);
        if(-1<readPosition){
            Now_ArmPosition_L[i] = readPosition;
        }
        readPosition = RobotArm.readPosition(ArmID_R[i], 1);
        if(-1<readPosition){
            Now_ArmPosition_R[i] = readPosition;
        }
        DT_Lock[i] = !DIP_INPUT[i].read();
    }
    //DT_Mode = 0;
    if(DT_Mode){
        
        DT_SpeedChangMode = DT_SpeedSwitch.read();
        DT_Reset = !DT_ResetButton.read();
        DT_Action = !DT_ActionButton.read();
        if( (DT_Action) && (!ActiveFlag) && (DT_Action_ButtonFlag) ){
            DT_phase = 0;
            ActiveFlag = 1;
            DT_OperationFirst = 1;
            DT_SpeedMagnification = 1;
            Goal_ArmPitchPosition = 0;
            velocity_ArmPitch = 0;
        }else if( (DT_Action) && (ActiveFlag) && (DT_Action_ButtonFlag) ){
            DT_phase = 0;
            ActiveFlag = 0;
            DT_OperationFirst = 0;
            DT_SpeedMagnification = 1;
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
                Check_Pitch = 0;
                DT_ProcessNumber++;
                DT_ProcessNumber = (DT_ProcessNumber==7) ? 1 : DT_ProcessNumber;
            }else if( (DT_Prev_ButtonFlag) && (DT_NumberPrev) ){

                DT_phase = 0;
                Check_Pitch = 0;
                DT_ProcessNumber--;
                DT_ProcessNumber = (DT_ProcessNumber==0) ? 6 : DT_ProcessNumber;
            }
        }
        DT_Next_ButtonFlag = !DT_NumberNext;
        DT_Prev_ButtonFlag = !DT_NumberPrev;
        
        if( (DT_Reset) && (!ActiveFlag) ){

            DT_phase = 0;
            Check_Pitch = 0;
            for(i=0; i<5; i++){
                for(j=0; j<4; j++){
                    DT_ArmPosition_L[DT_ProcessNumber-1][i][j] = 0;
                    DT_ArmPosition_R[DT_ProcessNumber-1][i][j] = 0;
                    DT_PhaseNum[DT_ProcessNumber-1] = -1;
                }
            }
        }

        if( (DT_Lock[0]) && (!ActiveFlag) ){
            
            RobotArm.torqueStatus(BROADCAST_ID, 1, 0);
            RobotArm.torqueStatus(BROADCAST_ID, 1, 1);
        }
        if( (DT_Lock[1]) && (!ActiveFlag) ){
            LockMode = 1;
        }else if( (!DT_Lock[1]) && (!ActiveFlag) ){
            LockMode = 0;
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
        //ActiveFlag = 0;
        DT_SpeedMagnification = 1;
        /*for(i=0; i<4; i++){
            Goal_ArmPosition_L[i] = 0;
            Goal_ArmPosition_R[i] = 0;
            Next_ArmPosition_L[i] = 0;
            Next_ArmPosition_R[i] = 0;
        }*/
        if( (DT_Next_ButtonFlag) && (DT_NumberNext) ){
            StopCount++;
            //StopCount = (COMMAND_NUM-1 < StopCount) ? COMMAND_NUM-1 : StopCount;
        }else if( (DT_Prev_ButtonFlag) && (DT_NumberPrev) ){
            StopCount--;
            //StopCount = (StopCount<0) ? 0 : StopCount;
        }else if( (DT_Point_ButtonFlag) && (DT_PointButton) ){
            StopCount += 5;
        }else if( (DT_Reset_Flag) && (DT_Reset) ){
            StopCount -= 5;
        }
        StopCount = (COMMAND_NUM-1 < StopCount) ? COMMAND_NUM-1 : StopCount;
        StopCount = (StopCount<-1) ? -1 : StopCount;
        DT_Next_ButtonFlag = !DT_NumberNext;
        DT_Prev_ButtonFlag = !DT_NumberPrev;
        DT_Point_ButtonFlag = !DT_PointButton;
        DT_Reset_Flag = !DT_Reset;

        if(DT_Lock[3]){
            LED_OutPut( (StopCount+1)%10 );
        }else{
            LED_OutPut(-1);
        }
    }
}

void LED_OutPut(int Number){
                               //6  7  9 10  1  2  4
    bool LED7seg_Out[10][7] = {{1, 1, 1, 1, 1, 1, 0},   //0
                              {0, 1, 1, 0, 0, 0, 0},   //1
                              {1, 1, 0, 1, 1, 0, 1},   //2
                              {1, 1, 1, 1, 0, 0, 1},   //3
                              {0, 1, 1, 0, 0, 1, 1},   //4
                              {1, 0, 1, 1, 0, 1, 1},   //5
                              {1, 0, 1, 1, 1, 1, 1},   //6
                              {1, 1, 1, 0, 0, 0, 0},   //7
                              {1, 1, 1, 1, 1, 1, 1},   //8
                              {1, 1, 1, 1, 0, 1, 1}};  //9
    //Number -= 1;
    for(i=0; i<7; i++){
        LED_7seg[i] = (-1<Number) ? !LED7seg_Out[Number][i] : 1;
    }
}