/*****************************************************************************************************************
	FILE        : def_monitor_printf.h
	DATE        :Mon, Jun 26, 2010
	DESCRIPTION :���j�^��ɏ������܂ꂽprintf�����scanf�̃A�h���X���`����
	CPU TYPE    :H8/3052F

*****************************************************************************************************************/

#define  printf	((int (*)(const char *,...))0x00002bb2)
#define  scanf	((int (*)(const char *,...))0x00002c04)