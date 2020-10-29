/*
 * タスク共通ヘッダ 
*/
#ifndef _TASK_H_
#define _TASK_H_

/* -------- */

#include "machine.h"
#include "reg3052.h"
#include "agvdef.h"
#include "agvvars.h"
#include "def_monitor_printf.h"
#include "accTable.h"

/* -------- */

void itask_control();
void itask_input();
void itask_motor();

#endif
