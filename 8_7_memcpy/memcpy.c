/*************************************************************************
	> File Name: memcpy.c
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Mon 07 Aug 2017 07:20:41 PM CST
 ************************************************************************/

#include<stdio.h>
#include<assert.h>

void* my_memcpy(void* des,const void* src, int num)
{
	assert(num > 0);
	char* pdest = (char*)des;
	char* psrc = (char*)src;

	while(num--)
	{
		pdest[num] = psrc[num];
	}
	return pdest;
}

int main()
{
	return 0;
}
