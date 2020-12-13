//PREPEND BEGIN
#include <iostream>
#include <string>

using namespace std;
//PREPEND END

//TEMPLATE BEGIN
class Polynomial {
public:
	// Add any member function if you need.
	Polynomial() = default;

	Polynomial(const int coefficient[], int n) {
		deg = n;
		coefficients = new int[n];
		for (int i = 0; i < n; i++) {
			coefficients[i] = coefficient[i];
		}
	}

	void print() {
		for (int i = deg - 1; i > 1; i--) {
			if (coefficients[i]) cout << showpos << coefficients[i] << "x^" << noshowpos << i;
		}
		if (coefficients[1]) cout << showpos << coefficients[1] << "x";
		if (coefficients[0]) cout << showpos << coefficients[0];
		cout << endl;
	}

	Polynomial add(Polynomial *poly2) {
		int max_deg = deg > poly2->deg ? deg : poly2->deg;
		int min_deg = deg < poly2->deg ? deg : poly2->deg;
		Polynomial sum(new int[max_deg], max_deg);
		for (int i = 0; i < max_deg; i++) {
			if (i < min_deg) {
				sum.coefficients[i] = coefficients[i] + poly2->coefficients[i];
			} else {
				sum.coefficients[i] = deg > poly2->deg ? coefficients[i] : poly2->coefficients[i];
			}
		}
		return sum;
	}

	Polynomial multiply(Polynomial *poly2) {
		int max_deg = deg + poly2->deg - 1;
		Polynomial Q(new int[max_deg], max_deg);

		for (int i = 0; i < max_deg; i++) {
			Q.coefficients[i] = 0;
			for (int j = 0; j <= i; j++) {
				if (j < deg && i - j < poly2->deg) {
					Q.coefficients[i] += coefficients[j] * poly2->coefficients[i - j];
				}
			}
		}

//		Polynomial *partial_sum;
//		for (int i = 0; i < poly2->deg; i++) {
//			partial_sum = new Polynomial(new int[deg + i], deg + i);
//			for (int j = 0; j < i; j++) {
//				partial_sum->coefficients[j] = 0;
//			}
//			for (int j = 0; j < deg; j++) {
//				partial_sum->coefficients[i + j] = coefficients[j] * poly2->coefficients[i];
//			}
//			Q = Q.add(partial_sum);
//			delete partial_sum;
//		}

		return Q;
	}

private:
	// Add any member variable if you need.
	int *coefficients{}, deg{};

};
//TEMPLATE END

//APPEND BEGIN
void test() {
	int n, m;
	int cmds, cmd, pid, pid2;
	int v[4096];
	cin >> n;
	auto *p = new Polynomial[n];
	for (int i = 0; i < n; i++) {
		cin >> m;
		for (int j = 0; j < m; j++)
			cin >> v[j];
		p[i] = Polynomial(v, m);
	}
	cin >> cmds;
	for (int i = 0; i < cmds; i++) {
		cin >> cmd >> pid;
		if (cmd == 1) {
			p[pid].print();
		} else if (cmd == 2) {
			cin >> pid2;
			Polynomial ret = p[pid].add(&p[pid2]);
			ret.print();
		} else if (cmd == 3) {
			cin >> pid2;
			Polynomial ret = p[pid].multiply(&p[pid2]);
			ret.print();
		}
	}
}

int main() {
	test();
	return 0;
}
//APPEND END