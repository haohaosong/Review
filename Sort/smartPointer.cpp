/*************************************************************************
	> File Name: smartPointer.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Mon 19 Jun 2017 04:26:13 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//autoPtr
template<typename T>
class autoPtr
{
public:
	//构造函数
	autoPtr(T* p)
		:_p(p)
	{}

	//拷贝构造函数
	autoPtr(autoPtr &ap)
		:_p(ap._p)
	{
		ap._p = NULL;
	}

	//赋值运算符重载
	autoPtr& operator=(autoPtr<T>& ap)
	{
		//如果不是自身拷贝
		if(this != &ap)
		{
			//如果自身指向不为空
			if(_p != NULL)
			{
					delete _p;
					_p = ap._p;
					ap._p = NULL;
			}
		}

		return *this;
	}
	
	//析构函数
	~autoPtr()
	{
		if(_p != NULL)
		{
			delete _p;
			_p = NULL;
		}
	}
	
	//获得智能指针存储的空间
	T* Get()
	{
		return _p;
	}
	
	//重载解引用运算符
	T& operator*()
	{
		return *_p;	
	}

	//重载箭头符号
	T* operator->()
	{
		return _p;
	}
protected:
	T* _p;
};

//scopedPtr
template<typename T>
class scopedPtr
{
public:
	//构造函数
	scopedPtr(T* sp)
		:_p(sp)
	{}

	//析构函数
	~scopedPtr()
	{
		if(_p != NULL)
		{
			delete _p;
			_p = NULL;
		}
	}

	//获取指针所指向的空间
	T* Get()
	{
		return _p;
	}
	
	//重载解引用运算符
	T& operator*()
	{
		return *_p;
	}

	//重载箭头运算符
	T* operaor->()
	{
		return _p;
	}
protected:
	T* _p;

protected:
	scopedPtr(scopedPtr& sp) = delete;
	scopedPtr& operator=(scopedPtr&sp) = delete;
};

template<typename T>
class sharedPtr()
{
public:
	sharedPtr(T* sp)
		:_p(sp)
		,_pCount(NULL)
	{
		//当对象不为空时，对_pCount进行引用计数
		if(_p != NULL)
		{
			_pCount = new int(1);
		}
	}
	
	sharedPtr(sharedPtr<T> & sp)
		:_p(sp._p)
		,_pCount(sp._pCount)
	{
			++(*sp._pCount);
			_pCount = sp._pCount;
	}

	sharedPtr&operator=(sharedPtr<T>& sp)
	{
		if(this != &sp)
		{
			if(_pCount == NULL)
			{
				_p = sp._p;
				_pCount = sp._pCount;
			}
			else if(*_pCount == 1)
			{
				delete _p;
				delete _pCount;
				_p = sp._p;
				_pCount = sp._pCount;
				if(_pCount != NULL)
					++(*_pCount);
			}
			else
			{
				--(*_pCount);
				_p = sp._p;
				_pCount = sp._pCount;
				if(_pCount != NULL)
					++(*_pCount);
			}
		}
	}
	~sharedPtr()
	{
		if(*_pCount == 0)
		{
			perror("~sharedPtr()");
		}
		else if(*_pCount == 1)
		{
			delete _p;
			delete _pCount;
		}
		else
		{
			(*_pCount) -= 1;	
		}
		_p = NULL;
		_pCount = NULL;
	}

protected:
	T* _p;
	int* _pCount;
};

int main()
{
	return 0;
}
