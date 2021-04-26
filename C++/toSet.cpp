/*
 * @Author: your name
 * @Date: 2021-04-23 11:42:41
 * @LastEditTime: 2021-04-26 18:48:43
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \undefinedh:\Desktop\git-Methods\Methods\C++\toSet.cpp
 */
//
// Created by hay boy on 2021/4/23.
//
#include <iostream>

using namespace std;

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
    int preIndex;
    int endIndex;
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

void toSetNormal(int *arr, int length, int transLength = 1, bool pushForward = true) {
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

int main() {

    int fg[19] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    toSetNormal(fg, 19, 4, true);
    printBlankArrayTemplate(fg, 19);


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