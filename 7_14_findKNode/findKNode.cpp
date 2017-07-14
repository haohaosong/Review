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

	Node* findLastKNode(size_t k)
	{
		if(k == 0)
			return NULL;

		Node* fast = _head;
		while(fast)
		{
			if(--k == 0)
				break;
			
			if(fast)
				fast = fast->_next;
		}
		
		if(k > 0)
			return NULL;

		Node* slow = _head;
		while(fast && fast->_next)
		{
			slow = slow->_next;
			fast = fast->_next;
		}

		return slow;
	}
protected:
	Node* _head;
	Node* _tail;
};

void TestFindLastKNode()
{
	List l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);
	l.PushBack(5);

	l.Print();

	Node* ret = NULL;
	if(ret = l.findLastKNode(6))
		cout<<" k : 6 "<<ret->_data<<endl;
	if(ret = l.findLastKNode(5))
		cout<<" k : 5 "<<ret->_data<<endl;
	if(ret = l.findLastKNode(4))
		cout<<" k : 4 "<<ret->_data<<endl;
	if(ret = l.findLastKNode(3))
		cout<<" k : 3 "<<ret->_data<<endl;
	if(ret = l.findLastKNode(2))
		cout<<" k : 2 "<<ret->_data<<endl;
	if(ret = l.findLastKNode(1))
		cout<<" k : 1 "<<ret->_data<<endl;
	if(ret = l.findLastKNode(0))
		cout<<" k : 0 "<<ret->_data<<endl;
}

int main()
{
	TestFindLastKNode();
	return 0;
}
