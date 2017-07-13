/*************************************************************************
	> File Name: OneToN1.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Thu 13 Jul 2017 03:54:05 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

typedef int (*p)(size_t n);

p Array[2];

int cal1(size_t n)
{
	return 0;
}

int cal2(size_t n)
{
	return Array[!n](n-1)+n;
}

int main()
{
	Array[0] = cal2;
	Array[1] = cal1;

	int count = cal2(100);
	cout<<count<<endl;

	return 0;
}
