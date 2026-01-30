/***********************************************************************/
/*                                                                     */
/*　2046年強化ダンボールの発明によって世界の物流は革新的な進歩を遂げた */
/*　あらゆる衝撃を吸収しほとんど無にしてしまう革命的な未来の箱が       */
/*　輸送手段の常識を覆したのだ                                         */
/*　しかしその箱はやがて全く別の目的で使われる事になる                 */
/*　ストリートで行われる少年たちの戦い　ホビー用小型ロボット           */
/*　LBXを操る彼らの戦場はダンボールの中へと移っていった                */
/*　その四角い戦場で戦う小さな戦士たち                                 */
/*　人は彼らを“ダンボール戦機”と呼んだ                               */
/*                                                                     */
/***********************************************************************/

#include "iodefine.h"
#include "omnidirectionaldriver.h"
#include "communication.h"	//dualshock.hとtsusin.hとRXduino.hは一緒∴どれか一つだけ
#include "init.h"
#include "define.h"
#include "relay.h"
#include "disp.h"
#include "pid.h"


int data[10] = {0};
int monitoring = 0;				//通信監視用

int velocity[4] = {0};			//駆動
int motor[4] = {0};			//motor[0]:上下機構、motor[1]:角度調節、motor[2]:回収機構、motor[3]:ベルトコンベア

int tol_vertical = 1;				//許容偏差範囲:上下機構	(ボリューム)
int tol_angle = 15;				//許容偏差範囲:角度機構
int tol_angle_reset = 5;			//許容偏差範囲:角度機構 リセット時
int vertical_vol = 0;				//今のボリュームの値:上下
int angle_vol = 0;				//今のボリュームの値:角度
int terget_vertical = 0, terget_angle = 0;	//目標値 (上下,角度)

//ボリュームの値 上下//
const int hang_vertical_vol = 758;		//かけるちょうどいい高さ
const int pass_vertical_vol = 590;		//排出する高さ
const int reset_vertical_vol = 515;		//初期高さ
const int collect_vertical_vol = 770;		//回収する高さ
const int top_vertical_vol = 865;		//一番上の高さ
//ボリュームの値 角度//
const int top_angle_vol = 750;			//790地面に対して直角の角度
const int uplimit_angle_vol = 920;		//915上限の角度
const int lowlimit_angle_vol = 330;		//310下限の角度
const int pass_angle_vol = 485;			//470排出の角度
const int reset_angle_vol = 900;		//905初期角度
const int collect_angle_vol = 400;		//390回収の角度
const int intermediate_angle_vol = 550;		//510速度が変わる角度

//ボタン//
int circle = 0;
int cross = 0;
int triangle = 0;
int square = 0;
int left = 0;
int right = 0;
int up = 0;
int down = 0;
int l1 = 0;
int l2 = 0;
int l3 = 0;
int r1 = 0;
int r2 = 0;
int r3 = 0;
int ps = 0;
int start = 0;
int select = 0;

int jsrx = 0;
int jsry = 0;
int jslx = 0;
int jsly = 0;

//フラッグ//
int deceleration_flag = 1, deceleration_sw_flag = 1;
int vertical_flag = 0, angle_flag = 0, pass_flag = 0, hang_flag = 0;
int collect_flag = 0, preparation_flag = 0;
int reset_flag = 0, stop_vertical_flag = 0, stop_angle_flag = 0;
int hang_sw_flag = 1, collect_sw_flag = 1, pass_sw_flag = 1, reset_sw_flag = 1;

void volume_stabilization(void);
void Button_JoyStick(void);
void onakahetta(void);

int main(void){
	
	int x = 0,y = 0, r = 0;
	
	init_all();
	//init_delay(timer);
	
	SYSTEM.SCKCR.BIT.PCK = 1;
	SYSTEM.SCKCR.BIT.ICK = 0;
	CMT.CMSTR0.BIT.STR1 = 1;
	
	vertical_vol = VOL_VERTICAL;
	angle_vol = VOL_ANGLE;
	
	while(1){
		////////////////
		Button_JoyStick();
		onakahetta();
		///駆動/////////
		smooth(&x,jslx);
		smooth(&y,jsly);
		smooth(&r,jsrx);
		//lipo_fire(&x,&y,hang_flag);
		anomalyOmnidirectionalDriver(x,y,r,velocity,deceleration_flag);
		////////////////
		relay_fet(velocity);
		relay(motor);
		
		disp(data[0]);
		disp(data[7]);
		disp(jsry);
		//disp(jslx);
		//disp(jsly);
		disp(monitoring);
		dnl();
	}
	return 0;
}

void volume_stabilization(void){
	vertical_vol = (double)(vertical_vol * 0.90) + (double)(VOL_VERTICAL * 0.10);
	angle_vol = (double)(angle_vol * 0.90) + (double)(VOL_ANGLE * 0.10);
}

