#ifndef __CONTROLLER_H
#define __CONTROLLER_H

#include "init.h"

#define START_PITCH1    500
#define START_PITCH2    400

#define SC_MAX          16383   //Speed Controller MAX value    0x3FFF
#define JS_MAX          1023    //JoyStick MAX value            0x3FF

#define OUT_TACTSW1     0x800000
#define OUT_TACTSW2     0x400000
#define OUT_TACTSW3     0x200000
#define OUT_TACTSW4     0x100000
#define OUT_TACTSW5     0x040000
#define OUT_TACTSW6     0x020000
#define OUT_TACTSW7     0x010000
#define OUT_TACTSW8     0x008000
#define OUT_TACTSW9     0x004000

#define OUT_TOGGLESW1   0x002000
#define OUT_TOGGLESW2   0x001000
#define OUT_TOGGLESW3   0x000400
#define OUT_TOGGLESW4   0x000200
#define OUT_TOGGLESW5   0x000100
#define OUT_TOGGLESW6   0x000080
#define OUT_TOGGLESW7   0x000040
#define OUT_TOGGLESW8   0x000020
#define OUT_TOGGLESW9   0x000010
#define OUT_TOGGLESW10  0x000004

#define OUT_CHANGESW    0x000002

extern uint16_t SC1, SC2;
extern uint16_t Pitch1, Pitch2;
extern int _Pitch1, _Pitch2;

void setControllerData(char _data[]);
void setSwitchData(void);
void setSpeedControllerData(void);
void setJoyStickData(void);
void setRotaryEncoderData(void);

char bitShift_OutData(char _data);

//extern uint8_t sendData[20];

#endif