#include<LPC21xx.h>
void ext0_int_isr(void)__irq
{
EXTINT=0x01;
IOSET0=1<<8;
IOCLR0=1<<8;
VICVectAddr=0;
}
void ext1_int_isr(void)__irq
{
EXTINT=0x02;
IOSET0=1<<9;
IOCLR0=1<<9;
VICVectAddr=0;
}
void ext2_int_isr(void)__irq
{
EXTINT=0x04;
IOSET0=1<<10;
IOCLR0=1<<10;
VICVectAddr=0;
}		  
int main()
{
unsigned int count=0;
IODIR0=1<<8|1<<9|1<<10;

PINSEL0=1<<2|1<<3|1<<6|1<<7|1<<14|1<<15;
VICIntSelect=0;
VICVectCntl0=0X20|14;
VICVectAddr0= (unsigned long) ext0_int_isr;
VICVectCntl1=0x20|15;
VICVectAddr1=(unsigned long)ext1_int_isr;
VICVectCntl2=0x20|16;
VICVectAddr2=(unsigned long)ext2_int_isr;
EXTMODE=0x07;
EXTPOLAR=0x00;
VICIntEnable=1<<14|1<<15|1<<16;

while(1)
{
 count++;
}

}