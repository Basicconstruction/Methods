#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
string get_2_bits_from_10(int n){
    string output = "";
    auto trans1 = 0;
    while(n>0){
        trans1 = n % 2;
        n = n / 2;
        output = static_cast<char>(trans1+48) + output;
    }
    return output;
}
int main() {
    int m;
    while(scanf("%d", &m)!=EOF){
        cout<<get_2_bits_from_10(m)<<endl;
    }
    return 0;
}
