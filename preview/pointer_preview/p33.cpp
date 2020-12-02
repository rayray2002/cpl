#include <iostream>
using namespace std;
int main( )
{
    int i,j;
    int a[2][3]={{1,2,3},
                 {4,5,6}};
    int **p=NULL;

    p = new int*[2];
    for (i=0;i<2;i++) {
        p[i] = new int[3];
    }
    for (i=0;i<2;i++) {
        for (j = 0; j < 3; j++) {
            p[i][j] = a[i][j] * a[i][j];
//            cout << p[i][j] << " ";
        }
    }

    for (i=0;i<2;i++) {
        delete [] p[i];
    }
    delete [] p;
}