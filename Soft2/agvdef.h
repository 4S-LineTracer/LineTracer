/*****************************************************************************************************************
	FILE        :agvdef.h
	DATE        :Tue, Oct 18, 2011
	DESCRIPTION :AGVの入出力デバイス関する定義を行う
	CPU TYPE    :H8/3052F

*****************************************************************************************************************/

/****	ディジタル入出力ポートに関するアドレス定義															*****/
#define	STEP_PORT	(*(volatile unsigned char *)0xa0000)		/* ステッピングモータ相出力ポートのアドレス定義	*/
#define	SENS_PORT	(*(volatile unsigned char *)0xa0000)		/* センサ情報入力ポートのアドレス定義			*/

/****	ワークベンチパネルデバイスのポートに関するアドレス定義												*****/
#define	SW_PORT		(*(volatile unsigned char *)0xa0007)		/* SWポートのアドレス定義						*/
#define	LED_PORT	(*(volatile unsigned char *)0xa0007)		/* LEDポートのアドレス定義						*/
#define	BEEP_PORT	(*(volatile unsigned char *)0xa0006)		/* BEEPポートのアドレス定義						*/

#define	BEEP_ON		0x01										/* BEEP ON コード								*/
#define	BEEP_OFF	0x00										/* BEEP OFF コード								*/	

/****	A/D関係のポートに関するアドレス定義およびbit定義													*****/
#define	SH_PORT		(*(volatile unsigned char *)0xa0003)		/* S&H動作指定ポートのアドレス定義				*/
																/* bit7=1でサンプルモード/0でホールド			*/
#define	SAMPLE_MODE	0x80										/* サンプルモードのbit定義						*/
#define	HOLD_MODE	0x00										/* ホールドモードのbit定義						*/

#define	AD_PORT		(*(volatile unsigned char *)0xa0002)		/* 任意値書込みで変換開始/読出し=変換値			*/

/****	D/Aポートに関するアドレス定義																		*****/
#define DA_PORT		(*(volatile unsigned char *)0xa0004)		/* D/Aポートのアドレス定義						*/

/**** 操作スイッチに関連する定義																			*****/
#define	RUN_SW	0x01											/* SW_DATAのこのbitが立つと走行開始				*/

/****	センサおよびハンドルに関連する定義																	*****/
#define SENS_CENTER		0x80									/* センサの中央値								*/
#define HANDLE_CENTER	0x80									/* ハンドルの中央値								*/

#define	Kp		0.8												/* ハンドル制御比例係数							*/
#define	Ki		0.05											/* ハンドル制御積分係数							*/
#define	INT_MAX	1000											/* 積分計算の上限値								*/


// 搬送車動作状態
#define AGV_BOOT 0
#define AGV_BOOT_ALM 1
#define AGV_READY 2
#define AGV_READY_ALM 3
#define AGV_RUN 4
#define AGV_SEARCH 5
#define AGV_RUN_ALM 6

// モータ動作状態
#define MOTOR_STOP 0
#define MOTOR_ACCEL 1
#define MOTOR_CONST 2
#define MOTOR_BREAK 3

