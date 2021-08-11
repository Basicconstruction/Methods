
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
long long int convertStringToLong(string s){
    long long int x = 0;
    for(unsigned int i=0; i<s.length();i++){
        x *= 10;
        x += static_cast<int>(s[i]-48);
    }
    return x;
}