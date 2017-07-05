/*************************************************************************
	> File Name: quickSort.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Thu 22 Jun 2017 08:52:26 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<assert.h>

void PrintArr(int* arr, size_t n)
{
	for(int i = 0; i<n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

//单趟排序，算法1：挖坑法
int PartSort1(int* arr, int left, int right)
{
	int key = arr[right];
	while(left < right)
	{
		while(left < right && arr[left] <= key)
			left++;
		arr[right] = arr[left];

		while(left < right && arr[right] >= key)
			right--;
		arr[left] = arr[right];
	}
	arr[left] = key;
	return left;
}

//单趟排序，算法2，左右指针法
int PartSort2(int* arr, int left, int right)
{
	while(left < right)
	{
		while(left < right && arr[left] <= arr[right])
			left++;

		while(left < right && arr[right] >= arr[left])
			right--;

		swap(arr[left],arr[right]);
	}

	return left;
}

//单趟排序，算法3，前后指针法
int PartSort3(int* arr, int left, int right)
{
	int cur = left;
	int prev = left-1;

	while(cur < right)
	{
		if(arr[cur] <arr[right] && ++prev != cur)
			std::swap(arr[prev],arr[cur]);

		cur++;
	}

	if(++prev != cur)
		std:swap(arr[prev],arr[cur]);

	return prev;
}

void quickSort(int* arr, int left, int right)
{
	assert(arr);

	if(left < right)
	{
		int mid = PartSort3(arr,left,right);
		quickSort(arr,left,mid-1);
		quickSort(arr,mid+1,right);
	}
}

int main()
{
	int arr[] = {1,3,5,7,9,2,4,6,8,0};
	quickSort(arr,0,sizeof(arr)/sizeof(arr[0])-1);
	PrintArr(arr,sizeof(arr)/sizeof(arr[0]));
	return 0;
}
