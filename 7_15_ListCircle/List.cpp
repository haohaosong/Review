/*************************************************************************
	> File Name: List.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Sat 15 Jul 2017 11:09:02 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

struct ListNode
{
	int _data;
	ListNode* _next;

	ListNode(int data)
		:_data(data)
		 ,_next(NULL)
	{}
};

class List
{
	typedef ListNode Node;
public:
	List()
		:_head(NULL)
	{}

	void PushBack(int data)
	{
		Node* newNode = new Node(data);

		if(_head == NULL)
		{	
			_head = newNode;
			return ;
		}
		Node* cur = _head;
		while(cur->_next)
			cur = cur->_next;

		cur->_next = newNode;
	}

	void Print()
	{
		Node* cur = _head;
		while(cur)
		{
			cout<<cur->_data<<" ";
			cur = cur->_next;
		}
		cout<<endl;
	}

	Node* find(int data)
	{
		Node* cur = _head;
		while(cur)
		{
			if(cur->_data == data)
				return cur;

			cur = cur->_next;
		}
		return NULL;
	}

	//O(N)
	Node* HasCircle()
	{
		Node* fast = _head;
		Node* slow = _head;

		while(fast)
		{
			Node* fNext = fast->_next;
			if(fNext == NULL)
				break;

			fast = fNext->_next;
			slow = slow->_next;

			if(fast == slow)
				return fast;
		}
		return NULL;
	}

	//O(N)
	size_t CircleLen()
	{
		Node* ret = HasCircle();
		if(ret == NULL)
			return 0;

		Node* cur = ret->_next;

		size_t count = 1;
		while(cur != ret)
		{
			cur = cur->_next;
			count++;
		}
		return count;
	}

	//
	Node* CircleFirst()
	{
		Node* fast = HasCircle();
		if(fast == NULL)
			return NULL;

		Node* slow = _head;
		while(slow != fast)
		{
			slow = slow->_next;
			fast = fast->_next;
		}

		return fast;
	}
private:
	Node* _head;
};

void Test()
{
	List l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);
	l.PushBack(5);
	l.PushBack(6);

	l.Print();
	l.find(6)->_next = l.find(3);

	cout<<l.CircleLen()<<endl;	
	cout<<l.CircleFirst()->_data<<endl;
}

int main()
{
	Test();
	return 0;
}
