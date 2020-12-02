//PREPEND BEGIN
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	char _binary[16];
	char _float[6] = {48};

	for (int i = 0; i < 16; ++i)
		cin >> _binary[i];

	for (int i = 0; i < 6; ++i)
		cin >> _float[i];
//PREPEND END

//TEMPLATE BEGIN
	// TODOs
	// binary format to float format.
	int binary[16];
	for (int i = 0; i < 16; ++i) {
		binary[i] = _binary[i] - 48;
//		cout << binary[i];
	}
	int exponent = 0;
	for (int i = 1; i <= 5; i++) {
		int temp = 1;
		for (int j = 0; j < 5-i; j++) {
			temp *= 2;
		}
		exponent += temp * binary[i];
	}
//	cout << exponent;

	long double fraction = 0;
	int max_fraction = 0;
	for (int i = 6; i <= 15; i++) {
		long double temp = 1;
		for (int j = 0; j > 5-i; j--) {
			temp = temp/2;
		}
		fraction += temp * binary[i];
		max_fraction = 5 - i;
	}
//	cout << max_fraction;
	bool integer = false;
	if (exponent - 15 + max_fraction > 0) {
		integer = true;
	}
//	cout << integer;

	long double float_ans, exponent_value = 1;
	int int_ans;
	if (exponent - 15 >= 0) {
		for (int j = 0; j < exponent - 15; j++) {
			exponent_value *= 2;
		}
	} else {
		for (int j = 0; j > exponent - 15; j--) {
			exponent_value /= 2;
		}
	}
	if (binary[0]) {
		float_ans = -1 * (1 + fraction) * exponent_value;
	} else {
		float_ans = 1 * (1 + fraction) * exponent_value;
	}
//	cout << float_ans;
	int_ans = float_ans*10;
	if (int_ans%10 >= 5) {
		int_ans = float_ans + 1;
	} else {
		int_ans = float_ans;
	}
//	cout << int_ans << endl;
	int bit = -1;
	if (int_ans >= 0) {
		for (int i = 1; i < 16; i++) {
			int temp = 1;
			for (int j = 0; j < i; j++) {
				temp *= 10;
			}
			if (temp >= int_ans) {
				bit = i;
				break;
			}
		}
	} else {
		int_ans *= -1;
		for (int i = 1; i < 16; i++) {
			int temp = 1;
			for (int j = 0; j < i; j++) {
				temp *= 10;
			}
			if (temp >= int_ans) {
				bit = i;
				break;
			}
		}
		int_ans *= -1;
	}
//	cout << bit << endl;

	if (fraction == 0 && exponent == 0) {
		if (binary[0] == 0) {
			cout << "0" << endl;
		} else {
			cout << "-0" << endl;
		}
	} else if (float_ans > 65504) {
		cout << "infinity" << endl;
	} else if (float_ans < -65504) {
		cout << "-infinity" << endl;
	} else {
		if (integer) {
			cout << int_ans << endl;
		} else {
			cout << setprecision(bit + 30) << float_ans << endl;
		}
	}





	// float format to binary format.
	int sign = 0, decimal_point = 0;
	for (int i = 0; i < 6; i++) {
		if (_float[i] == '-') {
			sign = 1;
		} else if (_float[i] == '.') {
			decimal_point = i;
		}
	}

	int int_num = 0;
	long double fraction_num = 0;
	for (int i = 0; i < decimal_point; i++) {
		if (_float[i] != '-') {
			int temp = 1;
			for (int j = 0; j < decimal_point - i - 1; j++) {
				temp *= 10;
			}
			int_num += temp * (_float[i] - 48);
		}
	}
	for (int i = decimal_point+1; i < 6; i++) {
		long double temp = 1;
		for (int j = 0; j > decimal_point - i; j--) {
			temp /= 10;
		}
		fraction_num += temp * (_float[i]-48);
	}
//	cout << int_num << fraction_num;

	int binary_digit = 0;
	for (int i = 0; i < 16; i++) {
		int temp = 1;
		for (int j = 0; j < i; j++) {
			temp *= 2;
		}
		if (temp >= int_num) {
			binary_digit = i-1;
			break;
		}
	}
//	cout << binary_digit << endl;

	int binary_raw[50] = {};
	for (int i = binary_digit; i >= 0; i--) {
		binary_raw[binary_digit-i] = (int_num>>i)&1;
//		cout << ((int_num>>i)&1);
	}
//	cout << endl;

	int temp;
	long double fraction_remain = fraction_num;
	for (int i = binary_digit+1; i <= 25; i++) {
		fraction_remain *= 2;
		temp = fraction_remain;
		binary_raw[i] = temp;
		fraction_remain -= temp;
	}

//	for (int i = 0; i < 25; i++) {
//		cout << binary_raw[i];
//		if (i == binary_digit) {
//			cout << '.';
//		}
//	}
//	cout << endl;

	int first_one = 0;
	while (binary_raw[first_one] != 1) {
		first_one += 1;
	}
//	cout << "first one=" << first_one << endl;

	exponent = binary_digit - first_one + 15;
//	cout << "exponent=" << exponent << endl;

	if (binary_raw[first_one + 10] == 1) {
		for (int i = 9; i >= 0; i--) {
			if (binary_raw[i + first_one + 1] == 1) {
				binary_raw[i + first_one + 1] = 0;
			} else {
				binary_raw[i + first_one + 1] = 1;
				break;
			}
		}
	}

	if (int_num == 0 && fraction_num == 0.0) {
		if (sign) {
			cout << "1000000000000000" << endl;
		} else {
			cout << "0000000000000000" << endl;
		}
	} else {
		if (sign) {
			cout << 1;
		} else {
			cout << 0;
		}
		for (int i = 4; i >= 0; i--) {
			cout << ((exponent >> i) & 1);
		}
		for (int i = 0; i < 10; i++) {
				cout << binary_raw[i + first_one + 1];
		}
	}

//TEMPLATE END

//APPEND BEGIN
	return 0;
}
//APPEND END