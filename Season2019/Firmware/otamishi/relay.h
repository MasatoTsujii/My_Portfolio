#ifndef _RELAY__H_
#define _RELAY_H_


#define PWM_VERTICAL		MTU0.TGRA
//#define PWM_KAI_K		MTU0.TGRB
#define PWM_ANGLE		MTU0.TGRC
#define PWM_BC			MTU0.TGRB	//å≥ÅFMTU4.TGRA
#define PWM_ROL			MTU4.TGRA

#define SIG_VERTICAL1	PORT2.DR.BIT.B0
#define SIG_VERTICAL2	PORT2.DR.BIT.B1
//#define SIG_KAI_K1	PORT2.DR.BIT.B2
//#define SIG_KAI_K2	PORT2.DR.BIT.B3
#define SIG_BC1		PORT2.DR.BIT.B2
#define SIG_BC2		PORT2.DR.BIT.B3
#define SIG_ANGLE1	PORT3.DR.BIT.B2		//PORT7.DR.BIT.B1
#define SIG_ANGLE2	PORT3.DR.BIT.B3		//PORT7.DR.BIT.B4
#define SIG_ROL1	PORT3.DR.BIT.B0
#define SIG_ROL2	PORT3.DR.BIT.B1

#define VOL_VERTICAL	AD0.ADDRA
//#define VOL_KAI_K	PORT6.ICR.BIT.B3
#define VOL_ANGLE	AD0.ADDRB

/*#define LIM_HANG_U	PORT4.ICR.BIT.B0
#define LIM_HANG_S	PORT4.ICR.BIT.B1
#define LIM_KAI_KU	PORT4.ICR.BIT.B2
#define LIM_KAI_KS	PORT4.ICR.BIT.B3
#define LIM_KAI_JU	PORT7.ICR.BIT.B5
#define LIM_KAI_JS	PORT7.ICR.BIT.B6*/

#define constant	90
#define constant_rol	20

int costrain(int value,int best,int worst);
void relay(int* motor);
#endif