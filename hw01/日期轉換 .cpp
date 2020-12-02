#include <iostream>
using namespace std;
//1/1/1 Sun
int check_leap(int y);

int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int y, m, d, delta = 0, error = 0;
        char c;
        cin >> y >> c >> m >> c >> d;
//        cout << "year=" << y << " month=" << m << " date=" << d << endl;
        for (int j=1; j<y; j++) {
            if (check_leap(j)) {
                delta += 366;
            } else {
                delta += 365;
            }
        }
        int ans2 = 0;
        for (int j=1; j<m; j++) {
            if (j == 2) {
                if (check_leap(y)) {
                    ans2 += 29;
                } else {
                    ans2 += 28;
                }
            } else if (j==1 || j==3 || j==5 || j==7 || j==8 || j==10 || j==12) {
                ans2 += 31;
            } else {
                ans2 += 30;
            }
        }
        ans2 += d;
        delta += ans2;
        int ans1 = delta%7;
        if (m<1 || m>12) {
            error = 1;
        }
        if (ans2<1 || ans2>366) {
            error = 1;
        }
        if (m == 2) {
            if (check_leap(y)) {
                if (d<1 || d>29) {
                    error = 1;
                }
            } else {
                if (d<1 || d>28) {
                    error = 1;
                }
            }
        } else if (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) {
            if (d<1 || d>31) {
                error = 1;
            }
        } else {
            if (d<1 || d>30) {
                error = 1;
            }
        }
        if (not error) {
            switch (ans1) {
                case (1) :
                    cout << "Mon ";
                    break;
                case (2) :
                    cout << "Tue ";
                    break;
                case (3) :
                    cout << "Wed ";
                    break;
                case (4) :
                    cout << "Thu ";
                    break;
                case (5) :
                    cout << "Fri ";
                    break;
                case (6) :
                    cout << "Sat ";
                    break;
                case (0) :
                    cout << "Sun ";
                    break;
            }
            cout << ans2 << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
int check_leap(int y){
    if (y%400 == 0) {
        return 1;
    } else if (y%100 == 0) {
        return 0;
    } else if (y%4 == 0) {
        return 1;
    } else {
        return 0;
    }
}