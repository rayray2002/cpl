#include <iostream>

using namespace std;

int main() {

	int N, K, row, col, ans;

	int** arr;

	//TEMPLATE BEGIN
	cin >> N;
	arr = new int*[N];
	for (int i = 0; i < N; i++) {
		cin >> K;
		arr[i] = new int[K];
		for (int j = 0; j < K; j++) {
			cin >> arr[i][j];
		}
	}

	cin >> row >> col;
	ans = 0;
	for (int i = 0; i < col; i++) {
		ans += arr[row-1][i];
	}
	//TEMPLATE END

	cout << ans;

	for (int i = 0; i < N; i++) {

		delete[] arr[i];

	}

	delete[] arr;

	return 0;

}
