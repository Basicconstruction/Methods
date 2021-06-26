#include <iostream>
#include <ctime>
#include <Windows.h>
#include <cmath>
using namespace std;

int main() {
    clock_t begin1,begin2;
    clock_t end1,end2;
    double sum = 0;
    long sumTime1 = 0;
    long sumTime2 = 0;
    for(int j = 0;j < 10;j++){
        begin1 = clock();
        for(long long i = 1;i < 1000000;i++){
            sum += (i*3+pow(i,3));
        }
        end1 = clock();
        cout<<sum<<endl;
        sum = 0;
        sumTime1 += end1 - begin1;
    }
    for(int j = 0;j < 10;++j){
        begin2 = clock();
        for(long long i = 1;i < 1000000;++i){
            sum += (i*3+pow(i,3));
        }
        end2 = clock();
        cout<<sum<<endl;
        sum = 0;
        sumTime2 += end2 - begin2;
    }

    cout<<sumTime1<<"ms"<<endl<<sumTime2<<"ms";
}
https://ferrolho.github.io/blog/2019-01-26/how-to-install-julia-on-ubuntu
