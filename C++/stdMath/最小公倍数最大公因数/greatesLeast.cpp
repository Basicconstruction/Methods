#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
template<typename T>
vector<T> getAbstract(T x, T y){
    for(long i = 2;i <=(x>y?y:x);){
        if(x%i==0&&y%i==0){
            x = x / i;
            y = y / i;
        }
        if(x%i!=0||y%i!=0){
            i++;
        }
    }
    return {x,y};
}
template<typename T>
T getGreatestCommonFactor(T x,T y){
    T lx = getAbstract(x,y)[0];
    return x / lx;
}
template<typename T>
T getLeastCommonMultiple(T x, T y){
    vector<T> cv = getAbstract(x,y);
    return cv[1] * x;
}
int main()
{
    cout<<getLeastCommonMultiple(10000,300);
    long a,b;
    vector<int> x(2);
//    cin>>a>>b;
    for(int i = 100;i<200;i+=2){
//        x = getAbstract(i,10000);
//        cout<<x[0]<<" "<<x[1]<<endl;
//        cout<<i/x[0]<<" "<<10000/x[1]<<endl;
        cout<<getGreatestCommonFactor(i,10000)<<endl;
    }
    return 0;
}