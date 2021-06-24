#include <iostream>
#include <string>
#include <cmath>
#include <stdio.h>
#include <vector>
#include <fstream>
using namespace std;
double getSqrt(double num){
    if(num<0){
        return -1;
    }
    double x,y;
    if(num==0||num==1){
        return num;
    }
    x = 1;
    y = (x + num/x)/2;
    while(abs(y-x)>=0.000001){
        x = y;
        y = (x + num/x)/2;
    }
    return x;
}
long long int convertStringToLong(const string& s){
    cout<<s.length()<<endl;
    long long int x = 0;
    for(int i = 0;i < s.length();i++){
        x *= 10;
        cout<<"i: "<<static_cast<int>(s[i])-48<<endl;
        x += (static_cast<int>(s[i])-48);

    }
    cout<<"x: "<<x<<" ";
    return x;
}
int main() {
    cout<<convertStringToLong("12");
    cout<<"This is a sqrt console!"<<endl;
    cout<<"gfromfileandoutputtofile=>1    ggfromfileandoutputtoconsole=>2"<<endl;
    cout<<"gfromconsoleandoutputtofile=>3    ggfromconsoleandoutputtoconsole=>4"<<endl;
    cout<<"please input the rule\n";
    ofstream outFile("of.txt");
    int rule;
    cin>>rule;
    double x;
    if(rule==4){
        while(true){
            cout<<"please input a number:!\n";
            cin>>x;
            if(x<0){
                return 0;
            }
            cout<<getSqrt(x)<<endl;
        }
    }else if(rule==3){
        vector<double> datas(0);
        while(true){
            cout<<"please input a number:!\n";
            cin>>x;
            if(x<0){
                outFile.close();
                return 0;
            }
            outFile<<getSqrt(x)<<" ";
        }
    }else if(rule==2){
        cout<<"please input the file source\n";
        string ifs;
        cin>>ifs;
        ifstream iff;
        iff.open(ifs);
        cout<<ifs<<endl;
        while(iff >>ifs){
            cout<<ifs<<" ";
            cout<<getSqrt(convertStringToLong(ifs))<<" \n";
        }
        iff.close();
    }else{
        cout<<"please input the file source\n";
        string ifs;
        cin>>ifs;
        ifstream iff;
        iff.open(ifs);
        while(iff>>ifs){
            outFile<<getSqrt(convertStringToLong(ifs))<<" ";
        }
        iff.close();
        outFile.close();
    }
}
/*for(int i = 0;i < s.length();i++){
        if(static_cast<int>(s[i]>0)){
            x *= 10;
            x += (static_cast<int>(s[i])-48);
        }

    }*/