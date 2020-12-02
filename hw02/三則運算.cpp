#include <iostream>
#define io cin.tie(0); ios_base::sync_with_stdio(0);

using namespace std;

int main()
{
	io
	int n;
	cin >> n;
	int *num;
	char *op;
	num = new int[n];
	op = new char[n-1];
	for (int i = 0; i < n-1; i++) {
		cin >> num[i];
		cin >> op[i];
	}
	cin >> num[n-1];

	for (int i = 0; i < n-1; i++) {
		if (op[i] == '*') {
			num[i+1] = num[i]*num[i+1];
			num[i] = 0;
			if (i) {
				op[i] = op[i-1];
			} else {
				op[i] = '+';
			}
		}
	}
	int sum = num[0];
	for (int i = 0; i < n-1; i++) {
		if (op[i] =='+') {
			sum += num[i+1];
		} else if (op[i] =='-') {
			sum -= num[i+1];
		}
	}
	cout << sum;
}