#include <iostream>
using namespace std;

int main()
{
	int n;
	char **keys;
	int *count;
	cin >> n;
	keys = new char *[n];
	count = new int [n];
	for (int i = 0; i < n; i++) {
		keys[i] = new char [21];
		count[i] = 0;
		cin >> keys[i];
	}
	char str[1001] = {0};
	cin >> str;
	int j = -1;
	for (int i = 0; str[i-1]||i==0; i++) {
		if (str[i] == '_' || str[i] == 0) {
			for (int a = 0; a < n; a++) {
				bool ident = true;
				int b;
				for(b = 0; keys[a][b]; b++);
				for (int k = j + 1; k < i; k++) {
					if (str[k] != keys[a][k-j-1] || b != i-j-1) {
						ident = false;
						break;
					}
				}
				if(ident) count[a]++;
			}
			j = i;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << keys[i] << " : " << count[i] << endl;
	}
}