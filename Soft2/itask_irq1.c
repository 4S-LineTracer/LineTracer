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

/*
// こっから先はそのままペターではダメです
// 適宜書き換えてください
#pragma interrupt imitation
void imitation(void){
	IRQ1_DATA = 0x01;
	ISR &= 0xFD;
	return;
}

// ---- itask_control ----
void itask_control(){
	if(IRQ1_DATA == 1){
		IRQ1_DATA = 0;	
		// interrupt process...
		// example:
		switch(AGV_STATE){
			
		}
		// MOTOR_SPEED = 0x00; // 可能な限りのスピードで減速
	}
}
*/