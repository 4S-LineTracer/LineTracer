/*
 * 入力インタフェースアクセサ
*/
#include "ifAccessor.h"

// スイッチの値を更新する。
//  - Returns: スイッチの値
unsigned char swInput(){
    static unsigned char swBuffer[] = {0x00, 0x00, 0x00, 0x00};
    static unsigned int index = 0;
	unsigned char i = 0;
	unsigned char tmp = 0xFF;

    // スイッチの値をバッファに格納
    swBuffer[index] = bios_sw_input();
    index++;
    index &= 0x03;

    // バッファの内容をもとにスイッチの値を特定 これで4ms分のチャタリングに耐えられる
    for (i = 0; i < 4; i++){
        tmp &= swBuffer[i];
    }
    return tmp;
}

// センサの値を更新する。
//  - Returns: センサの値
unsigned char sensInput(unsigned char zeroProof){
    static unsigned char zeroCount = 0; // ゼロ検出回数
    static unsigned char prevValue = 0; // 最後に検出されたまっとうな値
	static unsigned char zeroFlag = 0; // ゼロ検出フラグ

    // センサの値を取得
    unsigned char sensValue = bios_sensor_input();
    
    if(sensValue != 0){
        // まっとうな値が取れたら更新
        prevValue = sensValue;
		zeroCount = 0;
		zeroFlag = 0;
    }else{
        zeroCount++;
        // ゼロ検出回数が規定値を超えたら0x00を返す
        if(zeroCount >= zeroProof){
            zeroCount = 0;
			zeroFlag = 1;
            prevValue = 0x00;
        }
    }

    // TODO: センサの値もitask_inputでバッファリングするべきか?
    return prevValue;
}
