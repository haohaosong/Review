/*************************************************************************
	> File Name: layer.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Fri 21 Jul 2017 08:03:09 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<queue>

struct Node
{
	int data;
	Node* left;
	Node* right;
};

void LayOrder(Node* root)
{
	if(root == NULL)
		return ;

	queue<Node*> s;
	s.push(root);
	while(!s.empty())
	{
		Node* top = s.front();
		s.pop();
		cout<<top->data<<" ";

		if(top->left != NULL)
			s.push(top->left);
		if(top->right != NULL)
			s.push(top->right);
	}
	cout<<endl;
}

int main()
{
	return 0;
}
