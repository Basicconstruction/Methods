#include <iostream>
#include <vector>
using namespace std;
bool isExcell(int col, int row){
    col += 1;
    row += 1;
    if((col%4==1&&row%4==1)||(col%4==1&&row%4==0)||(col%4==0&&row%4==1)||(col%4==0&&row%4==0)){
        return true;
    }
    if((col%4==2&&row%4==2)||(col%4==2&&row%4==3)||(col%4==3&&row%4==2)||(col%4==3&&row%4==3)){
        return true;
    }
    return false;
}
vector<int> getMirror(int col,int row, const int MaxCol){
    return {MaxCol-1-col,MaxCol-1-row};
}
string convertNumToString(long long int x){
    // transfer int number to string
    string s;
    x *= 10;
    while(x>=10){
        x /= 10;
        s = static_cast<char>(x % 10+48) + s;
    }
    return s;
}
string tackleSetLength(int num,int n){
    return string(n - convertNumToString(num).length(), ' ')+ convertNumToString(num);
}
void randAllItems(const vector<vector<int> >& xd4n){
    for(const vector<int>& xd:xd4n){
        for(int x : xd){
            cout<<tackleSetLength(x,xd4n.size())<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int getColSum(vector<vector<int> >& xd4n){
    int sum = 0;
    for(int i = 0;i < xd4n.size();i++){
        sum += xd4n[0][i];
    }
    return sum;
}
void checkxd4n(vector< vector<int> >& xd4n){
    const unsigned int i0 = xd4n.size();
    cout<<i0<<" * "<<i0<<endl;
    cout<<"The Num of each line is:"<<getColSum(xd4n)<<endl;
    long long sumCol = 0;
    long long sumRow = 0;
    for(int i = 0; i < xd4n.size();i++){
        sumCol = 0;
        sumRow = 0;
        for(int j = 0; j< xd4n.size();j++ ){
            sumCol += xd4n[i][j];
        }
        if(sumCol != getColSum(xd4n)){
            cout<<"not match EE1!\n"<<"i = "<<i<<endl;
            return;
        }
        for(auto & j : xd4n){
            sumRow += j[i];
        }
        if(sumRow != getColSum(xd4n)){
            cout<<"not match EE1!\n"<<"i = "<<i<<endl;
            return;
        }
    }
    long long int sum1 = 0;
    long long int sum2 = 0;
    for(int i = 0;i < xd4n.size();i++){
        sum1 += xd4n[i][i];
        sum2 += xd4n[xd4n.size()-1-i][i];
    }
    if(sum1!= getColSum(xd4n)||sum2!= getColSum(xd4n)){
        cout<<"not match EE3!\n";
        return;
    }
    cout<<"All Ok!"<<endl;
}
void test(){
    cout<<convertNumToString(100);
}
int main() {
//    test();
    int n;
    cout<<"n==?\nplease input n!\n";
    cin>>n;
    vector< vector<int> > xd4n(n);
    vector<int> x2(2);
    int trans;
    for(int i = 0; i < n;i++){
        xd4n[i] = vector<int>(n);
    }
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            xd4n[i][j] = n * i+j+1;
        }
    }
    for(int col = 0; col < n/2;col++){
        for(int row = 0; row < n;row++){
            if(isExcell(col,row)){
                x2 = getMirror(col,row,n);
                trans = xd4n[col][row];
                xd4n[col][row] = xd4n[x2[0]][x2[1]];
                xd4n[x2[0]][x2[1]] = trans;
            }
        }
    }
    cout<<"translation right with no error!\n";
//    cout<<getColSum(xd4n);
    checkxd4n(xd4n);
    randAllItems(xd4n);
    // 可以额外附加导出到csv文件等功能
    return 0;
}
