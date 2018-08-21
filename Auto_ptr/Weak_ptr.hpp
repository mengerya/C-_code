#pragma once
#include<iostream>

using namespace std;

template<class T>
class Weak_ptr;


template<class T>
class Share_ptr
{
	friend class Weak_ptr<T>;
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

template<class T>
class Weak_ptr{
public:
	//可以将sharedptr的对像传给他，匿名对象
	Weak_ptr(Share_ptr<T>& sp){
		//这里将sharedptr的对象给weakptr(弱指针)进行初始化，此时弱指针指向的是sharedptr的对象
		_ptr = sp._ptr;
	}

	Weak_ptr()
		:_ptr(NULL)
	{}

	Weak_ptr& operator=(Share_ptr<T>& sp){
		_ptr = sp._ptr;
		return *this;
	}

	T& operator*(){
		return *_ptr;
	}

	T* operator->(){
		return _ptr;
	}

private:
	T* _ptr;
};

/*****************************使用实例*******************************/
struct ListNode{
public:
	int _data;
	Weak_ptr<ListNode> _next;
	Weak_ptr<ListNode> _prev;
	~ListNode(){
		cout << "delete ListNode" << endl;
	}
};

void TestSharePtrCycle(){
	Share_ptr<ListNode> cur = new ListNode;//使用弱指针
	Share_ptr<ListNode> next = new ListNode;
	cur->_next = next;//weakptr接收的是sharedptr的对象
	next->_prev = cur;
}
