/*************************************************************************
	> File Name: destroy.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Sun 23 Jul 2017 09:17:40 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

void destroy(Node* root)
{
	if(root == NULL)
		return ;

	if(root->left != NULL)
		destroy(root->left);
	if(root->right != NULL)
		destroy(root->right);

	delete[] root;
	root = NULL;
}

int main()
{
	return 0;
}
