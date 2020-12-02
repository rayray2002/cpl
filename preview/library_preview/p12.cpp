#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;
int num_of_primes (int n) {
	int i,j,freq=n-1;
	for (i=2; i<=n; ++i) for (j=sqrt(i);j>1;--j)
			if (i%j==0) {--freq; break;}
	return freq;
}

int main ()
{
	clock_t t = clock();
	cout << "Number of primes <=100,000 is " << num_of_primes(99999);
	t = clock() - t;
	cout << "\nCalculation time: " << t << " ticks ("
	     << ((float)t)/CLOCKS_PER_SEC << " seconds)" << endl;

}