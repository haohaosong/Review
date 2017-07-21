/*************************************************************************
	> File Name: Order.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Fri 21 Jul 2017 09:43:06 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<stack>
#include<queue>

template<typename T>
class Order
{
public:
	Order(const T* in,const T* out, size_t sz)
	{
		for(int i=0; i<sz; ++i)
		{
			sIn.push(in[i]);
			sOut.push(out[i]);
		}
	}

	bool isOrder()
	{
		if(sIn.size() != sOut.size())
			return false;

		stack<T> tmp;

		while(!sIn.empty())
		{
			tmp.push(sIn.front());
			sIn.pop();
			while(!tmp.empty() && tmp.top() == sOut.front())
			{
				cout<<tmp.top()<<" == " <<sOut.front()<<endl;
				tmp.pop();
				sOut.pop();
			}
		}

		if(tmp.empty())
			return true;
		return false;
	}
private:
	queue<T> sIn;
	queue<T> sOut;
};

int main()
{
	int In[5] = {1,2,3,4,5};
	//int Out[5] = {5,4,3,1,2};
	int Out[5] = {4,5,3,2,1};
	Order<int> o(In,Out,5);
	cout<<o.isOrder()<<endl;
	return 0;
}
