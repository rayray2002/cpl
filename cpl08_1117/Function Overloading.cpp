//PREPEND BEGIN
#include<iostream>
using namespace std;
//PREPEND END

//TEMPLATE BEGIN
int my_max_index(const double a[], int length=3){
	// TODO
	double max = -1000;
	int pos = -1;
	for (int i = 0; i < length; i++) {
		if (a[i] >= max) {
			max = a[i];
			pos = i;
		}
	}
	return pos+1;
}

int my_max_index(const double a[], const double b[], int length_a, int length_b){
	// TODO
	double *combine = new double [length_a+length_b];
	for (int i = 0; i < length_a+length_b; i++) {
		if (i < length_a) {
			combine[i] = a[i];
		} else {
			combine[i] = b[i-length_a];
		}
//		cout << combine[i] << endl;
	}
	double max = -1000;
	int pos = -1;
	for (int i = 0; i < length_a+length_b; i++) {
		if (combine[i] >= max) {
			max = combine[i];
			pos = i;
		}
	}
	return pos+1;
}

//TEMPLATE END

//APPEND BEGIN
int main(){
	int N_a, N_b;

	cin >> N_a >> N_b;

	double *a = new double[N_a];
	double *b = new double[N_b];

	for(int i = 0; i < N_a ; i++)
		cin >> a[i];
	for(int i = 0; i < N_b ; i++)
		cin >> b[i];
	cout << "Maximum in array [a1,a2,a3] is at position: ";
	cout << my_max_index(a) << endl;
	cout << "Maximum in array [b1,b2,b3] is at position: ";
	cout << my_max_index(b) << endl;
	cout << "Maximum in array a is at position: ";
	cout << my_max_index(a, N_a) << endl;
	cout << "Maximum in array b is at position: ";
	cout << my_max_index(b, N_b) << endl;
	cout << "Maximum in array (a + b) is at position: ";
	cout << my_max_index(a, b, N_a, N_b) << endl;

	delete [] a;
	delete [] b;

	return 0;
}
//APPEND END