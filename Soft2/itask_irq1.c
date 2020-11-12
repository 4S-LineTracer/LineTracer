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

    // TODO: IRQ1_DATAはここではアサートするだけにした方が良いかも?
    // ここで短時間で処理を終えられないとステッピングモータの制御に影響してくるので
    /*
    // 例えばこんな感じ
    IRQ1_DATA = 1;
    ISR &= 0xFD;
    return;
    */


    unsigned int i = 0;

    if (IRQ1_DATA == 1){
        IRQ1_DATA = 0;
    }else if (IRQ1_DATA == 0){
        IRQ1_DATA = 1;
    }

    while (--i){}

    ISR &= 0xfd;
    return;
}
