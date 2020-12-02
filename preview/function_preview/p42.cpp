#include <iostream>
using namespace std;
void printArray(const int[][3], int size);
int main( )
{
	int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
	int b[2][3] = {1, 2, 3, 4, 5};
	int c[2][3] = {{1, 2}, {4}};
	cout << "Values in array a by row are:" << endl;
	printArray(c, 2);
}
void printArray(const int a[][3], int size)
{
	for (int i=0;i<size;i++) {
		for (int j=0;j<3;j++)
			cout << a[i][j] << ' ';
	}
	cout << endl;
}