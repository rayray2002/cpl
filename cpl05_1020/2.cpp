#include <iostream>
using namespace std;

int main()
{
    int strlen, targetlen;
    cin >> strlen >> targetlen;

    char *str, *target;
    str = new char [strlen];
    target = new char [targetlen];
    for (int i = 0; i < strlen; i++) {
        cin >> str[i];
    }
    for (int i = 0; i < targetlen; i++) {
        cin >> target[i];
    }
    for (int i = 0; i < strlen; i++) {
        if (str[i] == target[0]) {
            int check = 1;
            for (int j = 0; j < targetlen; j++) {
                if (str[i+j] != target[j]) {
                    check = 0;
                }
            }
            if (check) {
                cout << i;
            }
        }
    }
    delete str;
	delete target;
}
