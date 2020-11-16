/*
 * IRQ1Š„‚è‚İˆ—
*/
#include "task.h"
#include "def_monitor_printf.h"

// IRQ1‚Ìó‘Ô‚ğIRQ1_DATA‚É”½‰f‚·‚éB (ƒgƒŠƒK: IRQ1)
//  - Parameters: ‚È‚µ
//  - Returns: ‚È‚µ
#pragma interrupt itask_irq1
void itask_irq1(void){

    // IRQ1Š„‚è‚İ‚ğitask_control‚É’Ê’m
    IRQ1_DATA = 1;
    ISR &= 0xFD;
    return;
}
