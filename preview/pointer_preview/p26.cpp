#include <iostream>
using namespace std;
int main( )
{
    char s1[10] = {'H','E','L','L','O'};
    char *s2 = "Hello";

    for (int i=0; (s1[i]=s2[i])!='\0'; i++);
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;

    s1[0] = 'h';
    cout << "s1 = " << s1 << endl;
// s2[0] = 'h'; // wrong
    cout << "s1:" << sizeof(s1) << "\ns2:" << sizeof(*s2) << endl;
}