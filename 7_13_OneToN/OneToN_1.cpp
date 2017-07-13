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
	A()
	{
		i++;
		count+=i;
	}

	static int GetCount()
	{
		return count;
	}

private:
	static int i;
	static int count;
};

int A::i = 0;
int A::count = 0;

int main()
{
	A* pa = new A[100];
	cout<<A::GetCount()<<endl;
	return 0;
}
