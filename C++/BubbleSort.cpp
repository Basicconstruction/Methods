//
// Created by hay boy on 2021/4/23.
//
#include <iostream>
using namespace std;
void bubbleSort1(int* list, int Length){
        int trans = 0;
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
void printArray(int* arr, int Length){
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
void printBlankArray(int* arr, int Length){
    for(int i = 0; i < Length; i++){
        cout<<arr[i]<<" ";
    }
    return;
}
int main(){
    int a[3] = {1,2,3};
    bubbleSort1(a,3);
    printBlankArray(a,3);
    
}
