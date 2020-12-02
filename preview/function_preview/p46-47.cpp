#include <iostream>
using namespace std;
void rotate(int&, int&);
void rotate(int, int&, int);

int main( )
{
	int a, b, c, d;
	a=1; b=2;
	rotate(a, b);
	cout<<"a="<<a<<" b="<<b<<endl;

	a=1; b=2; c=3;
	rotate(a, b, c);
	cout<<"a="<<a<<" b="<<b<<" c="<<c<<endl;
}

void rotate(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void rotate(int a, int& b, int c)
{
	int temp;
	temp = a;
	a = b;
	b = c;
	c = temp;
}