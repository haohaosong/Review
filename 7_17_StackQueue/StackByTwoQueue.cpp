/*************************************************************************
	> File Name: StackByTwoQueue.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Tue 18 Jul 2017 06:28:21 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<queue>
#include<assert.h>
template<typename T>
class Stack
{
public:
	void Push(const T&data)
	{
		qin.push(data);
	}

	void Pop()
	{
		if(qin.empty())
		{
			if(qout.empty())
				assert(0);
			while(qout.size()>1)
			{
				qin.push(qout.front());
				qout.pop();
			}
			qout.pop();
			return;
		}

		while(qin.size()>1)
		{
			qout.push(qin.front());
			qin.pop();
		}
		qin.pop();
	}

	const T& Top()
	{
		if(!qin.empty())
		{
			while(qin.size()>1)
			{
				qout.push(qin.front());
				qin.pop();
			}
			return qin.front();
		}

		while(qout.size()>1)
		{
			qin.push(qin.front());
			qout.pop();
		}
		const T& tmp = qout.front();
		qin.push(qout.front());
		return tmp;
	}
private:
	queue<T> qin;
	queue<T> qout;
};

int main()
{
	Stack<int> s;
	s.Push(1);
	cout<<s.Top()<<endl;
	s.Push(2);
	cout<<s.Top()<<endl;
	s.Push(3);
	cout<<s.Top()<<endl;
	s.Push(4);
	cout<<s.Top()<<endl;
	s.Pop();
	cout<<s.Top()<<endl;
	s.Push(5);
	cout<<s.Top()<<endl;
	return 0;
}
