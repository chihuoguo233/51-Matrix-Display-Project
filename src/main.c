#include <REGX51.H>
#include "matrixled.h"
#include "timer0.h"
#include "uart.h"

unsigned int g_ticks=0;
volatile char uart_cmd=0; //这个用来存串口指令
unsigned char eyes_state=0;



void main()
{
	static unsigned char current_state=0;	 //指令对应的状态,0是初始化
	_74hc595_Init();   //避免上点闪烁
	Timer_Init();	   //定时器初始化
	while(1)
	{
		if(uart_cmd)
		{
			switch(uart_cmd)		 //三个数字对应三种状态
			{
				case '1':{					
					current_state=1;
					UART_SendString("MCU Mode:smile\r\n");
					}break;			
				case '2':{
					current_state=2;
					UART_SendString("MCU Mode:cry\r\n");
					}break;
				case '3':{
				 	current_state=3;
					UART_SendString("MCU Mode:boring\r\n");
				}break;
				default:
				break;
			}
			uart_cmd=0;
		}

			switch(current_state)
			{		
				case 0:heartbeat();break;
				case 1:show_smile();break;
				case 2:show_cry();break;
				case 3:show_boring();break;
				default:
				break;
			}

	}
}

void Timer0_Rountine() interrupt 1
{
	TL0 = 0x66;				//设置定时初始值
	TH0 = 0xFC;				//设置定时初始值
	g_ticks++;
	if(g_ticks>=500)
	{
		g_ticks=0;
		eyes_state=!eyes_state;
	}
}

void UART_Rountine() interrupt 4
{
	if(RI==1)
	{
		RI=0;
		uart_cmd=SBUF;
	}
}
