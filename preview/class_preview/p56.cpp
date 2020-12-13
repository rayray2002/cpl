#include <iostream>
#include <cmath>
#include <cstdlib>
#include "graphics.h"

using namespace std;

class elipso {
	int r;
	const double PI;
	static int count;
public:
	elipso(int x);

	static int get_count() { return count; }
};

int elipso::count = 5;

elipso::elipso(int x) : PI(3.14159) {
	count++;
	r = x / count;
	cout << r << endl;
	circle(rand() % getmaxx(), rand() % getmaxy(), r);
}

int main(int argc, char *argv[]) {
	initwindow(800, 600);
	cleardevice();
	cout << "# of circles before is " << elipso::get_count() << endl;
	elipso *c1 = new elipso(100);
	elipso *c2 = new elipso(100);
	elipso *c3 = new elipso(100);
	cout << "# of circles is " << c1->get_count() << endl;
	delete c1;
	delete c2;
	delete c3;
	cout << "# of circles after is " << elipso::get_count() << endl;
	getch();
	closegraph();
}