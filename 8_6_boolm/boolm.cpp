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

template<class T>
struct BKDRHash
{
	size_t operator()(const T str)
	{
		register size_t hash = 0;
		for(size_t i=0; i<str.size(); ++i)
		{
			hash = hash*131+str[i];
		}
		return hash;
	}
};

template<class T>
struct SDBMHash
{
	size_t operator()(const T str)
	{
		register size_t hash = 0;
		for(size_t i=0; i<str.size(); i++)
		{
			hash = 65599*hash + str[i];
		}
		return hash;
	}
};

template<class T>
struct RSHash
{
	size_t operator()(const T str)
	{
		register size_t hash = 0;
		size_t magic = 63689;
		for(size_t i=0; i<str.size(); ++i)
		{
			hash = hash * magic +str[i];
			magic*=378551;
		}
		return hash;
	}
};

template<class T>
struct APHash
{
	size_t operator()(const T str)
	{
		register size_t hash = 0;
		for(long i=0; i<str.size(); ++i)
		{
			if((i&1) == 0)
			{
				hash^=((hash<<7)^str[i] ^(hash>>3));
			}
			else
			{
				hash^=(~((hash<<11)^str[i] ^(hash>>5)));
			}
		}
		return hash;
	}
};

template<class T>
struct JSHash
{
	size_t operator()(const T str)
	{
		if(str.empty())
			return 0;

		register size_t hash = 0;
		for(size_t i=0; i<str.size(); ++i)
		{
			hash ^= ((hash<<5)+str[i]+(hash>>2));
		}
		return hash;
	}
};

template<class K = string,
	class HashFunc1 = BKDRHash<K>,
	class HashFunc2 = SDBMHash<K>,
	class HashFunc3 = RSHash<K>,
	class HashFunc4 = APHash<K>,
	class HashFunc5 = JSHash<K>
>
class BoolmFilter
{
public:
	size_t HashFunC1(const K&num)
	{
		HashFunc1 hf;
		size_t index = hf(num);
		return index;
	}

	size_t HashFunC2(const K&num)
	{
		HashFunc2 hf;
		size_t index = hf(num);
		return index;
	}
	
	size_t HashFunC3(const K&num)
	{
		HashFunc3 hf;
		size_t index = hf(num);
		return index;
	}
	
	size_t HashFunC4(const K&num)
	{
		HashFunc4 hf;
		size_t index = hf(num);
		return index;
	}

	size_t HashFunC5(const K&num)
	{
		HashFunc5 hf;
		size_t index = hf(num);
		return index;
	}

	void Set(const K&num)
	{
		size_t hf1 = HashFunC1(num);
		size_t hf2 = HashFunC2(num);
		size_t hf3 = HashFunC3(num);
		size_t hf4 = HashFunC4(num);
		size_t hf5 = HashFunC5(num);
	
		bp.Set(hf1);
		bp.Set(hf2);
		bp.Set(hf3);
		bp.Set(hf4);
		bp.Set(hf5);
	}

	bool Find(const K& num)
	{
		size_t hf1 = HashFunC1(num);
		if(bp.Find(hf1) == false)
			return false;
		
		size_t hf2 = HashFunC2(num);
		if(bp.Find(hf2) == false)
			return false;

		size_t hf3 = HashFunC3(num);
		if(bp.Find(hf3) == false)
			return false;

		size_t hf4 = HashFunC4(num);
		if(bp.Find(hf4) == false)
			return false;

		size_t hf5 = HashFunC5(num);
		if(bp.Find(hf5) == false)
			return false;
	}
protected:
	BitMap bp;
};

int main()
{
	return 0;
}
