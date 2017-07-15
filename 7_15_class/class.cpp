/*************************************************************************
	> File Name: class.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Sat 15 Jul 2017 03:26:21 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A
{
public:
	static A* getObj()
	{
		A* obj = new A();
		return obj;
	}
private:
	A()
	{}
};

//class B:public A
//{};

class C
{
private:
	void* operator new(size_t t);
	void operator delete(void* ptr);
public:
	C()
	{}
	~C()
	{}
};

int main()
{
	A* pa = A::getObj();
	
	C c;
	return 0;	
}
