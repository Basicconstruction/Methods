//
// Created by hay boy on 2021/4/23.
//
/*冒泡排序 以及遍历数组输出的函数*/
#include <iostream>
using namespace std;
void bubbleSort1(int* list, int Length){
        int trans;
        int aSize = Length;
        for(int i = 0; i< Length - 1; i++){
           for(int j = 0; j < Length - 1 - i;j++){
                if(list[j] > list[j+1]){
                    trans = list[j];
                    list[j] = list[j+1];
                    list[j + 1] = trans;
                }
            }
        }
}
void enhancedBubbleSort1(int* list, int Length){
    //优化版冒泡排序，相比最初版的冒泡排序有一定提升
        int trans;
        int aSize = Length;
        bool sign = true;
        for(int i = 0; i< Length - 1; i++){
           for(int j = 0; j < Length - 1 - i;j++){
                if(list[j] > list[j+1]){
                    trans = list[j];
                    list[j] = list[j+1];
                    list[j + 1] = trans;
                    sign = false;
                }
            }
            if(sign){
                //cout<<"Over";   //debug-print
                return;
            }
        }
}
template<typename T>
void enhancedBubbleSortTemplate(T* list, int Length){
    //模板-优化版冒泡排序
        T trans;
        int aSize = Length;
        bool sign = true;
        for(int i = 0; i< Length - 1; i++){
           for(int j = 0; j < Length - 1 - i;j++){
                if(list[j] > list[j+1]){
                    trans = list[j];
                    list[j] = list[j+1];
                    list[j + 1] = trans;
                    sign = false;
                }
            }
            if(sign){
                //cout<<"Over";   //debug-print
                return;
            }
        }
}
void enhancedBubbleSortPlus(int* list, int preIndex, int endIndex){
    //区域冒泡排序。
    //目前该函数并未实现，数组越界检测，需要调用者注意，谨慎使用
    //参数 数组 需要排序序列的初始索引  需要排序序列的结束索引
    //默认：实现优化版冒泡排序--加入一个额外的判断
    //默认：<= 来遍历，尤其适合约束索引
        int trans;
        bool sign = true;
        int k = 0;
        for(int i = preIndex; i<= endIndex - 1; i++){
           for(int j = preIndex; j <=endIndex - k - 1;j++){
                if(list[j] > list[j+1]){
                    trans = list[j];
                    list[j] = list[j+1];
                    list[j + 1] = trans;
                    sign = false;
                }
            }
            k++;
            if(sign){
                //cout<<"Over";   //debug-print
                return;
            }
        }
}
template<typename T>
void enhancedBubbleSortPlusTemplate(T* list, int preIndex, int endIndex){
    //模板-区域冒泡排序
        T trans;
        bool sign = true;
        int k = 0;//k用来紧缩运算区域，省去部分计算，相当于整体冒泡排序的i的效果
        for(int i = preIndex; i<= endIndex - 1; i++){
           for(int j = preIndex; j <=endIndex - k - 1;j++){
                if(list[j] > list[j+1]){
                    trans = list[j];
                    list[j] = list[j+1];
                    list[j + 1] = trans;
                    sign = false;
                }
            }
            k++;
            if(sign){
                //cout<<"Over";   //debug-print
                return;
            }
        }
}
void printArray(int* arr, int Length){
    for(int i = 0; i < Length; i++){
        cout<<arr[i];
    }
    return;
}
template<typename T>
void printArrayTemplate(T* arr, int Length){
    for(int i = 0; i < Length; i++){
        cout<<arr[i];
    }
    return;
}
void printlnArray(int* arr, int Length){
    for(int i = 0; i < Length; i++){
        cout<<arr[i]<<"\n";
    }
    return;
}
template<typename T>
void printlnArrayTemplate(T* arr, int Length){
    for(int i = 0; i < Length; i++){
        cout<<arr[i]<<"\n";
    }
    return;
}
void printBlankArray(int* arr, int Length){
    for(int i = 0; i < Length; i++){
        cout<<arr[i]<<" ";
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
    double a[10] = {1,2,3,5.1,1,1,5,6.4,8,0.0};
    enhancedBubbleSortTemplate(a,10);
    printBlankArray(a,10);
    cout<<"\n";
    int b[6] = {1,3,1,2,4,2};
    enhancedBubbleSortPlus(b,2,5);
    printBlankArray(b,6);
    
}
