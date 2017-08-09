/*************************************************************************
	> File Name: atoi.c
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Wed 09 Aug 2017 09:20:20 AM CST
 ************************************************************************/

#include<stdio.h>

#define TRUE 1
#define FALSE 0

//flag为true表示正数
//flag为false表示负数
int my_atoi(const char* str)
{
	char* pstr = (char*)str;
	int flag = TRUE;
	int ret = 0;
	char ch = *pstr;
	if(ch == '-')
	{
		flag = FALSE;
		pstr++;
	}
	else if(ch == '+')
	{
		flag = TRUE;
		pstr++;
	}
	else if(ch > '9' || ch < '0')
	{
		return 0;
	}

	while(*pstr != '\0')
	{
		ch = *pstr;
		if(ch > '9' || ch < '0')
			break;

		ret = ret*10+(ch-48);
		pstr++;
	}

	if(flag == FALSE)
		return -ret;
	return ret;
}

int main()
{
	char* str = "12345";
	printf("%s -> %d, the right result is -> %d\n",str,my_atoi(str),atoi(str));
	
	str = "012345";
	printf("%s -> %d, the right result is -> %d\n",str,my_atoi(str),atoi(str));
	
	str = "123-45";
	printf("%s -> %d, the right result is -> %d\n",str,my_atoi(str),atoi(str));
	
	str = "12345+";
	printf("%s -> %d, the right result is -> %d\n",str,my_atoi(str),atoi(str));
	
	str = "-12345";
	printf("%s -> %d, the right result is -> %d\n",str,my_atoi(str),atoi(str));
	
	str = "+12345";
	printf("%s -> %d, the right result is -> %d\n",str,my_atoi(str),atoi(str));
	
	str = "+12.345";
	printf("%s -> %d, the right result is -> %d\n",str,my_atoi(str),atoi(str));
	
	return 0;
}
