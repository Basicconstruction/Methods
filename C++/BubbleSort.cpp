#include <iostream>

using namespace std;

/**
 * @description: Array inversion function
 *  The function receives the array (list) and the length of the array as parameters, and inverts the sequence of array elements. 
 * It is often used in conjunction with the sort function to use the function for inverted sorting.
 * @param {int} *list
 * @param {int} length
 * @return {*}  void
 * @brief description(中文): 数组倒置函数
 * 函数接收数组（列表）以及数组长度作为参数，倒置数组元素的序列，
 * 常结合排序函数使用用于倒置排序后的函数。
 */
void reverseArray(int *list, int length) {
    int trans;
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
 * @param {int} *list
 * @param {int} preIndex
 * @param {int} endIndex
 * @return {*}
 * @brief description(中文): 数组局部导致函数
 * 函数接收数组 数组索引1 数组索引2作为参数，倒置数组自数组索引1到数组索引2的元素的序列
 * 常结合排序函数使用
 */
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

/**
 * @description: Bubble Sort
 * This function receives the array length, whether ascending order as a parameter, 
 * if the ascending order parameter is true, the array will be sorted from small to large; 
 * if the ascending parameter is false, the array will be sorted from large to small
 * @param {int} *list
 * @param {int} length
 * @param {bool} ascending
 * @return {*}
 * @brief description(中文): 冒泡排序
 * 该函数接收数组 数组长度 是否升序 作为参数，如果是否升序参数为true，则将对数组进行从小到大的排序
 * 如果是否升序参数为false，则将对数组进行从大到小的排序
 */
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

/**
 * @description: Upgraded bubble sort
 * This function receives the array length, whether ascending order as a parameter, 
 * if the ascending order parameter is true, the array will be sorted from small to large; 
 * if the ascending parameter is false, the array will be sorted from large to small
 * @param {int} *list
 * @param {int} length
 * @param {bool} ascending
 * @return {*}
 * @brief description(中文): 升级版冒泡排序
 * 该函数接收数组 数组长度 是否升序 作为参数，如果是否升序参数为true，则将对数组进行从小到大的排序
 * 如果是否升序参数为false，则将对数组进行从大到小的排序
 */
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

/**
 * @description: Local bubble sort function
 * This function receives the array length, whether ascending order as a parameter, 
 * if the ascending order parameter is true, the array will be sorted from small to large; 
 * if the ascending parameter is false, the array will be sorted from large to small
 * @param {int} *list
 * @param {int} preIndex
 * @param {int} endIndex
 * @param {bool} ascending
 * @return {*}
 * @brief description(中文): 局部冒泡函数
 * 该函数接收数组 数组索引1 数组索引2 是否升序 作为参数，如果是否升序参数为true，则将对数组从索引1到索引2进行从小到大的排序
 * 如果是否升序参数为false，则将对数组从索引1到索引2进行从大到小的排序
 */
void enhancedBubbleSortOfRange(int *list, int preIndex, int endIndex, bool ascending = true) {
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

/**
 * @description: Print array
 * @param {int} *arr
 * @param {int} length
 * @return {*}
 * @brief description(中文): 打印数组
 */
void printArray(int *arr, int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i];
    }
    return;
}

/**
 * @description: Print the array to separate each element with a newline
 * @param {int} *arr
 * @param {int} length
 * @return {*}
 * @brief description(中文): 打印数组以换行隔开每个元素
 */
void printlnArray(int *arr, int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << "\n";
    }
    return;
}

/**
 * @description: Print the array with a space to separate each element
 * @param {int} *arr
 * @param {int} length
 * @return {*}
 * @brief description(中文): 打印数组以空格隔开每个元素
 */
void printBlankArray(int *arr, int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    return;
}

/**
 * @description: Print the array part with a space to separate each element
 * @param {int} *arr
 * @param {int} length
 * @return {*}
 * @brief description(中文): 打印数组局部以空格隔开每个元素
 */
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