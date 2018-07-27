/*

替换空字符串

*/

#include<stdio.h>
#include<stack>
#include<iostream>
#pragma warning(disable : 4996)
using namespace std;

void Print(char arr[], int size){
	for (size_t i = 0; i < size; ++i){
		cout << arr[i];
	}
	cout << endl;
}

int main(){
	char str[] = "hello world!\n";
	int count = 0;
	int size = 0;//原字符串大小
	size = strlen(str);
	//遍历字符串，计算有多少个需要替换的空格，并计算出新的字符串大小
	for (size_t i = 0; i < size; ++i){
		if (str[i] == ' ')
			count++;
	}
	Print(str, size);
	int new_size = size + 2 * count;
	//采用前后指针，从后向前遍历，遇见空格就替换
	char* pOld = &str[size - 1];
	char* pNew = &str[new_size - 1];
	while (pOld < pNew){
		if (*pOld == ' '){
			*pNew-- = '0';
			*pNew-- = '2';
			*pNew-- = '%';
			pOld--;
		}
		*pNew-- = *pOld--;

	}
	Print(str, new_size);
	return 0;
}
