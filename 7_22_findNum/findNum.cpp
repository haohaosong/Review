/*************************************************************************
	> File Name: findNum.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Sat 22 Jul 2017 02:30:32 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int findNum(int* arr,size_t n)
{
	int num = arr[0];
	int count = 1;
	for(int i = 1; i<n; ++i)
	{
		if(num == arr[i])
		{
			count++;
			continue;
		}

		if(--count == 0)
		{
			num = arr[i+1];
			count = 1;
		}
	}
	return num;
}

int main()
{
	int arr[] = {2,3,2,2,2,2,2,5,4,1,2,3};
	int ret = findNum(arr,sizeof(arr)/sizeof(arr[0]));
	cout<<ret<<endl;
	return 0;
}
