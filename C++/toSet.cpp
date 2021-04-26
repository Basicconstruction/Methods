/*
 * @Author: your name
 * @Date: 2021-04-23 11:42:41
 * @LastEditTime: 2021-04-26 12:28:49
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \undefinedh:\Desktop\git-Methods\Methods\C++\toSet.cpp
 */
//
// Created by hay boy on 2021/4/23.
//
#include <iostream>
using namespace std;

int localMin(int a, int b){
    if(a < b){
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
void toSet(int* arr, int l){
    //在运行时经常会异常退出，debug时可以正常运行
    bool sign = true;
    int nl = l;
    int* transArr = new int(nl);//nl = l = 6
    transArr[nl - 1] = 0;//transArr[newLength -1] = effectiveLengthOf "transArr"
    for(int i = 0; i < l - 1;i++){
        for(int j = 0;j < transArr[nl - 1]; j++){
            if(arr[i] == transArr[j]){
                sign = false;
            }
        }
        if(sign){
            transArr[transArr[nl - 1]] = arr[i];
            transArr[nl - 1] = transArr[nl -1] + 1;
            sign = true;
        }
    }
    for(int k = 0; k < transArr[nl - 1];k++){
        arr[k] = transArr[k];
    }
    arr[l - 1] =  transArr[nl - 1];//arr列表最后一位放置有效长度，不是有效索引哟
}
void elementsMoveForward(int *arr, int length, int forward = 1){
    //forward >= 1 否则将会无意义
    //注意这是一个未完成的方向
    if(forward < 1){
        return;
    }
    int preIndex;
    int endIndex;
    int trans;
    for(int i = 1; i <= forward;i++){
        preIndex = i - 1;
        endIndex = length - forward + preIndex;
        trans = arr[preIndex];
        arr[preIndex] = arr[endIndex];
        arr[endIndex] = trans;
    }
    for(int j = forward;j<length - forward;){
        /*1 2 3 4 5 6 7
         * 0 1 2 3 4 5 6
         * 5 6 7 4 1 2 3
         * j = 3 j < 4
         * k = 1 k <= min(3,4)=3
         *
         * */
        for(int k = 1; k <= localMin(forward, length - forward - j);k++){
            trans = arr[j - forward + k - 1];
            arr[j - forward + k - 1] = arr[j + k - 1];
            arr[j + k - 1] = trans;
        }
        j = j+forward;
    }
}

void bigRouter(){
    //注意这是一个未完成的方向

}

void localRouter(int *arr, int length, int forward){
    //requires length % forward == 0
    //注意这是一个未完成的方向
    int preIndex;
    int endIndex;
    int trans;
    for(int i = 1; i <= forward;i++){
        preIndex = i - 1;
        endIndex = length - forward + preIndex;
        trans = arr[preIndex];
        arr[preIndex] = arr[endIndex];
        arr[endIndex] = trans;
    }
}

//交换数组局部的 前n位与后n位
void localRouter(int *arr, int preIndex, int endIndex, int forward){
    //注意这是一个未完成的方向
    //requires length % forward == 0
    int trans;
    int localArrLength = endIndex - preIndex + 1;
//    if(localArrLength % forward != 0){
//        throw runtime_error("error resource: localRouter(int *arr, int preIndex, int endIndex, int forward){}");
//    }
    int localPreIndex;
    int localEndIndex;
    for(int i = 1; i <= forward;i++){
        localPreIndex = i - 1;
        localEndIndex = localArrLength - forward + localPreIndex;
        trans = arr[localPreIndex];
        arr[localPreIndex] = arr[localEndIndex];
        arr[localEndIndex] = trans;
    }
}

void elementsMoveOneStep(int *arr, int length, bool pushForward = true){
    //对数组进行整体移位，移位长度为1，pushForward为true时向前移位，否则向后移位
    if(pushForward){
        int first;
        first = arr[0];
        for(int i = 0; i < length - 1; i++){
            arr[i] = arr[i + 1];
        }
        arr[length - 1] = first;
    }else{
        int end;
        end = arr[length - 1];
        for(int i = 0; i < length - 1; i++){
            arr[i+1] = arr[i];
        }
        arr[0] = end;
    }

}

//数组局部  交换数组总cLength = n + x
//         原交换部分长度tLength = n
//比如: 1 2 3 4 5
/*
 * cLength = 5
 * tLength = n = 3
 * x = 2
 * 交换后: 4 5 1 2 3
 * 处理策略: 即时更改 当前交换部分长度
 * 如本次交换  nLength = 2 = cLength - 3
 * 交换 1 2 和  4 5
 * 生成 4 5 3 1 2
 * n当前交换长度 nLength = tLength - nLength = 1
 * 再将数组 向前移动一位即可
 * */
// 0 < x < n
/*
 * length < 2n
 *
 * */
void localUnequalLengthRouter(int *arr, int preIndex, int endIndex ,int transLength){
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
    while(!sign){
        sectionLength = sectionEndIndex - sectionPreIndex + 1;
        for(i = sectionPreIndex;i + nTLength <= sectionEndIndex - nTLength;){
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

void toSet2(int* arr, int l){
    //self tackle
    bool sign = true;
    int effectL = 0;
    arr[l-1] = effectL;
    for(int i = 1; i < l;i++){
        for(int j = 0;j < i; j++){
            if(arr[i] == arr[j]){

            }
        }
    }

}
//1 2 3 4 5 6
//0 1 2 3 4 5
//5 6 3 4 1 2
/**
 j = 2 j < 6
 k = 1 k <= min(2,3) = 2
 3 4 5 6 1 2
j = 4 j < 6
 k = 1 k <=
 */

 void toSetNormal(int *arr, int length, int transLength = 1, bool pushForward = true){
    if(transLength > length / 2){
        for(int i = 0; i < length - transLength; i++){
            elementsMoveOneStep(arr, length, !pushForward);
        }
    }else{
        for(int i = 0; i < transLength; i++){
            elementsMoveOneStep(arr, length, pushForward);
        }
    }
 }
int main(){
    int fg[14] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    int f[14] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
//    localUnequalLengthRouter(fg,0,13,4);
    toSetNormal(fg, 14, 5, true);
    toSetNormal(f,14,9,false);
    printBlankArrayTemplate(fg,14);
    cout<<"\n";
    printBlankArrayTemplate(f,14);
//    int c[6] = {1,2,3,4,5,6};
//    elementsMoveForward(c,6,2);
//    printBlankArrayTemplate(c,6);
//    cout<<"\n";
//    int d[7] = {1,2,3,4,5,6,7};
//    elementsMoveForward(d,7,3);
//    printBlankArrayTemplate(d,7);
//    cout<<"\n";
//    int f[8] = {1,2,3,4,5,6,7,8};
//    localRouter(f,0,5,3);
//    printBlankArrayTemplate(f,8);
//    cout<<"\n";
//    int p[4] = {1,2,3,4};
//    elementsMoveOneStep(p,4);
//    printBlankArrayTemplate(p,4);
//    elementsMoveForward(f,8,2);
//    printBlankArrayTemplate(f,8);
//    int a[6] = {1,2,3,4,1,2};//0 1 2 3 4 5
//    int b[5] = {1,2,3,1,2};// 0 1 2 3 4
//    toSet(a, 6);
//    toSet(b, 5);
//    for(int j = 0;j < a[5]; j++){
//        cout<<a[j]<<" ";
//    }
//    for(int k = 0;k < b[4]; k++){
//        cout<<b[k]<<" ";
//    }
}
