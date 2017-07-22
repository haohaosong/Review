/*************************************************************************
	> File Name: findLeafNum.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Sat 22 Jul 2017 02:39:13 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

struct Node
{
	Node* left;
	Node* right;
	int data;
};

int _getKLevelNode(Node* root,size_t k)
{
	if(root == NULL)
		return 0;

	if(k == 1)
		return 1;

	return _getKLevelNode(root->left,k-1)+_getKLevelNode(root->right,k-1);
}

int getKLevelNode(Node* root,size_t k)
{
	return _getKLevelNode(root,k);
}

void _countLeafNum(Node* root,int& count)
{
	if(root == NULL)
		return ;
	if(root->left == NULL && root->right == NULL)
		count++;

	if(root->left != NULL)
		_countLeafNum(root->left,count);
	if(root->right != NULL)
		_countLeafNum(root->right,count);
}

int countLeafNum(Node* root)
{
	int count = 0;
	_countLeafNum(root,count);
	return count;
}

int main()
{
	return 0;
}
