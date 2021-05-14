#include <iostream>
using namespace std;
long long CAB(int B, int A){
    if(A==0){
        return 1;
    }
    long long output = 1;
    for(int i = 1; i <= A;i++){
        output *= (B-i+1);
        output /= i;
    }
    return output;
}
void coutNum(int le){
    int num2;
    if(le%2==0){
        num2 = le / 2;
    }else{
        num2 = (le-1)/2;
    }
    long long sump = 0;
    for(int i = 0; i <= num2;i++){
        sump += CAB(le-i, i);
    }
    cout<<sump<<endl;
}
int main() {

    int M;
    while(scanf("%d",&M)!=EOF){
        coutNum(M);
    }
    return 0;
}
