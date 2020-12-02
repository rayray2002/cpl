#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int **p;
    p = new int*[n+1];
    for (int i = 0; i < n+1; i++) {
        p[i] = new int[n+1];
        for (int j = 0; j < n+1; j++) {
            p[i][j] = 0;
        }
    }

    for (int i = 0; i < k; i++) {
        int a, b, c;
        char x;
        cin >> a >> x >> x >> b >> x >> x >> c;
        p[b][a] = c;
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                if (j == 0) {
                    cout << setw(3) << ' ';
                } else {
                    cout << setw(3) << j;
                }
            } else {
                if (j == 0) {
                    cout << setw(3) << i;
                } else {
                    if (p[j][i] == 0) {
                        cout << setw(3) << '-';
                    } else if (p[j][i] == 1) {
                        cout << setw(3) << 'o';
                    } else if (p[j][i] == -1) {
                        cout << setw(3) << 'x';
                    }
                }
            }
        }
        cout << '\n';
    }
    for (int i = 0; i < n+1; i++) {
        delete p[i];
    }
    delete p;
    return 0;
}