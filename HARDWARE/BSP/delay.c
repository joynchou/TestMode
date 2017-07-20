/************************************************************
* 组织名称： (C), 1988-1999, Tech. Co., Ltd.
* 文件名称: delay.c
* 作者:
* 版本 :
* 日期:
* 描述: // 模块描述
* 主要函数及其功能 : // 主要函数及其功能
  1. -------
* 历史修改记录: // 历史修改记录
* <作者> <时间> <版本 > <描述>
***********************************************************/
/*************  功能说明    **************
本文件为STC15xxx系列的延时程序,用户几乎可以不修改这个程序.
******************************************/
#include    "delay.h"
//========================================================================
// 函数: void  delay_ms(unsigned char ms)
// 描述: 延时函数。
// 参数: ms,要延时的ms数, 这里只支持1~255ms. 自动适应主时钟.
// 返回: none.
// 版本: VER1.0
// 日期: 2013-4-1
// 备注:
//========================================================================
void  delay_ms(unsigned char ms)
{
    unsigned int i;
    do
    {
        i = MAIN_Fosc / 13000;
        while(--i)
        {
            ;    //14T per loop
        }
    }
    while(--ms);
}
