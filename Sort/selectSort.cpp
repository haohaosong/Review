/*************************************************************************
	> File Name: selectSort.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Wed 21 Jun 2017 08:44:05 AM CST
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

void selectSort(int* arr, size_t n)
{
	for(int i = 0; i<n-1; ++i)
	{
		int minIndex = i;
		for(int j = i; j<n; ++j)
		{
			if(arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}
		swap(arr[i],arr[minIndex]);
		PrintArr(arr,n);
	}
}

int main()
{
	int arr[] = {1,3,5,7,9,2,4,6,8,0};
	selectSort(arr, sizeof(arr)/sizeof(arr[0]));
	PrintArr(arr, sizeof(arr)/sizeof(arr[0]));
	return 0;
}
