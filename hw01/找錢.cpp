#include <iostream>
#include <iomanip>
#define endl '\n'
using namespace std;

int change(int, int, int, int*, int*, int);
int main()
{
	int num, value;
	cin >> num >> value;
	int *type;
	type = new int[num];
	int *stack;
	stack = new int[1000];
	for (int i = num-1; i >= 0; i--) {
		cin >> type[i];
	}
	change(0, value, num, type, stack, 0);
}

int change(int index, int money, int num, int *type, int *stack, int len) {
	int sol = 0;
	for (int i = index; i < num; i++) {
		int remain = money-type[i];
		if (remain > 0) {
			stack[len] = type[i];
			len++;
			change(i, remain, num, type, stack, len);
		} else if (remain == 0) {
			stack[len] = type[i];
			len++;
			for (int i = 0; i < len; i++) {
				cout << stack[i] << ' ';
			}
			cout << endl;
			delete stack;
			stack = new int [1000];
		}
	}
	return 0;
}