/*************************************************************************
	> File Name: OneToN1.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Thu 13 Jul 2017 03:54:05 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

template<int n>
int cal()
{
	return cal<n-1>()+n;
};

template<>
int cal<0>()
{
	return 0;
};

int main()
{
	int count = cal<100>();

	cout<<count<<endl;
	return 0;
}
