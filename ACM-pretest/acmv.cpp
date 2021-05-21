#include <iostream>
#include <string>
using namespace std;
string generateWidthLine(int width, bool getWidth = true){
    if(getWidth){
        string generateWidth = string(width, '-');
        return '+' + generateWidth + '+';
    }else{
        string generateWidth = string(width, ' ');
        return '|' + generateWidth + '|';
    }
}
int main() {
    int n,m;
    while(scanf("%d%d", &n, &m)!=EOF){
        cout<<generateWidthLine(n)<<endl;
        for(int y = 0; y < m; y++){
            cout<<generateWidthLine(n, false)<<endl;
        }
        cout<<generateWidthLine(n)<<endl;
        cout<<endl;
    }
    return 0;
}
