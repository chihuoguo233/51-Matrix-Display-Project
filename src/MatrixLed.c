#include <REGX51.H>
#include <INTRINS.H>
#include "matrixled.h"

void _74hc595_writebyte(unsigned char BYTE)	  //选行用的函数
{
	unsigned char i;
	for(i=0;i<8;i++)			  //循环8次送数据
	{
		SER=BYTE&(0x80>>i);		  //这么写，有数据就1，不然就0
		SCK=1;
		SCK=0;
	}
	RCK=1;						 //把数据发出去
	RCK=0;						 //发完清零
}

void MatrixLed_Show(unsigned char Column,line)//先选列，再选行,用74hc595
{ 
	 MatrixLed_Port=~(0x80>>Column);   //控制列用的，因为共阴极接法，选好列再取反
	 _74hc595_writebyte(line);
	 _nop_();						  //空一点时间给IO口电平变化
	 _74hc595_writebyte(0x00);		  //清零，避免串位的出现

}

void _74hc595_Init(void)			   //初始化
{
	SCK=0;
	RCK=0;
	_74hc595_writebyte(0x00);
}
