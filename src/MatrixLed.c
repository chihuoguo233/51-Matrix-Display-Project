#include <REGX51.H>
#include <INTRINS.H>
#include "matrixled.h"

extern unsigned char eyes_state;

code unsigned char smile[]={0x3C,0x42,0xAD,0x8B,0x8B,0xAD,0x42,0x3C,};
code unsigned char boring[]={0x3C,0x42,0x91,0x85,0x85,0x91,0x42,0x3C,};
code unsigned char cry[]={0x40,0x78,0x42,0x02,0x02,0x42,0x78,0x40,};
code unsigned char heart[]={0x30,0x78,0x7C,0x3E,0x3E,0x7C,0x78,0x30};
code unsigned char laugh[]={0x3C,0x42,0x99,0x85,0x85,0x99,0x42,0x3C,};



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

void show_smile(void)//先选列，再选行,用74hc595 ，这里行不写数字，要写16进制对应的符号
{ 
	unsigned char i;
	
	if(eyes_state)
	{
		for(i=0;i<8;i++)
		{
			 MatrixLed_Port=~(0x80>>i);   //控制列用的，因为共阴极接法，选好列再取反
			 _74hc595_writebyte(smile[i]);
			 _nop_();						  //空一点时间给IO口电平变化
			 _74hc595_writebyte(0x00);		  //清零，避免串位的出现
		}		
	}
	else
	{
		for(i=0;i<8;i++)
		{
			 MatrixLed_Port=~(0x80>>i);   //控制列用的，因为共阴极接法，选好列再取反
			 _74hc595_writebyte(laugh[i]);
			 _nop_();						  //空一点时间给IO口电平变化
			 _74hc595_writebyte(0x00);		  //清零，避免串位的出现
		}				
	}
}


void show_cry(void)//先选列，再选行,用74hc595 ，这里行不写数字，要写16进制对应的符号
{ 
	unsigned char i;
	for(i=0;i<8;i++)
	{
		 MatrixLed_Port=~(0x80>>i);   //控制列用的，因为共阴极接法，选好列再取反unsigned char Column,line
		 _74hc595_writebyte(cry[i]);
		 _nop_();						  //空一点时间给IO口电平变化
		 _74hc595_writebyte(0x00);		  //清零，避免串位的出现
	}
}


void show_boring(void)//先选列，再选行,用74hc595 ，这里行不写数字，要写16进制对应的符号
{ 
	unsigned char i;
	for(i=0;i<8;i++)
	{
		 MatrixLed_Port=~(0x80>>i);   //控制列用的，因为共阴极接法，选好列再取反unsigned char Column,line
		 _74hc595_writebyte(boring[i]);
		 _nop_();						  //空一点时间给IO口电平变化
		 _74hc595_writebyte(0x00);		  //清零，避免串位的出现
	}
}

void heartbeat(void)//先选列，再选行,用74hc595 ，这里行不写数字，要写16进制对应的符号
{ 
	unsigned char i;
	for(i=0;i<8;i++)
	{
		 MatrixLed_Port=~(0x80>>i);   //控制列用的，因为共阴极接法，选好列再取反
		 _74hc595_writebyte(heart[i]);
		 _nop_();						  //空一点时间给IO口电平变化
		 _74hc595_writebyte(0x00);		  //清零，避免串位的出现
	}
}


void _74hc595_Init(void)			   //初始化
{
	SCK=0;
	RCK=0;
	_74hc595_writebyte(0x00);
}
