#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
enum NumberType{
    odd,
    oddNotPrime,
    oddButPrime,
    even,
    evenWithOddFactor,
    evenWithoutOddFactor
};
static auto y = even;
bool isPrime(int &n){
    if(n==1||n==0){
        return false;
    }
    if(n%2==0){
        return false;
    }
    for(int i = 2;i<n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
vector<int> getFactorList(int & n){
    vector<int> x(0);
    for(int j = 2;j<n;j++){
        if(n%j==0){
            x.push_back(j);
        }
    }
    return x;
}
vector<int> filterForEven(vector<int> x){
    vector<int> list(0);
    for(int l: x){
        if(l%2!=0){
            list.push_back(l);
        }
    }
    return list;
}
void getType(int & n){
    if(n%2==0){
        y = even;
        vector<int> filtered = filterForEven(getFactorList(n));
        if(filtered.empty()){
            y = evenWithoutOddFactor;
        }else{
            y = evenWithOddFactor;
        }
    }else{
        y = odd;
        if(isPrime(n)){
            y = oddButPrime;
        }else{
            y = oddNotPrime;
        }
    }
}

void printAllItems(vector<int> & x){
    for(int ele: x){
        cout<<ele<<" "<<endl;
    }
}
void Call(int n){
    vector<int> x = getFactorList(n);
    getType(n);
    vector<int> filtered = filterForEven(getFactorList(n));
    if(y == evenWithoutOddFactor){
        cout<<"Null";
        cout<<endl;
    }else if(y == evenWithOddFactor){
        int centerNum;
        int length;
        int step;//步进，用于计算low位
        bool have = false;
        for(int k:filtered){
//            cout<<k<<" ";
            length = k;//这里使用了模糊处理，实际意义并不符合，但是确是正确的，从理论上来说是行得通的。
            centerNum = n / length;//
            step = (length-1)/2;
            if(centerNum-step>0){
                have = true;
                for(int low = centerNum-step;low <= centerNum+step;low++){
                    cout<<low<<" ";
                }
                cout<<endl;
            }
        }
        if(!have){
            cout<<"Null\n";
        }
    }else if(y == oddButPrime){
        cout<<(n-1)/2<<" "<<(n-1)/2+1<<endl;
    }else if(y == oddNotPrime){
        if(n==1){
            cout<<1<<endl;
            return;
        }
        int centerNum;
        int length;
        int step;//步进，用于计算low位
        for(int k:x){
            length = k;
            centerNum = n / length;
            step = (length-1)/2;
            if(centerNum-step>0){
                for(int low = centerNum-step;low <= centerNum+step;low++){
                    cout<<low<<" ";
                }
                cout<<endl;
            }
        }
        cout<<(n-1)/2<<" "<<(n-1)/2+1<<endl;
    }else{
        cout<<"Error occur"<<endl;
    }
}
int main() {
    cout<<"Please input a integer!>>"<<endl;
    int n;
//    cin>>n;
    for(int i = 0;i<100;i++){
        Call(i);
    }
//    Call(16,true);
//    printAllItems(x);

//    cin>>n;
//    for(int i = 0;i<100;i++){
//        cout<<(isPrime(i)?"true":"false")<<i<<endl;
//    }
//1 ->not legal
//2 -> legal
//3 -> legal
//4 -> not legal
//5 ->
//7 ->
//2n + 1 -> legal
// 15 -> 1+2+3+4+5   3 * 5      4 + 5 + 6   5 * 3      7 + 8  e (n-1)/2, (n-1)/2+1
// 17 -> 素数/奇数        8 + 9
// 21 -> 3*7  => not allowed          -1 1 2 3 4 5 6
//21     7 * 3   => 6 7 8                  e 10+11
//16
//20   4 * 5  2 3 4 5 6
//24   3 * 8  7 8 9

    return 0;
}
