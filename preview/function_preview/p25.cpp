#include <iostream>
#include <ctime>
using namespace std;
unsigned long fibonacci(int);
int main() {
	clock_t t = clock();
	for (int c = 0; c <= 10; c++)
		cout << "fibonacci( " << c << " ) = "
		     << fibonacci(c) << endl;
	t = clock() - t;
	cout << "\nCalculation time: " << t << " ticks ("
	     << ((float)t)/CLOCKS_PER_SEC << " seconds)" << endl;
}
unsigned long fibonacci(int number) {
	if (number <= 1)
		return number;
	else
		return fibonacci(number-1) + fibonacci(number-2);
}