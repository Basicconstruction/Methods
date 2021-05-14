/*
 * @Author: your name
 * @Date: 2021-05-14 22:43:12
 * @LastEditTime: 2021-05-14 22:54:12
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \undefinedh:\Desktop\git-Methods\Methods\ACM-pretest\acmy.cpp
 */
#include <iostream>
using namespace std;
int generate(char c){
    if(static_cast<int>(c)<=static_cast<int>('z')&&static_cast<int>(c)>=static_cast<int>('a')){
        return -(static_cast<int>(c)-static_cast<int>('a')+1);
    }else{
        return static_cast<int>(c)-static_cast<int>('A')+1;
    }
}
int main() {
    char a;
    int m;
    int N;
    cin>>N;
    for(int i = 0; i < N;i++){
        cin>>a;
        cin>>m;
        cout<<generate(a)+m<<endl;
    }
    return 0;
}
