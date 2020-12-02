#include <iostream>
using namespace std;
int main( )
{
    int a[5] = {10, 20, 30};
    int *aPtr, *bPtr;

    aPtr = a;
    bPtr = &a[1];
    for (int i = 0; i<5; i++) {
        cout << a[i] << endl;
    }
    cout << "The address of array a is " << a << "\n"
         << "The address of element a[0] is " << &a[0] << endl;
    cout << "The value of aPtr is " << aPtr << "\n"
         << "The value of bPtr is " << bPtr << endl;
    cout << "The value of aPtr[1] is " << aPtr[1] << endl;
    cout << "The value of bPtr[2] is " << bPtr[2] << endl;
    cout << "The value of aPtr[3]+bPtr[1] is " << aPtr[3]+bPtr[1] << endl; // a[3]+a[2]=0+30=30
    int *p = a;
//    cout << "++*p = " << ++*p << '\n'; // ++(*p)=a[0]+1
//    cout << "a[0] = " << a[0] ;
//    p = a;
//    cout << "*++p = " << *++p << '\n'; // *(++p)=a[1]
//    p = a;
    cout << "*p++ = " << *p++ << endl; // *(p++)=a[0]
//    cout << *p;
}