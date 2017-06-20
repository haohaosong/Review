/*************************************************************************
	> File Name: bubbleSort.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Tue 20 Jun 2017 02:57:43 PM CST
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

void bubbleSort(int* arr, size_t n)
{
	for(int i = 0; i<n-1; ++i)
	{
		for(int j = 0; j<n-1-i; ++j)
		{
			if(arr[j] > arr[j+1])
			{
				std::swap(arr[j],arr[j+1]);
			}
		}
	}
}

int main()
{
	int arr[10] = {1,3,5,7,9,2,4,6,8,0};
	bubbleSort(arr,sizeof(arr)/sizeof(arr[0]));
	PrintArr(arr,sizeof(arr)/sizeof(arr[0]));
	return 0;
}