void Button_JoyStick(void){
	circle = circle_button;
	cross = cross_button;
	triangle = triangle_button;
	square = square_button;
	left = left_button;
	right = right_button;
	up = up_button;
	down = down_button;
	l1 = l1_button;
	l2 = l2_button;
	l3 = l3_button;
	r1 = r1_button;
	r2 = r2_button;
	r3 = r3_button;
	ps = ps_button;
	start = start_button;
	select = select_button;
	jslx = joystick_lx;
	jsly = joystick_ly;
	jsrx = joystick_rx;
	jsry = joystick_ry;
}

void onakahetta(void){
	
	int i;
	
	//モータースピード減速//
	/*if((circle==1) && (deceleration_flag==0) && (deceleration_sw_flag)){
		deceleration_flag = 1;
	}else if((circle==1) && (deceleration_flag==1) && (deceleration_sw_flag==1)){
		deceleration_flag = 0;
	}
	
	deceleration_sw_flag = !circle;*/
	
	//かけるちょうどいい高さ//
	/*if((triangle==1) && (hang_flag==0) && (hang_sw_flag==1)){
		vertical_flag = 1;
		hang_flag = 1;
		terget_vertical = hang_vertical_vol;
	}else if((triangle==1) && (hang_flag==1) && (hang_sw_flag==1)){
		hang_flag = 0;
	}
	
	hang_sw_flag = !triangle;*/
	
	//回収ベルトコンベア回転//
	if((up==1) && (pass_flag==0) && (preparation_flag==0)  && (pass_sw_flag==1) && (square==0)){
		vertical_flag = 1;
		angle_flag = 1;
		pass_flag = 1;
		preparation_flag = 1;
		collect_flag = 0;
		terget_vertical = pass_vertical_vol;
		terget_angle = intermediate_angle_vol;
	}else if((down==1) && (collect_flag==0) && (preparation_flag==0) && (collect_sw_flag==1) && (square==0)){
		vertical_flag = 1;
		angle_flag = 1;
		collect_flag = 1;
		preparation_flag = 1;
		pass_flag = 0;
		terget_vertical = top_vertical_vol;
		terget_angle = intermediate_angle_vol;
	}else if(((up==1) && (pass_flag==1) && (pass_sw_flag==1)) || ((down==1) && (collect_flag==1) && (collect_sw_flag==1))){
		for(i=2; 4>i; i++)	motor[i] = 0;
		collect_flag = 0;
		pass_flag = 0;
		preparation_flag = 0;
		angle_flag = 1;
		vertical_flag = 1;
		terget_vertical = reset_vertical_vol;
		terget_angle = reset_angle_vol;
	}
	
	pass_sw_flag = !up;
	collect_sw_flag = !down;
	
	volume_stabilization();
	
	//リセット&フラッグ処理//
	if(reset_flag){
		if(((terget_angle-tol_angle_reset)<=angle_vol) && (angle_vol<=(terget_angle+tol_angle_reset)) && (angle_flag==1) && (stop_angle_flag==0))		stop_angle_flag = 1;
		if(((terget_vertical-tol_vertical)<=vertical_vol) && (vertical_vol<=(terget_vertical+tol_vertical)) && (vertical_flag==1) && (stop_vertical_flag==0))	stop_vertical_flag = 1;
		if(stop_angle_flag)		angle_flag = 0;
		if(stop_vertical_flag)		vertical_flag = 0;
		preparation_flag = 0;
		collect_flag = 0;
		pass_flag = 0;
		hang_flag = 0;
		motor[2] = 0;
		motor[3] = 0;
	}else{
		if(((terget_vertical-tol_vertical)<=vertical_vol) && (vertical_vol<=(terget_vertical+tol_vertical)) && (vertical_flag==1))	vertical_flag = 0;
		if(((terget_angle-tol_angle)<=angle_vol) && (angle_vol<=(terget_angle+tol_angle)) && (angle_flag==1))				angle_flag = 0;
	}
	
	//回収処理//
	if((angle_flag==0) && (preparation_flag==1)){
		if((vertical_flag==0) && (collect_flag==1)){
			terget_vertical = collect_vertical_vol;
			terget_angle = collect_angle_vol;
			preparation_flag = 0;
			vertical_flag = 1;
			angle_flag = 1;
		}else if(pass_flag){
			terget_angle = pass_angle_vol;
			preparation_flag = 0;
			vertical_flag = 1;
			angle_flag = 1;
		}
	}
	
	//回収ロール pwm// //回収ロール,BC:手動//
	if(left){
		pass_flag = 0;
		collect_flag = 0;
	}else if((square==1) && (up==1)){
		motor[2] = -1200;
		motor[3] = -1100;
	}else if((square==1) && (down==1)){
		motor[2] = 1200;
		motor[3] = 1100;
	}else if((square==1) || ((collect_flag==0) && (pass_flag==0))){
		motor[2] = 0;
		motor[3] = 0;
	}else if(pass_flag){
		motor[2] = -1200;
		motor[3] = -1100;
	}else if(collect_flag){
		motor[2] = 1200;
		motor[3] = 1100;
	}
	
	//上下機構 pwm//
	if(vertical_flag){
		if(preparation_flag)				motor[0] = PID(terget_vertical, vertical_vol, 2);
		else if(terget_vertical>vertical_vol)		motor[0] = PID(terget_vertical, vertical_vol, 0);
		else if(terget_vertical<vertical_vol)		motor[0] = PID(terget_vertical, vertical_vol, 1);
	}
	
	//回収角度 pwm//
	if(angle_flag){
		if((uplimit_angle_vol<angle_vol) || (angle_vol<lowlimit_angle_vol))	motor[1] = 0;
		else if((terget_angle<angle_vol) && (preparation_flag==1))		motor[1] = -680;
		else if((terget_angle>angle_vol) && (preparation_flag==1))		motor[1] = 750;
		else if((terget_angle>angle_vol) && (top_angle_vol>=angle_vol))		motor[1] = 630;
		else if((angle_vol>terget_angle) && (top_angle_vol>=angle_vol))		motor[1] = -350;
		else if((angle_vol>terget_angle) && (angle_vol>=top_angle_vol))		motor[1] = -280;
		else if((terget_angle>angle_vol) && (angle_vol>=top_angle_vol))		motor[1] = 200;
	}
	
	//ハンガー腕上下:手動//
	if(vertical_flag==0)	motor[0] = 0;
	if(l1)			motor[0] = 500;
	else if(l2)		motor[0] = -500;
	//motor[0] = (hang_flag==1) ? motor[0]/2:motor[0];
	
	//回収腕上下:手動//
	if(angle_flag==0){
		if(r1)		motor[1] = 300;
		else if(r2)	motor[1] = -300;
		else		motor[1] = 0;
	}
	
	//リセットモード//
	if((cross==1) && (reset_flag==0) && (reset_sw_flag==1)){
		for(i=0; 4>i; i++)	motor[i] = 0;
		terget_vertical = reset_vertical_vol;
		terget_angle = reset_angle_vol;
		//deceleration_flag = 2;
		vertical_flag = 1;
		angle_flag = 1;
		collect_flag = 0;
		preparation_flag = 0;
		pass_flag = 0;
		hang_flag = 0;
		//reset_flag = 1;
	}/*else if((cross==1) && (reset_flag==1) && (reset_sw_flag==1)){
		vertical_flag = 0;
		deceleration_flag = 1;
		angle_flag = 0;
		reset_flag = 0;
		stop_angle_flag = 0;
		stop_vertical_flag = 0;
	}*/
	
	reset_sw_flag = !cross;
}

