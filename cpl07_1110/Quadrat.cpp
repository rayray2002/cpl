#include <iostream>
#include <cmath>
using namespace std;

long long pow10(int n);
int* check(int array[], int digit, int d);
int main() {
	int time;
	cin >> time;
	for (int i=0; i<time; i++) {
		int n, d, count = 0;
		cin >> n >> d;

		long long range = pow10(n);
		int *current;
		current = new int [0];
		int *previous;
		for (int digit=1; digit<n; digit++) {
			for (long long j = 0; j < pow10(digit+1); j++) {
				long long square = j * j;
				long long trail = square % range;
				bool accept = true;

				for (int k = 0; k < n; k++) {
					int trail_digit = (trail / pow10(k)) % 10;
					int j_digit = (j / pow10(k)) % 10;
					if (trail_digit - j_digit > d && j_digit + 10 - trail_digit > d) {
						accept = false;
						break;
					}
					if (j_digit - trail_digit > d && trail_digit + 10 - j_digit > d) {
						accept = false;
						break;
					}
				}
				if (accept) {
					cout << digit << ' ' << j << endl;
				}
			}
		}
	}
}

long long pow10(int n) {
	long long range = 1;
	if (n == 0) {
		return range;
	} else {
		for (int i = 0; i < n; i++) {
			range *= 10;
		}
	}
	return range;
}

int* check(int array[], int digit, int d) {

}