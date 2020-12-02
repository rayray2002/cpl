#include <iostream>
using namespace std;
int main()
{
	int i = 6;
	char c = 'a';
	void *p;
	p = &i;
	cout << "Value of i is " << *(int*)p << endl;

	p = &c;
	cout << "Value of c is " << *(char*)p << endl;

	cout << p << endl;
	cout << (void*)&c;
}