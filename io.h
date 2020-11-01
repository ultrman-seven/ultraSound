#ifndef __IO_H__
#define __IO_H__
#include"common.h"

sbit in_hc138_0 = P2 ^ 2;
sbit in_hc138_1 = P2 ^ 3;
sbit in_hc138_2 = P2 ^ 4;

void digitalTube(un16 val);
#endif // !__IO_H__
