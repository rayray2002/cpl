#include <iostream>
#include <cstdlib>
#include <ctime>
#define io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;

inline bool check_input(const char input[]) {
	int len;
	for(len = 0; input[len]; len++);
	if (len != 4) {
		cout << "Wrong input length. Please enter again.\n";
		return false;
	}
	for(int i = 0; i < 4; i++) {
		if (input[i] > '9' || input[i] < '0') {
			cout << "Illegal character detected. Please enter again.\n";
			return false;
		}
	}
	for(int i = 0; i < 3; i++) {
		for(int j = i+1; j < 4; j++) {
			if (input[i] == input[j]) {
				cout << "Duplicate digit detected. Please enter again.\n";
				return false;
			}
		}
	}
	return true;
}
inline bool guessing(char ans[5]) {
	int counter = 0;
	while (true) {
		cout << "Please enter your guess number :\n";
		char guess[100];
		int n = 0, m = 0;
		do {
			cin >> guess;
		} while (not(check_input(guess)));

		for (int i = 0; i < 4; i++) {
			if (guess[i] == ans[i]) {
				n++;
			}
		}
		for(int i = 0; i < 4; i++) {
			for(int j = 0; j < 4; j++) {
				if (guess[i] == ans[j] && i != j) {
					m++;
				}
			}
		}
		counter++;
		cout << "Hint " << counter << " : " << n << "A" << m << "B\n";
		if (n == 4) {
			cout << "Correct! You only guessed for " << counter << " times.";
			return true;
		}
		if (counter == 7) {
			cout << "You lose this game! QQ\nThe correct answer is : " << ans << endl;
			return false;
		}
	}
}
int main()
{
	io
	int mode;
	char input[100];
	cout << "Please choose mode. 1 - random, 2 - user input, 3 - accessibility :\n";
	cin >> mode;
	switch (mode) {
		case 1:
			srand(time(nullptr));
			do {
				for (int i = 0; i < 4; i++) {
					input[i] = rand()%10 + '0';
				}
			} while (not(check_input(input)));
			guessing(input);
			break;
		case 2:
			cout << "Please enter correct answer :\n";
			do {
				cin >> input;
			} while (not(check_input(input)));
			guessing(input);
			break;
		case 3:
			cout << "Please enter the number of your guesses, your guess number and the results :\n";
			char guess[5], c;
			int n_i, m_i, num, n, m;
			cin >> num;

			int index = 0;
			char all[5040][5];
			for (int i = 0; i < 10000; i++) {
				char to_char[5];
				for (int j = 0; j < 4; j++) {
					to_char[j] = (i/(int)pow(10, j))%10 + '0';
				}
				bool legal = true;
				for(int k = 0; k < 3; k++) {
					for(int j = k+1; j < 4; j++) {
						if (to_char[k] == to_char[j]) {
							legal =  false;
						}
					}
				}
				if (legal) {
					for (int j = 0; j < 5; j++) all[index][j] = to_char[j];
					index++;
				}
			}

			for (int i = 0; i < num; i++) {
				cin >> guess >> n_i >> c >> m_i >> c;
//				cout << guess << n_i << m_i << endl;
				for (int j = 0; j < 5040; j++) {
					int n = 0; m = 0;
					for (int k = 0; k < 4; k++) {
						if (guess[k] == all[j][k]) {
							n++;
						}
					}
					for(int k = 0; k < 4; k++) {
						for(int l = 0; l < 4; l++) {
							if (guess[k] == all[j][l] && k != l) {
								m++;
							}
						}
					}
					if (n != n_i || m != m_i) {
						for (int k = 0; k < 4; k++) all[j][k] = 0;
					}
				}
			}

			int count = 0;
			for (int j = 0; j < 5040; j++) {
				if (all[j][0] != 0) {
//					cout << all[j] << endl;
					count++;
				}
			}
			cout << count;
			break;
	}
}