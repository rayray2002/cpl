//PREPEND BEGIN
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//PREPEND END
//TEMPLATE BEGIN
bool similarity(const double a[], const double b[], double &result, int n = 2) {
	bool equal = true;
	double sab = 0, sa = 0, sb = 0;
	for (int i = 0; i < n; i++) {
		sab += a[i] * b[i];
		sa += a[i]*a[i];
		sb += b[i]*b[i];
		if (a[i] != b[i]) equal = false;
	}
	result = sab / sqrt(sa * sb);
	return equal;
}

bool similarity(const char a[], const char b[], double &result, int n = 2) {
	bool equal = true;
	double count = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			equal = false;
		} else {
			count++;
		}
	}
	result = count/n;
	return equal;
}

//TEMPLATE END
//APPEND BEGIN
int main() {
	int N;
	cin >> N;
	auto *vec_A = new double[N];
	auto *vec_B = new double[N];
	char *str_A = new char[N + 1];
	char *str_B = new char[N + 1];
	for (int i = 0; i < N; ++i)
		cin >> vec_A[i];
	for (int i = 0; i < N; ++i)
		cin >> vec_B[i];
	cin >> str_A;
	cin >> str_B;
	double vec_result = 0.0;
	double str_result = 0.0;
	bool vec_equal = similarity(vec_A, vec_B, vec_result);
	bool str_equal = similarity(str_A, str_B, str_result);
	cout << "The first two elements of two double arrays are ";
	cout << (vec_equal ? "" : "not ") << "matched.\n";
	cout << "The first two elements of two char arrays are ";
	cout << (str_equal ? "" : "not ") << "matched.\n";
	cout << "Similarity between the first two elements of two double arrays is ";
	cout << fixed << setprecision(2) << vec_result << ".\n";
	cout << "Similarity between the first two elements of two char arrays is ";
	cout << fixed << setprecision(2) << str_result << ".\n";
	cout << endl;
	vec_result = 0.0;
	str_result = 0.0;
	vec_equal = similarity(vec_A, vec_B, vec_result, N);
	str_equal = similarity(str_A, str_B, str_result, N);
	cout << "Two double arrays are " << (vec_equal ? "" : "not ") <<
	     "identical.\n";
	cout << "Two char arrays are " << (str_equal ? "" : "not ") <<
	     "identical.\n";
	cout << "Similarity between two double arrays is ";
	cout << fixed << setprecision(2) << vec_result << ".\n";
	cout << "Similarity between two char arrays is ";
	cout << fixed << setprecision(2) << str_result << "." << endl;
	delete[] vec_A;
	delete[] vec_B;
	delete[] str_A;
	delete[] str_B;
	return 0;
}
//APPEND END