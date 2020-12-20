#include <iostream>
#include <cstring>

using namespace std;

class Person {
	static int total;
	int id;
	char *name;

public:
	Person() : name(nullptr) { id = ++total; }

	Person(const char *);

	Person &operator=(const Person &p);

	const char *Name() { return name; }

	~Person() { delete[] name; }
};

int Person::total = 0;

Person::Person(const char *tag)
{
	id=++total;
	name = new char[strlen(tag)+1];
	strcpy(name, tag);
}

Person &Person::operator=(const Person &p) {
	if (this != &p) {
		id = p.id;
		delete[] name;
		name = new char[strlen(p.name) + 1];
		strcpy(name, p.name);
	}
	return *this;
}

int main() {
	Person a("John"), b("Noname"), c;
	c = b = a;

	cout << b.Name();
}