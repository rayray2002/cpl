#include <iostream>
using namespace std;

int main()
{
    int *f, *g, *ans;
    int degf, degg, deg;
    cin >> degf >> degg;
    deg = max(degf, degg);
    f = new int[degf+1];
    g = new int[degg+1];
    ans = new int[degg+1];

    for(int i = degf; i >= 0; i--) {
        cin >> f[i];
    }
    for(int i = degg; i >= 0; i--) {
        cin >> g[i];
    }

    int start = 0;
    for(int i = deg; i >= 0; i--) {
        ans[i] = f[i] - g[i];
        if (ans[i]) {
            start = 1;
        }
        if (start) {
            cout << ans[i] << ",";
        }
    }
}
