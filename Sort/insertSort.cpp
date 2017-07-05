/*************************************************************************
	> File Name: insertSort.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Tue 20 Jun 2017 03:18:24 PM CST
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

void insertSort(int* arr,size_t n)
{
	for(int i = 1; i<n; ++i)
	{
		int tmp = arr[i];
		for(int j = i; j>=0; --j)
		{
			if(arr[j-1] > tmp)
			{
				if(j-1 >= 0)
					arr[j] = arr[j-1];
				else
					arr[j] = tmp;
			}
			else
			{
				arr[j] = tmp;
				break;
			}
		}
	}
}

int main()
{
	int arr[] = {1,3,5,7,9,2,4,6,8,0};
	insertSort(arr,sizeof(arr)/sizeof(arr[0]));
	PrintArr(arr,sizeof(arr)/sizeof(arr[0]));
	return 0;
}
