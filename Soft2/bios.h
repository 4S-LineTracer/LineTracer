/*
 * bios共通ヘッダ
*/
#ifndef _BIOS_H_
#define _BIOS_H_

/* -------- */

#include "machine.h"
#include "reg3052.h"
#include "agvdef.h"
#include "agvvars.h"

/* -------- */

// inputs
unsigned char bios_ad_input();
unsigned char bios_sensor_input();
unsigned char bios_sw_input();
unsigned char bios_irq1_input(); // IRQ1割り込みベクタに設定する場合はここをvoidに!

// outputs
void bios_step_output(unsigned char i);
void bios_led_output(unsigned char value);
void bios_da_output(unsigned char DA_DATA);
void bios_beep_output(unsigned char beep);

#endif
