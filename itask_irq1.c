/*
 * IRQ1Š„‚è‚İˆ—
*/
#include "task.h"

// IRQ1‚Ìó‘Ô‚ğIRQ1_DATA‚É”½‰f‚·‚éB (ƒgƒŠƒK: IRQ1)
//  - Parameters: ‚È‚µ
//  - Returns: ‚È‚µ
#pragma	interrupt itask_irq1
void  itask_irq1(void){
	unsigned char IRQ1_P = bios_irq1_input();
	if(IRQ1_P == 0x00 && IRQ1_DATA == 1){IRQ1_DATA = 0;}
	if(IRQ1_P == 0x00 && IRQ1_DATA == 0){IRQ1_DATA = 1;}	
}
