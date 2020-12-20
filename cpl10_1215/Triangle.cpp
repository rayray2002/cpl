//PREPEND BEGIN
#include <iostream>
#include <cmath>

using namespace std;

class Point {
public:
	Point();//Construct a point located at the Origin(0, 0).
	Point(int x, int y);//Construct a point (x, y)
	int getX();//Return x;
	int getY();//Return y;
	void print();//Print the location as (x,y)
private:
	int x;
	int y;
};

class Triangle {
private:
	Point V[3];
public:
	Triangle(Point, Point, Point);

	~Triangle(); //destructor
	void enlarge(int r);//according to the Origin(0, 0)
	double getArea();

	void print();//in format as (1,1)(2,3)(3,2)
};


int main() {
	int x[3], y[3];
	for (int i = 0; i < 3; ++i) { cin >> x[i] >> y[i]; }
	Point p1(x[0], y[0]);
	Point p2(x[1], y[1]);
	Point p3(x[2], y[2]);
	Triangle t1 = Triangle(p1, p2, p3);
	Triangle t2 = t1; //copy constructor
	t1.enlarge(3);
	cout << "t1: ";
	t1.print();
	cout << endl;
	cout << "t1.getArea() = " << t1.getArea() << endl;
	cout << "t2: ";
	t2.print();
	cout << endl;
	cout << "t2.getArea() = " << t2.getArea() << endl;
	return 0;
}

//PREPEND END
//TEMPLATE BEGIN
Point::Point() {
	x = 0;
	y = 0;
}

Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
}

int Point::getX() {
	return x;
}

int Point::getY() {
	return y;
}

void Point::print() {
	cout << "(" << x << ", " << y << ")";
}

Triangle::Triangle(Point a, Point b, Point c) {
	V[0] = a;
	V[1] = b;
	V[2] = c;
}

Triangle::~Triangle() {}

void Triangle::enlarge(int r) {
	for (int i = 0; i < 3; i++) {
		int nx, ny;
		nx = V[i].getX() * r;
		ny = V[i].getY() * r;
		Point new_point(nx, ny);
		V[i] = new_point;
	}
}

double Triangle::getArea() {
	return 0.5 * abs((V[0].getX() * V[1].getY() +
	                   V[1].getX() * V[2].getY() +
	                   V[2].getX() * V[0].getY()) -
			                  V[1].getX() * V[0].getY() -
			                  V[2].getX() * V[1].getY() -
			                  V[0].getX() * V[2].getY());
}

void Triangle::print() {
	for (int i = 0; i < 3; i++) V[i].print();
}
//TEMPLATE END
//APPEND BEGIN
//APPEND END