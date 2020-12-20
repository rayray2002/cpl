#include <iostream>

using namespace std;

class Digit {
	int dgt;
public:
	Digit(int nDigit = 0) { dgt = nDigit; }

	Digit &operator++(); // prefix
	Digit operator++(int); // postfix
	int GetDigit() const { return dgt; }
};

Digit &Digit::operator++() {
	if (dgt == 9) dgt = 0;
	else ++dgt;
	return *this;
}

Digit Digit::operator++(int) {
	Digit cResult(dgt);
	++(*this);
	return cResult;
}

int main() {
	Digit cDigit(5);
	++cDigit; // calls Digit::operator++();
	cDigit++; // calls Digit::operator++(int);
}