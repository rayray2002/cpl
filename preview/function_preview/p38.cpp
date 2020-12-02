#include <iostream>
using namespace std;
void cubeByReference1(int *);
void cubeByReference2(int &);
int main( )
{
	int number = 5;
	cout << "Old value is " << number
	     << endl;
	cubeByReference1(&number);
	cout << "New value is " << number
	     << endl;

	number = 5;
	cout << "Old value is " << number
	     << endl;
	cubeByReference2(number);
	cout << "New value is " << number
	     << endl;

}

void cubeByReference1(int *nPtr)
{
	*nPtr = *nPtr * *nPtr * *nPtr;
}
void cubeByReference2(int &nPtr)
{
	nPtr = nPtr * nPtr * nPtr;
}