#include "init.h"

DigitalIn TactSW[9] = {DigitalIn(PA_9, PullUp),
                       DigitalIn(PA_8, PullUp),
                       DigitalIn(PB_10, PullUp),
                       DigitalIn(PB_4, PullUp),
                       DigitalIn(PA_10, PullUp),
                       DigitalIn(PB_14, PullUp),
                       DigitalIn(PB_2, PullUp),
                       DigitalIn(PB_12, PullUp),
                       DigitalIn(PA_11, PullUp)};

DigitalIn ToggleSW[10] = {DigitalIn(PB_8, PullUp),
                          DigitalIn(PB_6, PullUp),
                          DigitalIn(PB_5, PullUp),
                          DigitalIn(PB_13, PullUp),
                          DigitalIn(PB_15, PullUp),
                          DigitalIn(PC_9, PullUp),
                          DigitalIn(PB_9, PullUp),
                          DigitalIn(PB_3, PullUp),
                          DigitalIn(PC_4, PullUp),
                          DigitalIn(PB_1, PullUp)};

DigitalIn changeSW(PA_15, PullUp);

//Speed Controller
AnalogIn SC[2] = {AnalogIn(PB_0),
                  AnalogIn(PA_4)};

//JoyStick Left
AnalogIn JSL[2] = {AnalogIn(PC_1),
                   AnalogIn(PC_0)};
//JoyStick Right
AnalogIn JSR[2] = {AnalogIn(PA_6),
                   AnalogIn(PA_7)};

CRotaryEncoder Pitch[2] = {CRotaryEncoder(PC_5, PA_12),
                           CRotaryEncoder(PC_8, PC_6)};

//UnbufferedSerial LEDBus(PC_10, PC_11, 115200);
UnbufferedSerial LEDBus(PA_0, PA_1, 115200);

Timer t;

int _time;

bool ControlFlg(void)
{
    _time = t.elapsed_time().count();
    if( ControlCycle<_time )
    {
        t.stop();
        t.reset();
        t.start();
        return true;
    }else
    {
        return false;
    }
}
//CRotaryEncoder Pitch1(PA_11, PB_12);
//CRotaryEncoder Pitch2(PC_5, PA_12);
//CRotaryEncoder Yaw(PC_8, PC_6);
/*
Ticker ControlCycle;
bool ControlFlg = false;*/

void init(void)
{
    t.start();
    LEDBus.format(8, SerialBase::None, 1);
}