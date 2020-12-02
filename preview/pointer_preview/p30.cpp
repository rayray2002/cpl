#include <iostream>
using namespace std;
int main( )
{
    int osize=10, nsize=20;
    int *p=NULL, *temp=NULL;
    p = new int[osize]; // the original block
    for (int i=0;i<osize;i++) {
        p[i] = i*i;
        cout << p[i] << " ";
    }
    temp = new int[nsize]; // new block for the expanded array
    for (int i=0;i<osize;i++) {
        temp[i] = p[i];
    }
    delete [] p; // deallocate the old block
    p = temp; // point to the new block

    for (int i=osize;i<nsize;i++) {
        p[i] = i;
        cout << p[i] << " ";
    }
    int sum = 0;
    for (int i=0; i<nsize; i++) {
        sum += p[i];
    }
    cout << "\nsum of p = " << sum;
    delete [] p;
}