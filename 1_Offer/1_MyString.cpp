#include <iostream>
#include <string.h>
using namespace std;

class MyString
{
public:
	MyString(const char* msg = " ")
		:_str(new char[strlen(msg)+1])
	{
		strcpy(_str, msg);
	}
	~MyString()
	{
		delete []_str;
	}
	MyString(const MyString& s)
		:_str(new char[s.size()+1])
	{
		strcpy(_str, s.c_str());
	}
	MyString& operator=(const MyString& s)
	{
		MyString tmp(s);
		swap(tmp);
		return *this;
	}
	size_t size() const
	{
		return strlen(_str);
	}
	const char* c_str() const
	{
		return _str;
	}
	void swap(MyString& s)
	{
		std::swap(_str, s._str);
	}
	void output()
	{
		cout << _str << endl;
	}
private:
	char* _str;
};

int main()
{
	MyString ms("love");
	ms.output();
	MyString mt;
	mt.output();
	mt = ms;
	ms.output();
	mt.output();
	MyString mg(ms);
	mg.output();
	return 0;
}
