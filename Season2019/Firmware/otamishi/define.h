#ifndef __DEFINE__H__
#define __DEFINE__H__

#define motor_FR_L	PORTA.DR.BIT.B4
#define motor_FR_R	PORTA.DR.BIT.B2
#define motor_FL_L	PORTA.DR.BIT.B3
#define motor_FL_R	PORT9.DR.BIT.B5
#define motor_BR_L	PORT9.DR.BIT.B2
#define motor_BR_R	PORT9.DR.BIT.B0
#define motor_BL_L	PORT9.DR.BIT.B6
#define motor_BL_R	PORT9.DR.BIT.B3

#define pwm_FR		MTU6.TGRA
#define pwm_FL		MTU6.TGRC
#define pwm_BR		MTU7.TGRA
#define pwm_BL		MTU7.TGRC

#define WHEEL_COUNT				4
#define TRANSLATIONAL_VELOCITY_RATIO		2.0
#define TRANSLATIONAL_VELOCITY_RATIO_HALF	1.5
#define ROTATIONAL_VELOCITY_RATIO		1.5
#define SPEED_LIMIT				1919.0

#endif