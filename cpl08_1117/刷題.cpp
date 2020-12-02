#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int *raw = new int [n];
	int catagory = 0;
	for(int i = 0; i < n; i++){
		cin >> raw[i];
		if (catagory < raw[i]) catagory = raw[i];
	}
	int *group = new int [catagory];
	for(int i = 0; i < n; i++){
		group[i] = 0;
	}
	for(int i = 0; i < n; i++){
		group[raw[i]-1]++;
	}
	for(int i = 0; i < catagory; i++) {
		cout << group[i];
	}
}