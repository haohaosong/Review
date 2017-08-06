/*************************************************************************
	> File Name: bitMap.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Sat 05 Aug 2017 09:08:06 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<vector>
#include<assert.h>
class BitMap
{
public:
	BitMap(size_t n = 1024)
		:size(0)
	{
		v.resize(n/32+1);
	}

	void Set(size_t n)
	{
		int index = (n>>5);
		int value = n%32;

		v[index] |= 1<<(value-1);
		size++;
	}

	void ReSet(size_t n)
	{
		assert(size > 0);

		int index = (n>>5);
		int value = n%32;

		v[index] ^= 1<<(value-1);
		size--;
	}

	bool Find(size_t n)
	{
		int index = (n>>5);
		int value = n%32;

		return (v[index]>>(value-1))&1;
	}

protected:
	vector<size_t> v;
	size_t size;
};

int main()
{
	return 0;
}
