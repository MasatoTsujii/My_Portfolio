#ifndef __IM920S_H
#define __IM920S_H

#include <mbed.h>
#include <string.h>
#include <USBSerial.h>

//int BaudRate[10] = {1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200, 230400, 460800};
#define BAUDRATE    115200

class IM920sDriver
{
public:
    IM920sDriver(PinName TxPin, PinName RxPin, PinName busyPin);
    IM920sDriver(PinName TxPin, PinName RxPin, PinName busyPin, PinName StatusPin);
    //~IM920sDriver();

    //
    void send(const char _Data[]);
    void read(char _Data[]);

    //固有ID
    void getID(void);

    //ノード番号
    void setNode(const char _NodeID[]);
    void getNode(void);

    //グループ番号
    void setGroup(void);
    void getGroup(void);

    //通信チャンネル
    void setChannel(const char _Channel[]);
    void getChannel(void);

    //送信電力
    void setOutput(const char _Output);
    void getOutput(void);

    //ネットワークモード
    void setNetWork(const char _NetWork);
    void getNetWork(void);

    //最大ホップ数
    void setHopCount(const char _HopCount[]);
    void getHopCount(void);

    //受信RSSI閾値
    void setThreshold(const char _Threshold[]);
    void getThreshold(void);

    //キャラクター入出力モード
    void setEnableCharacterIO(void);
    void setDisableCharacterIO(void);
    
    //Flash ROM設定
    void setEnableWriting(void);
    void setDisableWriting(void);
    
    //ボーレート
    void setBaudRate(const char _Number, const int _BaudRate);

    //パラメータ取得
    void getParameter(void);

    

    int sa(void);

private:
    UnbufferedSerial *IM;
    DigitalIn *Status;
    DigitalIn *busy;
    Timer *t;

    void receive(void);
    void endCommand(void);
    bool CheckOut(void);

    bool endFlg = false;
    //bool Checker = false;
    bool outputFlg = false;
    uint8_t phase=0;
    int8_t commandType = 0;
    int8_t dataNum = 0;
    int8_t strNum = 0;
    char data[50] = {0};
    char str[50] = {0};
    char normal[3] = "OK";
    int a=0;
};

#endif