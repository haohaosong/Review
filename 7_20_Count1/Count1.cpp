/*************************************************************************
	> File Name: Count1.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Fri 21 Jul 2017 10:35:00 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int Count1(int num)
{
	int count = 0;
	while(num)
	{
		num = num&(num-1);
		count++;
	}
	return count;
}

int Count2(unsigned int  num)
{
	int count = 0;
	for(int i=0; i<32; ++i)
	{
		if((num >> i) & 1 == 1)
			count++;
	}
	return count;
}


int main()
{
	cout<<Count2(-1)<<endl;
	return 0;
}
