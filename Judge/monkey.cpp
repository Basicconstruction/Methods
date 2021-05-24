#include <iostream>
#include <vector>

using namespace std;

void printNOTBlank(vector<int> &x) {
    for (int i :x) {
        if (i != 0) {
            cout << i;
        }
    }
}

void kk(int&n, int&m) {
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        x[i] = i + 1;
    }
    int im = m;
    int in = n - 1;
    int p = -1;
    bool get = false;
    while (in != 0) {
        while (!get) {
            while (im != 0) {
                p++;
                if (p > n - 1) {
                    p = 0;
                }
                if (x[p] != 0) {
                    im--;
                }
            }
            x[p] = 0;
            get = true;
        }
        get = false;
        in--;
        im = m;
    }
    printNOTBlank(x);
}
void FF(int& n, int&m){
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        x[i] = i + 1;
    }
    int index = -1;
    for(int cir = 0; cir < n-1;cir++){
        index = index + m;
        index = int(index % x.size());
        x.erase(x.begin()+index);
        if(index == 0||index == x.size()){
            index = -1;
        }else{
            index = index - 1;
        }
//        for(int k : x){
//            cout<<k<<" ";
//        }
//        cout<<endl;
    }
    cout<<x[0];
}
int main() {
    int n, m;
    cin >> n >> m;
    kk(n,m);
    cout<<" ";
    FF(n,m);
    return 0;
}
