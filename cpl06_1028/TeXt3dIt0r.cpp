#include <iostream>
using namespace std;

int main()
{
	int n, a, b;
	cin >> n;
	char **list;
	list = new char*[n];
	for (int i = 0; i < n; i++) {
		list[i] = new char[101];
		cin >> list[i];
//		cout << list[i] << endl;
	}
	while (cin >> a >> b) {
		int la, lb;
		char *temp;
		for (la = 0; list[a][la]; la++);
		for (lb = 0; list[b][lb]; lb++);
//		cout << la;
		temp = new char[la+1];
		for (int j = 0; j <= la; j++) {
			temp[j] = list[a][j];
		}
		delete list[a];
		list[a] = new char[lb+la+1];
		for (int j = 0; j <= la; j++) {
			list[a][j] = temp[j];
		}
		delete temp;
		for (int j = 0; j <= lb; j++) {
			list[a][la+j] = list[b][j];
		}
//		cout << list[a] << endl;
		for (int j = b; j < n; j++) {
			list[j] = list[j+1];
		}
		n--;
	}
	for (int j = 0; j < n; j++) {
		cout << list[j] << endl;
	}
}