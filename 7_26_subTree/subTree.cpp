/*************************************************************************
	> File Name: subTree.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Fri 28 Jul 2017 03:21:08 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

struct Node
{
	Node* left;
	Node* right;
	int data;
};

bool DoesHasSubTree(Node* srcT,Node* subT)
{
	if(subT == NULL)
		return true;

	if(srcT == NULL)
		return false;

	if(subT->data != srcT->data)
		return false;

	bool left = DoesHasSubTree(src->left,subT->left);
	bool right = DoesHasSubTree(src->right,subT->right);

	return left && right;
}

bool HasSubTree(Node* srcT, Node* subT) 
{
	if(subT == NULL)
		return false;

	bool ret = false;
	if(srcT != NULL)
	{
		if(srcT->data == subT->data)
			ret = DoesHasSubTree(srcT,subT);

		if(!ret)
			ret = HasSubTree(srcT->left,subT);

		if(!ret)
			ret = HasSubTree(srcT->right.subT);
	}

	return ret;
}

int main()
{
	return 0;
}
