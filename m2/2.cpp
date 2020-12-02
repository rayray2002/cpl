#include <iostream>
#include <iomanip>

using namespace std;

double det2(double a, double b, double c, double d) {
	return a * d - b * c;
}

int main() {
	auto **A = new double *[3];
	for (int i = 0; i < 3; i++) {
		A[i] = new double[3];
		cin >> A[i][0] >> A[i][1] >> A[i][2];
	}
	double detA = A[0][0] * det2(A[1][1], A[1][2], A[2][1], A[2][2])
	              - A[0][1] * det2(A[1][0], A[1][2], A[2][0], A[2][2])
	              + A[0][2] * det2(A[1][0], A[1][1], A[2][0], A[2][1]);
	cout << fixed << setprecision(2) << "Determinant of A:\n" << setw(10) << detA << "\nInverse of A:\n";
	if (detA == 0) {
		cout << "No answer!\n";
	} else {
		auto **Ai = new double *[3];
		for (int i = 0; i < 3; i++) {
			Ai[i] = new double[3];
		}
		Ai[0][0] = det2(A[1][1], A[1][2], A[2][1], A[2][2]) / detA;
		Ai[0][1] = -det2(A[0][1], A[0][2], A[2][1], A[2][2]) / detA;
		Ai[0][2] = det2(A[0][1], A[0][2], A[1][1], A[1][2]) / detA;

		Ai[1][0] = -det2(A[1][0], A[1][2], A[2][0], A[2][2]) / detA;
		Ai[1][1] = det2(A[0][0], A[0][2], A[2][0], A[2][2]) / detA;
		Ai[1][2] = -det2(A[0][0], A[0][2], A[1][0], A[1][2]) / detA;

		Ai[2][0] = det2(A[1][0], A[1][1], A[2][0], A[2][1]) / detA;
		Ai[2][1] = -det2(A[0][0], A[0][1], A[2][0], A[2][1]) / detA;
		Ai[2][2] = det2(A[0][0], A[0][1], A[1][0], A[1][1]) / detA;

		for (int i = 0; i < 3; i++) {
			A[i] = new double[3];
			cout << fixed << setprecision(2) << setw(10) << Ai[i][0] << setw(10) << Ai[i][1] << setw(10) << Ai[i][2]
			     << endl;
		}
	}
	return 0;
}
