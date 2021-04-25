//
// Created by hay boy on 2021/4/23.
//
#include <iostream>
using namespace std;

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
void toSet(int* arr, int preWorkLength){
    bool sign = true;
    int newLength = preWorkLength;
    int* transArr = new int(newLength);
    transArr[newLength - 1] = 0;//transArr[newLength -1] = effectiveLengthOf "transArr"
    for(int i = 0; i < preWorkLength - 1;i++){
        for(int j = 0;j < transArr[newLength - 1]; j++){
            if(arr[i] == transArr[j]){
                sign = false;
            }
        }
        if(sign){
            transArr[transArr[newLength - 1]] = arr[i];
            transArr[newLength - 1] += 1;
            sign = true;
        }
    }
    for(int k = 0; k < transArr[newLength - 1];k++){
        arr[k] = transArr[k];
    }
    arr[preWorkLength - 1] =  transArr[newLength - 1];//arr列表最后一位放置有效长度，不是有效索引哟
    delete transArr;
    /*
     * README.txt
     * 本函数的作用:
     * 传入一个数组，以及它的长度，获取它的独特值，并且最后一个元素将会用来存储有效长度
     * 传入函数要求：声明时，把要传入函数的数组长度多声明一个长度，以避免原数组中没有相同元素时，存储元素和存储长度的冲突
     * ￥尽管这样会造成额外的麻烦，但是我们还是觉得这并不是一件难事
     * 改变函数特点，尽管我们传入的数组相比于原来应该长度多了一个一个长度，但是我们还是省略了将无效区段的数组元素改为其他值。
     * 尽管此函数有一定的作用，但是我们还是觉得你需要谨慎使用，尤其是需要先弄懂或会自制此或此类函数。
     * */
}
int main(){
    const int m = 6;
    const int n = 5;
    int *a = new int(m+1);
    int *b = new int(n+1);
    for(int i = 0; i < m; i++){
        cin>>a[m];
    }
    for(int i = 0; i < n; i++){
        cin>>b[n];
    }
    toSet(a, m+1);
    toSet(b, n+1);
    for(int i = 0;i < a[m-1]; i++){
        cout<<a[i]<<" ";
    }
    for(int i = 0;i < b[n-1]; i++){
        cout<<a[i]<<" ";
    }
}
