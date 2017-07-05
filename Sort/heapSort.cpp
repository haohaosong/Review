/*************************************************************************
	> File Name: heapSort.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Wed 21 Jun 2017 09:05:49 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

void PrintArr(int* arr, size_t n)
{
	for(int i = 0; i<n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void AdjustDown(int* arr,size_t n, size_t i)
{
	int parent = i;
	int child = parent*2+1;
	while(child <  n)
	{
		//找出孩子中的最大值
		if(child + 1< n && arr[child] < arr[child+1])
			child += 1;

		if(arr[child] > arr[parent])
			std::swap(arr[child],arr[parent]);
		else
			break;
		parent = child;
		child = parent*2+1;
	}
}

void heapSort(int* arr, size_t n)
{
	for(int i = (n-2)/2; i>=0; --i)
	{
		AdjustDown(arr,n,i);
	}
	int end = n-1;
	while(end > 0)
	{
		swap(arr[0],arr[end]);
		AdjustDown(arr,end,0);
		end--;
	}
}

int main()
{
	int arr[] = {1,3,5,7,9,2,4,6,8,0};
	heapSort(arr,sizeof(arr)/sizeof(arr[0]));
	PrintArr(arr,sizeof(arr)/sizeof(arr[0]));
	return 0;
}
