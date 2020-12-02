#include <iostream>
#define endl "\n"
using namespace std;

void hanoi(int N, int i, int j, int k) {
	if (N > 1) {
		hanoi(N - 1, i, k, j);
		cout << i << " -> " << k << endl;
		hanoi(N - 1, j, i, k);
	} else {
		cout << i << " -> " << k << endl;
	}
}
int main()
{
	int N;
	cin >> N;
	hanoi(N, 1, 2, 3);
}