/*************************************************************************
	> File Name: mirror.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Mon 24 Jul 2017 10:36:13 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

struct Node
{
	Node* left;
	Node* right;
	int data;
};

void mirror(Node* root)
{
	if(root == NULL)
		return NULL;

	swap(root->left,root->right);

	mirror(root->left);
	mirror(root->right);
}

Node* Mirror(Node* root)
{
	mirror(root);
	return root;
}

int main()
{
	return 0;
}
