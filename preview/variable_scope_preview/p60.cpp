#include <iostream>
using namespace std;
double max_value(double);
int main( )
{
	double num, max=-1;

	while (1)
	{
		cout << "Enter any positive number; negative value to stop: ";
		cin >> num;
		cout<< "old max=" << max << "\tinput number=" << num;
		if (num<=0) break;
		else max = max_value(num);
		cout<< "\tnew max=" << max <<endl;
	}
}

double max_value(double num)
{
	static double max=-1;

	max = (num>max) ? num : max;

	return max;
}