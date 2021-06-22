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
static int y = even;
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
    for(int i=0;i<x.size();i++){
        if(x[i]%2!=0){
            list.push_back(x[i]);
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
    for(int i = 0;i<x.size();i++){
        cout<<x[i]<<" "<<endl;
    }
}
void Call(int n){
    vector<int> x = getFactorList(n);
    getType(n);
    vector<int> filtered = filterForEven(getFactorList(n));
    if(y == evenWithoutOddFactor){
        cout<<"NONE";
        cout<<endl;
    }else if(y == evenWithOddFactor){
        vector<vector<int> > vvs(0);
        vector<int> vs(0);
        int centerNum;
        int length;
        int step;//步进，用于计算low位
        bool have = false;
        for(int i = 0;i<filtered.size();i++){
//            cout<<k<<" ";
            length = filtered[i];//这里使用了模糊处理，实际意义并不符合，但是确是正确的，从理论上来说是行得通的。
            centerNum = n / length;//
            step = (length-1)/2;
            if(centerNum-step>0){
                have = true;
                for(int low = centerNum-step;low <= centerNum+step;low++){
                    vs.push_back(low);
                }
                vvs.push_back(vs);
                vs.clear();
            }
        }
        vector<int> printHelper(vvs.size());
        for(int h = 1;h <= vvs.size();h++){
            printHelper[h-1] = vvs[h-1][0];
        }
        int minN;
        int index;
        int len = printHelper.size();
        for(int i = 0;i < len;i++){
            index = 0;
            minN = printHelper[0];
            for(int j = 0;j < printHelper.size();j++){
                if(minN > printHelper[j]){
                    index = j;
                    minN = printHelper[j];
                }
            }
            for(int k = 0;k < vvs[index].size();k++){
                cout<<vvs[index][k]<<" ";
            }
            printHelper.erase(printHelper.begin()+index);
            cout<<endl;
        }
        if(!have){
            cout<<"NONE\n";
        }
    }else if(y == oddButPrime){
        cout<<(n-1)/2<<" "<<(n-1)/2+1<<endl;
    }else if(y == oddNotPrime){
        if(n==1){
            cout<<"NONE"<<endl;
            return;
        }
        vector<vector<int> > vvs(0);
        vector<int> vs(0);
        int centerNum;
        int length;
        int step;//步进，用于计算low位
        for(int k=0;k<x.size();k++){
            length = x[k];
            centerNum = n / length;
            step = (length-1)/2;
            if(centerNum-step>0){
                for(int low = centerNum-step;low <= centerNum+step;low++){
                    vs.push_back(low);
                }
                vvs.push_back(vs);
                vs.clear();
            }

        }
        vector<int> printHelper(vvs.size());
        for(int h = 1;h <= vvs.size();h++){
            printHelper[h-1] = vvs[h-1][0];
        }
        int minN = printHelper[0];
        int index = 0;
        int len = printHelper.size();
        for(int i = 0;i < len;i++){
            index = 0;
            minN = printHelper[0];
            for(int j = 0;j < printHelper.size();j++){
                if(minN > printHelper[j]){
                    index = j;
                    minN = printHelper[j];
                }
            }
            for(int k = 0;k < vvs[index].size();k++){
                cout<<vvs[index][k]<<" ";
            }
            printHelper.erase(printHelper.begin()+index);
            cout<<endl;
        }
        cout<<(n-1)/2<<" "<<(n-1)/2+1<<endl;
    }else{
        cout<<"Error occur"<<endl;
    }
}
int main() {
    int n;
    cin>>n;
    Call(n);
    /*
    for(int y = 0;y <=100;y++){
        Call(y);
    }*/
    return 0;
}
