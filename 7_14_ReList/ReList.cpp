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

typedef ListNode Node;

class List
{
public:
	List()
	:_head(NULL)
	,_tail(NULL)
	{}
	void PushBack(int data)
	{
		Node* newNode = new Node(data);
		if(_head == NULL)
		{
			_head = _tail = newNode;
		}
		else
		{	
			_tail->_next = newNode;
			_tail = newNode;
		}	
	}
	
	List(Node* phead)
	:_head(phead)
	,_tail(NULL)
	{
		Node* cur = phead;
		Node* prev = NULL;
		while(cur)
		{
			prev = cur;
			cur = cur->_next;
		}
		_tail = prev;
	}

	void Print()
	{
		Node* cur = _head;
		while(cur)	
		{
			cout << cur->_data << " ";
			cur = cur->_next;
		}
		cout<<endl;
	}

	void ReListNonR()
	{
		Node* cur = _head;
		Node* prev = NULL;

		_tail = _head;
		while(cur)
		{
			Node* Next = cur->_next;
			cur->_next = prev;
			prev = cur;
			cur = Next;
		}

		_head = prev;
	}

	Node* _ReList(Node* head)
	{
		if(head == NULL)
			return NULL;
		
		Node* ret =  _ReList(head->_next);
		if(ret)
			ret->_next = head;
		else
			_head = head;

		return head;
	}

	void ReList()
	{
		_tail = _ReList(_head);
		_tail->_next = NULL;
	}

protected:
	Node* _head;
	Node* _tail;
};

void TestReList()
{
	List l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);
	l.PushBack(5);

	l.Print();

	l.ReListNonR();
	l.Print();
}

int main()
{
	TestReList();
	return 0;
}
