/*************************************************************************
	> File Name: copyCpp.c
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Fri 28 Jul 2017 07:18:26 PM CST
 ************************************************************************/

#include<stdlib.h>
#include<stdio.h>

typedef struct A
{
	int a;
	void (*print)(struct A* This);
}A;

typedef struct B
{
	A aa;
	int b;
}B;

void PrintA(struct A* this)
{
	printf("PrintA(A*)\n");
}

void PrintB(struct A* this)
{
	printf("PrintB(B*)\n");
}

A* createA(int a)
{
	A* This = NULL;
	This = (A*)malloc(sizeof(A));
	if(This != NULL)
	{
		This->a = a;
		This->print = PrintA;

		printf("create A success!!\n");
	}
	return This;
}

void destroyA(A **pa)
{
	if(*pa != NULL)
	{
		free(*pa);
		*pa = NULL;
		printf("delete A success!!\n");
	}
}

B* createB(int a,int b)
{
	B* This = NULL;
	This = (B*)malloc(sizeof(B));
	if(This != NULL)
	{
		This->aa.a = a;
		This->b = b;
		This->aa.print = PrintB;
		printf("create B success!!\n");
	}
	return This;
}

void destroyB(B **pb)
{
	if(*pb != NULL)
	{
		free(*pb);
		*pb = NULL;
		printf("delete B success!!\n");
	}
}

int main()
{
	B* pb = createB(1,2);
	A* pa;

	pa = (A*)pb;

	pa->print(pa);
	destroyB(&pb);
	return 0;
}
