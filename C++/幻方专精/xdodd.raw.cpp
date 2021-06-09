#include <iostream>
#include <vector>
using namespace std;
string convertNumToString(long long int x) {
    // transfer int number to string
    string s;
    x *= 10;
    while (x >= 10) {
        x /= 10;
        s = static_cast<char>(x % 10 + 48) + s;
    }
    return s;
}
vector<int> getMirror(int col,int row, const int MaxCol){
    return {MaxCol-1-col,MaxCol-1-row};
}
int getNextN(const vector<vector<int> >& xdodd, int num, int plus){
    const unsigned int square = xdodd.size() * xdodd.size();
    return num+plus<=square?num+plus:num+plus-square;
}
void putInMirror(vector<vector<int> > & xdodd,int col, int row){
    vector<int> x = getMirror(col,row,xdodd.size());
    xdodd[x[0]][x[1]] = xdodd.size() * xdodd.size() + 1 - xdodd[col][row];
}
string tackleSetLength(int num, int n) {
    return string(n - convertNumToString(num).length(), ' ') + convertNumToString(num);
}
void randAllItems(const vector<vector<int> >& xdodd) {
    for (const vector<int>& xd : xdodd) {
        for (int x : xd) {
            cout << tackleSetLength(x, xdodd.size()) << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int getColSum(vector<vector<int> >& xdodd) {
    int sum = 0;
    for (int i = 0; i < xdodd.size(); i++) {
        sum += xdodd[0][i];
    }
    return sum;
}
void checkxdodd(vector< vector<int> >& xdodd) {
    const unsigned int i0 = xdodd.size();
    cout << i0 << " * " << i0 << endl;
    cout << "The Num of each line is:" << getColSum(xdodd) << endl;
    long long sumCol = 0;
    long long sumRow = 0;
    for (int i = 0; i < xdodd.size(); i++) {
        sumCol = 0;
        sumRow = 0;
        for (int j = 0; j < xdodd.size(); j++) {
            sumCol += xdodd[i][j];
        }
        if (sumCol != getColSum(xdodd)) {
            cout << "not match EE1!\n" << "i = " << i << endl;
            return;
        }
        for (auto& j : xdodd) {
            sumRow += j[i];
        }
        if (sumRow != getColSum(xdodd)) {
            cout << "not match EE1!\n" << "i = " << i << endl;
            return;
        }
    }
    long long int sum1 = 0;
    long long int sum2 = 0;
    for (int i = 0; i < xdodd.size(); i++) {
        sum1 += xdodd[i][i];
        sum2 += xdodd[xdodd.size() - 1 - i][i];
    }
    if (sum1 != getColSum(xdodd) && sum2 != getColSum(xdodd)) {
        cout << "not match EE3-ALL!\n";
        return;
    }
    else if (sum1 != getColSum(xdodd)) {
        cout << "not match EE3-DownRight!\n";
        return;
    }
    else if (sum2 != getColSum(xdodd)) {
        cout << "not match EE3-UpRight!\n";
        return;
    }
    else {

    }
    cout << "All Ok!" << endl;
}
int getNextInt(int num, int n) {
    for (int i = 0; i < n; i++) {
        if (num >= i * n + 1 && num <= (i + 1) * n) {
            ++num;
            if (num > (i + 1) * n) {
                num = i * n + 1;
            }
            return num;
        }
    }
    return -1;
}
void test() {
    int n = 5;
    int m = 3;
    while (true) {
        cin >> m;
        cout << getNextInt(m, n) << endl;
        if (m == 0) {
            break;
        }
    }
}
int main() {
    //    test();
    int n;
    cout << "n==?\nplease input n!\n";
    cin >> n;
    int col, row;
    int low;
    vector<vector<int> > xdodd(n);
    for (int i = 0; i < n; i++) {
        xdodd[i] = vector<int>(n);
    }
    for(int j = 0; j < n;j++){
        xdodd[j][(n-1)/2] = (n * n - 1) / (n-1) * j + 1;
    }
    col = -1;
//    row = (n-1)/2;
    for (int i = (n-1)/2-1; i >=0; i--) {
        col += 2;
        row = i;
        xdodd[col][row] = xdodd[col-1][row+1] + n - 1;
        putInMirror(xdodd,col,row);
        xdodd[col+1][row] = xdodd[col][row]+1;
        putInMirror(xdodd,col+1,row);
        int transCol = col+1;
        int lateCol;
//        randAllItems(xdodd);
        for(int k = 1; k <= n-2;k++){
            lateCol = transCol + 1 <= n-1?transCol+1:transCol+1-n;
//            cout<<"transCol "<<transCol<<" lateCol"<<lateCol<<endl;
            xdodd[lateCol][row] = getNextN(xdodd,xdodd[transCol][row],n+1);
            putInMirror(xdodd,lateCol,row);
            transCol = lateCol;
        }
    }
    checkxdodd(xdodd);
    randAllItems(xdodd);

    return 0;
}
