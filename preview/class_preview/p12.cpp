#include <iostream>
using namespace std;
enum color {red=1, green, blue=4};

int main() {
	color a = red;
	if (a == red) a = blue;
//	cout << red;
	cout << (red | green);
}