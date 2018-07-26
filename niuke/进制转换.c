#include<stdio.h>
#include<iostream>
#pragma warning(disable : 4996)
using namespace std;

int main(){
	int M = 0;
	int N = 0;
	int i = 0;
	int temp = 0;
	scanf("%d %d", &M, &N);
	string buff;
	string out = "0123456789ABCDEF";
	if (N<2 && N>16)
		return 0;

	if (M == 0)
		cout << "0" << endl;
	if (M<0){
		cout << "-";
		M = -M;
	}
	while (M){
		buff += out[M%N];
		M /= N;
	}
	/*itoa(M, buff, N);*/
	cout << buff.c_str() << endl;
	return 0;
}
