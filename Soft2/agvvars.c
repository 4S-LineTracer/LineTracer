/*
 * 共有変数 
*/
#include "agvvars.h"

// データ系
unsigned char SW_DATA;
unsigned char SENS_DATA;
unsigned char IRQ1_DATA;
unsigned char MOTOR_SPEED;
extern unsigned char SENS_PROOF_TIME; // 未検出耐久時間

// 状態変数
unsigned char AGV_STATE;
unsigned char MOTOR_STATE;
