#include <iostream>
using namespace std;
int main( )
{
    int *vPtr, *cPtr;
    int v[5];

    vPtr = &v[0];
    cout << vPtr << endl;
    vPtr ++;
    cout << vPtr << endl;
    cPtr = &v[0] + 3; //v[3]
    cout << &cPtr[1] << ',' << &v[4] << endl;

}