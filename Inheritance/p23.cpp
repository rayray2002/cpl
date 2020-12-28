#include <iostream>

using namespace std;

class CPolygon {
protected:
	int width, height;
public:
	void set_values(int a, int b) {
		width = a;
		height = b;
	}

//	virtual int area() { return (0); }
	int area() { return (0); }
};

class CRectangle : public CPolygon {
public:
	int area() { return (width * height); }
};

class CTriangle : public CPolygon {
public:
	int area() { return (width * height / 2); }
};

int main() {
	CRectangle rect;
	CTriangle trgl;
	CPolygon poly;
	CPolygon *ppoly[] = {&rect, &trgl, &poly};
	for (int i = 0; i < 3; i++)
		ppoly[i]->set_values(4, 5);
	for (int i = 0; i < 3; i++)
		cout << ppoly[i]->area() << endl;
}