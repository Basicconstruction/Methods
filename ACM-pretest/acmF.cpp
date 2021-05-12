#include <iostream>
using namespace std;
int localPow(int a, int b){
    a = a % 1000;
    int c = 1;
    for(int y = 0; y < b-1;y++){
        c = c * a % 1000;
    }
    c = c * a%1000;
    return c;
}
int main() {
    int a;
    int b;
    while(true){
        cin>>a>>b;
        if(a==0&&b==0){
            break;
        }
        cout<<localPow(a,b)<<endl;
    }
}