void timer(void){
	monitoring++;
	if(monitoring>=200){
		circle_button   = 0;
		cross_button    = 0;
		triangle_button = 0;
		square_button   = 0;
		left_button  = 0;
		right_button = 0;
		up_button    = 0;
		down_button  = 0;
		l1_button = 0;
		l2_button = 0;
		l3_button = 0;
		r1_button = 0;
		r2_button = 0;
		r3_button = 0;
		ps_button = 0;
		start_button  = 0;
		select_button = 0;
		joystick_rx = 0;
		joystick_ry = 0;
		joystick_lx = 0;
		joystick_ly = 0;
	}
}

/*void control_data_receive(void){
	static int receive_byte = 0;
	monitoring = 0;
	switch(SCI2.RDR&0x07){
		
		case 0x01:
		data[2] = SCI2.RDR;
		break;
		case 0x02:
		data[3] = SCI2.RDR;
		break;
		case 0x03:
		data[4] = SCI2.RDR;
		break;
		case 0x04:
		data[5] = SCI2.RDR;
		break;
		case 0x05:
		data[6] = SCI2.RDR;
		break;
		case 0x06:
		data[7] = SCI2.RDR;
		break;
		case 0x07:
		data[8] = SCI2.RDR;
		break;
		case 0x00:
		if((SCI2.RDR&0x08)==0x08)	data[1] = SCI2.RDR;
		else				data[0] = SCI2.RDR;
		break;
	}
	receive_byte++;
	if(receive_byte==9){
		updataState(data);
		receive_byte = 0;
	}
	SCI2.SSR.BIT.RDRF = 0;
}*/

void control_data_receive(void){
	static int No = 0;
	monitoring = 0;
	if(SCI2.RDR==0x80){
		No = 0;
		data[No++] = 0x80;
	}else if(No > 0){
		data[No++] = SCI2.RDR;
		if(No > 8){
			updataState(data);
			No = 0;
		}
	}
	SCI2.SSR.BIT.RDRF = 0;
}