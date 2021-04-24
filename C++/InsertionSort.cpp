//
// Created by hay boy on 2021/4/24.
//
//编写插入排序时某些逻辑总是很容易向冒泡排序倾斜，尽管没有查阅资料，感觉插入排序比冒泡排序效果更好
#include <iostream>
using namespace std;
void insertionSort(int* arr, int length){
    int key;
    int j;
    for(int i = 0; i < length; i++){
        key = arr[i];
        j = i -1 ;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j - 1 ;
        }
        arr[j+1] = key;
    }
}
template <typename T>
void insertionSortTemplate(T* arr, int length){
    T key;
    int j;
    for(int i = 0; i < length; i++){
        key = arr[i];
        j = i -1 ;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j - 1 ;
        }
        arr[j+1] = key;
    }
}
template <typename T>
void printBlankArrayTemplate(T* arr, int Length){
    for(int i = 0; i < Length; i++){
        cout<<arr[i]<<" ";
    }
    return;
}
int main(){
    int arr[11]{5,2,4,6,1,3,9,7,8,11,10};
    insertionSort(arr, 11);
    printBlankArrayTemplate(arr,11);
    return 0;
}