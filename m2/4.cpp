//PREPEND BEGIN
#include <iostream>

using namespace std;

char *my_strtok(char *str, char delim) {
//PREPEND END

//TEMPLATE BEGIN
	static int index = -1;
	static char *string = str;
	if (str != nullptr) {
		string = str;
		index = -1;
	}
	int i;
	if (string[index + 1] == 0) return nullptr;
	for (i = index + 1; string[i] != 0; ++i) {
		if (string[i] == delim) break;
	}

	char *out = new char[i - index];
	for (int j = index + 1; j < i; j++) out[j - index - 1] = string[j];
	out[i - index - 1] = 0;
	while (string[i] == delim) i++;
	index = i - 1;

	return out;
//TEMPLATE END

//APPEND BEGIN
}

int main() {
	char str1[50000];
	char delim1;
	int N = 0;

	char str2[50000];
	char delim2;
	char *token;

	//---------- first round! ----------
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> str1[i];
	str1[N] = '\0';
	cin >> delim1;

	/* get the first token */
	token = my_strtok(str1, delim1);

	/* walk through other tokens */
	while (token != nullptr) {
		cout << token << endl;
		token = my_strtok(nullptr, delim1);
	}

	//---------- second round! ----------
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> str2[i];
	str2[N] = '\0';
	cin >> delim2;

	token = my_strtok(str2, delim2);
	while (token != nullptr) {
		cout << token << endl;
		token = my_strtok(nullptr, delim2);
	}

	return 0;
}
//APPEND END