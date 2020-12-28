#include <iostream>

using namespace std;

class Base {
	int value;
public:
	Base(int nValue) : value(nValue) {}

protected:
	void PrintValue() { cout << "Base: " << value << endl; }
};

class Derived : public Base {
	int value;
public:
	Derived(int nValue) : Base(nValue * 2), value(nValue) {}

//void PrintValue() { cout << "Derived: " << value << endl; }
	using Base::PrintValue;
};

int main() {
	Derived cDerived(7);
	cDerived.PrintValue();
}