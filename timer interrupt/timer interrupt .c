#include<LPC21xx.h>
#define sw 1<<14
int flag=1;
void delay(int ms)
{
int i;
for(;ms>0;ms--)
for(i=12000;i>0;i--);
}
void interrupt()__irq
{
T0IR=1<<0;
if(flag==1)
{
IOCLR0=1<<0;
flag=0;
}
else
{
IOSET0=1<<0;
flag=1;
}
VICVectAddr=0;
}
int main()
{
int count=0;
IODIR0=0x03;
T0MCR|=1<<1|1<<0;
T0MR0=7500000-1;
VICIntSelect=0;
VICVectCntl0=(0x20)|4;
VICVectAddr0= (unsigned int)interrupt;
VICIntEnable=1<<4;
T0TCR=0x01;
while(1)
{

if((IOPIN0&sw)==0)
{
count=1;
}
if(count==1)
{
IOCLR0=1<<1;
delay(1000);
IOSET0=1<<1;
delay(1000);
count=0;
}
else
	IOSET0=1<<1;

}
}
