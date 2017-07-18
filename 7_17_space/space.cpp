/*************************************************************************
	> File Name: space.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Tue 18 Jul 2017 07:21:20 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

char* Replace(char* str)
{
	int count = 0;
	char* pstr = str;
	
	while(*str)
	{
		if(*str == ' ')
			count++;
		str++;
	}

	char* end = str;
	char* end_new = str+2*count;

	while(end != end_new)
	{
		if(*end == ' ')
		{
			*end_new-- = '$';
			*end_new-- = '$';
			*end_new-- = '$';
			end--;
		}
		else
		{
			*end_new-- = *end--;
		}
	}

	return pstr;
}

int main()
{
	char arr[128] = "welcome to my github!";
	char* ret = Replace(arr);

	cout<<ret<<endl;
}
