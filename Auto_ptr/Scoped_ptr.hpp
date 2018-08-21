#pragma once
#include<iostream>

using namespace std;

template<class T>
class Scoped_ptr{
public:
	//构造函数
	Scoped_ptr(T* p){
		_ptr = p;
	}
	T& operator*(){
		return *_ptr;
	}

	T* operator->(){
		return _ptr;
	}

	//析构函数
	~Scoped_ptr<T>(){
		if (_ptr)
			delete _ptr;
	}

private:
	Scoped_ptr(const Scoped_ptr<int>&sp);//拷贝构造
	Scoped_ptr& operator=(const Scoped_ptr<int>&sp);//赋值运算符的重载
	T* _ptr;
};
