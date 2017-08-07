/*************************************************************************
	> File Name: memmove.c
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Mon 07 Aug 2017 07:23:49 PM CST
 ************************************************************************/

#include<stdio.h>

void* my_memmove(void* des, const void* src, int num)
{
	char* pdes = (char*)des;
	char* psrc = (char*)src;

	if(des < src)//从前向后
	{
		while(num--)
			*(pdes++) = *(psrc++);
	}
	else
	{
		while(num--)
			pdes[num] = psrc[num];
	}

	return des;
}

int main()
{
	return 0;
}
