//
// Created by hay boy on 2021/4/24.
//
//插入排序，区域插入排序
#include <iostream>
using namespace std;

template<typename T>
void reverseArrayOfRangeTemplate(T *list, int preIndex, int endIndex) {
    T trans;
    for (int i = preIndex; i < (endIndex - preIndex + 1) / 2 + preIndex; i++) {
        trans = list[i];
        list[i] = list[endIndex - i + preIndex];
        list[endIndex - i + preIndex] = trans;
    }
    return;
}

template<typename T>
void reverseArrayTemplate(T *list, int length) {
    T trans;
    for (int i = 0; i < (length - 1) / 2; i++) {
        trans = list[i];
        list[i] = list[length - 1 - i];
        list[length - 1 - i] = trans;
    }
    return;
}

void insertionSort(int* arr, int length, bool ascending = true){
    //插入排序
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
    if(!ascending){
        reverseArrayTemplate(arr, length);
    }
    return;
}

void insertionSortOfRange(int* arr, int preIndex, int endIndex ,bool ascending = true){
    //插入排序
    int key;
    int j;
    for(int i = 0; i <= endIndex; i++){
        key = arr[i];
        j = i -1 ;
        while(j >= preIndex && arr[j] > key){
            arr[j+1] = arr[j];
            j = j - 1 ;
        }
        arr[j+1] = key;
    }
    if(!ascending){
        reverseArrayOfRangeTemplate(arr, preIndex, endIndex);
    }
    return;
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
    insertionSortOfRange(arr, 2, 5);
    printBlankArrayTemplate(arr,11);
    return 0;
}