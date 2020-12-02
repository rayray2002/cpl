#include <iostream>
using namespace std;
void useLocal();
void useStaticLocal();
void useGlobal();

int x = 1;
int main()
{
	int x = 5;
	cout << "local x in main's outer scope is " << x << endl;
	{ // start new scope
		int x = 7;
		cout << "local x in main's inner scope is " << x << endl;
	} // end new scope
	cout << "local x in main's outer scope is " << x << endl;
	useLocal();
	useStaticLocal();
	useGlobal();
	useLocal();
	useStaticLocal();
	useGlobal();
	cout << "\nlocal x in main is " << x << endl;
}

void useLocal( void )
{
//	int x = 25;
	cout << endl << "local x is " << x
	     << " on entering useLocal" << endl;
	++x;
	cout << "local x is " << x
	     << " on exiting useLocal" << endl;

}
void useStaticLocal( void )
{
	static int x = 50;
	cout << endl << "local static x is " << x
	     << " on entering useStaticLocal" << endl;
	++x;
	cout << "local static x is " << x
	     << " on exiting useStaticLocal" << endl;

}

void useGlobal( void )
{
	cout << endl << "global x is " << x
	     << " on entering useGlobal" << endl;
	x *= 10;
	cout << "global x is " << x
	     << " on exiting useGlobal" << endl;

}