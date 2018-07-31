#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int RandomInRange(int arr[], int start, int end){
    //生成随机的三个数，返回大小在中间的那个数
    int num[3];
    int temp = 0;


    for (size_t i = 0; i < 3; ++i){
        while (1){
            temp = rand() % (end + 1);
            if (temp >= start)
                break;
        }
        num[i] = temp;
    }
    if (arr[num[0]]>arr[num[1]]){
        if (arr[num[1]] > arr[num[2]])
            return num[1];
        else
            return num[2];
    }
    else{
        if (arr[num[0]] > arr[num[2]])
            return num[0];
        else
            return num[2];
    }
}

int Partition(int arr[], int len, int start, int end){
    if (arr == NULL || len <= 0 || start < 0 || end >= len)
        throw new exception("Invalid Parameters");
    int key_index = RandomInRange(arr,start, end);
    swap(arr[key_index], arr[end]);
    int small = start - 1;
    for (key_index = start; key_index <= end; ++key_index){
        if (arr[key_index] < arr[end]){
            ++small;
            if (key_index != small)
                swap(arr[key_index], arr[small]);
        }
    }
    ++small;
    swap(arr[small], arr[end]);

    return small;
}

//传入区间是左闭右闭区间
void QuickSort(int arr[], int len, int start, int end){
    if (start == end)
        return;
    int index = Partition(arr, len, start, end);
    if (index>start)
        QuickSort(arr, len, start, index - 1);
    if (index < end)
        QuickSort(arr, len, index + 1, end);

}
void Print(int arr[], int len){
    for (size_t i = 0; i < len; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = { 3, 5, 7, 9, 1, 4, 2, 0, 6, 8/*31, 15, 7, 39, 24, 48, 32, 19, 4, 40, 0, 1, 49, 30, 13, 5, 33, 41, 22, 3, 46, 25, 11, 16, 47, 34, 18, 23, 42, 38, 29, 2, 20, 35, 26, 45, 9, 43, 6, 12, 36, 8, 17, 14, 27, 44, 37, 21, 28*/ };
    int len = sizeof(arr) / sizeof(arr[0]);
    cout << "排序前：" << endl;
    Print(arr, len);
    QuickSort(arr, len, 0, len - 1);
    cout << "排序后：" << endl;
    Print(arr, len);

    cout << endl;
    cout << endl;

    int arr1[] = { 31, 15, 7, 39, 24, 48, 32, 19, 4, 40, 0, 1, 49, 30, 13, 5, 33, 41, 22, 3, 46, 25, 11, 16, 47, 34, 18, 23, 42, 38, 29, 2, 20, 35, 26, 45, 9, 43, 6, 12, 36, 8, 17, 14, 27, 44, 37, 21, 28 };
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "排序前：" << endl;
    Print(arr1, len1);
    QuickSort(arr1, len1, 0, len1 - 1);
    cout << "排序后：" << endl;
    Print(arr1, len1);

    return 0;
}
