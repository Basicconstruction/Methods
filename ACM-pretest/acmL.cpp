#include <iostream>
using namespace std;
long long int localPow(int a, int b){
    long long output = 1;
    for(int k = 0; k < b; k++){
        output *= a;
    }
    return output;
}
int main() {
    int N;
    cin>>N;
    int num;
    long long list;
    for(int k = 0; k < N;k++){
        cin>>num;
        list = localPow(2,num);
        cout<<3 * list - 2*( list - 1)<<endl;
    }
    return 0;
}