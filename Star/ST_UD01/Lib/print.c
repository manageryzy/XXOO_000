/*******************************************************************************
* Copyright 2014      深圳思达仪表  固件部  
* All right reserved
*
* 文件名称：print
*
* 文件标识：
* 摘    要：print lib
*
* 当前版本：V1.0
* 作    者：F06553
* 完成日期：2014-9-2
* 编译环境：D:\software\IAR_for_ARM\arm
* 
* 源代码说明：
*******************************************************************************/
#include    "all_header_file.h"

/*** static function prototype declarations ***/



/*** static variable declarations ***/



/*** extern variable declarations ***/





static const char FormatHexChar[16] = 
{
	'0', '1', '2', '3', '4', '5', '6', '7', 
	'8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
};

/*******************************************************************************
* 函数名称: 
* 输入参数: buff *p
*           buff  size
* 输出参数: 
* --返回值: 
* 函数功能: print Hex 
*******************************************************************************/
void printHex(const unsigned char *buf, uint32_t len)
{
	char str;
	int i;
	unsigned char uc;

	for(i=1u; i<=len; i++) 
	{
		uc = *buf++;
		str = FormatHexChar[uc>>4];
		printf("%c", str);
		str = FormatHexChar[uc&0x0f];
		printf("%c", str);
		if(0u == (i&0x1f)) 
		{
			printf("\r\n");
		}
		else if(0u == (i&0x03)) 
		{
			printf("%c", ' ');
		}
	}

 	printf("\r\n");
}

/*******************************************************************************
* 函数名称: Flash_map
* 输入参数: 
* 输出参数: 
* --返回值: 
* 函数功能: read extern Flash(MX25L4006) verify image
*******************************************************************************/
void Flash_map(void)
{
    uint32_t i = 0;
    uint32_t j = ApplicationAddress; 
    
    memset(&tab_1024[0], 0, PACKET_SIZE);
    for (i=0u; i<1056; i++) /* (132*1024)/128 0-32 sector */
    {
        MX25L3206_Read((uint8_t *)tab_1024, j, PACKET_SIZE);
        j += PACKET_SIZE;
        printHex(tab_1024,PACKET_SIZE);
    }    
}




