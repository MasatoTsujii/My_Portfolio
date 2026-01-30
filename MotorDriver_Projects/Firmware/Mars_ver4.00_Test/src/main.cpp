#include <mbed.h>

PwmOut SR(PA_3);
PwmOut PHASE(PA_4);
PwmOut PWMH(PA_6);
PwmOut PWML(PA_7);

DigitalIn UserButton(PA_5, PullUp);

float PWM_value = 0.5f;
bool CW = true;

int main(void)
{

  SR.period_us(20);
  PHASE.period_us(20);
  PWMH.period_us(20);
  PWML.period_us(20);

  PHASE.write(0.5f);
  PWMH.write(1.0f);
  PWML.write(1.0f);
  SR.write(0.0f);
  
  thread_sleep_for(500);

  while(1)
  {
    if(!UserButton.read())
    {
      if(CW==true)
      {
        PWM_value += 0.1f;
        if(1.0f<=PWM_value) CW = false;
      }else
      {
        PWM_value -= 0.1f;
        if(PWM_value<=0.0f) CW = true;
      }
      PHASE.write(PWM_value);
    }else
    {
      PWM_value = 0.5f;
      PHASE.write(0.5f);
      PWMH.write(1.0f);
      PWML.write(1.0f);
      SR.write(0.0f);
    }
  }
  thread_sleep_for(500);
}