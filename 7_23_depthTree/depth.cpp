/*************************************************************************
	> File Name: depth.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Sun 23 Jul 2017 08:43:32 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

struct Node
{
	Node* left;
	Node* right;
};

size_t _depth(Node* root)
{
	if(root == NULL)
		return 0;

	size_t leftDepth = _depth(root->left);
	size_t rightDepth = _depth(root->right);

	return leftDepth>rightDepth ? leftDepth+1 : rightDepth+1;
}

size_t depth(Node* root)
{
	return _depth(root);
}

int main()
{
	return 0;
}
