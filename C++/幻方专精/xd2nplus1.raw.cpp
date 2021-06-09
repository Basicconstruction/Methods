#include <iostream>
#include <vector>
using namespace std;
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
void randAllItems(const vector<vector<int> >& xd2nplus1){
    for(const vector<int>& xd:xd2nplus1){
        for(int x : xd){
            cout<<tackleSetLength(x,xd2nplus1.size())<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int getColSum(vector<vector<int> >& xd2nplus1){
    int sum = 0;
    for(int i = 0;i < xd2nplus1.size();i++){
        sum += xd2nplus1[0][i];
    }
    return sum;
}
void checkxd2nplus1(vector< vector<int> >& xd2nplus1){
    const unsigned int i0 = xd2nplus1.size();
    cout<<i0<<" * "<<i0<<endl;
    cout<<"The Num of each line is:"<<getColSum(xd2nplus1)<<endl;
    long long sumCol = 0;
    long long sumRow = 0;
    for(int i = 0; i < xd2nplus1.size();i++){
        sumCol = 0;
        sumRow = 0;
        for(int j = 0; j< xd2nplus1.size();j++ ){
            sumCol += xd2nplus1[i][j];
        }
        if(sumCol != getColSum(xd2nplus1)){
            cout<<"not match EE1!\n"<<"i = "<<i<<endl;
            return;
        }
        for(auto & j : xd2nplus1){
            sumRow += j[i];
        }
        if(sumRow != getColSum(xd2nplus1)){
            cout<<"not match EE1!\n"<<"i = "<<i<<endl;
            return;
        }
    }
    long long int sum1 = 0;
    long long int sum2 = 0;
    for(int i = 0;i < xd2nplus1.size();i++){
        sum1 += xd2nplus1[i][i];
        sum2 += xd2nplus1[xd2nplus1.size()-1-i][i];
    }
    if(sum1!= getColSum(xd2nplus1)||sum2!= getColSum(xd2nplus1)){
        cout<<"not match EE3!\n";
        return;
    }
    cout<<"All Ok!"<<endl;
}
void swapRow(vector<vector<int> > & xd2nplus1, int row1, int row2){
    int trans;
    for(auto & i : xd2nplus1){
        trans = i[row1];
        i[row1] = i[row2];
        i[row2] = trans;
    }
}
void swapEachRow(vector<vector<int> > & xd2nplus1){
    const unsigned int squareLen = xd2nplus1.size();
    vector<vector<int> > copySEMI((squareLen-1)/2);
    for(auto & i : copySEMI){
        i = vector<int>(squareLen);
    }
    for(int j = 0;j< copySEMI.size();j++){
        for(int k = 0; k < squareLen;k++){
            copySEMI[j][k] = xd2nplus1[k][copySEMI.size()+1+j];
        }//finish copy
//        cout<<"jjj"<<copySEMI.size()+1+j<<endl;
    }
    for(int l = 1;l < 1+copySEMI.size();l++){
        swapRow(xd2nplus1, l, copySEMI.size()+l);
//        cout<<"PP! "<<l<<" "<<copySEMI.size()+l<<endl;
    }
    swapRow(xd2nplus1,0,copySEMI.size());
    for(int i = 0;i < copySEMI.size();i++){
//        cout<<"pp2 "<<i<<endl;
        for(int k = 0;k < xd2nplus1.size();k++){
            xd2nplus1[k][i] = copySEMI[i][k];
        }
    }
    cout<<"finished!\n";

}
bool reachEnd(vector<vector<int> >& xd2nplus1,int col,int row){
    if(col==0||row==xd2nplus1.size()-1){
        return true;
    }
    return false;
}
bool isValid(vector<vector<int> > & xd2nplus1,int col,int row){
    const unsigned int validate = xd2nplus1.size();
    if(col>=0&&col<validate&&row>=0&&row<validate){
        return true;
    }
    return false;
}
int getNextInt(int num, int n){
    for(int i = 0;i<n;i++){
        if(num>=i * n+1&&num<=(i+1)*n){
            ++num;
            if(num>(i+1)*n){
                num = i * n + 1;
            }
            return num;
        }
    }
    return -1;
}
void test(){
    int n = 5;
    int m = 3;
    while(true){
        cin>>m;
        cout<<getNextInt(m,n)<<endl;
        if(m==0){
            break;
        }
    }
}
int main() {
//    test();
    int n;
    cout<<"n==?\nplease input n!\n";
    cin>>n;
    int col,row;
    int low;
    vector<vector<int> > xd2nplus1(n);
    for(int i = 0;i < n;i++){
        xd2nplus1[i] = vector<int> (n);
    }
    for(int i = 0; i < 2 * n-1;i++){
        col = i;
        row = 0;
        low = (n*n-1)/(n-1) * i + 1;
        if(i>=n){
            low = (n*n-1)/(n-1) * (i-n) + 1;
        }
        if(isValid(xd2nplus1,col,row)){
            xd2nplus1[col][row] = low;
        }
//        cout<<string(10,'-')<<endl;
//        cout<<"**i == "<<i<<endl;
//        cout<<"col "<<col<<" row "<<row<<"low"<<low<<endl;
        while(!reachEnd(xd2nplus1,col,row)){
            col --;
            row ++;
            low = getNextInt(low,xd2nplus1.size());
            if(isValid(xd2nplus1,col,row)){
                xd2nplus1[col][row] = low;
//                cout<<"low == "<<low<<endl;
            }
//            if(row<=n-1&&col<=n-1){
//                xd2nplus1[col][row] = low;
//                cout<<"low == "<<low<<endl;
//            }
//            cout<<"**i == "<<i<<endl;
//            cout<<"col "<<col<<" row "<<row<<"low "<<low<<endl;
        }
    }
//    randAllItems(xd2nplus1);
    swapEachRow(xd2nplus1);
    checkxd2nplus1(xd2nplus1);
    randAllItems(xd2nplus1);
    return 0;
}
