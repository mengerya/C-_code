#pragma once
#include<iostream>
using namespace std;

template<class T>
class Auto_ptr
{
public:
	//构造函数
	Auto_ptr(T* p)
		:_ptr(p)
	{}

	//拷贝构造函数--管理权的转移--只改变指针的指向（浅拷贝）
	Auto_ptr(Auto_ptr<T>& ap){
		_ptr = ap._ptr;
		ap._ptr = NULL;
	}

	//赋值运算符重载
	Auto_ptr<T>& operator=(const Auto_ptr<T>& ap){
		//防止自己给自己赋值
		if (*this != *ap){
			//释放旧空间
			if (_ptr){
				delete _ptr;
			}
			_ptr = ap._ptr;
			ap._ptr = NULL;
		}
		return *this;
	}

	T& operator*(){
		return *_ptr;
	}

	T* operator->(){
		return _ptr;
	}

	//析构函数
	~Auto_ptr<T>(){
		if (_ptr)
			delete _ptr;
	}


private:
	T* _ptr;

};
