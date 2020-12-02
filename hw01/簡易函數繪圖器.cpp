#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double four, three, two, one, zero;
	bool abs_bool;
	cin >> four >> three >> two >> one >> zero >> abs_bool;

	char plot[41][41];
	for (int i=0; i<41; i++) {
		for (int j = 0; j < 41; j++) {
			if (j == 20) {
				if (i == 0) {
					plot[j][i] = '2';
				} else if (i == 10) {
					plot[j][i] = '1';
				} else if (i == 20) {
					plot[j][i] = '0';
				} else if (i == 30) {
					plot[j][i] = '1';
				} else if (i == 40) {
					plot[j][i] = '2';
				} else {
					plot[j][i] = '-';
				}
			} else if (i == 20) {
				if (j == 0) {
					plot[j][i] = '2';
				} else if (j == 10) {
					plot[j][i] = '1';
				} else if (j == 30) {
					plot[j][i] = '1';
				} else if (j == 40) {
					plot[j][i] = '2';
				} else {
					plot[j][i] = '|';
				}
			} else {
				plot[j][i] = ' ';
			}
		}
	}

	double fx, x;
	int y;
	for (int i=0; i<41; i++) {
		x = i;
		x = (x/10)-2;
//		cout << i << x;
		if (abs_bool) {
			fx = abs(four*x*x*x*x + three*x*x*x + two*x*x + one*x + zero);
		} else {
			fx = four*x*x*x*x + three*x*x*x + two*x*x + one*x + zero;
		}
		y = round(-fx*10+20);
		if (y>=0 && y<=40) {
			plot[y][i] = '*';
		}

//		cout << "x=" << x << " f(x)=" << fx << " y=" << y_convert << endl;
//		for (int k=0; k<41; k++) {
//			for (int j = 0; j < 41; j++) {
//				cout << plot[k][j];
//			}
//			cout << endl;
//		}
	}

	for (int k=0; k<41; k++) {
		for (int j = 0; j < 41; j++) {
			cout << plot[k][j];
		}
		cout << endl;
	}
}