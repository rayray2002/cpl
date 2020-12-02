//PREPEND BEGIN
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	char _binary[16];
	char _float[6];

	for (int i = 0; i < 16; ++i)
		cin >> _binary[i];

	for (int i = 0; i < 6; ++i)
		cin >> _float[i];
//PREPEND END

//TEMPLATE BEGIN
	// TODOs
	// binary format to float format.
	//convert to int
	int binary[16];
	for (int i = 0; i < 16; i++) {
		binary[i] = _binary[i]-'0';
	}

	//calc exponent
	int exponent = 0;
	int int_temp = 1;
	for (int i = 5; i >= 1; i--) {
		exponent += binary[i] * int_temp;
		int_temp *= 2;
	}
//	cout << exponent << endl;

	//calc fraction
	double fraction = 0;
	double float_temp = 1;
	int max_fraction = -1;
	for (int i = 6; i <= 15; i++) {
		float_temp /= 2;
		fraction += binary[i] * float_temp;
		if (binary[i]) {
			max_fraction = i - 7;
		}
	}
//	cout << fraction << endl;

	//calc exponent value
	float_temp = 1;
	if (exponent-15 > 0) {
		for (int i = 0; i < exponent-15; i++) {
			float_temp *= 2;
		}
	} else {
		for (int i = 0; i > exponent-15; i--) {
			float_temp /= 2;
		}
	}
	double exponent_value = float_temp;

	//int check
	bool integer = false;
	if (exponent-15 > max_fraction) {
		integer = true;
	}

	//calc result
	double float_value;
	int int_value;
	if (binary[0]) {
		float_value = -1*(1+fraction)*exponent_value;
	} else {
		float_value = (1+fraction)*exponent_value;
	}
	int_value = float_value;

	//calc int part digit
	int int_len = 0;
	int_temp = 1;
	if (int_value >= 10) {
		while (int_temp < int_value) {
			int_temp *= 10;
			int_len++;
		}
	} else {
		int_len = 1;
	}
//	cout << int_len << endl;

	//output
	if (_binary == "0000000000000000") {
		cout << "0" << endl;
	} else if (_binary == "1000000000000000") {
		cout << "-0" << endl;
	} else if (float_value > 65504) {
		cout << "infinity" << endl;
	} else if (float_value < -65504) {
		cout << "-infinity" << endl;
	} else if (integer) {
		cout << int_value << endl;
	} else {
		cout << setprecision(int_len+30) << float_value << endl;
	}


	for (int i = 0; i < 16; i++) {
		binary[i] = 0;
	}


	// float format to binary format.
	//convert input
	bool sign = false;
	binary[0] = 0;
	int point_pos;
	for (int i = 0; i < 6; i++) {
		if (_float[i] == '-') {
			sign = true;
			binary[0] = 1;
		} else if (_float[i] == '.') {
			point_pos = i;
		}
	}
	int int_part = 0;
	int_temp = 1;
	for (int i = point_pos-1; i >= 0; i--) {
		if (_float[i] != '-') {
			int_part += int_temp * (_float[i] - '0');
		}
		int_temp *= 10;
	}
	double fraction_part = 0;
	float_temp = 1;
	for (int i = point_pos+1; i <= 5; i++) {
		float_temp /= 10;
		fraction_part += float_temp * (_float[i]-'0');
	}
	int int_raw = int_part;
	double fraction_raw = fraction_part;
//	cout << int_part << endl << fraction_part << endl;

	//int convert
	int digit = 0;
	int_temp = 1;
	if (int_part >= 2) {
		while (int_temp < int_part) {
			int_temp *= 2;
			digit++;
		}
	} else {
		digit = 1;
	}
	exponent = digit + 14;
//	cout << digit << endl;

	int index = 6;
	bool start = false;
	for (int i = digit-1; i >= 0; i--) {
		if (start) {
			binary[index] = (int_part>>i)&1;
			index++;
		} else {

			if (((int_part>>i)&1) == 1) {
				start = true;
			}
		}
	}

	//fraction convert
	for (int i = index; i <= 15; i++) {
		binary[index] = fraction_part * 2;
		fraction_part = fraction_part*2 - binary[index];
	}

	//exponent convert
	for (int i = 5; i >= 1; i--) {
		binary[i] = exponent % 2;
		exponent /= 2;
	}

	//output
	if (int_raw == 0 && fraction_raw == 0) {
		if (binary[0]) {
			cout << 1000000000000000 << endl;
		} else {
			cout << 0000000000000000 << endl;
		}
	} else {
		for (int i = 0; i < 16; i++) {
			cout << binary[i];
		}
	}
	cout << endl;
//TEMPLATE END

//APPEND BEGIN
	return 0;
}
//APPEND END