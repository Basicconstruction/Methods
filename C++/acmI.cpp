#include <iostream>
#include <string>
using namespace std;
void printYes(int a, int b, int c){
    if((a+b>c)&&(a+c>b)&&(b+c>a)&&a>0&&b>0&&c>0){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
}
int main() {
    int lines;
    cin>>lines;
    int a,b,c;
    for(int i = 0; i< lines;i++){
        cin>>a>>b>>c;
        printYes(a,b,c);
    }
    return 0;
}
