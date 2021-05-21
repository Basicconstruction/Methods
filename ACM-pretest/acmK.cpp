#include <iostream>
using namespace std;
long cAB(int B, int A){
    if(A==0){
        return 1;
    }
    long output = 1;
    for(int i = 1;i<=A;i++){
        output *= (B-i+1);
        output /= i;
    }
    return output;
}
void printWays(int s){
    int howMany2;
    long ways = 0;
    if(s % 2 == 0){
        howMany2 = s / 2;
    }else{
        howMany2 = (s-1)/2;
    }
    for(int i = 0;i<=howMany2;i++){
        ways += cAB(s-i,i);
    }
    cout<<ways<<endl;
}
int main() {
    int lines;
    cin>>lines;
    int M;
    int steps;
    for(int i = 0; i < lines;i++){
        cin>>M;
        steps = M - 1;
        if(steps==0){
            cout<<0<<endl;
        }else{
            printWays(steps);
        }
    }
    return 0;
}