/*************************************************************************
	> File Name: OrderNonR.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Tue 25 Jul 2017 03:36:25 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<stack>

struct Node
{
	Node* left;
	Node* right;
	int data;
};

void PreOrderNonR(Node* root)
{
	Node* cur = root;
	stack<Node*> s;	
	while(cur || !s.empty())
	{
		while(cur)
		{
			cout<<cur->data<<" ";
			s.push(cur);
			cur = cur->left;
		}

		Node* top = s.top();
		s.pop();
		cur = top->right;
	}
	cout<<endl;
}

void InOrderNonR(Node* root)
{
	stack<Node*> s;
	Node* cur = root;
	while(cur || !s.empty())
	{
		while(cur)
		{
			s.push(cur);
			cur = cur->left;
		}
		Node* top = s.top();
		s.pop();
		cout<<top->data<<" ";
		cur = top->right;
	}
	cout<<endl;
}

void PostOrderNonR(Node* root)
{
	stack<Node*> s;
	Node* cur = root;
	Node* prev = NULL;
	while(cur || !s.empty())
	{
		while(cur)
		{
			s.push(cur);
			cur = cur->left;
		}
		Node* top = s.top();
		
		//不用访问右子树
		if(top->right == NULL || top->right == prev)
		{
			cout<<top->data<<" ";
			s.pop():
			prev = top;
		}
		else//访问右子树
		{
			cur = top->right;
		}
	}
	cout<<endl;
}

int main()
{
	return 0;
}
