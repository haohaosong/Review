/*************************************************************************
	> File Name: OneToN1.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Thu 13 Jul 2017 03:54:05 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A
{
public:
	virtual int cal(size_t n)
	{
		return 0;
	}
};

A* Array[2];

class B:public A
{
public:
	virtual int cal(size_t n)
	{
		return Array[!n]->cal(n-1)+n;
	}
};

int main()
{
	A a;
	B b;
	Array[0] = &b;
	Array[1] = &a;

	int count = Array[0]->cal(100);
	cout<<count<<endl;

	return 0;
}
