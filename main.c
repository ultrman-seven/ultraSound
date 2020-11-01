#include"ultraSound.h"
#include"io.h"
sbit key = P3 ^ 3;
void main()
{
	un16 dist = 0;
	while (1)
	{
		if (!key)
		{
			delay(20);
			if (!key)
				dist = ULsound_diatance();
		}
		digitalTube(dist);
	}
}
void delay(un16 time)
{
	while (time--);
}