#include<stdio.h>
#include<vector>
#include<iostream>
#pragma warning(disable : 4996)
using namespace std;
#define MAX 1024

int  main(){
	int n = 0, sum = 0;
	vector<long long> A(sum + 1);
	vector<int> B(n);
	cin >> n;
	cin >> sum;
	for (size_t i = 0; i < n; ++i){
		cin >> B[i];
	}
	A[0] = 1;
	for (int i = 0; i<n; i++)
	for (int j = sum; j >= B[i]; j--)
		A[j] += A[j - B[i]];
	cout << A[sum] << endl;
	return 0;
}
