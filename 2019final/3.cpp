#include <iostream>
#include <cmath>

#define io cin.tie(0); ios_base::sync_with_stdio(0);
#define endl "\n"
using namespace std;

int func(const int &mode, int n, int i, int j, int k) {
	static int index = 0, dis = 0;
	switch (mode) {
		default:
			if (n == 1) {
				cout << i << " -> " << k << endl;
			} else {
				func(mode, n - 1, i, k, j);
				cout << i << " -> " << k << endl;
				func(mode, n - 1, j, i, k);
			}
			break;
		case 2:
			if (n == 1) {
				index++;
				cout << index<<". "<<i << " -> " << k << endl;
			} else {
				func(mode, n - 1, i, k, j);
				index++;
				cout << index<<". "<<i << " -> " << k << endl;
				func(mode, n - 1, j, i, k);
			}
			break;
		case 3:
			if (n == 1) {
				index++;
				dis+=abs(i-k);
				cout << index<<". "<<i << " -> " << k <<" Dist: "<<dis<< endl;
			} else {
				func(mode, n - 1, i, k, j);
				index++;
				dis+=abs(i-k);
				cout << index<<". "<<i << " -> " << k <<" Dist: "<<dis<< endl;
				func(mode, n - 1, j, i, k);
			}
			break;
	}
	return dis;
}

int main() {
	io
	int mode, n;
	cin >> mode >> n;
	int td = func(mode, n, 1, 2, 3);
	if (mode == 3) cout << "Total Distance: "<<td;
	return 0;
}
