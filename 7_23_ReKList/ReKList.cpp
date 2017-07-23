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

	//排序一个小段
	//返回新小段的第一个节点
	Node* PReKList(Node* fNode, Node* lNode)
	{
		Node* cur = fNode;
		Node* prev = NULL;

		while(cur && cur != lNode)
		{
			Node* Next = cur->_next;
			cur->_next = prev;
			prev = cur;
			cur = Next;
		}
		return prev; 
	}

	//返回需要排序段的最后一个节点
	Node* findKNode(Node* node,size_t k)
	{
		Node* cur = node;
		for(int i=0; cur && cur->_next &&  i<k-1; ++i)
			cur = cur->_next;

		return cur;
	}

	//返回每一段排序后的第一个节点
	Node* _ReKList(Node* fNode, size_t k)
	{
		Node* lNode = findKNode(fNode,k);
		if(lNode)
		{
			Node* NNode = lNode->_next;
			Node* ret = PReKList(fNode,NNode);
			fNode->_next = _ReKList(NNode,k);
			return ret;
		}
		return NULL;
	}

	void ReKList(size_t k)
	{
		_head = _ReKList(_head,k);	
	}

protected:
	Node* _head;
};

void TestReList()
{
	List l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);
	l.PushBack(5);
	l.PushBack(6);

	l.Print();

	l.ReKList(4);
	l.Print();
}

int main()
{
	TestReList();
	return 0;
}
