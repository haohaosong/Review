/*************************************************************************
	> File Name: QueueByTwoStack.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Tue 18 Jul 2017 05:30:58 PM CST
 ************************************************************************/
//==37%^

#include<iostream>
using namespace std;
#include<stack>

template<typename T>
class Queue
{
public:
	void Push(const T& data)
	{
		sin.push(data);
	}

	void Pop()
	{
		if(sout.empty())
		{
			while(!sin.empty())
			{
				sout.push(sin.top());
				sin.pop();
			}
		}
		if(!sout.empty())
			sout.pop();
	}

	const T& Front()
	{
		if(!sout.empty())
			return sout.top();
		
		while(!sin.empty())
		{
			sout.push(sin.top());
			sin.pop();
		}
		return sout.top();
	}
private:
	stack<T> sin;
	stack<T> sout;
};

int main()
{
	Queue<int> q;
	q.Push(1);
	cout<<q.Front()<<endl;
	q.Push(2);
	cout<<q.Front()<<endl;
	q.Push(3);
	cout<<q.Front()<<endl;
	q.Push(4);
	cout<<q.Front()<<endl;

	q.Pop();
	cout<<q.Front()<<endl;
	return 0;
}
