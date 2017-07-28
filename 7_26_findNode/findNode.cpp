/*************************************************************************
	> File Name: findNode.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Fri 28 Jul 2017 03:36:30 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

struct Node
{
	Node* left;
	Node* right;
};

bool isExist(Node* root,Node* node)
{
	if(root == NULL || node == NULL)
		return false;

	if(root == node)
		return true;

	bool left = isExist(root->left,node);	
	bool right = isExist(root->right,node);	

	return left || right;
}

int main()
{
	return 0;
}
