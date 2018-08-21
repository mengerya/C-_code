#pragma once
#include<iostream>
using namespace std;

template<class T>
class Scoped_array{
public:
	//构造函数
	Scoped_array(T* p){
		_ptr = p;
	}

	T& operator[](size_t i){
		return _ptr[i];
	}

	//析构函数
	~Scoped_array<T>(){
		if (_ptr)
			delete[] _ptr;
	}


private:
	//拷贝构造
	Scoped_array(const Scoped_array<int>& s);
	//赋值运算符的重载
	Scoped_array& operator=(const Scoped_array<int>& s);
	T* _ptr;
};
