/*************************************************************************
	> File Name: itoa.c
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Wed 09 Aug 2017 09:48:13 AM CST
 ************************************************************************/

#include<stdio.h>

#define TRUE 1
#define FALSE 0

#include<stdlib.h>

char* my_itoa(int value,char* string,int redix)
{
	int x = value;//保留除下来的数字
	int y = 0;//保留取余的数
	int i = 0;//字符串的下标
	int flag = TRUE;
	int left = 0;
	int right = 0;

	if(value < 0)
	{
		flag = FALSE;
		x = -value;
		string[i++] = '-';
	}
	do
	{
		y = x%redix;
		x = x/redix;

		if(y <= 9)
			string[i++] = y+'0';
		else
			string[i++] = y+'a'-10;
	}while(x);

	string[i] = '\0';
	right = i-1;
	if(flag == FALSE)
		left = 1;

	while(left < right)
	{
		char tmp = string[left];
		string[left] = string[right];
		string[right] = tmp;
		
		left++;
		right--;
	}

	return string;
}

int main()
{
	char buf[32];
	
	int num = 95;
	printf("%d -> %s\n",num,my_itoa(num,buf,99));
	
	num = 0;
	printf("%d -> %s\n",num,my_itoa(num,buf,10));
	
	num = -12345;
	printf("%d -> %s\n",num,my_itoa(num,buf,10));
	
	return 0;
}
