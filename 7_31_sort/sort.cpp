/*************************************************************************
	> File Name: sort.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Mon 31 Jul 2017 08:13:33 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

void PrintArr(int* arr,size_t n)
{
	for(int i = 0; i<n; ++i)
		cout<<arr[i]<<" ";
	cout<<endl;
}

void selectSort(int* arr,size_t n)
{
	for(int i=0; i<n; ++i)
	{
		int min = i;
		for(int j=i+1; j<n; ++j)
		{
			if(arr[min] > arr[j])
				min = j;
		}
		swap(arr[min],arr[i]);
	}
}

void adjustDown(int* arr,size_t n,size_t i)
{
	int parent = i;
	int child = parent*2+1;

	while(child < n)
	{
		if(child+1<n && arr[child] < arr[child+1])
			child++;

		if(arr[child] > arr[parent])
		{
			swap(arr[child],arr[parent]);
			parent = child;
			child = parent*2+1;
		}
		else
		{
			break;
		}
	}
}

void heapSort(int* arr,size_t n)
{
	int* heap = new int[n];

	for(int i=0; i<n; ++i)
		heap[i] = arr[i];

	for(int i=(n-2)/2; i>=0; --i)
		adjustDown(heap,n,i);

	int end = n-1;

	while(end > 0)
	{
		swap(heap[0],heap[end]);
		adjustDown(heap,end,0);
		end--;
	}

	for(int i=0; i<n; ++i)
		arr[i] = heap[i];

	delete heap;
	heap = NULL;
}

int main()
{
	int arr[] = {1,3,5,7,9,2,4,6,8,0};
	heapSort(arr,10);
	PrintArr(arr,10);
	return 0;
}
