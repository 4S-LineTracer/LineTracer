/*
 * IRQ1割り込み処理
*/
#include "task.h"

// IRQ1の状態をIRQ1_DATAに反映する。 (トリガ: IRQ1)
//  - Parameters: なし
//  - Returns: なし
#pragma	interrupt itask_irq1
void  itask_irq1(void){
	unsigned char IRQ1_P = bios_irq1_input();
	if(IRQ1_P == 0x00 && IRQ1_DATA == 1){IRQ1_DATA = 0;}
	if(IRQ1_P == 0x00 && IRQ1_DATA == 0){IRQ1_DATA = 1;}	
}
