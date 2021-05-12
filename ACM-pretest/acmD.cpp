#include <iostream>
#include <stdio.h>
using namespace std;
void getTime(int a,int b,int c, int d, int e,int f){
    a = a+d;
    b = b+e;
    c = c+f;
    if(c>=60){
        c = c - 60;
        b++;
    }
    if(b>=60){
        b = b-60;
        a++;
    }
    cout<<a<<" "<<b<<" "<<c<<"\n";
}
int main() {
    int lines;
    cin>>lines;
    int a,b,c,d,e,f;
    for(int y = 0; y < lines; y++){
        scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
        getTime(a,b,c,d,e,f);
    }
    return 0;
}