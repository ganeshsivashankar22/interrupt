#include<LPC21xx.h>
void delay(int ms)
{
int i;
for(;ms>0;ms--)
for(i=12000;i>0;i--);
}
void nonvectinter()__irq
{
if((VICIRQStatus>>14)&1)
{
EXTINT=1<<0;
IOCLR0=1<<0;
delay(1000);
IOSET0=1<<0;

}
else if ((VICIRQStatus>>15)&1)
{
EXTINT=1<<1;
IOCLR0=1<<1;
delay(1000);
IOSET0=1<<1;
} 
VICVectAddr=0; 
}

int main()
{
int count=0;
IODIR0=0x03;
PINSEL1=1<<0;
PINSEL0|=1<<6|1<<7;
IOSET0|=1<<0|1<<1;
VICIntSelect=0;
VICDefVectAddr=	(unsigned long) nonvectinter;
VICIntEnable|=1<<14|1<<15;
EXTMODE|=1<<1|1<<0;
EXTPOLAR=0x00;
while(1)
{
count++;
}


}