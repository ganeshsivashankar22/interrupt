  #include<LPC21xx.h>
  void FIQ_Int()__irq
  {
  EXTINT=1<<1;
  IOSET0=1<<0;
  IOCLR0=1<<0;
  
  }
 int main()
 {
 int count=0;
 IODIR0=0x01;
PINSEL0|= 1<<29|0<<28;
VICIntSelect=1<<15;
EXTMODE=0x00;
EXTPOLAR=0x00;
VICIntEnable=1<<15;
while(1)
count++;
 }