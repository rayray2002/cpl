#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int sum = 1;
        for (int j = 1; j < n; j++) {
            sum = (sum*i)%n;
            cout << setw(3) << sum;
        }
        cout << '\n';
    }
}
