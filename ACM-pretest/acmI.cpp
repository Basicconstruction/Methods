/*
 * @Author: your name
 * @Date: 2021-05-12 21:57:56
 * @LastEditTime: 2021-05-12 22:03:18
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \undefinedh:\Desktop\git-Methods\Methods\ACM-pretest\acmI.cpp
 */
#include <iostream>
#include <string>
using namespace std;
//actually T,T2,T3 in this problem will always be assumed to float
template <typename T,typename T2,typename T3>
void printYes(T a, T2 b, T3 c){
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