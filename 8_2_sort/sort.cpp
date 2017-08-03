/*************************************************************************
	> File Name: sort.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Thu 03 Aug 2017 09:42:55 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

void _merge(int* arr,int* tmp,int left,int mid, int right)
{
	int begin1 = left;
	int end1 = mid;
	int begin2 = mid+1;
	int end2 = right;

	int index = left;

	while(begin1 <= end1 && begin2 <=end2)
	{
		if(arr[begin1] < arr[begin2])
			tmp[index++] = arr[begin1++];
		else
			tmp[index++] = arr[begin2++];
	}
	while(begin1 <= end1)
		tmp[index++] = arr[begin1++];

	while(begin2 <= end2)
		tmp[index++] = arr[begin2++];

	for(int i=left; i<=right; ++i)
		arr[i] = tmp[i];
}

void _mergeSort(int* arr,int* tmp, int left, int right)
{
	if(left < right)
	{
		int mid = left + ((right-left)>>1);
		_mergeSort(arr,tmp,left,mid);
		_mergeSort(arr,tmp,mid+1,right);

		_merge(arr,tmp,left,mid,right);
	}
}

void mergeSort(int* arr,int n)
{
	int* tmp = new int[n];

	int left = 0;
	int right = n-1;
	_mergeSort(arr,tmp,left,right);

	delete[] tmp;
}

void PrintArr(int* arr,size_t n)
{
	for(int i=0; i<n; ++i)
		cout<<arr[i]<<" ";

	cout<<endl;
}

int main()
{
	int arr[] = {1,3,5,7,9,2,4,6,8,0};
	mergeSort(arr,10);
	PrintArr(arr,10);
	return 0;
}
