/*
 * @Author: your name
 * @Date: 2021-04-28 07:29:44
 * @LastEditTime: 2021-04-28 08:30:16
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \undefinedh:\Desktop\git-Methods\Methods\C++\toSetTemplate.cpp
 */

#include <iostream>
using namespace std;

/**
 * @description: 
 * The parameter is list list index 1 list index 2
 * Processing: Reverse the elements of the list from list index 1 to list index 2
 * Dependent function: None
 * @param {T} *list
 * @param {int} preIndex
 * @param {int} endIndex
 * @return {*} void
 * @brief description(Chinese): 局部列表反转函数
 * 参数为 模板列表 列表索引1:int 列表索引2:int
 * 依赖函数: None
 * 处理：反转列表的 自列表索引1 到 列表索引2 的元素
 */
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

/**
 * @description: Partial insertion sort function
 * This function receives the array length, whether ascending order as a parameter, 
 * if the ascending order parameter is true, the array will be sorted from small to large; 
 * if the ascending parameter is false, the array will be sorted from large to small
 * Dependent function: reverseArrayTemplate(T *list, int length):void
 * @param {int} *list
 * @param {int} preIndex
 * @param {int} endIndex
 * @param {bool} ascending
 * @return {*}
 * @brief description(中文): 局部插入排序函数
 * 参数: int列表 列表索引1:int 列表索引2:int 是否升序:bool，
 * 依赖函数: reverseArrayTemplate(T *list, int length):void
 * 处理:如果是否升序参数为true，则将对列表从索引1到索引2进行从小到大的排序
 * 如果是否升序参数为false，则将对列表从索引1到索引2进行从大到小的排序
 */
