#include <iostream>
using namespace std;
class Pointer{
public:
    long long arr[49];
    int l;
    Pointer(int _l){
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 2;
        arr[3] = 3;
        arr[4] = 5;
        for(int i = 5; i <=49;i++){
            arr[i] = arr[i-1]+arr[i-2];
        }
        this->l = _l;
    }
};
// void tackle(int&start, int&ending){
//     int difference;
//     if(start % 2 == 0){
//         difference = start - 2;
//         start = 2;
//         ending = ending - difference;
//     }else{
//         difference = start - 1;
//         start = 1;
//         ending = ending - difference;
//     }
// }
long long getWays(int on, int on2, Pointer* x){
    // if(on%2==0){
    //     on = on -1;
    //     on2 = on2-1;
    // }
    return x->arr[on2-on];
}
int main() {
    int N;
    cin>>N;
    int start;
    int ending;
    auto* x = new Pointer(0);
    for(int i = 0; i < N;i++){
        cin>>start>>ending;
        // tackle(start, ending);
        cout<<getWays(start, ending, x)<<endl;
    }
    return 0;
}
/*(这个(如果取消注释代码块中的注释代码))并不是最简化的代码，实际上蜜蜂行进方式至于两点的标志之差有关*/
/*tackle()函数以传引用的方式修改start 和 ending的值，使数据全部转化为1-n和2-n的形式, 这个是最一般的思路，毕竟不论怎么变，这种转换方法不会错，至于 自奇数到偶数，自偶数到奇数
自奇数到奇数，自偶数到偶数如何变化，暂且不管*/
/*进一步操作我们发现实际上 蜜蜂行进方式至于两点的标志之差有关 于是我们只需传入 差值即可，
*/