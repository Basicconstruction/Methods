#include <iostream>
using namespace std;
int main() {
    int N;
    cin>>N;
    int m;
    for(int y = 0; y < N;y++){
        cin>>m;//an - an-1 = (n-1)*4+1   -> an = 2 n * n -n + 1;
        cout<<2 * m * m - m + 1<<endl;
    }
    return 0;
}
