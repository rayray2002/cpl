#include <iostream>
#include <ctime>
using namespace std;
unsigned long fibonacci(int number) {
	if (number == 0) return 0; unsigned long u=0, v=1, t; for (int i=2; i<=number; i++) {
		t = u + v; u = v;
		v = t;
	}
	return v; }
int main() {
	clock_t t = clock();
	for (int c = 0; c <= 10; c++)
		cout << "fibonacci( " << c << " ) = " << fibonacci(c) << endl;
	t = clock() - t;
	cout << "\nCalculation time: " << t << " ticks ("
	     << ((float)t)/CLOCKS_PER_SEC << " seconds)" << endl;
}