template<typename T>
void insertionSortOfRangeTemplate(T* arr, int preIndex, int endIndex, bool ascending = true){
    //插入排序
    T key;
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

/**
 * @description: 
 * Processing: output each element of the list, and append a space after each element
 * @param {int} Length
 * @return {*}
 * @brief description(Chinese): 遍历列表输出函数
 * 参数: 模板列表 列表长度:int
 * 依赖函数: None
 * 处理: 输出列表的每一个元素, 并在每一个元素后面追加一个空格
 */
template<typename T>
void printBlankArrayTemplate(T *arr, int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    return;
}

/**
 * @description: 
 * Processing: Shift the list part as a whole, the shift length is 1, shift forward when pushForward is true, otherwise shift backward
 * Dependent function: None
 * @param {int} *arr
 * @param {int} preIndex
 * @param {int} endIndex
 * @param {bool} pushForward
 * @return {*}
 * 依赖函数: None
 * @brief description(Chinese): 首尾相连移位函数
 * 处理: 对 列表局部 进行整体移位，移位长度为1，pushForward为true时向前移位，否则向后移位
 */
template<typename T>
void elementsMoveOneStepTemplate(T *arr, int preIndex, int endIndex, bool pushForward = true) {
    if(preIndex == endIndex){
        return;
    }
    if (pushForward) {
        T first;
        first = arr[preIndex];
        for (int i = preIndex; i <= endIndex - 1; i++) {
            arr[i] = arr[i + 1];
        }
        arr[endIndex] = first;
    } else {
        T end;
        //2 3 4 5 6
        //6 2 3 4 5
        end = arr[endIndex];
        for (int i = endIndex; i > preIndex; i--) {
            arr[i] = arr[i - 1];
        }
        arr[preIndex] = end;
    }

}

/**
 * @description: 
 * Dependent function: None
 * warning: If the function is called, the check will be ignored by default
 * @param {int} *arr
 * @param {int} length
 * @param {int} forward
 * @param {bool} beGetByOtherFunction
 * @return {*}
 * 依赖函数: None
 * @brief description(Chinese): 列表前n位与后n位交换的函数
 * 处理:交换列表的前n位与后n位
 * warning: 如果该函数被调用时会默认忽略检查
 */
template<typename T>
void localRouterTemplate(T *arr, int length, int forward, bool beGetByOtherFunction = false) {
    //requires length % forward == 0
    if (length % forward != 0 && !beGetByOtherFunction) {
        throw runtime_error("error resource: localRouter(int *arr, int preIndex, int endIndex, int forward){}");
    }
    int localPreIndex;
    int localEndIndex;
    T trans;
    for (int i = 1; i <= forward; i++) {
        localPreIndex = i - 1;
        localEndIndex = length - forward + localPreIndex;
        trans = arr[localPreIndex];
        arr[localPreIndex] = arr[localEndIndex];
        arr[localEndIndex] = trans;
    }
}

/**
 * @description: Processing: swap the first n bits and the last n bits of the list, if pushForward is true, move forward, otherwise, move backward
 * Dependent function: elementsMoveOneStep(int *arr, int preIndex, int endIndex, bool pushForward = true)
 * @param {int} *arr
 * @param {int} length
 * @param {int} forward
 * @param {bool} pushForward
 * @return {*}
 * 依赖函数: elementsMoveOneStepTemplate(int *arr, int preIndex, int endIndex, bool pushForward = true)
 * @brief description(Chinese): 处理移n位情况函数(待进一步提高效率)
 * 处理:交换列表的前n位与后n位， 如果pushForward为true，向前移动，否则，向后移动
 */
template<typename T>
void elementsMoveForwardTemplate(T *arr, int length, int forward = 1, bool pushForward = true) {
    if (forward < 1) {
        return;
    }
    T trans;
    localRouter(arr, length, forward, true);
    for (int j = forward; j < length - forward;) {
        if (length - forward - j >= forward) {
            for (int k = 1; k <= forward; k++) {
                trans = arr[j - forward + k - 1];
                arr[j - forward + k - 1] = arr[j + k - 1];
                arr[j + k - 1] = trans;
            }
            j = j + forward;
        } else {
            int nl = length - forward - j;
            for (int i = 0; i < nl; i++) {
                elementsMoveOneStepTemplate(arr, j - forward, length - forward - 1, !pushForward);
            }
            j = j + 4;
        }

    }
}

/**
 * @description: Processing: swap the first n bits and the last n bits of the list, if pushForward is true, move forward, otherwise, move backward
 * Dependent function:elementsMoveOneStep(int *arr, int preIndex, int endIndex, bool pushForward = true):void
 *      elementsMoveForward(int *arr, int length, int forward = 1, bool pushForward = true):void
 *      localRouter(int *arr, int length, int forward, bool beGetByOtherFunction = false):void
 * @param {int} *arr
 * @param {int} length
 * @param {int} transLength
 * @param {bool} pushForward
 * @return {*}
 * @brief description(Chinese): 处理移n位情况函数(多种方法复合)
 * 依赖函数: elementsMoveOneStepTemplate(int *arr, int preIndex, int endIndex, bool pushForward = true):void
 *      elementsMoveForwardTemplate(int *arr, int length, int forward = 1, bool pushForward = true):void
 *      localRouterTemplate(int *arr, int length, int forward, bool beGetByOtherFunction = false):void
 * 处理:交换列表的前n位与后n位， 如果pushForward为true，向前移动，否则，向后移动
 */
template<typename T>
void elementsMoveForwardNormalTemplate(int *arr, int length, int transLength = 1, bool pushForward = true) {
    if (length / transLength == 2) {
        localRouterTemplate(arr, length, transLength);
        return;
    }
    if(transLength >= 2 && length / transLength >= 3){
        elementsMoveForwardTemplate(arr, length, transLength, true);
        return;
    }
    if (transLength > length / 2) {
        for (int i = 0; i < length - transLength; i++) {
            elementsMoveOneStepTemplate(arr, length, !pushForward);
        }
    } else {
        for (int i = 0; i < transLength; i++) {
            elementsMoveOneStepTemplate(arr, length, pushForward);
        }
    }
}

/**
 * @description: 
 * Processing: traverse the list, if it appears multiple times, move it to the end, and store the number of independent elements in the last digit of the list
 * Dependent function:insertionSortOfRangeTemplate(T* arr, int preIndex, int endIndex, bool ascending = true):void
 *      elementsMoveOneStep(int *arr, int preIndex, int endIndex, bool pushForward = true):void
 * @warning The incoming list is one more than the length of the topic
 * @param {int} *arr
 * @param {int} length
 * @param {bool} needSort
 * @param {bool} ascending
 * @return {*}
 * @brief description(Chinese): 复合函数，见处理
 * 依赖函数: insertionSortOfRangeTemplate(T* arr, int preIndex, int endIndex, bool ascending = true):void
 *      elementsMoveOneStepTemplate(int *arr, int preIndex, int endIndex, bool pushForward = true):void
 * 处理: 对列表进行遍历，如果出现多次，就将它移到最后，并在列表最后一位存储独立元素的个数
 * @warning 传入的列表要比 题目 长度多一
 */
template<typename T>
void toSetLowSystemVersionTemplate(T *arr, int length, bool needSort = false, bool ascending = true){
    int M = 0;
    int Mv = 0;
    bool sign = true;
    for(int p = 0; p <= length - Mv - 2; p++){
        for(int k = 0; k < M && sign; k++){
            if(arr[k] == arr[p]){
                elementsMoveOneStepTemplate(arr,p,length - 2,true);
                sign = false;
            }
        }
        if(sign){
            M = M + 1;
        }else{
            p = M - 1;
            Mv = Mv + 1;
        }
        sign = true;

    }
    arr[length-1] = M;
    if(needSort){
        insertionSortOfRangeTemplate(arr,0,M-1,ascending);
    }
}
int main() {
    //--Debugger
    int arr[] = {1, 2, 3, 1, 2, 1, 5, 6, 7, 8, 0, 8, 9, 0};
    toSetLowSystemVersionTemplate(arr, 14, true, false);
    printBlankArrayTemplate(arr,14);


}

