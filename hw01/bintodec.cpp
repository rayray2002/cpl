#include <iostream>
using namespace std;
int main()
{
	int n, ans = 0, sign;
	char bin[65] = {0};
	cin >> n >> bin;
	sign = bin[0];
	for (int i = 1; bin[i]; i++) {
		ans += bin[i]-'0';
		ans <<= 1;
	}
	cout << ans;
}

