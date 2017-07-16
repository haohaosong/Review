/*************************************************************************
	> File Name: testFork.c
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Sun 16 Jul 2017 06:05:03 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int i = 0;
	for(i = 0; i<2; ++i)
	{
		vfork();
		printf("%d\n",i);
	}
	return 0;
}
