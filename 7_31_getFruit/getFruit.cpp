/*************************************************************************
	> File Name: getFruit.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Mon 31 Jul 2017 09:19:15 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<map>
#include<vector>

struct Cmp
{
	bool operator()(const int&x1,const int&x2)
	{
		return x1 > x2;
	}
};

void GetFruit(const vector<string>& fruits,size_t n)
{
	map<string,int> countMap;

	for(int i=0; i<fruits.size(); ++i)
	{
		map<string,int>::iterator ret = countMap.find(fruits[i]);
		if(ret != countMap.end())//存在
		{
			ret->second++;	
		}
		else//不存在则插入
		{
			countMap.insert(pair<string,int>(fruits[i],1));
		}
	}

	multimap<int,string,Cmp> _countMap;
	for(map<string,int> :: iterator it = countMap.begin();it != countMap.end(); it++)
	{
		_countMap.insert(pair<int,string>(it->second,it->first));
	}
	
	multimap<int,string,Cmp>::iterator it = _countMap.begin();
	
	size_t count = 0;
	while(it != _countMap.end() && count<n)
	{
		cout<<(*it).first<<":"<<(*it).second<<endl;
		count++;
		it++;
	}
}

int main()
{
	vector<string> v;
	v.push_back("苹果");
	v.push_back("香蕉");
	v.push_back("香蕉");
	v.push_back("香蕉");
	v.push_back("香蕉");
	v.push_back("香蕉");
	v.push_back("香蕉");
	v.push_back("香蕉");
	v.push_back("香蕉");
	v.push_back("香蕉");
	v.push_back("苹果");
	v.push_back("西瓜");
	v.push_back("西瓜");
	v.push_back("西瓜");
	v.push_back("西瓜");
	v.push_back("西瓜");
	v.push_back("桃子");
	v.push_back("桃子");
	v.push_back("西瓜");
	v.push_back("桃子");
	v.push_back("桃子");
	v.push_back("桃子");
	v.push_back("苹果");
	v.push_back("苹果");
	GetFruit(v,3);
	return 0;
}
