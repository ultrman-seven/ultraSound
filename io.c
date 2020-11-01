#include"io.h"

un8 dis_num[] = { 0x3f,0x06, 0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,/*0-9*/
							0x77,0x7c,0x58, 0x5e, 0x79,0x71,/*a-f*/		0x80/*.*/ };

un8 value;
char findZero(un8 n)
{
	char count;
	for (count = 0; n % 2; n /= 2)
		count++;
	return count;
}

void digitalTube(un16 val)
{
	void delay(un16 n);
	void hc138(un8 n);
	un8 count;
	if (val)
		for (count = 0; count <= 7; count++, val /= 10)
		{
			hc138(count);
			P0 = val ? dis_num[val % 10] : 0x00;
			delay(200);
			P0 = 0x00;
		}
	else
	{
		hc138(0);
		P0 = dis_num[0];//0x79;
	}
}
void hc138(un8 n)
{
	if (0 <= n && n <= 7)
	{
		in_hc138_0 = n % 2;
		n /= 2;
		in_hc138_1 = n % 2;
		n /= 2;
		in_hc138_2 = n % 2;
	}
}
