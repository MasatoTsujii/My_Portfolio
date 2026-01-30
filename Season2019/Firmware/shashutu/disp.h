#ifndef _RX_DISP_H_
#define _RX_DISP_H_

void txd(char D);
void txvalue(unsigned char D);
void dnl(void);
void putstr(char *TXDATA);
void disp(long int D);
void comma(void);
int advancedDisp(double opr, int pre);

#endif