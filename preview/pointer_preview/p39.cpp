#include <iostream>
using namespace std;

int main() {
	int a = 0;
	int *const p = &a;
	++(*p);
	*(++p);
	*(p++);
	return 0;
}
