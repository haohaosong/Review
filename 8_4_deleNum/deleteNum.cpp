/*************************************************************************
	> File Name: deleteNum.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Thu 10 Aug 2017 10:31:44 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#include<vector>
#include<string>

void countStr(vector<int>& v,string& str)
{
	char ch = 0;
	int i = 0;
	while(ch = str[i++])
		v[ch]++;
}

void deleteNum(string& str)
{
	vector<int> v;
	v.resize(256);
	countStr(v,str);

	string::iterator fast = str.begin();	
	string::iterator slow = str.begin();

	while(fast != str.end())
	{
		if(v[*fast] > 1)
		{
			v[*fast]--;
		}
		else if(v[*fast] == 1)
		{
			v[*fast] = 0;
			*slow = *fast;
			*slow++;
		}

		*fast++;
	}
	while(slow != str.end())
		*slow++ = '\0';
}

int main()
{
	string str = "bbcacdww";
	deleteNum(str);
	cout<<str<<endl;
	return 0;
}
