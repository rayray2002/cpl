#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		int num, k;
		cin >> num;
		k = num%10;
		if (num == 0) {
			cout << 1 << endl;
		} else if (k == 0 || k == 1 || k == 5 || k == 6) {
			cout << k << endl;
		}
		else {
			int out;
			out = pow(k, num%4+4);
			cout << out%10 << endl;
		}
	}
	return 0;
}
