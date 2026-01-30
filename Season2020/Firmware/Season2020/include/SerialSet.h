#ifndef SERIALSET_H
#define SERIALSET_H

#include <mbed.h>
#include "getkey.h"
#include "disp.h"
#include "debuger.h"
#include <USBSerial.h>

/* disp setup */
/////////////////////////////////////////////
/* Tx p9, p13, p28, USBTX */
#define Tx USBTX
/* Rx p10, p14, p27, USBRX */
#define Rx USBRX
#define BAUDRATE 57600
/* 5~8 */
#define BIT 8
/*  Palityなし  Serial::None
    奇数パリティ Serial::Odd
    偶数パリティ Serial::Even	
    1強制       Serial::Forced1	
    0強制       Serial::Forced0
*/
#define PALITY SerialBase::None
/* 1~2 */
#define STOP_BIT 1
////////////////////////////////////////////

extern UnbufferedSerial SCI;

extern char rx_buff;

void dispSet();
void receiveInt();
int bitCount(int);

#endif