#ifndef _INIT_H_
#define _INIT_H_

void init_io();
void init_cmt0();
void init_mtu();
void init_ad();
//void timer();
void init_timerinterrupt();
void wait(int time);
void relay(int motor);
void init_disp();
void init_sci2();
//void RXI2();
void init();

#endif
