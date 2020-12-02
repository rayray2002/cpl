//PREPEND BEGIN
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
//PREPEND END

//TEMPLATE BEGIN
struct Point {
	char name;
	double x, y, z;
};

Point *read_points(int N) {
	Point *arr = new Point[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i].name >> arr[i].x >> arr[i].y >> arr[i].z;
	}
	return arr;
}

double space(Point a, Point b) {
	double d = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
	return d;
}

double space(Point a, Point b, Point c) {
	double s = (space(a, b) + space(c, b) + space(a, c)) / 2;
	double A = sqrt(s * (s - space(a, b)) * (s - space(c, b)) * (s - space(a, c)));
	return A;
}

double det2(double a, double b, double c, double d) {
	return a * d - b * c;
}

double space(Point a, Point b, Point c, Point d) {
	;
	double A[3][3], V;
	A[0][0] = b.x - a.x;
	A[1][0] = c.x - a.x;
	A[2][0] = d.x - a.x;

	A[0][1] = b.y - a.y;
	A[1][1] = c.y - a.y;
	A[2][1] = d.y - a.y;

	A[0][2] = b.z - a.z;
	A[1][2] = c.z - a.z;
	A[2][2] = d.z - a.z;
	double detA = A[0][0] * det2(A[1][1], A[1][2], A[2][1], A[2][2])
	              - A[0][1] * det2(A[1][0], A[1][2], A[2][0], A[2][2])
	              + A[0][2] * det2(A[1][0], A[1][1], A[2][0], A[2][1]);
	V = abs(detA / 6);
	return V;
}
//TEMPLATE END

//APPEND BEGIN
int main() {

	int N, Index1, Index2, Index3, Index4;
	double s, max;
	cin >> N;
	Point *pArray = read_points(N);

	Index1 = Index2 = -1;
	max = -1;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			s = space(pArray[i], pArray[j]);
			if (s > max) {
				max = s;
				Index1 = i;
				Index2 = j;
			}

		}
	}
	cout << "Max Length: Point " << pArray[Index1].name;
	cout << ", " << pArray[Index2].name;
	cout << " and Length = " << fixed << setprecision(4) << max;
	cout << endl;

	Index1 = Index2 = Index3 = -1;
	max = -1;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				s = space(pArray[i], pArray[j], pArray[k]);
				if (s > max) {
					max = s;
					Index1 = i;
					Index2 = j;
					Index3 = k;
				}
			}
		}
	}
	cout << "Max Area: Point " << pArray[Index1].name;
	cout << ", " << pArray[Index2].name;
	cout << ", " << pArray[Index3].name;
	cout << " and Area = " << fixed << setprecision(4) << max;
	cout << endl;

	Index1 = Index2 = Index3 = Index4 = -1;
	max = -1;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				for (int l = k + 1; l < N; l++) {
					s = space(pArray[i], pArray[j], pArray[k], pArray[l]);
					if (s > max) {
						max = s;
						Index1 = i;
						Index2 = j;
						Index3 = k;
						Index4 = l;
					}

				}
			}
		}
	}
	cout << "Max Volume: Point " << pArray[Index1].name;
	cout << ", " << pArray[Index2].name;
	cout << ", " << pArray[Index3].name;
	cout << ", " << pArray[Index4].name;
	cout << " and Volume = " << fixed << setprecision(4) << max;
	cout << endl;

}
//APPEND END