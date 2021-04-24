#include <iostream>

using namespace std;

void reverseArray(int *list, int length) {
    int trans;
    for (int i = 0; i < (length - 1) / 2; i++) {
        trans = list[i];
        list[i] = list[length - 1 - i];
        list[length - 1 - i] = trans;
    }
    return;
}

void reverseArrayOfRange(int *list, int preIndex, int endIndex) {
    int trans;//1 2 3 4 5 6
              //0 1 2 3 4 5
    for (int i = preIndex; i < (endIndex - preIndex + 1) / 2 + preIndex; i++) {
        trans = list[i];
        list[i] = list[endIndex - i + preIndex];
        list[endIndex - i + preIndex] = trans;
    }
    return;
}

void bubbleSort(int *list, int length, bool ascending = true) {
    int trans;
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - 1 - i; j++) {
            if (list[j] > list[j + 1]) {
                trans = list[j];
                list[j] = list[j + 1];
                list[j + 1] = trans;
            }
        }
    }
    if (ascending) {
        return;
    } else {
        reverseArray(list, length);
    }
}

void enhancedBubbleSort(int *list, int length, bool ascending = true) {
    //优化版冒泡排序，相比最初版的冒泡排序有一定提升
    int trans;
    bool sign = true;
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - 1 - i; j++) {
            if (list[j] > list[j + 1]) {
                trans = list[j];
                list[j] = list[j + 1];
                list[j + 1] = trans;
                sign = false;
            }
        }
        if (sign && ascending) {
            //cout<<"Over";   //debug-print
            return;
        }
    }
    if (!ascending) {
        reverseArray(list, length);
    }
    return;

}

void enhancedBubbleSortOfRange(int *list, int preIndex, int endIndex, bool ascending = true) {
    //区域冒泡排序。
    //目前该函数并未实现，数组越界检测，需要调用者注意，谨慎使用
    //参数 数组 需要排序序列的初始索引  需要排序序列的结束索引
    //默认：实现优化版冒泡排序--加入一个额外的判断
    //默认：<= 来遍历，尤其适合约束索引
    int trans;
    bool sign = true;
    int k = 0;
    for (int i = preIndex; i <= endIndex - 1; i++) {
        for (int j = preIndex; j <= endIndex - k - 1; j++) {
            if (list[j] > list[j + 1]) {
                trans = list[j];
                list[j] = list[j + 1];
                list[j + 1] = trans;
                sign = false;
            }
        }
        k++;
        if (sign&&ascending) {
            //cout<<"Over";   //debug-print
            return;
        }
    }
    if(!ascending){
        reverseArrayOfRange(list, preIndex, endIndex);
    }
    return;
}

void printArray(int *arr, int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i];
    }
    return;
}

void printlnArray(int *arr, int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << "\n";
    }
    return;
}

void printBlankArray(int *arr, int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    return;
}

void printBlankArrayOfRange(int *arr, int preIndex, int endIndex){
    for (int i = preIndex; i <= endIndex; i++) {
        cout << arr[i] << " ";
    }
    return;
}

int main() {
    int a[6] = {1,2,3,4,5,6};
    printlnBlankArrayOfRange(a,2,5);
}