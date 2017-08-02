/*************************************************************************
	> File Name: sort.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Wed 02 Aug 2017 05:15:28 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<stack>
void PrintArr(int* arr,size_t n)
{
	for(int i=0; i<n; ++i)
		cout<<arr[i]<<" ";
	cout<<endl;
}

void BubbleSort(int* arr,size_t n)
{
	for(int i=0; i<n; ++i)
	{
		for(int j=0; j<n-i-1; j++)
		{
			if(arr[j] > arr[j+1])
				swap(arr[j],arr[j+1]);
		}
	}
}

int partSortL(int *arr, int left, int right)
{
	int cur = left;
	int prev = cur-1;

	while(cur < right)
	{
		if(arr[cur]<arr[right] && ++prev != cur)
			swap(arr[cur],arr[prev]);

		cur++;
	}
	
	swap(arr[cur],arr[prev]);
	return prev;
}

int partSort(int* arr, int left, int right)
{
	int key = right;

	while(left < right)
	{
		while(left < right && arr[left] <= arr[key])
			left++;

		while(left < right && arr[right] >= arr[key])
			right--;
		
		if(left < right)
			swap(arr[left],arr[right]);
	}
	
	swap(arr[left],arr[key]);
	return left;
}

void quickSort(int* arr,int left, int right)
{
	if(left < right)
	{
		int mid = partSort(arr,left,right);
		quickSort(arr,left,mid-1);
		quickSort(arr,mid+1,right);
	}
}

void quickSortNonR(int* arr,size_t n)
{
	int left = 0;
	int right = n-1;

	stack<int> s;
	s.push(right);
	s.push(left);

	while(!s.empty())
	{
		left = s.top();
		s.pop();
		right = s.top();
		s.pop();

		int mid = partSort(arr,left,right);

		if(left < mid-1)
		{
			s.push(mid-1);
			s.push(left);
		}

		if(mid+1 < right)
		{
			s.push(right);
			s.push(mid+1);
		}
	}
}

int main()
{
	int arr[10] = {1,3,5,7,9,2,4,6,8,0};
//	BubbleSort(arr,10);
	quickSortNonR(arr,10);
	PrintArr(arr,10);
	return 0;
}
