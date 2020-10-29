/*
 * センサ制御
*/
#include "bios.h"

// センサの状態を取得する。
//  - Parameters: なし
//  - Returns: センサの検出状態(0:未検出 1:検出)
unsigned char bios_sensor_input(){
	return ~SENS_PORT;
}
