#include <iostream>

using namespace std;

/**
 * @description: Array inversion function
 *  The function receives the array (list) and the length of the array as parameters, and inverts the sequence of array elements. 
 * It is often used in conjunction with the sort function to use the function for inverted sorting.
 * @param {T} *list
 * @param {T} length
 * @return {*}  void
 * @brief description(中文): 数组倒置函数
 * 函数接收数组（列表）以及数组长度作为参数，倒置数组元素的序列，
 * 常结合排序函数使用用于倒置排序后的函数。
 */
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
 * @description: Array local inversion function
 * The function accepts array array index 1 and array index 2 as parameters, 
 * and inverts the sequence of elements from array index 1 to array index 2 
 * and is often used in conjunction with the sort function
 * @param {T} *list
 * @param {T} preIndex
 * @param {T} endIndex
 * @return {*}
 * @brief description(中文): 数组局部导致函数
 * 函数接收数组 数组索引1 数组索引2作为参数，倒置数组自数组索引1到数组索引2的元素的序列
 * 常结合排序函数使用
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
 * @description: Bubble Sort
 * This function receives the array length, whether ascending order as a parameter, 
 * if the ascending order parameter is true, the array will be sorted from small to large; 
 * if the ascending parameter is false, the array will be sorted from large to small
 * @param {T} *list
 * @param {T} length
 * @param {bool} ascending
 * @return {*}
 * @brief description(中文)
 * 该函数接收数组 数组长度 是否升序 作为参数，如果是否升序参数为true，则将对数组进行从小到大的排序
 * 如果是否升序参数为false，则将对数组进行从大到小的排序
 */
template<typename T>
void bubbleSortTemplate(T *list, int length, bool ascending = true) {
    T trans;
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

/**
 * @description: Upgraded bubble sort
 * This function receives the array length, whether ascending order as a parameter, 
 * if the ascending order parameter is true, the array will be sorted from small to large; 
 * if the ascending parameter is false, the array will be sorted from large to small
 * @param {T} *list
 * @param {T} length
 * @param {bool} ascending
 * @return {*}
 * @brief description(中文): 升级版冒泡排序
 * 该函数接收数组 数组长度 是否升序 作为参数，如果是否升序参数为true，则将对数组进行从小到大的排序
 * 如果是否升序参数为false，则将对数组进行从大到小的排序
 */
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

/**
 * @description: Local bubble sort function
 * This function receives the array length, whether ascending order as a parameter, 
 * if the ascending order parameter is true, the array will be sorted from small to large; 
 * if the ascending parameter is false, the array will be sorted from large to small
 * @param {T} *list
 * @param {T} preIndex
 * @param {T} endIndex
 * @param {bool} ascending
 * @return {*}
 * @brief description(中文): 局部冒泡函数
 * 该函数接收数组 数组索引1 数组索引2 是否升序 作为参数，如果是否升序参数为true，则将对数组从索引1到索引2进行从小到大的排序
 * 如果是否升序参数为false，则将对数组从索引1到索引2进行从大到小的排序
 */
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

/**
 * @description: Print array
 * @param {T} *arr
 * @param {T} length
 * @return {*}
 * @brief description(中文): 打印数组
 */
template<typename T>
void printArrayTemplate(T *arr, int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i];
    }
    return;
}

/**
 * @description: Print the array to separate each element with a newline
 * @param {T} *arr
 * @param {T} length
 * @return {*}
 * @brief description(中文): 打印数组以换行隔开每个元素
 */
template<typename T>
void printlnArrayTemplate(T *arr, int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << "\n";
    }
    return;
}

/**
 * @description: Print the array with a space to separate each element
 * @param {T} *arr
 * @param {T} length
 * @return {*}
 * @brief description(中文): 打印数组以空格隔开每个元素
 */
template<typename T>
void printBlankArrayTemplate(T *arr, int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    return;
}

/**
 * @description: Print the array part with a space to separate each element
 * @param {T} *arr
 * @param {T} length
 * @return {*}
 * @brief description(中文): 打印数组局部以空格隔开每个元素
 */
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