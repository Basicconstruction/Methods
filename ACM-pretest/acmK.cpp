/*
 * @Author: your name
 * @Date: 2021-05-12 09:03:41
 * @LastEditTime: 2021-05-12 09:04:44
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \undefinedh:\Desktop\git-Methods\Methods\ACM-pretest\acmK.cpp
 */
#include <iostream>
using namespace std;
long factorial(int n, int k = 2){
    if(n==0){
        return 1;
    }
    long output = 1;
    for(int j = n; j >= k;j--){
        output *= j;
    }
    return output;
}
long cAB(int B, int A){
    return (factorial(B, B-A+1))/(factorial(A));
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
//        cout<<"&& "<<i<<"  "<<cAB(s-i,i)<<endl;
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
/* 测试用例
10
1
0
2
1
3
2
4
3
5
5
6
8
7
13
8
21
9
34
10
55*/