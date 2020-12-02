//PREPEND BEGIN
#include <iostream>
using namespace std;

int num_of_ways(int);

int main()
{
	int N;
	cin >> N;
	cout << num_of_ways(N) << endl;
}
int num_of_ways(int N){
//PREPEND END

//TEMPLATE BEGIN
	static int num = 0;
	static int time = -1;
	static int *method = NULL;
	if (method == NULL) {
		method = new int [12];
		for (int i = 0; i < 12; i++) {
			method[i] = 0;
		}
	}
	time++;
	switch(N) {
		case 0:
			for (int i = 0; i < time-1; i++) {
				cout << method[i] << ' ';
			}
			cout <<  method[time-1] << endl << time << endl;
			num++;
			break;
		case 1:
			method[time] = 1;
			num_of_ways(0);
			break;
		case 2:
			method[time] = 1;
			num_of_ways(1);
			method[time] = 2;
			num_of_ways(0);
			break;
		case 3:
			method[time] = 1;
			num_of_ways(2);
			method[time] = 2;
			num_of_ways(1);
			method[time] = 3;
			num_of_ways(0);
			break;
		default:
			method[time] = 1;
			num_of_ways(N-1);
			method[time] = 2;
			num_of_ways(N-2);
			method[time] = 3;
			num_of_ways(N-3);
			break;
	}
	time--;
	return num;
//TEMPLATE END

//APPEND BEGIN
}
//APPEND END