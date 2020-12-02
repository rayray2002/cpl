//PREPEND BEGIN
#include <iostream>

using namespace std;

void func(int &);

int main(){
	int N;
	cin >> N;
	func(N);
	cout << N;
	return 0;
}
//PREPEND END

//TEMPLATE BEGIN
void func(int &n){
	if (n <= 1) {
		n = 0;
	} else {
		int k = n / 2;
		func(k);
		n = k + 1;
	}
	// TODOs

	// if n <= 1:
	//   n = 0
	// else:
	//   generate integer k, let k = n / 2
	//   put k into func()
	//   let n = 1 + k
}
//TEMPLATE END

//APPEND BEGIN
//APPEND END