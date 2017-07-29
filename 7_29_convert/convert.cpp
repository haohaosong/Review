/*************************************************************************
	> File Name: convert.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Sat 29 Jul 2017 11:04:59 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

void Convert(Node* root, Node*& prevNode)
{
	if(root == NULL)
		return;

	Convert(root->left,prevNode);

	root->left = prevNode;

	if(prevNode)
		prevNode->right = root;

	prevNode = root;

	Convert(root->right,prevNode);
}

int main()
{
	return 0;
}
