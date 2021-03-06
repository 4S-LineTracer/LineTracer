/*
 * IRQ1割り込み処理
*/
#include "task.h"
#include "def_monitor_printf.h"

// IRQ1の状態をIRQ1_DATAに反映する。 (トリガ: IRQ1)
//  - Parameters: なし
//  - Returns: なし
#pragma interrupt itask_irq1
void itask_irq1(void){

    // IRQ1割り込みをitask_controlに通知
    if(COOL_TIME == 0){
		IRQ1_DATA = 1;
	}
    ISR &= 0xFD;
	
    return;
}
