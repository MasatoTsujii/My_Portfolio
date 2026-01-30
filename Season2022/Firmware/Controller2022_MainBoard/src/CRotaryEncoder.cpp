#include <mbed.h>
#include "CRotaryEncoder.h"

CRotaryEncoder::CRotaryEncoder(PinName pinA, PinName pinB)
{
    m_pinA = new InterruptIn(pinA);
    m_pinA->rise(callback(this,&CRotaryEncoder::rise));
    m_pinA->fall(callback(this,&CRotaryEncoder::fall));

    m_pinB = new DigitalIn(pinB, PullDown);
    m_position = 0;
}

CRotaryEncoder::~CRotaryEncoder()
{
    delete m_pinA;
    delete m_pinB;
}

int CRotaryEncoder::Get(void)
{
    return m_position;
}

void CRotaryEncoder::Set(int value)
{
    m_position = value;
}
    
void CRotaryEncoder::fall(void)
{
    if(*m_pinB == 1)
    {
        m_position++;
    }else
    {
        m_position--;
    }
}

void CRotaryEncoder::rise(void)
{
    if(*m_pinB == 1)
    {
        m_position--;
    }else
    {
        m_position++;
    }
}

