#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	int n, len;
	cin >> n;

	for (int i = 0; i < n; i++) {
		char mode;
		char str[101] = "";
		cin >> setw(101) >> mode >> str;
//		cout << n << mode << str << endl;

		for (len = 0; str[len]; len++);
		len = sqrt(len);
//		cout << len;

		char **arr;
		arr = new char *[len];
		for (int j = 0; j < len; j++) {
			arr[j] = new char [len];
			for (int k = 0; k < len; k++) {
				arr[j][k] = str[j*len+k];
//				cout << arr[j][k];
			}
//			cout << endl;
		}

		char op[10] = "";
		int a[10] = {0}, b[10] = {0}, count = 0;
		cin >> setw(1) >> op[0];
		while (op[count] != 's') {
			cin >> a[count] >> b[count];
			count++;
			cin >> setw(1) >> op[count];
		}
		for (int j = 0; j < count; j++) {
			char *temp;
			temp = new char [len];
			if (mode == 'e') {
//				cout << op[j] << a[j] << b[j] << endl;
				if (op[j] == 'r') {
					temp = arr[a[j]-1];
					arr[a[j]-1] = arr[b[j]-1];
					arr[b[j]-1] = temp;
				} else {
					for (int k = 0; k < len; k++) {
						temp[k] = arr[k][a[j]-1];
						arr[k][a[j]-1] = arr[k][b[j]-1];
						arr[k][b[j]-1] = temp[k];
					}
				}
			} else {
//				cout << op[count-j-1] << a[count-j-1] << b[count-j-1] << endl;
				if (op[count-j-1] == 'r') {
					temp = arr[a[count-j-1]-1];
					arr[a[count-j-1]-1] = arr[b[count-j-1]-1];
					arr[b[count-j-1]-1] = temp;
				} else {
					for (int k = 0; k < len; k++) {
						temp[k] = arr[k][a[count-j-1]-1];
						arr[k][a[count-j-1]-1] = arr[k][b[count-j-1]-1];
						arr[k][b[count-j-1]-1] = temp[k];
					}
				}
			}
//			for (int j = 0; j < len; j++) {
//				for (int k = 0; k < len; k++) {
//					cout << arr[j][k];
//				}
//				cout << endl;
//			}
		}

		for (int j = 0; j < len; j++) {
			for (int k = 0; k < len; k++) {
				cout << arr[j][k];
			}
		}
		cout << endl;
	}
}