#include <iostream>
using namespace std;
bool isARB(long a,long b){
    long getTotalB = 0;
    for(long i = 1; i <= b/2;i++){
        if(b%i==0){
            getTotalB += i;
        }
    }
    if(a==getTotalB){
        return true;
    }else{
        return false;
    }
}
void printYes(long a,long b){
    if(a==b){
        cout<<"YES\n";
        return;
    }
    if(isARB(a,b)&&isARB(b,a)){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
}
int main() {
    int lines;
    cin>>lines;
    long M;
    long N;
    while(lines--){
        cin>>M>>N;
        printYes(M,N);
    }
    return 0;
}