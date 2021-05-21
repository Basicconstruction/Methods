#include <iostream>
#include <stdio.h>
using namespace std;
class Pointer{
public:
    int l;
    long long arr[51];
    long long arr2[51];
    Pointer(int _l){
        this->l = _l;
        arr[0] = 0;
        arr[1] = 3;
        arr[2] = 6;
        arr[3] = 6;
        arr[4] = 18;
        arr[5] = 24;
        arr[6] = 48;
        arr2[0] = 0;
        arr2[1] = 3;
        arr2[2] = 6;
        arr2[3] = 12;
        arr2[4] = 24;
        for(int i = 7; i <= _l;i++){
            arr2[i-2] = arr2[i-3]*2;
            arr[i] = arr2[i-2] * 2;
        }
    }
};
void callBack(int n, Pointer* x){
    cout<<(*x).arr[n]<<endl;
}
int main() {
    int M;
    Pointer* x = new Pointer(49);
    bool run = false;
    if(!run){
        for(int i = 1; i < 50;i++){
            callBack(i,x);
        }
    }else{
        while(scanf("%d", &M)!=EOF){
            callBack(M, x);
        }
    }

    return 0;
}
/*
 * 1 -> 3      1*3   3         3
 * 2 -> 6      C23   6         6
 * 3 -> 6      A33   6         12
 * 4 -> 18     C23 * C23 18    24
 * 5 -> 24     C23 * 8
 * 6 -> 48     c23 * 16
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * */
