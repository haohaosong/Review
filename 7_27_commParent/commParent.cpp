/*************************************************************************
	> File Name: commParent.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Sat 29 Jul 2017 12:18:51 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<stack>

bool FindPath(Node* root,int data, stack<int>& Path)
{
	if(root == NULL)
		return false;

	Path.push(root);
	if(root->data == data)
		return true;

	if(FindPath(root->left,data,Path))
		return true;

	if(FindPath(root->right,data,Path))
		return true;

	Path.pop();
	return false;
}

int TheCommNode(Node* root,int x1,int x2)
{
	assert(root);

	stack<int> s1;
	stack<int> s2;

	FindPath(root,x1,s1);
	FindPath(root,x2,s2);

	int size1 = s1.size();
	int size2 = s2.size();

	if(size1 > size2)
	{
		int tmp = size1 - size2;
		while(tmp--)
			s1.pop();
	}

	if(size2 > size1)
	{
		int tmp = size2 - size1;
		while(tmp--)
			s2.pop();
	}

	while(1)
	{
		if(s1.top() == s2.top())
			return s1.top():
	
		s1.pop();
		s2.pop();
	}

	assert(false);
}

int main()
{
	return 0;
}
