/*
 * ”À‘—Ô‰Šú‰»ƒ‹[ƒ`ƒ“
*/
#include "bios.h"

#ifndef _INITIALIZE_H_
#define _INITIALIZE_H_

/* -------- */
void initialize();

/* -------- */
#define ITU_PS_1 0x00
#define ITU_PS_2 0x01
#define ITU_PS_4 0x02
#define ITU_PS_8 0x03

#define ITU_PS_EXT_A 0x04
#define ITU_PS_EXT_B 0x05
#define ITU_PS_EXT_C 0x06
#define ITU_PS_EXT_D 0x07

#define ITU_EDGE_RISE (0x00 << 3)
#define ITU_EDGE_FALL (0x01 << 3)
#define ITU_EDGE_ALL (0x02 << 3)

#define ITU_CLR_NEVER (0x00 << 5)
#define ITU_CLR_GRA (0x01 << 5)
#define ITU_CLR_GRB (0x02 << 5)
#define ITU_CLR_SYNC (0x03 << 5)

#endif
