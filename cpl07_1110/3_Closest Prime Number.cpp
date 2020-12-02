//PREPEND BEGIN
#include <iostream>
#include <math.h>
using namespace std;
//PREPEND END

//TEMPLATE BEGIN
void find_primes(int, int);
bool test_prime(int);

void find_primes(int p, int n) {
	int d = 0;
	int count = 0;
	int list [100] = {0};
	while (count < n) {
		if (d == 0) {
			if (test_prime(p)) {
//				cout << p << ',';
				list[count] = p;
				count++;
			}
		} else {
			if (test_prime(p - d)) {
//				cout << p - d << ',';
				list[count] = p-d;
				count++;
			}
			if (count >= n) {
				break;
			}
			if (test_prime(p + d)) {
//				cout << p + d << ',';
				list[count] = p+d;
				count++;
			}
		}
		d++;
	}
	for (int i = 0; i < count; i++) {
		for (int i = 0; i < count-1; i++) {
			if (list[i] > list[i+1]) {
				int temp = list[i];
				list[i] = list[i+1];
				list[i+1] = temp;
			}
		}
	}
	for (int i = 0; i < count; i++) {
		cout << list[i] << ',';
	}
}
bool test_prime(int n) {
	if (n > 1) {
		for (int i = 2; i < n; i++) {
			if (n%i == 0) {
				return false;
			}
		}
		return true;
	} else {
		return false;
	}
}
//TEMPLATE END

//APPEND BEGIN
int main(){
	int p, n;
	cin >> p >> n;
	find_primes(p, n);
	return 0;
}
//APPEND END
