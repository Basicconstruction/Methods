#include <iostream>
#include <string>
using namespace std;
bool isAsc(int bi){
    if(bi>=0&&bi<=128){
        return true;
    }
    return false;
}
int main() {
    int line = 1;
//    cin>>line;
    string s1;
    int count;
    int total = 0;
    for(int i = 0; i < line; i++){
        count = 0;
        getline(cin,s1, '\n');
        cout<<s1;
        for(char y : s1){
            if(isAsc(static_cast<int>(y))){
                count++;
                cout<<static_cast<int>(y)<<"  ";
            }
        }
        cout<<"$"<<count;//hi请重新安装
        cout<<"&&"<<s1.length();
        total = total + (s1.length() - count) / 3;
    }
    cout<<"*"<<total;
    return 0;


}
