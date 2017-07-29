/*************************************************************************
	> File Name: absTree.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Sat 29 Jul 2017 11:55:47 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<queue>

struct Node
{
	Node* left;
	Node* right;
	int data;
};

bool absTree(Node* root)
{
	if(root == NULL)
		return false;
	
	queue<Node*> q;
	q.push(root);

	while(!q.empty())
	{
		Node* top = q.front();
		q.pop();

		if(top == NULL)
			break;

		q.push(top->left);
		q.push(top->right);
	}
		
	while(!q.empty())
	{
		Node* top = q.front();
		if(top != NULL)
			return false;

		q.pop();
	}

	return true;
}

int main()
{
	return 0;
}
