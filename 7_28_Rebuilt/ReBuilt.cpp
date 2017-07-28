/*************************************************************************
	> File Name: absTree.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Fri 28 Jul 2017 03:45:35 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;

	Node(int d)
		:data(d)
	{}
};

Node* ReBuilt(int* preOrder,int& i,int n,
			  int* inOrder, int left ,int right)
{
	if(i >= n || left > right)
	{
		i--;
		return NULL;
	}
	Node* newNode = new Node(preOrder[i]);

	int mid = -1;
	for(int m=left; m<=right;++m)
	{
		if(inOrder[m] == preOrder[i])
		{
			mid = m;
			break;
		}
	}

	newNode->left = ReBuilt(preOrder,++i,n,inOrder,left,mid-1);
	newNode->right = ReBuilt(preOrder,++i,n,inOrder,mid+1,right);

	cout<<"node:"<<newNode->data;

	if(newNode->left)
		cout<<" left:"<<newNode->left->data;
	if(newNode->right)
		cout<<" left:"<<newNode->right->data;

	cout<<endl;
	return newNode;
}

void PrintTree(Node* root)
{
	if(root == NULL)
		return ;
	PrintTree(root->left);
	cout<<root->data<<" ";
	PrintTree(root->right);
}

int main()
{
	int preOrder[6] = {1,2,3,4,5,6};
	int inOrder[6] = {3,2,4,1,6,5};
	int i = 0;
	Node* root = ReBuilt(preOrder,i,6,inOrder,0,5);
	PrintTree(root);
	cout<<endl;
	return 0;
}
