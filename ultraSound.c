#include"ultraSound.h"
un16 distance = 0;
//89C52
void Delay20us()		//@12.000MHz
{
	unsigned char i;

	_nop_();
	i = 7;
	while (--i);
}
void Delay100ms()		//@12.000MHz
{
	unsigned char i, j;

	i = 195;
	j = 138;
	do
	{
		while (--j);
	} while (--i);
}


un16 ULsound_diatance(void)
{
	un8 maxWait = 100;
	un8 count=1;
	trig = distance = 0;
	Delay100ms();
	trig = 1;
	Delay20us();
	trig = 0;
	while (!echo);
	TMOD = 0x01;
	TH0 = TL0 = 0;
	TR0 = 1;
	EA = EX0 = 1;
	while (echo&&--maxWait)
	{
		if(TF0)
		{
			count++;
			TF0=0;
		}
		Delay20us();
	}
	return count * distance / 58;//cm
}

void countDistance(void) interrupt 0
{
	TR0 = 0;
	distance = TH0;
	distance <<= 8;
	distance |= TL0;
	EA = EX0 = 0;
}