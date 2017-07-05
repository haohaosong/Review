/*************************************************************************
	> File Name: List.h
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Wed 05 Jul 2017 03:45:09 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

template<typename T>
struct __ListNode
{
	__ListNode* _prev;
	__ListNode* _next;

	T _data;

	__ListNode(T data)
		:_prev(NULL)
		,_next(NULL)
		,_data(data)
	{}
};

template<typename T, typename Ref, typename Ptr>
struct __ListIterator
{
	typedef __ListNode<T> Node;
	typedef __ListIterator<T,Ref,Ptr> self;

	Node* _node;

	__ListIterator()
		:_node(NULL)
	{}

	__ListIterator(Node* node)
		:_node(node)
	{}

	self& operator++()//前置++
	{
		_node = _node->_next;
		return (self&)_node;
	}

	self& operator++(int)
	{
		Node* tmp = _node;
		_node = _node->_next;
		return tmp;
	}

	self& operator--()
	{
		_node = _node->_prev;
		return (self&)_node;
	}

	self& operator--(int)
	{
		Node* tmp = _node;
		_node = _node->_prev;
		return tmp;
	}

	bool operator != (const self& s)
	{
		return _node != s._node;
	}
	
	bool operator == (const self& s)
	{
		return _node == s._node;
	}

	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return _node;
	}
};

template<typename T>
class List
{
	typedef __ListNode<T> Node;
public:
	typedef __ListIterator<T,T&,T*> Iterator;	
	
	Node* BuyNewNode(int data)
	{
		return new Node(data);
	}

	List()
		:_head(BuyNewNode(T()))
	{
		_head->_prev = _head;
		_head->_next = _head;
	}

	void PushBack(int data)
	{
		Node* newNode = BuyNewNode(data);
		Node* lastNode = _head->_prev;//找到最后一个节点
		lastNode->_next = newNode;
		newNode->_next = _head;
		_head->_prev = newNode;
		newNode->_prev = lastNode;
	}

	Iterator Begin()
	{
		return _head->_next;
	}

	Iterator End()
	{
		return _head;
	}

protected:	
	Node* _head;
};

void TestList()
{
	List<int> l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);

	List<int>::Iterator it = l.Begin();

	while(it != l.End())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
}

int main()
{
	TestList();
	return 0;
}
