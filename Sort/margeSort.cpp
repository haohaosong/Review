/*************************************************************************
	> File Name: margeSort.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Fri 23 Jun 2017 11:05:44 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

void PrintArr(int* arr,size_t n)
{
	for(int i = 0; i<n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void _marge(int* arr,int* tmp, int left, int mid,int right)
{
	int beg1 = left;
	int end1 = mid;
	int beg2 = mid+1;
	int end2 = right;

	int index = left;

	while(beg1 <= end1 && beg2 <= end2)
	{
		if(arr[beg1] < arr[beg2])
			tmp[index++] = arr[beg1++];
		else
			tmp[index++] = arr[beg2++];
	}

	while(beg1 <= end1)
		tmp[index++] = arr[beg1++];
	while(beg2 <= end2)
		tmp[index++] = arr[beg2++];

	for(int i = left; i<=right; ++i)
	{
		arr[i] = tmp[i];
	}
}

void _margeSort(int* arr,int* tmp, int left, int right)
{
	//如果元素不大于1，返回，不用进行排序
	if(left>=right)
		return;

	int mid = left+((right-left)>>1);

	_margeSort(arr,tmp,left,mid);
	_margeSort(arr,tmp,mid+1,right);

	_marge(arr,tmp,left,mid,right);
}

void margeSort(int* arr,size_t n)
{
	int* tmp = new int[n];
	int left = 0; 
	int right = n-1;
	_margeSort(arr,tmp,left,right);
	delete[] tmp;
}

int main()
{
	int arr[] = {1,3,5,7,9,2,4,6,8,0};
	margeSort(arr,sizeof(arr)/sizeof(arr[0]));
	PrintArr(arr,sizeof(arr)/sizeof(arr[0]));
	return 0;
}
