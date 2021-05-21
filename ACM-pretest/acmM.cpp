#include <iostream>
#include <string>
using namespace std;
int kindChar(char c){
    int charInt = static_cast<int>(c);
    if(charInt>=(static_cast<int>('a'))&&charInt<=(static_cast<int>('z'))){
        return 1;
    }
    if(charInt>=(static_cast<int>('A'))&&charInt<=(static_cast<int>('Z'))){
        return 2;
    }
    if(charInt>=(static_cast<int>('0'))&&charInt<=(static_cast<int>('9'))){
        return 3;
    }
    return 4;
}
int main() {
    int lines;
    cin>>lines;
    string secretCode;
    int arr[4] = {0,0,0,0};
    for(int i = 0; i < lines;i++){
        arr[0] = 0;arr[1] = 0;
        arr[2] = 0;arr[3] = 0;
        cin>>secretCode;
        if(secretCode.length()<8||secretCode.length()>16){
            cout<<"NO"<<endl;
        }else{
            for(char y : secretCode){
                arr[kindChar(y)-1] = kindChar(y);
            }
            if((arr[0]!=0)+(arr[1]!=0)+(arr[2]!=0)+(arr[3]!=0)>=3){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
        }

    }
    return 0;
}