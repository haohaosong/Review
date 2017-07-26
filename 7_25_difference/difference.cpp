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
	{}
	void PushBack(int data)
	{
		Node* newNode = new Node(data);
		if(_head == NULL)
		{
			_head = newNode;
		}
		else
		{
			Node* cur = _head;
			while(cur->_next)
				cur = cur->_next;
			cur->_next = newNode;
		}	
	}
	
	List(Node* phead)
	:_head(phead)
	{}

	Node*& Head()
	{
		return _head;
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

protected:
	Node* _head;
};

void deleteNode(Node** LA,Node* dNode)
{
	if(dNode == NULL)
		return;

	if(dNode == *LA)
	{
		*LA = (*LA)->_next;
		delete dNode;
		dNode = NULL;
		return ;
	}

	Node* prev = *LA;
	while(prev && prev->_next != dNode)
	{
		prev = prev->_next;
	}

	if(prev)
		prev->_next = dNode->_next;
}

void difference(Node** LA,Node* LB)
{
	if(*LA == NULL || LB == NULL)
		return ;

	Node* cur1 = *LA;
	Node* cur2 = LB;

	Node* ret = *LA;
	while(cur1 != NULL)
	{
		cur2 = LB;
		while(cur2)
		{
			if(cur2->_data == cur1->_data)
				break;

			cur2 = cur2->_next;
		}

		if(cur2)
			deleteNode(LA,cur1);

		cur1 = cur1->_next;
	}
}

void Test()
{
	List l1;
	l1.PushBack(5);
	l1.PushBack(10);
	l1.PushBack(20);
	l1.PushBack(15);
	l1.PushBack(25);
	l1.PushBack(30);

	List l2;

	l2.PushBack(5);
	l2.PushBack(15);
	l2.PushBack(35);
	l2.PushBack(25);

	difference(&l1.Head(),l2.Head());

	l1.Print();
}

int main()
{
	Test();
	return 0;
}
