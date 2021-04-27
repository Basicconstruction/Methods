#include <iostream>
using namespace std;

template <typename T>
void printBlankArrayTemplate(T* arr, int Length){
    for(int i = 0; i < Length; i++){
        cout<<arr[i]<<" ";
    }
    return;
}

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

void elementsMoveOneStep(int *arr, int preIndex, int endIndex, bool pushForward = true) {
    if(preIndex == endIndex){
        return;
    }
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

void insertionSort(int* arr, int length, bool ascending = true){
    //插入排序
    int key;
    int j;
    bool getIt = false;
    for(int i = 0; i < length; i++){
        key = arr[i];
        j = i - 1 ;
        //{2,1,4,6,3,5}
        while(!getIt&&j>=0){
            if(arr[j] < key && ascending){
                getIt = true;
            }
            j--;
        }
        if(getIt){
            elementsMoveOneStep(arr, j+2, i, false);
        }else{
            elementsMoveOneStep(arr, 0,i,false);
        }
//        cout<<"$";
//        printBlankArrayTemplate(arr,length);
//        cout<<"\n";
//        if(arr[j] <= key){
//
//        }else{
//            j--;
//            while(!getIt&&j>=0){
//                if(arr[j] < key && ascending){
//                    getIt = true;
//                }
//                j--;
//            }
//            if(getIt){
//                elementsMoveOneStep(arr, j+2, i, false);
//            }else{
//                elementsMoveOneStep(arr, 0,i,false);
//            }
//        }
        getIt = false;
    }
    if(!ascending){
        reverseArrayTemplate(arr, length);
    }
    return;
}

int main() {
    int a[] = {2,1,1,6,3,5,1,2,1,2,0,8,3,2,1,9,7,2,90,-2};
    insertionSort(a,10,true);
    printBlankArrayTemplate(a,10);
    return 0;
}
