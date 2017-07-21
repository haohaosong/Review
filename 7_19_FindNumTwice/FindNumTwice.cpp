/*************************************************************************
	> File Name: FindNumTwice.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Fri 21 Jul 2017 09:21:29 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

char FindTwice(char* str)
{
	unsigned short s[256] = {0};
	char* pstr = str;
	while(*pstr++ != '\0')
	{
		if(s[*pstr] < 3)
			s[*pstr]++;
	}

	pstr = str;
	while(*pstr++ != '\0')
	{
		if(s[*pstr] == 2)
			return *pstr;
	}

	return 0;
}

int main()
{
	char* str = "abcdefabcdefabc";
	char ret = FindTwice(str);
	cout<<ret<<endl;
	return 0;
}
