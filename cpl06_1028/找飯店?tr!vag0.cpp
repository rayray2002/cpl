//PREPEND BEGIN
#include <iostream>
using namespace std;

int* booking(int, int*);

int main(){
	bool run = true;
	int B, tmp;
	int *p = NULL;
	while(run){
		cin >> B;

		// write data
		p = booking(B, p);

		// checking
		for (int i = 0; i < B; ++i){
			cin >> tmp;
			if (tmp != p[i]){
				cout << "Error!";
				return 0;
			}
		}

		// continue or not
		cin >> run;
	}
	return 0;
}

int* booking(int B, int *pArray)
{
//PREPEND END

//TEMPLATE BEGIN
	delete pArray;
	pArray = new int[B];
	// dynamic memory allocation
	for (int i = 0; i < B; ++i)
		cin >> pArray[i];
	return pArray;
//TEMPLATE END

//APPEND BEGIN
}
//APPEND END