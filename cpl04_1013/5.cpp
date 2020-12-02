#include <iostream>
using namespace std;

int main( ) {
    int n, m, a, first_max, second_max;
    int list[1000000] = {};
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        first_max = 0, second_max = 0;
        for (int j = 0; j < m; j++) {
            cin >> a;
            if (a > second_max) {
                if (a > first_max) {
                    second_max = first_max;
                    first_max = a;
                } else {
                    second_max = a;
                }
            }
        }
        list[i] = second_max;
    }
    for (int i = 0; i < n; i++) {
        cout << list[i] << '\n';
    }
}