/*************************************************************************
	> File Name: string.cpp
	> Author: haohaosong
	> Mail: haohaosong@yeah.net 
	> Created Time: Tue 20 Jun 2017 09:50:35 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<string.h>

class String
{
public:
	//构造函数
	String(const char* pStr = "")
	{
		if(NULL != _pstr)
		{
			_pstr = new char[strlen(_pstr)+1];
			strcpy(_pstr,pStr);
		}
		else
		{
			_pstr = new char[1];
			*_pstr = '\0';
		}
	}

	//拷贝构造函数
	String(const String& s)
		:_pstr(new char[strlen(s._pstr)+1])
	{
		strcpy(_pstr,s._pstr);
	}

	//赋值运算符重载函数
	String& operator=(const String &s)
	{
		if(this != &s)
		{
			delete[] _pstr;
			_pstr = new char[strlen(s._pstr)+1];
			strcpy(_pstr,s._pstr);	
		}
		return *this;
	}

	//析构函数
	~String()
	{
		if(_pstr != NULL)
		{
			delete _pstr;
			_pstr = NULL;
		}
	}

	friend ostream& operator<<(ostream & _cout,String &s)
	{
		_cout << s._pstr;
		return _cout;
	}
protected:
	char* _pstr;
};

void TestString()
{
	string s1("123");
	string s2 = s1;
	string s3(s2);
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
}

int main()
{
	TestString();
	return 0;
}
