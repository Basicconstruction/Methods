/*
 * @Author: your name
 * @Date: 2021-05-12 21:57:53
 * @LastEditTime: 2021-05-12 22:01:17
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \undefinedh:\Desktop\git-Methods\Methods\ACM-pretest\acmE.cpp
 */
#include <iostream>
#include <algorithm>
using namespace std;
void enhancedBubbleSortOfRange(int list[], int preIndex, int endIndex) {
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
        if (sign) {
            return;
        }
    }
    return;
}
class Pointer{
public:
    int l;
    int arr[100];

    void sort(){
        enhancedBubbleSortOfRange(arr, 0, l);
    }

    Pointer(int _l){
        this->l = _l;
    }
    void print(){
        for(int i = 0; i < l;i++){
            cout<<arr[i]<<" ";
        }
    }
};
int main() {
    int a;
    int b;
    Pointer y(0);
    Pointer x(0);
    Pointer z(0);
    bool sign;
    int le;
    while(true){
        cin>>a;
        cin>>b;
        x = NULL;
        y = NULL;
        z = NULL;
        le = 0;
        if(a==0&&b==0){
            break;
        }
        x = Pointer(a);
        for(int i = 0; i < a;i++){
            cin>>x.arr[i];
        }
        y = Pointer(b);
        for(int i = 0; i < b;i++){
            cin>>y.arr[i];
        }
        z = Pointer(0);
        sign = false;
        for(int i = 0; i < a;i++){
            for(int j = 0;j<b;j++){
                if(x.arr[i] == y.arr[j]){
                    sign = true;
                }
            }
            if(!sign){
                z.arr[le] = x.arr[i];
                z.l++;
                le ++;
            }
            sign = false;
        }
        z.sort();
        z.print();
        if(z.l==0){
            cout<<"NULL\n";
        }else{
            cout<<"\n";
        }

    }

}