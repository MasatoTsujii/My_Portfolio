#include "Controller.h"

//uint8_t sendData[20] = {0};
uint32_t SW_state;
uint16_t SC1, SC2;
uint16_t JSLX, JSLY, JSRX, JSRY;
uint16_t Pitch1, Pitch2;
int8_t i;
int _Pitch;

float volSC1, volSC2;
int _Pitch1=0, _Pitch2=0;

void setControllerData(char _data[])
{
    setSwitchData();
    setSpeedControllerData();
    setJoyStickData();
    setRotaryEncoderData();
    /*SW_state = 0xF7F7F6;
    SC1 = SC2 = 0x3FFF;
    JSLX = JSLY = JSRX = JSRY = Pitch1 = Pitch2 = 0x3FF;*/
    _data[0]  = ((SW_state>>16)&0xF7);
    _data[1]  = ((SW_state>>8)&0xF7);
    _data[2]  = ((SW_state>>0)&0xF7);
    _data[3]  = bitShift_OutData((SC1>>6)&0xFE);
    _data[4]  = bitShift_OutData((SC1<<1)&0xFE);
    _data[5]  = bitShift_OutData((SC2>>6)&0xFE);
    _data[6]  = bitShift_OutData((SC2<<1)&0xFE);
    _data[7]  = bitShift_OutData((JSLX>>2)&0xFE);
    _data[8]  = (((JSLX<<5)&0xE0) | ((JSLY>>7)&0x07));
    _data[9]  = bitShift_OutData((JSLY<<1)&0xFE);
    _data[10] = bitShift_OutData((JSRX>>2)&0xFE);
    _data[11] = (((JSRX<<5)&0xE0) | ((JSRY>>7)&0x07));
    _data[12] = bitShift_OutData((JSRY<<1)&0xFE);
    _data[13] = bitShift_OutData((Pitch1>>2)&0xFE);
    _data[14] = (((Pitch1<<5)&0xE0) | ((Pitch2>>7)&0x07));
    _data[15] = bitShift_OutData((Pitch2<<1)&0xFE);
    for(i=0; i<16; i++)
    {
        if(_data[i]==0) _data[i] = 0x08;
    }
}

void setSwitchData(void)
{
    SW_state = 0;
    if(!TactSW[0].read())    SW_state |= OUT_TACTSW1;
    if(!TactSW[1].read())    SW_state |= OUT_TACTSW2;
    if(!TactSW[2].read())    SW_state |= OUT_TACTSW3;
    if(!TactSW[3].read())    SW_state |= OUT_TACTSW4;
    if(!TactSW[4].read())    SW_state |= OUT_TACTSW5;
    if(!TactSW[5].read())    SW_state |= OUT_TACTSW6;
    if(!TactSW[6].read())    SW_state |= OUT_TACTSW7;
    if(!TactSW[7].read())    SW_state |= OUT_TACTSW8;
    if(!TactSW[8].read())    SW_state |= OUT_TACTSW9;

    if(!ToggleSW[0].read())  SW_state |= OUT_TOGGLESW1;
    if(!ToggleSW[1].read())  SW_state |= OUT_TOGGLESW2;
    if(!ToggleSW[2].read())  SW_state |= OUT_TOGGLESW3;
    if(!ToggleSW[3].read())  SW_state |= OUT_TOGGLESW4;
    if(!ToggleSW[4].read())  SW_state |= OUT_TOGGLESW5;
    if(!ToggleSW[5].read())  SW_state |= OUT_TOGGLESW6;
    if(!ToggleSW[6].read())  SW_state |= OUT_TOGGLESW7;
    if(!ToggleSW[7].read())  SW_state |= OUT_TOGGLESW8;
    if(!ToggleSW[8].read())  SW_state |= OUT_TOGGLESW9;
    if(!ToggleSW[9].read())  SW_state |= OUT_TOGGLESW10;

    if(!changeSW.read())     SW_state |= OUT_CHANGESW;
}

void setSpeedControllerData(void)
{
    volSC1 = volSC1*0.9 + SC[0].read()*0.1;
    volSC2 = volSC2*0.9 + SC[1].read()*0.1;
    SC1 = (uint16_t)(SC_MAX * (1.0-volSC1));
    SC2 = (uint16_t)(SC_MAX * (1.0-volSC2));
}

void setJoyStickData(void)
{
    JSLX = (uint16_t)(JS_MAX * JSL[0].read());
    JSLY = (uint16_t)(JS_MAX * JSL[1].read());
    JSRX = (uint16_t)(JS_MAX * JSR[0].read());
    JSRY = (uint16_t)(JS_MAX * JSR[1].read());
}

void setRotaryEncoderData(void)
{
    //Pitch1 = Pitch2 = 0;

    //_Pitch = 1505;
    Pitch1 = START_PITCH1 - (Pitch[0].Get()/5);
    if(Pitch1<200)          Pitch1 = 200;
    else if(830<Pitch1)     Pitch1 = 830;
    
    Pitch2 = START_PITCH2 + (Pitch[1].Get()/5);
    if(Pitch2<240)          Pitch2 = 240;
    else if(550<Pitch2)     Pitch2 = 550;
    // if(_Pitch<0)  Pitch1 |= 0x200;
    // if( 511<abs(_Pitch) )   _Pitch = 511;
    // Pitch1 |= (uint16_t)(abs(_Pitch));
    // if( 511<_Pitch )        _Pitch1 -= 511.0;
    // else if( _Pitch<-511 )  _Pitch1 += 511.0;
    // else                    _Pitch1 -= _Pitch;

    //_Pitch = -51;
    //_Pitch = Pitch[1].Get();
    // if(_Pitch<0)  Pitch2 |= 0x200;
    // if( 511<abs(_Pitch) )   _Pitch = 511;
    // Pitch2 |= (uint16_t)(abs(_Pitch));
    // if( 511<_Pitch )        _Pitch2 -= 511.0;
    // else if( _Pitch<-511 )  _Pitch2 += 511.0;
    // else                    _Pitch2 -= _Pitch;

    // Pitch[0].Set(0);
    // Pitch[1].Set(0);
}

char bitShift_OutData(char _data)
{
    return ((_data&0xF0) | ((_data>>1)&0x07));
}