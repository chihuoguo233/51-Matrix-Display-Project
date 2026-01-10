#ifndef __MATRIXLED_H__
#define __MATRIXLED_H__

sbit RCK=P3^5;
sbit SCK=P3^6;
sbit SER=P3^4;

#define MatrixLed_Port P0


void _74hc595_writebyte(unsigned char BYTE);
void MatrixLed_Show(unsigned char Data,Column);
void _74hc595_Init(void);

#endif
