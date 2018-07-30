#include<stdio.h>
#include<iostream>
#pragma warning(disable : 4996)
using namespace std;

int main(){
	int n = 0;
	int count = 0;
	int flag = 0;
	scanf("%d", &n);
	if (n<0)
		n = n*(-1);
	if (n == 0){
		cout << 1 << endl;
		return 0;
	}
	if (n < 5 && n>0){
		cout << 0 << endl;
		return 0;
	}
	for (size_t i = 5; i <= n; i += 5){
		flag = 0;
		for (size_t j = i; j >= 5; j /= 5){
			if (j % 5 == 0)
				++flag;
		}
		count += flag;
	}
	cout << count << endl;
	return 0;
}
