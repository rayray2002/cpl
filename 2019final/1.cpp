#include <iostream>
#define io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;

long long arr(long long a[], const long long c[], const long long &n) {
	long long an = a[n];
	if (n > 2) an = c[2] * arr(a, c, n - 1) + c[1] * arr(a, c, n - 2) + c[0] * arr(a, c, n - 3);
	a[n] = an;
	return an;
}

int main() {
	io
	long long n, c[3], sum = 0;
	cin >> n;
	auto *a = new long long [n];
	cin >> a[0] >> a[1] >> a[2];
	cin >> c[0] >> c[1] >> c[2];
	for (int i = 0; i < n; i++) sum += arr(a, c, i);
	cout << arr(a, c, n - 1) << " " << sum;
	return 0;
}
