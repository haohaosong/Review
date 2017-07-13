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

	Node*& GetHead()
	{
		return _head;
	}
protected:
	Node* _head;
	Node* _tail;
};

Node* MergeOrderListNonR(Node* phead1,Node* phead2)
{
	if(phead1 == NULL)
		return phead2;
	if(phead2 == NULL)
		return phead1;

	Node* newHead = NULL;
	Node* Cur = NULL;

	Node* cur1 = phead1;
	Node* cur2 = phead2;

	if(cur1->_data <= cur2->_data)
	{
		newHead = cur1;
		cur1 = cur1->_next;
	}
	else
	{
		newHead = cur2;
		cur2 = cur2->_next;
	}

	Cur = newHead;

	while(cur1 && cur2)
	{
		if(cur1->_data <= cur2->_data)
		{
			Cur->_next = cur1;
			cur1 = cur1->_next;
		}
		else
		{
			Cur->_next = cur2;
			cur2 = cur2->_next;
		}

		Cur = Cur->_next;
	}

	if(cur1 == NULL)
		Cur->_next = cur2;
	else
		Cur->_next = cur1;

	return newHead;
}

Node* MergeOrderList(Node* phead1,Node* phead2)
{
	if(phead1 == NULL)
		return phead2;
	if(phead2 == NULL)
		return phead1;

	Node* newHead = NULL;
	if(phead1->_data < phead2->_data)
	{
		newHead = phead1;
		newHead->_next = MergeOrderList(phead1->_next,phead2);
	}
	else
	{
		newHead = phead2;
		newHead->_next = MergeOrderList(phead1, phead2->_next);
	}
	
	return newHead;
}
void TestMergeOrderList()
{
	List l1;
	l1.PushBack(1);
	l1.PushBack(2);
	l1.PushBack(3);
	l1.PushBack(4);
	l1.PushBack(5);

	List l2;
	l2.PushBack(0);
	l2.PushBack(6);
	l2.PushBack(7);
	l2.PushBack(8);
	l2.PushBack(9);

    List l;
	l.GetHead() = MergeOrderListNonR(l1.GetHead(),l2.GetHead());
    cout<<endl;
	l.Print();
}

int main()
{
	TestMergeOrderList();
	return 0;
}
