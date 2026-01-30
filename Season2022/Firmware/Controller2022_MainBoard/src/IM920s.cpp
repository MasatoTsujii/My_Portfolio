#include "IM920s.h"

IM920sDriver::IM920sDriver(PinName TxPin, PinName RxPin, PinName busyPin)
{
    IM = new UnbufferedSerial(TxPin, RxPin, BAUDRATE);
    IM->format(8, SerialBase::None, 1);
    //Status = new DigitalIn(StatusPin);
    busy = new DigitalIn(busyPin);
    IM->attach(callback(this,&IM920sDriver::receive), UnbufferedSerial::RxIrq);
}

IM920sDriver::IM920sDriver(PinName TxPin, PinName RxPin, PinName busyPin, PinName StatusPin)
{
    IM = new UnbufferedSerial(TxPin, RxPin, BAUDRATE);
    IM->format(8, SerialBase::None, 1);
    Status = new DigitalIn(StatusPin);
    busy = new DigitalIn(busyPin);
    IM->attach(callback(this,&IM920sDriver::receive), UnbufferedSerial::RxIrq);
}

void IM920sDriver::send(const char _data[])
{
    IM->write(_data, strlen(_data));
    //for(size_t i = 0;i < strlen(_Data); i++)    IM->write(&_Data[i], 1);
}

//ブロードキャスト送信（可変長）
void IM920sDriver::write(const char _data[])
{
    // if( !busy->read() )
    // {
        send("TXDA ");
        send(_data);
        send("\r\n");/*
        commandType = 1;
        HAL_Delay();
        CheckOut();*/
    //}
    //phase = 1;
}

//ユニキャスト送信
void IM920sDriver::write(const char _ID[], const char _data[])
{
    if( !busy->read() )
    {
        send("TXDU ");
        send(_ID);
        send(",");
        send(_data);
        send("\r\n");/*
        commandType = 1;
        HAL_Delay(5);
        CheckOut();*/
    }
    //phase = 2;
}

void IM920sDriver::read(char _data[])
{
    if(outputFlg)
    {
        outputFlg = false;
        strncpy(_data, latestData, latestNum);
    }
}

void IM920sDriver::receive(void)
{
    IM->read(&_buffer, 1);

    data[dataNum] = _buffer;
    if(_buffer==0x0D)
    {
        endFlg = true;
        dataNum++;
    }
    else if( (endFlg) && (_buffer==0x0A) )
    {
        str[dataNum] = '\0';
        if(5<dataNum)
        {
            strncpy(latestData, data, dataNum);
            latestNum = dataNum;
        outputFlg = true;
        }
        //outputFlg = true;
        endFlg = false;
        dataNum = 0;
        //setChack();
    }
    else
    {
        str[dataNum] = _buffer;
        endFlg = false;
        dataNum++;
    }
    a++;
}

bool IM920sDriver::CheckOut(void)
{
    if(outputFlg)
    {
        outputFlg = false;
        if(commandType==1)
        {
            char _str[3] = {0};
            strncpy(_str, str, 2);
            printf("%s\n", _str);
            for(int8_t i=0; str[i]!='\0'; i++)      str[i] = 0;
            if( strcmp(_str, strOK)==0 )           return true;
            else                                    return false;
        }
        else if(commandType==2)
        {
            printf("%s\n", str);
            for(int8_t i=0; str[i]!='\0'; i++)      str[i] = 0;
            return true;
        }
        else    return false;
    }else       return false;
}

int IM920sDriver::sa(void){
    return a;
}

void IM920sDriver::setMyNode(uint8_t _node[])
{
    
}

int8_t IM920sDriver::getCommandType(void)
{
    return commandType;
}

int16_t IM920sDriver::getNGcount(void)
{
    return NG_count;
}

void IM920sDriver::resetNGcount(void)
{
    NG_count = 0;
}

int16_t IM920sDriver::getOKcount(void)
{
    return OK_count;
}

void IM920sDriver::resetOKCount(void)
{
    OK_count = 0;
}

void IM920sDriver::getNode(void)
{
    send("RDNN");
    send("\r\n");
    commandType = 2;
    HAL_Delay(5);
    CheckOut();
}

void IM920sDriver::getGroup(void)
{
    send("RDGN");
    send("\r\n");
}

void IM920sDriver::getID(void)
{
    send("RDID");
    send("\r\n");
}

void IM920sDriver::getChannel(void)
{
    send("RDNN");
    send("\r\n");
}

void IM920sDriver::getParameter(void)
{
    send("RPRM");
    send("\r\n");
}

//void IM920sDriver::