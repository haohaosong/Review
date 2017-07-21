/*************************************************************************
	> File Name: N.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Fri 21 Jul 2017 07:58:02 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

unsigned int CountZero(unsigned int n)
{
	unsigned count = 0;
	for(int i=1; i<=n; ++i)
	{
		for(int j=i; j%5 == 0; )
		{
			count++;
			j=j/5;
		}
	}

	return count;
}

int main()
{
	cout<<CountZero(1)<<endl;
	cout<<CountZero(3)<<endl;
	cout<<CountZero(5)<<endl;
	cout<<CountZero(10)<<endl;
	return 0;
}
