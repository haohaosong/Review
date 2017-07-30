/*************************************************************************
	> File Name: insertSort.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Sun 30 Jul 2017 06:00:36 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

void PrintArr(int* arr ,size_t n)
{
	for(int i = 0; i<n; ++i)
		cout<<arr[i]<<" ";

	cout<<endl;
}
void insertSort(int* arr,size_t n)
{
	for(int i = 1; i<n; ++i)
	{
		int tmp = arr[i];
		int j = 0;
		for(j = i-1; j>=0; --j)
		{
			if(arr[j] < tmp)
				break;
			arr[j+1] = arr[j];
		}
		arr[j+1] = tmp;
		PrintArr(arr,n);
	}
}

void ShellSort(int* arr,size_t n)
{
	int gap = n;

	while(gap > 1)
	{
		gap = gap/3+1;

		for(int i = gap; i<n; ++i)
		{
			int end = i-gap;
			int tmp = arr[i];

			while(end >= 0)
			{
				if(arr[end] <= tmp)
					break;
				
				arr[end+gap] = arr[end];
				end-=gap;
			}
			arr[end+gap] = tmp; 
		}
	}
}

int main()
{
	int arr[10] = {1,3,5,7,9,2,4,6,8,0};
	ShellSort(arr,10);
	PrintArr(arr,10);
	return 0;
}
