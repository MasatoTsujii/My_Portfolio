#ifndef _RELAY__H_
#define _RELAY_H_
#define pwm_f		 MTU6.TGRA
#define pwm_r 		 MTU6.TGRC
#define pwm_l 		 MTU7.TGRA
#define pwm_b 		 MTU7.TGRC
#define	PWM_dozer	 MTU0.TGRB
#define PWM_roller1	 MTU0.TGRC
#define PWM_roller2 	 MTU0.TGRA
#define STG_f1 		 PORTA.DR.BIT.B4
#define STG_f2    	 PORTA.DR.BIT.B2
#define STG_r1 		 PORTA.DR.BIT.B3
#define STG_r2		 PORT9.DR.BIT.B5
#define STG_l1		 PORT9.DR.BIT.B6
#define STG_l2		 PORT9.DR.BIT.B3
#define STG_b1		 PORT9.DR.BIT.B2
#define STG_b2		 PORT9.DR.BIT.B0
#define STG_dozer1	 PORT7.DR.BIT.B1
#define STG_dozer2	 PORT7.DR.BIT.B4
#define constant         30

int costrain(int value,int best,int worst);
void relay(int* motor);
#endif