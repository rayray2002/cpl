//PREPEND BEGIN
#include <iostream>
#include <iomanip>
#include <string>

// uncomment line below if you use dev-c++
#include <cstdint>

using namespace std;

// range of uint64_t is 0 ~ 18,446,744,073,709,551,615
// define 10^19-1 as the max value in single element
// which means we can have 19 '9's
// the U added at the end means this is an unsigned number
const uint64_t CARRY = 10000000000000000000U;
const uint64_t CARRY_LENGTH = 19U;
int max_length = 1; // max length of data array in exist HugeInteger(s)

class HugeInteger {
public:
	HugeInteger();                     // default constructor
	HugeInteger(string &s);      // constructor with value
	~HugeInteger();                    // destructor

	void resize(); // double the length of data array

	//HugeInteger addition(HugeInteger& n);  //   add
	//HugeInteger subtraction(HugeInteger& n); // minus

	bool isGreaterThan(HugeInteger &n); // >

	void input(string &s); // input a number
	void print();                // display the number

private:
	bool _sign; // false for positive ; true for negative
	int _length; // length of data array
	uint64_t *data; // integer array holding the huge integer
};

//PREPEND END

//TEMPLATE BEGIN

HugeInteger::HugeInteger() {
	// TODO 1
	_length = max_length;
	data = new uint64_t[_length];
	for (int i = 0; i < _length; i++) data[i] = 0;
	_sign = false;
}

HugeInteger::HugeInteger(string &s) {
	_length = max_length;
	data = new uint64_t[_length];
	_sign = false;
	input(s);
}

HugeInteger::~HugeInteger() {
	// TODO 2
	delete data;
}

void HugeInteger::resize() {
	if (max_length == _length) return;
	uint64_t *temp = data;
	data = new uint64_t[max_length];
	for (int i = 0; i < max_length - _length; ++i)
		data[i] = 0;
	for (int i = max_length - _length; i < max_length; ++i)
		data[i] = temp[i + _length - max_length];
	delete[] temp;
	_length = max_length;
	return;
}

void HugeInteger::input(string &s) {
	while (s.length() > max_length * CARRY_LENGTH)
		max_length <<= 1;
	_length = max_length;
//	delete[] data;
	// TODO 3
	_sign = false;
	data = new uint64_t[_length];
	if (s[0] == '-') _sign = true;
	for (int i = _length - 1; i >= 0; i--) {
		data[i] = 0;
		for (int j = 18; j >= 0; j--) {
			if (s.length() > (_length - i - 1) * 19 + j) {
				if (s.length() - (_length - i - 1) * 19 - j - 1 != 0 || s[0] != '-') {
					data[i] += s[s.length() - (_length - i - 1) * 19 - j - 1] - '0';
				}
			}
			if (j) data[i] *= 10;
		}
	}
//	for (int i = 0; i < _length; i++) {
//		cout << i << ' ' << data[i] << endl;
//	}
	return;
}

void HugeInteger::print() {
	// TODO 4
	bool is_zero = true;
	for (int i = 0; i < _length; i++) {
		if (data[i]) is_zero = false;
	}
	if (is_zero) {
		cout << 0;
		_sign = false;
		return;
	}

	is_zero = true;
	if (_sign) cout << '-';
	for (int i = 0; i < _length; i++) {
		if (data[i] || !is_zero) {
			if (is_zero) {
				cout << data[i];
			} else {
				cout << setfill('0') << setw(19) << data[i];
			}
			is_zero = false;
		}
	}
	if (is_zero) cout << 0;
	// hint: you will need setw(), setfill('0'), and controll cout carefully.
	return;
}

bool HugeInteger::isGreaterThan(HugeInteger &n) {
	this->resize();
	n.resize();
	// TODO 5
	bool flag = false;
	if (_sign && !n._sign) return false;
	if (!_sign && n._sign) return true;
	if (!_sign && !n._sign) {
		for (int i = 0; i < _length; i++) {
			if (data[i] > n.data[i]) flag = true;
		}
	} else {
		for (int i = 0; i < _length; i++) {
			if (data[i] < n.data[i]) flag = true;
		}
	}
	return flag;
}
//TEMPLATE END

//APPEND BEGIN
int main() {
	string s1, s2;
	cin >> s1 >> s2;
	HugeInteger n1;
	n1.input(s1);
	HugeInteger n2(s2);
	HugeInteger n3;
	n3.input(s2);

	n1.print();
	cout << endl;
	n2.print();
	cout << endl;
	n3.print();
	cout << endl;

	n3.input(s1);
	n3.print();
	cout << endl;

	cout << (n1.isGreaterThan(n2) ? "Yes" : "No") << endl;

	return 0;
}
//APPEND END
