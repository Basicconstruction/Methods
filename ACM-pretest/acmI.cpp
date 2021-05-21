#include <iostream>
#include <string>
using namespace std;
void printYes(float a, float b, float c){
    if((a+b>c)&&(a+c>b)&&(b+c>a)){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
}
int main() {
    int lines;
    cin>>lines;
    auto a = 0.0f;
    auto b = 0.0f;
    auto c = 0.0f;
    for(int i = 0; i< lines;i++){
        cin>>a>>b>>c;
        printYes(a,b,c);
    }
    return 0;
}

// template <typename T,typename T2,typename T3>
// void printYes(T a, T2 b, T3 c){
//     if((a+b>c)&&(a+c>b)&&(b+c>a)){
//         cout<<"YES\n";
//     }else{
//         cout<<"NO\n";
//     }
// }