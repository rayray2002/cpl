//PREPEND BEGIN
#include <iostream>
using namespace std;
int main() {
//PREPEND END

//TEMPLATE BEGIN
    int n[3];
    cin >> n[0] >> n[1] >> n[2];

    int max = 0;
    for (int i = 0; i < 3; i++) {
        if (n[i] > max) {
            max = n[i];
        }
    }

    int max_factor = max;
    while (not(n[0]%max_factor == 0 && n[1]%max_factor == 0 && n[2]%max_factor == 0)) {
        max_factor--;
    }
    cout << max_factor << endl;

//TEMPLATE END

//APPEND BEGIN
    return 0;
}
//APPEND END