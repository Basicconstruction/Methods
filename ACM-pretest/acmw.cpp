/*
 * @Author: your name
 * @Date: 2021-05-14 22:52:56
 * @LastEditTime: 2021-05-14 22:53:34
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \undefinedh:\Desktop\git-Methods\Methods\ACM-pretest\acmw.cpp
 */
#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;
int getChild(long a){
    int count = 0;
    for(int i = 1; i <=a;i++){
        if(a % i==0){
            count ++;
        }
    }
    return count;
}

int main() {
    long y;
    while(scanf("%ld",&y)!=EOF){
        if(getChild(y)%2==0){
            cout<<0<<endl;
        }else{
            cout<<1<<endl;
        }
    }
    return 0;
}
//待优化
/*
void getAssert(int n){
    cout<<getC(n)<<" "<<getChild(n)<<endl;
//    assert(getC(n) == getChild(n));
}
int getC(long a){
    int count = 0;
    for(int i = 1;i <= static_cast<int>(sqrt(a)); i++){
        if(a%i==0){
            count += 2;
        }
    }
    if(a % static_cast<int>(sqrt(a)) == 0){
        count -= 1;
    }
    return count;
}
 */