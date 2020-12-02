//PREPEND BEGIN
#include <iostream>
#include <cmath>

using namespace std;

struct dyad {
	char label;
	double length;
	double x_start;
	double y_start;
	double rad;
	double x_end;
	double y_end;
};

dyad *B = nullptr, *A = nullptr;

void init() {
	// Allocate new memory space
	B = new dyad;
	A = new dyad;

	// input the data
	cin >> B->label >> B->length >> B->x_start >> B->y_start >> B->rad;
	cin >> A->label >> A->length >> A->rad;
}
//PREPEND END

//TEMPLATE BEGIN
void calculate(dyad *r) {
	// TODO 1.
	// update x_end & y_end
	// according to length, x_start, y_start, rad
	r->x_end = r->x_start + r->length * cos(r->rad);
	r->y_end = r->y_start + r->length * sin(r->rad);
}

void clearALL() {
	// TODO 2.
	// delete the memory space and set the pointer to the correct value
	delete A;
	delete B;
}
//TEMPLATE END

//APPEND BEGIN
void output(dyad *r) {
	cout << "dyad " << r->label << ":" << endl;
	cout << "Starting position: (" << r->x_start << ", " << r->y_start << ')' << endl;
	cout << "Ending position: (" << r->x_end << ", " << r->y_end << ')' << endl;
}

int main() {
	int times;
	cin >> times;
	while (times--) {
		init();
		calculate(B);
		A->x_start = B->x_end;
		A->y_start = B->y_end;
		calculate(A);

		output(B);
		output(A);
		clearALL();
	}
	return 0;
}
//APPEND END