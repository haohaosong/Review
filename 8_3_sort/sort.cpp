/*************************************************************************
	> File Name: sort.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Thu 03 Aug 2017 07:01:50 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<vector>

int main()
{
	int arr[] = {12,13,12,13,19,18,15,12,15,16,17};
	vector<int> v;
	v.resize(20);
	for(int i=0; i<sizeof(arr)/sizeof(arr[0]);++i)
		v[arr[i]]++;

	for(int i=0; i<v.size(); ++i)
	{
		while((v[i]--) > 0 )
			cout<<i<<" ";
	}
	cout<<endl;
	return 0;
}
