/*************************************************************************
	> File Name: ReList.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Tue 18 Jul 2017 08:28:25 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

struct ListNode
{
	ListNode* _next;
	int _data;
};

void _PrintRList(ListNode* head)
{
	if(head == NULL)
		return ;

	PrintRList(head->_next);
	cout<<head_data<<" ";
}

void PrintRList(ListNode* head)
{
	_PrintRList(head);
	cout<<endl;
}

void PopNotBack(ListNode* node)
{
	ListNode* delNode = node->_next;
	node->_data = delNode->_data;
	node->_next = delNode->_next;

	delete delNode;
}

int main()
{
	return 0;
}
