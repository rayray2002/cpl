#include <iostream>
#include <iomanip>
using namespace std;
int main( )
{
	unsigned char a[4] = {0x46, 0x43, 0xFC, 0x44};
	void *p = a;
	cout << "floating value=" << setprecision(8) << *(float*)p << endl;
	double x = -1313.3131;
	p = &x;
	cout << "byte sequence=";

//	( (unsigned char*)p )[4] = 0;
//	cout << *(float*)p << endl;

	for (int i=7;i>=0;i--)
		cout << hex << uppercase << (int)( (unsigned char*)p )[i] << ' ';
}