/*************************************************************************
	> File Name: quickSortNonR.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Thu 22 Jun 2017 09:22:24 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<assert.h>
#include<stack>

void PrintArr(int* arr, size_t n)
{
	for(int i = 0; i<n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int PartSort(int* arr, int left, int right)
{
	int cur = left;
	int prev = left-1;

	while(cur < right)
	{
		if(arr[cur] < arr[right] && ++prev != cur)
			std:swap(arr[cur],arr[prev]);

		++cur;
	}

	if(++prev != cur)
		swap(arr[cur],arr[prev]);

	return prev;
}

void quickSortNonR(int* arr, int n)
{
	stack<int> s;
	int left = 0;
	int right = n-1;
	s.push(right);
	s.push(left);

	while(!s.empty())
	{
		int left = s.top();
		s.pop();
		int right = s.top();
		s.pop();

		int mid = PartSort(arr, left, right);
		if(left < mid-1)
		{
			s.push(mid-1);
			s.push(left);
		}

		if(right > mid+1)
		{
			s.push(right);
			s.push(mid+1);
		}
	}
}

int main()
{
	int arr[] = {1,3,5,7,9,2,4,6,8,0};
	quickSortNonR(arr,sizeof(arr)/sizeof(arr[0]));
	PrintArr(arr,sizeof(arr)/sizeof(arr[0]));
	return 0;
}
