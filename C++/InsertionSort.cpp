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

/**
 * @description: Insertion sort
 * This function receives the array length, whether ascending order as a parameter, 
 * if the ascending order parameter is true, the array will be sorted from small to large; 
 * if the ascending parameter is false, the array will be sorted from large to small
 * @param {T} *list
 * @param {T} length
 * @param {bool} ascending
 * @return {*}
 * @brief description(中文): 插入排序
 * 该函数接收数组 数组长度 是否升序 作为参数，如果是否升序参数为true，则将对数组进行从小到大的排序
 * 如果是否升序参数为false，则将对数组进行从大到小的排序
 */
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

/**
 * @description: Partial insertion sort function
 * This function receives the array length, whether ascending order as a parameter, 
 * if the ascending order parameter is true, the array will be sorted from small to large; 
 * if the ascending parameter is false, the array will be sorted from large to small
 * @param {int} *list
 * @param {int} preIndex
 * @param {int} endIndex
 * @param {bool} ascending
 * @return {*}
 * @brief description(中文): 局部插入排序函数
 * 该函数接收数组 数组索引1 数组索引2 是否升序 作为参数，如果是否升序参数为true，则将对数组从索引1到索引2进行从小到大的排序
 * 如果是否升序参数为false，则将对数组从索引1到索引2进行从大到小的排序
 */
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