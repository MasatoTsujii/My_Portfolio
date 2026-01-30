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
    //t = new Timer;
}

void IM920sDriver::send(const char _Data[])
{
    IM->write(_Data, strlen(_Data));
}

void IM920sDriver::read(char _Data[])
{
    /*for(size_t i=0; i<strlen(data); i++)
    {
        //if(data[])
        _Data[i] = data[i];
    }*/
}

void IM920sDriver::receive(void)
{
    char receiveData;

    IM->read(&receiveData, 1);
    /*str[0] = receiveData;
    str[1] = "\0";*/
    //printf("%c ", receiveData);
    //printf("%x ", receiveData);
    //data[dataNum] = receiveData;

    if(receiveData==0x0D)
    {
        endFlg = true;
        dataNum++;
    }
    else if( (endFlg) && (receiveData==0x0A) )
    {
        str[dataNum] = '\0';
        //printf("%s ", str);
        outputFlg = true;
        endFlg = false;
        dataNum = 0;
        //setChack();
    }
    else
    {
        str[dataNum] = receiveData;
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
            if( strcmp(_str, normal)==0 )           return true;
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

void IM920sDriver::setEnableWriting(void)
{
    send("ENWR");
    endCommand();
    commandType = 1;
    HAL_Delay(100);
    while( !CheckOut() )
    {
        HAL_Delay(500);
        printf("not Enable Writing\n");
        setEnableWriting();
    }
}

void IM920sDriver::setDisableWriting(void)
{
    send("DSWR");
    endCommand();
    commandType = 1;
    HAL_Delay(100);
    while( !CheckOut() )
    {
        HAL_Delay(500);
        printf("not DisableWriting\n");
        setDisableWriting();
    }
}

void IM920sDriver::getID(void)
{
    send("RDID");
    endCommand();
    commandType = 2;
    HAL_Delay(10);
    CheckOut();
}

void IM920sDriver::setNode(const char _NodeID[])
{
    send("STNN ");
    send(_NodeID);
    endCommand();
    commandType = 1;
    HAL_Delay(100);
    while( !CheckOut() )
    {
        HAL_Delay(500);
        printf("not setting Gro\n");
        setNode(_NodeID);
        //setEnableWriting();
    }
}

void IM920sDriver::getNode(void)
{
    send("RDNN");
    endCommand();
    commandType = 2;
    HAL_Delay(10);
    CheckOut();
}

void IM920sDriver::setGroup(void)
{
    send("STGN ");
    endCommand();
    commandType = 1;
    HAL_Delay(100);
    while( !CheckOut() )
    {
        HAL_Delay(500);
        printf("not setting Group\n");
        setGroup();
        //setEnableWriting();
    }
}

void IM920sDriver::getGroup(void)
{
    send("RDGN");
    endCommand();
    commandType = 2;
    HAL_Delay(10);
    CheckOut();
}

void IM920sDriver::setChannel(const char _Channel[])
{
    send("STCH ");
    send(_Channel);
    endCommand();
    commandType = 1;
    HAL_Delay(100);
    while( !CheckOut() )
    {
        HAL_Delay(500);
        printf("Not setting\n");
        setChannel(_Channel);
        //setEnableWriting();
    }
}

void IM920sDriver::getChannel(void)
{
    send("RDCH");
    endCommand();
    commandType = 2;
    HAL_Delay(10);
    CheckOut();
}

void IM920sDriver::setOutput(const char _Output)
{
    send("STPO ");
    send(&_Output);
    endCommand();
    commandType = 1;
    HAL_Delay(100);
    while( !CheckOut() )
    {
        HAL_Delay(500);
        printf("Not setting\n");
        setOutput(_Output);
    }
}

void IM920sDriver::getOutput(void)
{
    send("RDPO");
    endCommand();
    commandType = 2;
    HAL_Delay(10);
    CheckOut();
}

void IM920sDriver::setNetWork(const char _NetWork)
{
    send("STNM");
    send(&_NetWork);
    endCommand();
    commandType = 1;
    HAL_Delay(100);
    while( !CheckOut() )
    {
        HAL_Delay(500);
        printf("Not setting\n");
        setNetWork(_NetWork);
    }
}

void IM920sDriver::getNetWork(void)
{
    send("RDNM");
    endCommand();
    commandType = 2;
    HAL_Delay(10);
    CheckOut();
}

void IM920sDriver::setHopCount(const char _HopCount[])
{
    send("STTL ");
    send(_HopCount);
    endCommand();
    commandType = 1;
    HAL_Delay(100);
    while( !CheckOut() )
    {
        HAL_Delay(500);
        printf("Not setting\n");
        setHopCount(_HopCount);
    }
}

void IM920sDriver::getHopCount(void)
{
    send("RTTL");
    endCommand();
    commandType = 2;
    HAL_Delay(10);
    CheckOut();
}

void IM920sDriver::setThreshold(const char _Threshold[])
{
    send("STTH ");
    send(_Threshold);
    endCommand();
    commandType = 1;
    HAL_Delay(100);
    while( !CheckOut() )
    {
        HAL_Delay(500);
        printf("Not setting\n");
        setThreshold(_Threshold);
    }
}

void IM920sDriver::getThreshold(void)
{
    send("RDTH");
    endCommand();
    commandType = 2;
    HAL_Delay(10);
    CheckOut();
}

void IM920sDriver::setEnableCharacterIO(void)
{
    send("ECIO");
    endCommand();
    commandType = 1;
    HAL_Delay(100);
    while( !CheckOut() )
    {
        HAL_Delay(500);
        printf("not Enable CharacterIO\n");
        setEnableCharacterIO();
    }
}

void IM920sDriver::setDisableCharacterIO(void)
{
    send("DCIO");
    endCommand();
    commandType = 1;
    HAL_Delay(100);
    while( !CheckOut() )
    {
        HAL_Delay(500);
        printf("not Disable CharacterIO\n");
        setDisableCharacterIO();
    }
}

void IM920sDriver::getParameter(void)
{
    send("RPRM");
    endCommand();
    commandType = 5;
}

void IM920sDriver::setBaudRate(const char _Number, const int _BaudRate)
{
    send("SBRT ");
    send(&_Number);
    endCommand();
    HAL_Delay(500);
    IM->baud(_BaudRate);
}

void IM920sDriver::endCommand(void)
{
    send("\r\n");
    //t->start();
}
//void IM920sDriver::