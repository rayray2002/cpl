#include <iostream>
using namespace std;
void printArray(int[], int);
int main( )
{
	const int N = 5;
	int a[N] = {1, 2, 3, 4, 5};

	cout << "Values in array a by row are:" << endl;
	printArray(a, N);
}

void printArray(int a[], int size)
{
	for (int i=0;i<size;i++)
		cout << a[i] << ' ';

	cout << endl;
}