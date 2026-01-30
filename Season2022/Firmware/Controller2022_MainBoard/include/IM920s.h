#ifndef __IM920S_H
#define __IM920S_H

#include <mbed.h>
#include <string.h>
#include <USBSerial.h>

//int BaudRate[10] = {1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200, 230400, 460800};
#define BAUDRATE    460800

class IM920sDriver
{
public:
    IM920sDriver(PinName TxPin, PinName RxPin, PinName busyPin);
    IM920sDriver(PinName TxPin, PinName RxPin, PinName busyPin, PinName StatusPin);
    //~IM920sDriver();

    void send(const char _data[]);
    void write(const char _data[]);
    void write(const char _ID[], const char _data[]);

    void read(char _data[]);

    bool getOutputFlg(void);
    int8_t getCommandType(void);
    int16_t getNGcount(void);
    void resetNGcount(void);
    int16_t getOKcount(void);
    void resetOKCount(void);

    void setMyNode(uint8_t _node[]);

    void getNode(void);
    void getGroup(void);
    void getID(void);
    void getChannel(void);
    void getNetWork(void);
    void getParameter(void);

    int sa(void);

    //int datanum = 0;

private:
    UnbufferedSerial *IM;
    DigitalIn *Status;
    DigitalIn *busy;

    int a=0;

    void receive(void);
    void endCommand(void);
    bool CheckOut(void);
    bool readCheck(void);
    
    bool endFlg = false;
    //bool Checker = false;
    bool outputFlg = false;
    char _buffer;

    int8_t commandType = 0;
    int8_t dataNum = 0;
    int8_t latestNum = 0;
    int8_t strNum = 0;
    
    char data[40] = {0};
    char latestData[40] = {0};
    char str[40] = {0};
    char strOK[3] = "OK";
    char strNG[3] = "NG";

    int NG_count = 0;
    int OK_count = 0;
    //char str[2] = {"a"};
};

#endif