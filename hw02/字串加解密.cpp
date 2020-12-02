#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
void rotate(char , int , int , char **, int);
int main()
{
	int n, len;
	cin >> n;

	for (int i = 0; i < n; i++) {
		char mode;
		char str[101] = "";
		cin >> setw(101) >> mode >> str;

		for (len = 0; str[len]; len++);
		len = sqrt(len);

		char **arr;
		arr = new char *[len];
		for (int j = 0; j < len; j++) {
			arr[j] = new char [len];
			for (int k = 0; k < len; k++) {
				arr[j][k] = str[j*len+k];
			}
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
			if (mode == 'e') {
				rotate(op[j], a[j], b[j], arr, len);
			} else {
				rotate(op[j], a[count-j-1], b[count-j-1], arr, len);
			}
		}

		for (int j = 0; j < len; j++) {
			for (int k = 0; k < len; k++) {
				cout << arr[j][k];
			}
			delete arr[j];
		}
		cout << endl;
		delete arr;
	}
}
 void rotate(char op, int a, int b, char **arr, int len) {
	char *temp;
	temp = new char [len];
	if (op == 'r') {
		temp = arr[a-1];
		arr[a-1] = arr[b-1];
		arr[b-1] = temp;
	} else {
		for (int k = 0; k < len; k++) {
			temp[k] = arr[k][a-1];
			arr[k][a-1] = arr[k][b-1];
			arr[k][b-1] = temp[k];
		}
	}
}