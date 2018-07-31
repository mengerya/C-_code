#include<stdio.h>
#include<iostream>
using namespace std;

int Min(int arr[], int len){
    if (NULL == arr || len <= 0){
        throw new exception("Invalid parameters");
    }
    int first = 0;
    int last = len - 1;
    int mid = 0;
    while (arr[first] >= arr[last]){
        if (last - first == 1){
            //此时两个标记相邻，说明最小的元素就是两个相邻元素靠后的那一个
            mid = last;
            break;
        }
        mid = (first + last) / 2;
        if (arr[mid] >= arr[first])
            first=mid;
        if (arr[mid] <= arr[last])
            last = mid;
    }
    return arr[mid];
}

void Print(int arr[], int len){
    for (size_t i = 0; i < len; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = { 8, 9, 1, 2, 3, 4, 5, 6, 7 };

    int len = sizeof(arr) / sizeof(arr[0]);
    Print(arr, len);
    int ret = Min(arr, len);
    cout << "该数组最小的元素为：" << ret << endl;
}
