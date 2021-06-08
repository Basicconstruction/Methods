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
vector<int> getMirror(int col,int row){
    return {11-col,11-row};
}
string tackleSetLength(int num){
    string x = " ";
    if(num < 10){
        x = x + static_cast<char>(static_cast<int>('0')+num);
    }else{
        x = "";
        x = x + static_cast<char>(static_cast<int>('0')+num/10) + static_cast<char>(static_cast<int>('0')+num%10);
    }
    return x;
}
void randAllItems(const vector<vector<int> >& xd12){
    for(const vector<int>& xd:xd12){
        for(int x : xd){
            cout<<tackleSetLength(x)<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int getColSum(vector<vector<int> >& xd12){
    int sum = 0;
    for(int i = 0;i < 12;i++){
        sum += xd12[0][i];
    }
    return sum;
}
void checkxd12(vector< vector<int> >& xd12){
    for(int i = 0; i < 12;i++){
        if(xd12[i][0]+xd12[i][1]+xd12[i][2]+xd12[i][3]+xd12[i][4]+xd12[i][5]+xd12[i][6]+xd12[i][7]
        +xd12[i][8]+xd12[i][9]+xd12[i][10]+xd12[i][11]!= getColSum(xd12)
        ){
            cout<<"not match EE1!\n"<<"i = "<<i<<endl;
            return;
        }
        if(xd12[0][i]+xd12[1][i]+xd12[2][i]+xd12[3][i]+xd12[4][i]+xd12[5][i]+xd12[6][i]+xd12[7][i]
        +xd12[8][i]+xd12[9][i]+xd12[10][i]+xd12[11][i]!= getColSum(xd12)
        ){
            cout<<"not match EE2!\n"<<"i = "<<i<<endl;
            return;
        }
    }
    int sum1 = 0;
    int sum2 = 0;
    for(int i = 0;i < 12;i++){
        sum1 += xd12[i][i];
        sum2 += xd12[11-i][i];
    }
    if(sum1!= getColSum(xd12)||sum2!= getColSum(xd12)){
        cout<<"not match EE3!\n";
        return;
    }
    cout<<"All Ok!"<<endl;
}
int main() {
    vector< vector<int> > xd12(12);
    vector<int> x2(2);
    int trans;
    for(int i = 0; i < 12;i++){
        xd12[i] = vector<int>(12);
    }
    for(int i = 0; i < 12;i++){
        for(int j = 0; j < 12;j++){
            xd12[i][j] = 12 * i+j+1;
        }
    }
    for(int col = 0; col < 12/2;col++){
        for(int row = 0; row < 12;row++){
            if(isExcell(col,row)){
                x2 = getMirror(col,row);
                trans = xd12[col][row];
                xd12[col][row] = xd12[x2[0]][x2[1]];
                xd12[x2[0]][x2[1]] = trans;
            }
        }
    }
    cout<<"translation right with no error!\n";
    cout<<getColSum(xd12);
    checkxd12(xd12);

    return 0;
}
//推广并不难