/*
 * @Author: your name
 * @Date: 2021-04-30 19:53:58
 * @LastEditTime: 2021-04-30 20:15:01
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \undefinedh:\Desktop\git-Methods\Methods\C++\SelectionSort.cpp
 */
#include <iostream>
using namespace std;

/**
 * @description: Select sort
 * Worst case running time series: approximately 9 * (n+1)(n-1)/2
 * @param {T} *arr
 * @param {T} length
 * @return {*} void
 * @brief description(Chinese): 选择排序
 * 最坏情况下的运行时间序列：大约（n + 1）（n-1）/ 2   ** 2 * 9
 */
template<typename T>
void SelectSortTemplate(T *arr, int length){
    T trans;
    int x;
    for(int k = 0; k < length - 1; k++){
        trans = arr[k];
        x = k;
        for(int y = k;y<length;y++){
            if(trans > arr[y]){
                trans = arr[y];
                x = y;
            }
        }
        arr[x] = arr[k];
        arr[k] = trans;
    }
}

template <typename T>
void printBlankArrayTemplate(T *arr, int length){
    for(int i = 0; i < length; i++){
        cout<<arr[i]<<" ";
    }
}
int main() {
    int *a = new int[10]{1,3,2,5,1,0,3,2,4,1};
    SelectSort(a,10);
    printBlankArray(a,10);
    return 0;
}
