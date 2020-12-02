#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int **input_a, **input_b, **a;
	input_a = new int *[n];
	input_b = new int *[n];
	a = new int *[n];
	for (int i = 0; i < n; i++) {
		input_a[i] = new int[n];
		input_b[i] = new int[n];
		a[i] = new int[n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> input_a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> input_b[i][j];
		}
	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cout << input_a[i][j];
//		}
//		cout << endl;
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cout << input_b[i][j];
//		}
//		cout << endl;
//	}

	int max_overlap = 0;
	for (int dy = -(n-1); dy <= n-1; dy++) {
		for (int dx = -(n-1); dx <= n-1; dx++) {
			int overlap = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (i-dy >= 0 && i-dy <= n-1 && j-dx >= 0 && j-dx <= n-1) {
						a[i][j] = input_a[i-dy][j-dx];
					} else {
						a[i][j] = 0;
					}
					if (a[i][j] == input_b[i][j] && a[i][j] == 1) {
						overlap ++;
					}
				}
			}
			if (overlap > max_overlap) {
				max_overlap = overlap;
			}
//			cout << "dx=" << dx << " dy=" << dy << endl;
//			for (int i = 0; i < n; i++) {
//				for (int j = 0; j < n; j++) {
//					cout << a[i][j];
//				}
//				cout << endl;
//			}
		}
	}
	for (int i = 0; i < n; i++) {
		delete input_a[i];
		delete input_b[i];
		delete a[i];
	}
	delete input_a;
	delete input_b;
	delete a;

	cout << max_overlap << endl;
}