#ifndef __MATRIXLED_H__
#define __MATRIXLED_H__

sbit RCK=P3^5;
sbit SCK=P3^6;
sbit SER=P3^4;

#define MatrixLed_Port P0


void _74hc595_writebyte(unsigned char BYTE);
void show_smile(void);
void show_cry(void);
void show_boring(void);
void _74hc595_Init(void);
void heartbeat(void);

#endif
