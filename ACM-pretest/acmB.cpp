/*
 * @Author: your name
 * @Date: 2021-05-12 21:57:48
 * @LastEditTime: 2021-05-12 21:59:01
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \undefinedh:\Desktop\git-Methods\Methods\ACM-pretest\acmB.cpp
 */
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
string addPre(string s, int a, bool upperAlpha = true){
    char s2;
    if(a>=0&&a<=9){
        s2 = static_cast<char>(a + 48);
    }else{
        if(upperAlpha){
            s2 = static_cast<char>((static_cast<int>('A'))+a - 10);
        }else{
            s2 = static_cast<char>((static_cast<int>('a'))+a - 10);
        }
    }
    return s2+s;
}
string bitsFrom10(int input10, int bits, bool upperAlpha = true){
    bool sign = false;
    if(input10<0){
        sign = true;
        input10 = -input10;
    }
    int trans = 0;
    int trans2 = 0;
    string output = "";
    while(input10/bits>0){
        trans = input10 / bits;
        trans2 = input10 % bits;
        output = addPre(output, trans2);
        input10 = trans;
    }
    output = addPre(output, input10, upperAlpha);
    if(sign){
        output = "-"+output;
    }
    return output;
}
int main() {
    int input10;
//    cin>>input10;
    int dataN;
//    cin>>dataN;
    while(scanf("%d%d", &input10,&dataN)!=EOF){
        std::cout<<bitsFrom10(input10, dataN)<<endl;
    }
    return 0;