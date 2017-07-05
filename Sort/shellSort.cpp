/*************************************************************************
	> File Name: shellSort.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Fri 23 Jun 2017 11:25:43 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

void PrintArr(int* arr, size_t n)
{
	for(int i = 0 ;i<n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void shellSort(int* arr, size_t n)
{
	int gap = n;
	while(gap > 1)
	{
		gap = gap/3+1;

		for(size_t i = gap; i<n; ++i)
		{
			int end = i-gap;
			int tmp = arr[i];

			while(end >= 0)
			{
				if(arr[end] <= tmp)
					break;

				arr[end+tmp] =  arr[end];
				end -= gap;
			}

			arr[end+gap] = tmp;
		}
	}
}

int main()
{	
	int arr[] = {1,3,5,7,9,2,4,6,8,0};
	shellSort(arr,sizeof(arr)/sizeof(arr[0]));
	PrintArr(arr,sizeof(arr)/sizeof(arr[0]));
	return 0;
}
