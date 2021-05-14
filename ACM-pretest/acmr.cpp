#include <iostream>
#include <stdio.h>
#include <cassert>
using namespace std;
class Pointer{
public:
    long long arr[21];

    Pointer(){//arr[7] = 6 * 5 * nf(1+4) + 6 * f(5)
        arr[0] = 0;//nf(k) = f(k-1)+f(k)
        arr[1] = 0;//N(n) = (n-1)*(n-2)*{f(n-2)+f(n-3)}+(n-1)*f(n-2)
        //N(n)= (n-1)(n-1)f(n-2)+(n-1)(n-2)*f(n-3)
        arr[2] = 1;//f(2) = 0;
        arr[3] = 2 * 1;//f(3) = 2;f(4) = 9;f(5)=
        arr[4] = 3 * 3; //3 * 2 * (1)+3*1 == 3 * 2 *(1+0)+ 3 * 1 == 3 * 3+3 * 2 * 0
        arr[5] = 44;//44     //4 * 3 * nf(1+2)+f(3)*4
        arr[6] = 265; //    //5 * 4 * nf(1+3) + f(4)*5
        for(int l = 7;l<=20;l++){
            arr[l] = (l-1)*(l-1)*arr[l-2]+(l-1)*(l-2)*arr[l-3];
        }
    }

};
long long FAB(int b){
    assert(b!=0);
    long long output = 1;
    for(int k = 1; k <= b;k++){
        output *= k;
    }
    return output;
}
void coutOutput(int n, Pointer* x){
    printf("%.2f%c\n", static_cast<float>((*x).arr[n]) / static_cast<float>(FAB(n))*100, '%');
}
int main() {
    int C;
    cin>>C;
    int N;
    Pointer* x = new Pointer();
    for(int i = 0; i < C;i++){
        cin>>N;
        coutOutput(N,x);
    }
    return 0;
}
