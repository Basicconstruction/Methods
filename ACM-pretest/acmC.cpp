#include <iostream>
#include <stdio.h>
using namespace std;

class Pointer {
public:
    int *arr;
    int l;

    Pointer(int _len) {
        this->l = _len;
        arr = new int[l];
    }

    void printArray() {
        for (int i = 0; i < l - 1; i++) {
            cout << arr[i] << " ";
        }
        cout << arr[l - 1] << "\n";
    }
};

void generateTri(int cols) {
    if (cols == 1) {
        cout << "1\n";
        return;
    }
    if (cols == 2) {
        cout << "1\n1 1\n";
        return;
    }
    cout << "1\n1 1\n";
    Pointer x = Pointer(2);
    x.arr[0] = 1;
    x.arr[1] = 1;
    Pointer y = Pointer(3);
    for (int i = 3; i <= cols; i++) {
        y = NULL;
        y = Pointer(i);
        y.arr[0] = 1;
        y.arr[i - 1] = 1;
        for (int k = 1; k < i - 1; k++) {
            y.arr[k] = x.arr[k] + x.arr[k - 1];
        }
        y.printArray();
        x = y;
    }
}

int main() {
    int line;
    while (scanf("%d", &line) != EOF) {
        generateTri(line);
        cout<<endl;
    }
    return 0;
}