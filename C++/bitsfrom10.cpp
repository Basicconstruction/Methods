#include <iostream>
using namespace std;
string addPre(string s, int a){
    char s2;
    if(a>=0&&a<=9){
        s2 = static_cast<char>(a + 48);
    }else{
        s2 = static_cast<char>((static_cast<int>('a'))+a - 10);
    }
    return s2+s;
}
string bitsFrom10(int input10, int bits){
    bool sign = false;
    if(input10<0){
        sign = true;
        input10 = -input10;
    }
    int trans = 0;
    int trans2 = 0;
    string output = "";
    while(input10/bits>0){
        trans = input10 / bits;
        trans2 = input10 % bits;
        output = addPre(output, trans2);
        input10 = trans;
    }
    output = addPre(output, input10);
    if(sign){
        output = "-"+output;
    }
    return output;
}
int main() {
    int input10;
    cin>>input10;
    int dataN;
    cin>>dataN;
    std::cout<<bitsFrom10(input10, dataN).c_str();
    return 0;
}
