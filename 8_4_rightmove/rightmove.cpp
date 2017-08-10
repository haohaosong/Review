/*************************************************************************
	> File Name: rightmove.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Thu 10 Aug 2017 10:24:43 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

void _Move(int* arr, int left, int right)
{
	while(left < right)
	{
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;

		left++;
		right--;
	}
}

void Move(int* arr,const size_t sz, const size_t num)
{
	int left = 0;
	int right = sz-1;
	int mid = num-1;

	_Move(arr,left,mid-1);
	_Move(arr,mid,right);
	_Move(arr,left,right);
}

void PrintArr(int* arr,size_t n)
{
	for(int i=0; i<n; ++i)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int main()
{
	int arr[5] = {1,2,3,4,5};
	PrintArr(arr,sizeof(arr)/sizeof(arr[0]));
	Move(arr,sizeof(arr)/sizeof(arr[0]),3);
	PrintArr(arr,sizeof(arr)/sizeof(arr[0]));
	return 0;
}
