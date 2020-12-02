#include <iostream>
using namespace std;

bool convertandcheck(int n, int base);
int main() {
    int n, c;
    cin >> n >> c;

    int *num;
    num = new int[n];

    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        if (convertandcheck(num[i], 2) && convertandcheck(num[i], c)) {
            sum += num[i];
        }
    }
    cout << sum;
}

bool convertandcheck(int n, int base) {
    int digit = 0, temp = 1;
    if (n >= base) {
        while (temp <= n) {
            temp *= base;
            digit++;
        }
    } else {
        digit = 1;
    }
//    cout << base << "digit=" << digit << endl;

    int *digits;
    digits = new int[digit];
    temp = n;
    for (int i = 0; i < digit; i++) {
        digits[i] = temp%base;
        temp = temp/base;
//        cout << digits[i];
    }
//    cout << endl;

    bool check = 1;
    for (int i = 0; i < digit/2+1; i++) {
        if (digits[i] != digits[digit-i-1]) {
            check = 0;
        }
    }
    delete digits;
    return check;
}

