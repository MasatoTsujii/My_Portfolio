#include <DynamixelSerial.h>

//int i=2;

void setup() {
  //Serial(0,1);
  Dynamixel.setSerial(&Serial); // &Serial - Arduino UNO/NANO/MICRO, &Serial1, &Serial2, &Serial3 - Arduino Mega
  Dynamixel.begin(38400, 2);  // Inicialize the servo at 1 Mbps and Pin Control 2
  delay(100);
}

void loop(){
  /*if(i==0){
    Dynamixel.reset(0xFE);
    i++;
  }*/
  /*if(i==1){
    Dynamixel.setBD(0xFE, 19200);
    i++;
  }*/
  //if(i==2){
    Dynamixel.move(0xFE,1000);  // Move the Servo radomly from 200 to 800
    delay(4000);
    Dynamixel.move(0xFE,10);  // Move the Servo radomly from 200 to 800
    delay(4000);
    Dynamixel.move(0xFE,800);  // Move the Servo radomly from 200 to 800
    delay(4000);
    Dynamixel.move(0xFE,400);  // Move the Servo radomly from 200 to 800
    delay(4000);
  //}
}
