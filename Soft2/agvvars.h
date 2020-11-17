/*
 * 共有変数 
*/
#ifndef _AGVVARS_H_
#define _AGVVARS_H_

// データ系
extern unsigned char SW_DATA;
extern unsigned char SENS_DATA;
extern unsigned char IRQ1_DATA;
extern unsigned char MOTOR_SPEED;
extern unsigned char SENS_PROOF_TIME; // 未検出耐久時間

// 状態変数
extern unsigned char AGV_STATE;
extern unsigned char MOTOR_STATE;

#endif
