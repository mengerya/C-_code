#pragma once
#include<iostream>
using namespace std;

template<class T>
class Share_ptr{
public:
	//构造函数
	Share_ptr(const T* p)
		:_ptr(p)
		, _pCount(new int(1))
	{}

	Share_ptr(Share_ptr<T>* sp, int* spCount)
		:_ptr(sp)
		, _pCount(spCount)
	{}

	//拷贝构造函数
	Share_ptr(const Share_ptr<T>& sp){
		_ptr = sp._ptr;
		_pCount = sp._pCount;
		++(*_pCount);
	}

	//赋值运算符重载
	Share_ptr& operator=(Share_ptr<T>& sp){
		if (this != &sp){
			if (--(*_pCount) == 0){
				delete _ptr;
				delete _pCount;
			}
			_ptr = sp._ptr;
			_pCount = sp._pCount;
			++(*_pCount);
		}
		return *this;
	}

	T&operator*(){
		return *_ptr;
	}

	T*operator->(){
		return _ptr;
	}

	~Share_ptr(){
		if (--(*_pCount) == 0){
			delete _ptr;
			delete _pCount;
		}
	}

private:
	T* _ptr;
	int* _pCount;

};
