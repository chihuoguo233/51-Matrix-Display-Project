#include <REGX51.H>

//char str[]="hello world!";

void UART_SendString(char*str)	//发送数据的函数
{
	unsigned char i;
	for(i=0;str[i]!='\0';i++)
	{
		SBUF=str[i];
		while(!TI);
		TI=0;
	}
}


