#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include<iostream>
#include<string>
#include<assert.h>
using namespace std;

namespace bit
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}

		/*string()
			:_str(new char[1]{'\0'})
			,_size(0)
			,_capacity(0)
		{}*/

		// 短小频繁调用的函数，可以直接定义到类里面，默认是inline
		string(const char* str = "")
		{
			_size = strlen(str);
			// _capacity不包含\0
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		// 深拷贝问题
		// s2(s1)
		/*string(const string& s)
		{
			_str = new char[s._capacity + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}*/

		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		// s2(s1)
		// 现代写法
		string(const string& s)
		{
			string tmp(s._str);
			swap(tmp);
		}

		// s2 = s1
		// s1 = s1
		/*string& operator=(const string& s)
		{
			if (this != &s)
			{
				delete[] _str;

				_str = new char[s._capacity + 1];
				strcpy(_str, s._str);
				_size = s._size;
				_capacity = s._capacity;
			}

			return *this;
		}*/

		// s1 = s3;
		//string& operator=(const string& s)
		//{
		//	if (this != &s)
		//	{
		//		//string tmp(s._str);
		//		string tmp(s);

		//		swap(tmp);
		//	}

		//	return *this;
		//}

		// s1 = s3;
		string& operator=(string tmp)
		{
			swap(tmp);

			return *this;
		}

		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
				_size = _capacity = 0;
			}
		}

		const char* c_str() const
		{
			return _str;
		}

		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}

		size_t size() const
		{
			return _size;
		}

		size_t capacity() const
		{
			return _capacity;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);

			return _str[pos];
		}

		const char& operator[](size_t pos) const
		{
			assert(pos < _size);

			return _str[pos];
		}

		/*void copy_on_write()
		{
			if (count > 1)
			{
				深拷贝
			}
		}*/

		void reserve(size_t n);
		void push_back(char ch);
		void append(const char* str);
		string& operator+=(char ch);
		string& operator+=(const char* str);

		void insert(size_t pos, char ch);
		void insert(size_t pos, const char* str);
		void erase(size_t pos, size_t len = npos);

		size_t find(char ch, size_t pos = 0);
		size_t find(const char* str, size_t pos = 0);
		string substr(size_t pos = 0, size_t len = npos);
	private:
		//char _buff[16];
		char* _str = nullptr;
		size_t _size = 0;
		size_t _capacity = 0;

		//static const size_t npos = -1;
		static const size_t npos;

		/*static const int N = 10;
		int buff[N];*/
	};

	bool operator<(const string& s1, const string& s2);
	bool operator<=(const string& s1, const string& s2);
	bool operator>(const string& s1, const string& s2);
	bool operator>=(const string& s1, const string& s2);
	bool operator==(const string& s1, const string& s2);
	bool operator!=(const string& s1, const string& s2);

	ostream& operator<<(ostream& out, const string& s);
	istream& operator>>(istream& in, string& s);
}