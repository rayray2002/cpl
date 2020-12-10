//PREPEND BEGIN
#include <iostream>

using namespace std;

enum color_code {
	Black, Brown, Red, Orange, Yellow,
	Green, Blue, Purple, Gray, White,
	Gold, Silver, None
};
//PREPEND END

//TEMPLATE BEGIN
class Resistor {
private:
	bool valid;
	color_code code[4] = {None, None, None, None};
public:
	bool setValue(color_code a, color_code b, color_code c, color_code d) {
		if (a < 1 || a > 9) return false;
		if (b < 0 || b > 9) return false;
		if (c < 0 || c > 11) return false;
		if (d < 1 || d == 3 || d == 4 || d == 9 || d > 11) return false;
		code[0] = a;
		code[1] = b;
		code[2] = c;
		code[3] = d;
		return true;
	}

	void display_color() {
		for (int i = 0; i < 4; i++) {
			switch (code[i]) {
				case Black:
					cout << "Black";
					break;
				case Brown:
					cout << "Brown";
					break;
				case Red:
					cout << "Red";
					break;
				case Orange:
					cout << "Orange";
					break;
				case Yellow:
					cout << "Yellow";
					break;
				case Green:
					cout << "Green";
					break;
				case Blue:
					cout << "Blue";
					break;
				case Purple:
					cout << "Purple";
					break;
				case Gray:
					cout << "Gray";
					break;
				case White:
					cout << "White";
					break;
				case Gold:
					cout << "Gold";
					break;
				case Silver:
					cout << "Silver";
					break;
				default:
					cout << "None";
					break;
			}
			if (i != 3) cout << " | ";
		}
		cout << endl;
	}

	void display_value() {
		// TODO
		if (code[2] == Gold) {
			cout << code[0] << '.' << code[1];
		} else if (code[2] == Silver) {
			cout << "0." << code[0] << code[1];
		} else {
			cout << code[0] << code[1];
			for (int i = 0; i < code[2]; i++) cout << '0';
		}
		cout << " +/-";
		switch (code[3]) {
			case Brown:
				cout << "1%";
				break;
			case Red:
				cout << "2%";
				break;
			case Green:
				cout << "0.5%";
				break;
			case Blue:
				cout << "0.25%";
				break;
			case Purple:
				cout << "0.1%";
				break;
			case Gray:
				cout << "0.05%";
				break;
			case Gold:
				cout << "5%";
				break;
			case Silver:
				cout << "10%";
				break;
		}
		cout << endl;
	}
};
//TEMPLATE END

//APPEND BEGIN
int main() {
	Resistor R;
	int a, b, c, d;
	do {
		cin >> a >> b >> c >> d;
	} while (!(R.setValue(static_cast<color_code>(a), \
                        static_cast<color_code>(b), \
                        static_cast<color_code>(c), \
                        static_cast<color_code>(d))));

	R.display_color();
	R.display_value();

	return 0;
}
//APPEND END
