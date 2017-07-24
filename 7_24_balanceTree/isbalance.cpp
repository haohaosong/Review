/*************************************************************************
	> File Name: isbalance.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Mon 24 Jul 2017 10:08:28 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<math.h>

struct Node
{
	Node* left;
	Node* right;
	int data;
};

int depth(Node* root)
{
	if(root == NULL)
		return 0;

	int leftDepth = depth(root->left);
	int rightDepth = depth(root->right);

	return leftDepth>rightDepth? leftDepth+1:rightDepth+1;
}

bool isBalance(Node* root)
{
	if(root == NULL)
		return true;

	int leftDepth = depth(root->left);
	int rightDepth = depth(root->right);

	if(fabs(leftDepth-rightDepth)<2)
		return isBalance(root->left) && isBalance(root->right);

	return false;
}

bool isBalanceB(Node* root,int& depth)
{
	if(root == NULL)
	{
		depth = 0;
		return true;
	}

	int leftDepth = 0;
	int rightDepth = 0;

	bool isLeft = isBalanceB(root->left,leftDepth);
	bool isRight = isBalanceB(root->right,rightDepth);

	bool ret = isLeft && isRight;

	if(!ret)
		return false;

	depth = leftDepth > rightDepth ? leftDepth+1 : rightDepth+1;
	return fabs(leftDepth-rightDepth)<2;
}

int main()
{
	return 0;
}
