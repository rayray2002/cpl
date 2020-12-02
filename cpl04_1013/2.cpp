#include <iostream>
using namespace std;

int main() {
    int a, b;
    int s;
    cin >> a >> b;
//    cout << a << b;
    if (a == 0 || a == 1) {
        a = 2;
    }
    for (int i = a; i < b; i++) {
//        cout << i;
        s = 0;
        for (int j = 2; j < i; j++) {
            if (i%j == 0) {
                s = 1;
            }
        }
        if (s == 0) {
            cout << i << ", ";
        }
    }
    return 0;
}
