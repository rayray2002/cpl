//PREPEND BEGIN
#include <iostream>

using namespace std;

class Complex {
protected:
	double re;
	double im;
public:
	Complex() : re(0), im(0) {}

	Complex(double a, double b) : re(a), im(b) {}

	Complex operator+(const Complex &);

	Complex operator||(const Complex &);

	friend istream &operator>>(istream &input, Complex &c);

	friend ostream &operator<<(ostream &output, Complex &c);
};

class Resistor : public Complex {
public:
	Resistor() {
		re = 0;
		im = 0;
	}

	Resistor(double r) {
		re = r;
		im = 0;
	}

	friend istream &operator>>(istream &, Resistor &);
};

class Capacitor : public Resistor {
private:
	double C;
	double w;
public:
	Capacitor() : C(0), w(0) {}

	Capacitor(double Cin, double win) : C(Cin), w(win) { compute(); }

	void compute();

	friend istream &operator>>(istream &, Capacitor &);
};

class Inductor : public Resistor {
private:
	double L;
	double w;
public:
	Inductor() : L(0), w(0) {}

	Inductor(double Lin, double win) : L(Lin), w(win) { compute(); }

	void compute();

	friend istream &operator>>(istream &, Inductor &);
};

//PREPEND END

//TEMPLATE BEGIN
Complex Complex::operator+(const Complex &complex) {
	double new_re = re + complex.re;
	double new_im = im + complex.im;
	Complex _new(new_re, new_im);
	return _new;
}

Complex Complex::operator||(const Complex &complex) {
	double new_re = ((re * complex.im + im * complex.re) * (im + complex.im) +
	                 (re * complex.re - im * complex.im) * (re + complex.re)) /
	                ((re + complex.re) * (re + complex.re) + (im + complex.im) * (im + complex.im));
	double new_im = ((re * complex.im + im * complex.re) * (re + complex.re) -
	                 (re * complex.re - im * complex.im) * (im + complex.im)) /
	                ((re + complex.re) * (re + complex.re) + (im + complex.im) * (im + complex.im));
	Complex _new(new_re, new_im);
	return _new;
}

ostream &operator<<(ostream &output, Complex &c) {
	output << noshowpos;
	if (c.re) output << c.re << showpos;
	if (c.im) output << c.im << "i";
	if (!c.re && !c.im) output << 0;
	output << '\n';
	return output;
}

istream &operator>>(istream &input, Complex &c) {
	input >> c.re >> c.im;
	return input;
}

istream &operator>>(istream &input, Resistor &R) {
	input >> R.re;
	R.im = 0;
	return input;
}

void Capacitor::compute() {
	re = 0;
	im = -1 / (w * C);
}

istream &operator>>(istream &input, Capacitor &c) {
	input >> c.C >> c.w;
	c.compute();
	return input;
}

void Inductor::compute() {
	im = w * L;
	re = 0;
}

istream &operator>>(istream &input, Inductor &I) {
	input >> I.L >> I.w;
	I.compute();
	return input;
}
//TEMPLATE END

//APPEND BEGIN
int main() {
	Complex Zeq, Zeq2, Zeq3, Zeq4;
	Resistor r1(3), r2(4), r3(5), r4, r5;
	Capacitor zC(0.00003, 10000), zC2;
	Inductor zL(0.1, 10000), zL2;
	Zeq = (r1 || r2 || r3);
	Zeq2 = (zC + zL);
	cout << Zeq << Zeq2;

	cin >> r4 >> zC2;
	Zeq3 = r4 + zC2;
	cout << Zeq3;

	cin >> r5 >> zL2;
	Zeq4 = r5 || zL2;
	cout << Zeq4;
	return 0;
}
//APPEND END