/*************************************************************************
	> File Name: SpAdd.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Fri 14 Jul 2017 11:16:17 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int SpAdd(int x, int y)
{
	int sum = 0;
	int tmp = 0;

	do
	{
		sum = x^y;//求出不进位的结果

		tmp = (x&y)<<1;//求出需要进位的位置

		x = sum;
		y = tmp;

	}while(tmp != 0);

	return sum;
}

int main()
{
	cout<<"1 + 2 = " << SpAdd(1,2)<<endl;
	cout<<"5 + 8 = " << SpAdd(5,8)<<endl;
	cout<<"5 + 17 = " << SpAdd(5,17)<<endl;
	return 0;
}
