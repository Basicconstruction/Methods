#include <iostream>

using namespace std;

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
void enhancedBubbleSortTemplate(T *list, int length, bool ascending = true) {
    //模板-优化版冒泡排序
    T trans;
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
        reverseArrayTemplate(list, length);
    }
    return;
}

template<typename T>
void enhancedBubbleSortOfRangeTemplate(T *list, int preIndex, int endIndex, bool ascending = true) {
    T trans;
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
        reverseArrayOfRangeTemplate(list, preIndex, endIndex);
    }
    return;
}

template<typename T>
void printArrayTemplate(T *arr, int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i];
    }
    return;
}

template<typename T>
void printlnArrayTemplate(T *arr, int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << "\n";
    }
    return;
}

template<typename T>
void printBlankArrayTemplate(T *arr, int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    return;
}

template<typename T>
void printBlankArrayOfRange(T *arr, int preIndex, int endIndex){
    for (int i = preIndex; i <= endIndex; i++) {
        cout << arr[i] << " ";
    }
    return;
}

int main() {
    cout << "\n";
    double a[10] = {1, 2, 3, 5.1, 1, 1, 5, 6.4, 8, 0.0};
    enhancedBubbleSortTemplate(a, 10, false);
    printBlankArrayTemplate(a, 10);
    cout << "\n";
    int b[6] = {1, 3, 1, 2, 4, 2};
    enhancedBubbleSortOfRangeTemplate(b, 2, 5, false);
    printBlankArrayTemplate(b, 6);
}