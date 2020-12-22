//PREPEND BEGIN
#include <iostream>
#include <iomanip>
#include <string>

// uncomment line below if you use dev-c++
//#include <stdint.h>

using namespace std;

// range of uint64_t is 0 ~ 18,446,744,073,709,551,615
// define 10^19-1 as the max value in single element
// which means we can have 19 '9's
// the U added at the end means this is an unsigned number
const uint64_t CARRY = 10000000000000000000ULL;
const uint64_t CARRY_LENGTH = 19U;

class HugeInteger {
public:
	HugeInteger();                     // default constructor
	HugeInteger(const string &s);      // constructor with value
	HugeInteger(const HugeInteger &n); // copy constructor
	~HugeInteger();                    // destructor

//PREPEND END

//TEMPLATE BEGIN
	bool operator<(HugeInteger &n) {
		return !isGreater(n) && !isEqual(n);
	}

	bool operator>(HugeInteger &n) {
		return isGreater(n);
	}

	bool operator==(HugeInteger &n) {
		return isEqual(n);
	}

	bool operator!=(HugeInteger &n) {
		return !isEqual(n);
	}

	bool operator<=(HugeInteger &n) {
		return !isGreater(n);
	}

	bool operator>=(HugeInteger &n) {
		return isGreater(n) || isEqual(n);
	}

	void abs() { _sign = false; } // abs
	void print();                // display the number

private:
	bool _sign; // false for positive ; true for negative
	int64_t _length; // length of data array
	uint64_t *_data; // integer array holding the huge integer
	static int64_t _maxl; // max length of data array in exist HugeInteger(s)

	// helper function
	bool isGreater(HugeInteger &n);

	bool isEqual(HugeInteger &n);

	// increase the length of data array to max length
	void resize();
};

int64_t HugeInteger::_maxl = 1;

HugeInteger::HugeInteger(const HugeInteger &n) {
	_length = n._length;
	_data = new uint64_t[_length];
	for (int i = 0; i < _length; ++i)
		_data[i] = n._data[i];
	_sign = n._sign;
}

//TEMPLATE END

//APPEND BEGIN

HugeInteger::HugeInteger() {
	_length = _maxl;
	_data = new uint64_t[_length];
	for (int i = 0; i < _length; ++i)
		_data[i] = 0;
	_sign = false;
}

HugeInteger::HugeInteger(const string &s) {
	while (s.length() > _maxl * CARRY_LENGTH)
		_maxl <<= 1;
	_length = _maxl;
	_data = new uint64_t[_length];
	for (int i = 0; i < _length; ++i)
		_data[i] = 0;
	if (s.length() == 0) return;
	_sign = (s[0] == '-');
	for (int i = (_sign ? 1 : 0); i < s.length(); ++i) {
		_data[(CARRY_LENGTH * _length + i - s.length()) / CARRY_LENGTH] *= 10;
		_data[(CARRY_LENGTH * _length + i - s.length()) / CARRY_LENGTH] += (uint64_t) ((char) s[i] - '0');
	}
	}

HugeInteger::~HugeInteger() {
	delete[] _data;
}

void HugeInteger::print() {
	bool not_zero = false;
	for (int64_t i = 0; (i < _length && (!not_zero)); ++i)
		not_zero |= _data[i];
	if (!not_zero) {
		cout << '0';
		return;
	}

	cout << (_sign ? "-" : "");
	int64_t iter;
	for (iter = 0; iter < _length; ++iter)
		if (_data[iter] || iter == (_length - 1)) {
			cout << _data[iter];
			break;
		}
	for (++iter; iter < _length; ++iter)
		cout << setw(CARRY_LENGTH) << setfill('0') << _data[iter];
	cout << setfill(' ');
}

bool HugeInteger::isGreater(HugeInteger &n) {
	this->resize();
	n.resize();
	if (_sign != n._sign) {
		for (int i = 0; i < this->_length; ++i)
			if (_data[i] || n._data[i]) return !_sign;
	} else {
		for (int i = 0; i < this->_length; ++i) {
			if (_data[i] > n._data[i]) return !_sign;
			if (_data[i] < n._data[i]) return _sign;
		}
	}
	return false;
}

bool HugeInteger::isEqual(HugeInteger &n) {
	this->resize();
	n.resize();
	if (_sign != n._sign) {
		for (int i = 0; i < this->_length; ++i)
			if (_data[i] || n._data[i]) return false;
	} else {
		for (int i = 0; i < this->_length; ++i)
			if (_data[i] != n._data[i]) return false;
	}
	return true;
}

void HugeInteger::resize() {
	if (_maxl == _length) return;
	uint64_t *temp = _data;
	_data = new uint64_t[_maxl];
	for (int i = 0; i < _maxl - _length; ++i)
		_data[i] = 0;
	for (int i = _maxl - _length; i < _maxl; ++i)
		_data[i] = temp[i + _length - _maxl];
	delete[] temp;
	_length = _maxl;
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	HugeInteger n1(s1);
	HugeInteger n2(s2);
	HugeInteger n3(n1);
	HugeInteger n4(n3);

	cout << "n1: ";
	n1.print();
	cout << endl;
	cout << "n2: ";
	n2.print();
	cout << endl;
	cout << "n3: ";
	n3.print();
	cout << endl;
	cout << "n4: ";
	n4.print();
	cout << endl;

	cout << "-------------------------------" << endl;

	cout << (n3 == n1 ? "n3 == n1" : "n3 != n1") << endl;
	cout << (n4 == n3 ? "n4 == n3" : "n4 != n3") << endl;
	n4.abs();
	cout << (n4 == n3 ? "|n4| == n3" : "|n4| != n3") << endl;

	cout << "-------------------------------" << endl;

	cout << (n1 == n2 ? "n1 == n2" : "") << endl;
	cout << (n1 != n2 ? "n1 != n2" : "") << endl;
	cout << (n1 > n2 ? "n1 > n2" : "") << endl;
	cout << (n1 < n2 ? "n1 < n2" : "") << endl;
	cout << (n1 >= n2 ? "n1 >= n2" : "") << endl;
	cout << (n1 <= n2 ? "n1 <= n2" : "") << endl;

	return 0;
}
//APPEND END