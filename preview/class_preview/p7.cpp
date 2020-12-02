#include <iostream>
using namespace std;
struct record {
	char sex;
	int age;
	double height, weight;
};

int main( )
{
	record John;
	John.sex = 'M';
	John.age = 25;
	John.height = 179.5;
	John.weight = 70;
	record Mary = {'F', 23, 160, 50};
	cout << "John's age is " << John.age << " years old" << endl;
}