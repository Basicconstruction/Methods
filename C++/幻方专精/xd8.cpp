#include <iostream>
#include <vector>
using namespace std;
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
void randAllItems(const vector<vector<int> >& xd8){
    for(const vector<int>& xd:xd8){
        for(int x : xd){
            cout<<tackleSetLength(x)<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void swapVec(vector<vector<int> > &xd8,int one,int another){
    xd8[one].swap(xd8[another]);
}
void checkxd8(vector< vector<int> >& xd8){
    for(int i = 0; i < 8;i++){
        if(xd8[i][0]+xd8[i][1]+xd8[i][2]+xd8[i][3]+xd8[i][4]+xd8[i][5]+xd8[i][6]+xd8[i][7]!=260){
            cout<<"not match EE1!\n"<<"i = "<<i<<endl;
            return;
        }
        if(xd8[0][i]+xd8[1][i]+xd8[2][i]+xd8[3][i]+xd8[4][i]+xd8[5][i]+xd8[6][i]+xd8[7][i]!=260){
            cout<<"not match EE2!\n"<<"i = "<<i<<endl;
            return;
        }
    }
    int sum1 = 0;
    int sum2 = 0;
    for(int i = 0;i < 8;i++){
        sum1 += xd8[i][i];
        sum2 += xd8[7-i][i];
    }
    if(sum1!=260||sum2!=260){
        cout<<"not match EE3!\n";
        return;
    }
}
int main() {
    int y;
    cout<<"what do you want to tackle with? input the data(1) or use the default data(0)!\n";
    cin>>y;
    int again;
    vector< vector<int> > xd8(8);
    if(y==1){
        for(int i = 0; i < 8;i++){
            xd8[i] = vector<int> (8);
            for(int j = 0; j< 8;j++){
                cin>>xd8[i][j];
            }
        }
        cout<<"\n"<<"load is ok!"<<endl;
    }else if(y==0){
        for(int i = 0; i < 8;i++){
            xd8[i] = vector<int> (8);
        }
        xd8[0] = {64,2,3,61,60,6,7,57};
        xd8[1] = {9,55,54,12,13,51,50,16};
        xd8[2] = {17,47,46,20,21,43,42,24};
        xd8[3] = {40,26,27,37,36,30,31,33};
        xd8[4] = {32,34,35,29,28,38,39,25};
        xd8[5] = {41,23,22,44,45,19,18,48};
        xd8[6] = {49,15,14,52,53,11,10,56};
        xd8[7] = {8,58,59,5,4,62,63,1};
    }else{
        for(int i = 0; i < 8;i++){
            xd8[i] = vector<int> (8);
        }
        while(true){
            cout<<"please input the data!\n";
            for(int i = 0; i < 8;i++){
                for(int j = 0; j< 8;j++){
                    cin>>xd8[i][j];
                }
            }
            cout<<"\n"<<"load is ok!"<<endl;
            checkxd8(xd8);
            cout<<"again?\n";
            cin>>again;
            if(!again){
                break;
            }
        }

    }
    char instruct;
    int instructCode1;
    int instructCode2;
    while(true){
        cout<<"please input the instructCode,input 0 to break, or swap the the row by input r n m,\n";
        cout<<"swap the col by input c n m";
        cin>>instruct;
        if(instruct=='0'){
            break;
        }
        if(instruct=='r'){
            cin>>instructCode1>>instructCode2;
            cout<<"row swaped "<<instructCode1<<" "<<instructCode2<<endl;
            swapVec(xd8,instructCode1,instructCode2);
        }else if(instruct=='c'){
            cin>>instructCode1>>instructCode2;
            cout<<"col swaped "<<instructCode1<<" "<<instructCode2<<endl;
            swapVec(xd8,instructCode1,instructCode2);
        }else{
            cout<<"tackle with the default operation: print all the items in the xd8\n";
        }
        randAllItems(xd8);


    }


    randAllItems(xd8);


    return 0;
}
/*
8 58 59 5 4 62 63 1
9 55 54 12 13 51 50 16
17 47 46 20 21 43 42 24
40 26 27 37 36 30 31 33
32 34 35 29 28 38 39 25
41 23 22 44 45 19 18 48
49 15 14 52 53 11 10 56
64 2 3 61 60 6 7 57
row swaped 0 7
64 2 3 61 60 6 7 57
9 55 54 12 13 51 50 16
17 47 46 20 21 43 42 24
40 26 27 37 36 30 31 33
32 34 35 29 28 38 39 25
41 23 22 44 45 19 18 48
49 15 14 52 53 11 10 56
8 58 59 5 4 62 63 1

col swaped 1 6
64 2 3 61 60 6 7 57
49 15 14 52 53 11 10 56
17 47 46 20 21 43 42 24
40 26 27 37 36 30 31 33
32 34 35 29 28 38 39 25
41 23 22 44 45 19 18 48
9 55 54 12 13 51 50 16
8 58 59 5 4 62 63 1

col swaped 2 5
64 2 3 61 60 6 7 57
49 15 14 52 53 11 10 56
41 23 22 44 45 19 18 48
40 26 27 37 36 30 31 33
32 34 35 29 28 38 39 25
17 47 46 20 21 43 42 24
9 55 54 12 13 51 50 16
8 58 59 5 4 62 63 1

















 */