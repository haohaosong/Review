/*************************************************************************
	> File Name: MinStack.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Fri 21 Jul 2017 08:58:29 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<stack>

template<typename T>
class Stack
{
public:
	void Push(const T& data)
	{
		s.push(data);

		if(sMin.empty())
		{	
			sMin.push(data);
		}
		else
		{
			if(sMin.top()>=data)
				sMin.push(data);
		}
	}

	void Pop()
	{
		if(s.empty())
			return ;

		if(s.top()==sMin.top())
			sMin.pop();
		s.pop();
	}

	const T& Min()
	{
		if(sMin.empty())
			return T();
		return sMin.top();
	}
private:
	stack<T> s;
	stack<T> sMin;
};

int main()
{
	Stack<int> s;
	cout<<s.Min()<<endl;
	s.Push(3);
	cout<<s.Min()<<endl;
	s.Pop();
	cout<<s.Min()<<endl;
	s.Push(2);
	cout<<s.Min()<<endl;
	s.Push(1);
	cout<<s.Min()<<endl;
	s.Push(7);
	cout<<s.Min()<<endl;
	s.Push(6);
	cout<<s.Min()<<endl;
	s.Push(9);
	cout<<s.Min()<<endl;
	return 0;
}
