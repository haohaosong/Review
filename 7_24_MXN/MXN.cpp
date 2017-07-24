/*************************************************************************
	> File Name: MXN.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Mon 24 Jul 2017 10:41:26 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

bool isExist(int* arr, int m, int n, int key)
{
	int x = m-1;
	int y = 0;

	while(x >= 0 && y < n)
	{
		if(arr[y*m+x] < key)
			y++;
		else if(arr[y*m+x] > key)
			x--;
		else
			return true;
	}
	return false;
}

int main()
{
	int arr[] = {1,2,3,4,
				 2,3,4,5,
				 3,4,5,6};

	cout<<isExist(arr,4,3,7)<<endl;
	return 0;
}
