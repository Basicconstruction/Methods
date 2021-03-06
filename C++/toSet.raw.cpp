/*
 * @Author: your name
 * @Date: 2021-04-23 11:42:41
 * @LastEditTime: 2021-04-28 07:03:14
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \undefinedh:\Desktop\git-Methods\Methods\C++\toSet.cpp
 */
//
// Created by hay boy on 2021/4/23.
//
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

int localMin(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

template<typename T>
void printBlankArrayTemplate(T *arr, int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    return;
}

void bigRouter() {
    //注意这是一个未完成的方向

}

void localRouter(int *arr, int length, int forward, bool beGetByOtherFunction = false) {
    //requires length % forward == 0
    //注意这是一个未完成的方向
    if (length % forward != 0 && !beGetByOtherFunction) {
        throw runtime_error("error resource: localRouter(int *arr, int preIndex, int endIndex, int forward){}");
    }
    int localPreIndex;
    int localEndIndex;
    int trans;
    for (int i = 1; i <= forward; i++) {
        localPreIndex = i - 1;
        localEndIndex = length - forward + localPreIndex;
        trans = arr[localPreIndex];
        arr[localPreIndex] = arr[localEndIndex];
        arr[localEndIndex] = trans;
    }
}

//交换数组局部的 前n位与后n位
void localRouterOfRange(int *arr, int preIndex, int endIndex, int forward, bool beGetByOtherFunction = false);

void elementsMoveOneStep(int *arr, int length, bool pushForward = true) {
    //对数组进行整体移位，移位长度为1，pushForward为true时向前移位，否则向后移位
    if (pushForward) {
        int first;
        first = arr[0];
        for (int i = 0; i < length - 1; i++) {
            arr[i] = arr[i + 1];
        }
        arr[length - 1] = first;
    } else {
        int end;
        end = arr[length - 1];
        for (int i = 0; i < length - 1; i++) {
            arr[i + 1] = arr[i];
        }
        arr[0] = end;
    }

}

void elementsMoveOneStep(int *arr, int preIndex, int endIndex, bool pushForward = true) {
    //对数组进行整体移位，移位长度为1，pushForward为true时向前移位，否则向后移位
    if(preIndex == endIndex){
        return;
    }
    if (pushForward) {
        int first;
        first = arr[preIndex];
        for (int i = preIndex; i <= endIndex - 1; i++) {
            arr[i] = arr[i + 1];
        }
        arr[endIndex] = first;
    } else {
        int end;
        //2 3 4 5 6
        //6 2 3 4 5
        end = arr[endIndex];
        for (int i = endIndex; i > preIndex; i--) {
            arr[i] = arr[i - 1];
        }
        arr[preIndex] = end;
    }

}

void elementsMoveForward(int *arr, int length, int forward = 1, bool pushForward = true) {
    //forward >= 1 否则将会无意义
    if (forward < 1) {
        return;
    }
    int trans;
    localRouter(arr, length, forward, true);
    //debug
//    printBlankArrayTemplate(arr, length);
//    cout<<"\n";
    for (int j = forward; j < length - forward;) {
        if (length - forward - j >= forward) {
            for (int k = 1; k <= forward; k++) {
                trans = arr[j - forward + k - 1];
                arr[j - forward + k - 1] = arr[j + k - 1];
                arr[j + k - 1] = trans;
            }
            j = j + forward;
            //debug
//            cout<<"$j"<<j<<"\n";
//            printBlankArrayTemplate(arr, length);
//            cout<<"\n";
        } else {
            int nl = length - forward - j;
            for (int i = 0; i < nl; i++) {
                elementsMoveOneStep(arr, j - forward, length - forward - 1, !pushForward);
            }
            j = j + 4;
            //debug
//            printBlankArrayTemplate(arr, length);
//            cout<<"\n";
        }

    }
}

void localUnequalLengthRouter(int *arr, int preIndex, int endIndex, int transLength);

void elementsMoveForwardNormal(int *arr, int length, int transLength = 1, bool pushForward = true) {
    if (length / transLength == 2) {
        localRouter(arr, length, transLength);
        return;
    }
    if(transLength >= 2 && length / transLength >= 3){
        elementsMoveForward(arr, length, transLength, true);
        return;
    }
    if (transLength > length / 2) {
        for (int i = 0; i < length - transLength; i++) {
            elementsMoveOneStep(arr, length, !pushForward);
        }
    } else {
        for (int i = 0; i < transLength; i++) {
            elementsMoveOneStep(arr, length, pushForward);
        }
    }
}

void toSet(int *arr, int l);

//1 2 3 1 2 1 5 6 7 8
/*i l-2
//1 2 3 2 1 5 6 7 8 1
//1 2 3 1 5 6 7 8 1 2 
//1 2 3 5 6 7 8 1 2 1
*/
void toSetLowSystemVersion(int *arr, int length, bool needSort = false, bool ascending = true){
    int M = 0;//M 有效存储位,因为p = 0时，第一轮for循环不会被执行
    int Mv = 0;
    bool sign = true;
    for(int p = 0; p <= length - Mv - 2; p++){
//        printBlankArrayTemplate(arr, length);
//        cout<<" "<<p<<"  ";
        if(p==0){
            sign = true;
        }
        for(int k = 0; k < M && sign; k++){
            if(arr[k] == arr[p]){
                elementsMoveOneStep(arr,p,length - 2,true);
                sign = false;
            }
        }
        if(sign){
            M = M + 1;
        }else{
            p = M - 1;
            Mv = Mv + 1;
        }
//        cout<<"@M: "<<M<<" "<<p<<"  ";
//        cout<<" #sign "<<sign<<"   ";
//        printBlankArrayTemplate(arr, length);
//        cout<<"\n";
        sign = true;

    }
    arr[length-1] = M;
    cout<<"$M"<<M<<"   ";
    if(needSort){
        insertionSortOfRangeTemplate(arr,0,M-1,ascending);
    }
//    cout<<Mv;
//    cout<<"\n";
}

int main() {

    // int fg[19] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    // elementsMoveForwardNormal(fg, 19, 4, true);
    // printBlankArrayTemplate(fg, 19);
    int arr[] = {1, 2, 3, 1, 2, 1, 5, 6, 7, 8, 0, 8, 9, 0};
    toSetLowSystemVersion(arr, 14, true, false);
    printBlankArrayTemplate(arr,14);


}


/**
 * @description:
 * Receive an array and its length. This array is generally one more than the length of the array to be processed.
 * After the processing of the modified function, the last bit of the array will store the effective independent bit in the array. There is no doubt that this number is greater than or equal to 1.
 * And the length of the first valid independent bit of the array will be used to store the independent bit.
 * @param {int} preWorkLength
 * @return {*}
 * @brief description(中文):
 * 接收一个数组，以及它的长度。这个数组一般要比要处理的数组长度多1。
 * 经过改函数的处理，该数组的最后一位将会存储该数组中有效独立位，毫无疑问这个数字大于等于1
 * 并且该数组的前有效独立位长度将会用来存储独立位。
 */
void toSet(int *arr, int l) {
    //借助动态数组实现，运行时会出现异常
    bool sign = true;
    int nl = l;
    int *transArr = new int(nl);//nl = l = 6
    transArr[nl - 1] = 0;//transArr[newLength -1] = effectiveLengthOf "transArr"
    for (int i = 0; i < l - 1; i++) {
        for (int j = 0; j < transArr[nl - 1]; j++) {
            if (arr[i] == transArr[j]) {
                sign = false;
            }
        }
        if (sign) {
            transArr[transArr[nl - 1]] = arr[i];
            transArr[nl - 1] = transArr[nl - 1] + 1;
            sign = true;
        }
    }
    for (int k = 0; k < transArr[nl - 1]; k++) {
        arr[k] = transArr[k];
    }
    arr[l - 1] = transArr[nl - 1];//arr列表最后一位放置有效长度，不是有效索引哟
}

void localRouterOfRange(int *arr, int preIndex, int endIndex, int forward, bool beGetByOtherFunction) {
//requires length % forward == 0
//注意这是一个未完成的方向
    int trans;
    int localArrLength = endIndex - preIndex + 1;
    if (localArrLength % forward != 0 && beGetByOtherFunction) {
        throw runtime_error("error resource: localRouter(int *arr, int preIndex, int endIndex, int forward){}");
    }
    int localPreIndex;
    int localEndIndex;
    for (int i = 1; i <= forward; i++) {
        localPreIndex = preIndex + i - 1;
        localEndIndex = localArrLength - forward + localPreIndex;
        trans = arr[localPreIndex];
        arr[localPreIndex] = arr[localEndIndex];
        arr[localEndIndex] = trans;
    }
}
void localUnequalLengthRouter(int *arr, int preIndex, int endIndex, int transLength) {
    //
    int cLength = endIndex - preIndex + 1;//交换数组总长度
    int sectionLength = cLength;//现在交换数组总长度
    int tLength = transLength;// 原成组长度   仅为简化
    int nTLength = transLength;            //现成组长度
    int sectionPreIndex = preIndex;
    int sectionEndIndex = endIndex;
    int localPreIndex;
    int localEndIndex;
    bool sign = false;
    int i;
    while (!sign) {
        sectionLength = sectionEndIndex - sectionPreIndex + 1;
        for (i = sectionPreIndex; i + nTLength <= sectionEndIndex - nTLength;) {
            localPreIndex = i;
            localEndIndex = sectionEndIndex;
            localRouter(arr, localPreIndex, localEndIndex, nTLength);
            i = i + nTLength;
        }
        sectionPreIndex = sectionEndIndex + 1;
        sectionEndIndex = sectionPreIndex + (sectionLength % nTLength) - 1;
        sign = true;
    }
}