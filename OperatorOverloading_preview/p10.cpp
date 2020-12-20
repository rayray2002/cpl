#include <iostream>

using namespace std;

class rational {
	friend ostream &operator<<(ostream &, const rational &);

	friend istream &operator>>(istream &, rational &);

public:
	rational(int x = 0, int y = 1) {
		n = x;
		d = y;
	}

	rational operator+(const rational &);

	rational operator*(const rational &);

	rational operator/(const rational &);

private:
	int n, d;
};

ostream &operator<<(ostream &, const rational &);

istream &operator>>(istream &, rational &);

rational rational::operator+(const rational &y) {
	rational z;
	z.n = n * y.d + d * y.n;
	z.d = d * y.d;
	return z;
}

rational rational::operator*(const rational &y) {
	rational z;
	z.n = n * y.n;
	z.d = d * y.d;
	return z;
}

rational rational::operator/(const rational &y) {
	rational z;
	z.n = n * y.d;
	z.d = d * y.n;
	return z;
}

ostream &operator<<(ostream &output, const rational &r) {
	output << r.n << "/" << r.d;
	return output;
}

istream &operator>>(istream &input, rational &r) {
	char c;

	do {
		input >> r.n;
		input >> c;
		input >> r.d;
	} while (c != '/' || r.d == 0);

	return input;
}

int main() {
	rational a, b, c, d, e;

	cout << "Please enter a=";
	cin >> a;
	cout << "Please enter b=";
	cin >> b;

	c = a + b;
	d = a * b;
	e = a / b;

	cout << a << " + " << b << " = " << c << endl;
	cout << a << " * " << b << " = " << d << endl;
	cout << a << " / " << b << " = " << e << endl;
}