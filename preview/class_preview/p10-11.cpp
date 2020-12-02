#include <iostream>
using namespace std;

struct rational {
	int n;
	int d;
};
rational rplus(rational, rational);
rational rmultiply(rational, rational);
rational rdivide(rational, rational);

int main( )
{
	rational a={4, 6}, b={2, 3};
	rational c, d, e;

	c = rplus(a, b);
	d = rmultiply(a, b);
	e = rdivide(a, b);
	cout<<a.n<<"/"<<a.d<<"+"<<b.n<<"/"<<b.d<<"="<<c.n<<"/"<<c.d<<endl;
	cout<<a.n<<"/"<<a.d<<"*"<<b.n<<"/"<<b.d<<"="<<d.n<<"/"<<d.d<<endl;
	cout<<a.n<<"/"<<a.d<<"/"<<b.n<<"/"<<b.d<<"="<<e.n<<"/"<<e.d<<endl;
	cout<<c.n/c.d;
}
rational rplus(rational x, rational y) {
	rational z;
	z.n = x.n*y.d + x.d*y.n;
	z.d = x.d*y.d;
	return z;
}

rational rmultiply(rational x, rational y) {
	rational z;
	z.n = x.n*y.n;
	z.d = x.d*y.d;
	return z;
}

rational rdivide(rational x, rational y) {
	rational z;
	z.n = x.n*y.d;
	z.d = x.d*y.n;
	return z;
}