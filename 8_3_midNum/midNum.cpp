/*************************************************************************
	> File Name: midNum.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Thu 03 Aug 2017 07:15:32 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int partSort(int* arr,int left, int right)
{
	int cur = left;
	int prev = cur-1;

	while(cur < right)
	{
		if(arr[cur] < arr[right] && ++prev != cur)
			swap(arr[cur],arr[prev]);

		++cur;
	}

	if(++prev != cur)
		swap(arr[prev],arr[cur]);
	return prev;
}

void _findMidNum(int* arr,int left, int right,const int mLIndex,const int mRIndex,int& midL,int& midR)
{
	if(right < mLIndex || left > mRIndex)
		return ;

	if(left < right)
	{
		int mid = partSort(arr,left,right);
		if(mLIndex != -1 && mid == mLIndex)
			midL = arr[mid];
		
		if(mid == mRIndex)
			midR = arr[mid];
	
		_findMidNum(arr,left,mid-1,mLIndex,mRIndex,midL,midR);
		_findMidNum(arr,mid+1,right,mLIndex,mRIndex,midL,midR);
	}
}

void findMidNum(int* arr,int n)
{
	int mLIndex = -1;
	int mRIndex = n>>1;
	if((n&1)!= 1)
		mLIndex = mRIndex-1;

	int midL = 0;
	int midR = 0;

	cout<<n<<endl;
	_findMidNum(arr,0,n-1,mLIndex,mRIndex,midL,midR);

	if((n&1)!=1)
		cout<<"midL: "<<midL<<" midR:"<<midR<<endl;
	else
		cout<<"mid: "<<midR<<endl;
}

int main()
{
	int arr[] = {2,5,4,9,3,6,8,7,1,0};
	findMidNum(arr,sizeof(arr)/sizeof(arr[0]));
	return 0;
}
