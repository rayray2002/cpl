#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    long double a[2][2], a_t[2][2], a_i[2][2];
    long double b[2], b_p[2];
    cin >> a[0][0] >> a[0][1] >> a[1][0] >> a[1][1] >> b[0] >> b[1];

    a_t[0][0] = a[0][0];
    a_t[0][1] = a[1][0];
    a_t[1][0] = a[0][1];
    a_t[1][1] = a[1][1];

    cout << "Transpose Matrix of A:" << '\n';
    cout << setw(10) << fixed << setprecision(2) << a_t[0][0];
    cout << setw(10) << a_t[0][1] << '\n';
    cout << setw(10) << a_t[1][0];
    cout << setw(10) << a_t[1][1] << endl;

    long double det = a[0][0]*a[1][1] - a[0][1]*a[1][0];
    cout << "Inverse Matrix of A:" << '\n';
    if (det != 0) {
        a_i[0][0] = a[1][1] / det;
        a_i[0][1] = a[0][1] / det * -1;
        a_i[1][0] = a[1][0] / det * -1;
        a_i[1][1] = a[0][0] / det;
        cout << setw(10) << fixed << setprecision(2) << a_i[0][0];
        cout << setw(10) << a_i[0][1] << '\n';
        cout << setw(10) << a_i[1][0];
        cout << setw(10) << a_i[1][1] << endl;
    } else {
        cout << "No answer!" << '\n';
    }

    long double ata[2][2], ata_i[2][2], atatai[2][2], a_p[2][2];
    cout << "Project b on A:" << '\n';
    ata[0][0] = a_t[0][0]*a[0][0] + a_t[0][1]*a[1][0];
    ata[0][1] = a_t[0][0]*a[0][1] + a_t[0][1]*a[1][1];
    ata[1][0] = a_t[1][0]*a[0][0] + a_t[1][1]*a[1][0];
    ata[1][1] = a_t[1][0]*a[0][1] + a_t[1][1]*a[1][1];

    long double det_ata = ata[0][0]*ata[1][1] - ata[0][1]*ata[1][0];
    if (det_ata != 0) {
        ata_i[0][0] = ata[1][1] / det_ata;
        ata_i[0][1] = ata[0][1] / det_ata * -1;
        ata_i[1][0] = ata[1][0] / det_ata * -1;
        ata_i[1][1] = ata[0][0] / det_ata;

        atatai[0][0] = a_t[0][0]*ata_i[0][0] + a_t[0][1]*ata_i[1][0];
        atatai[0][1] = a_t[0][0]*ata_i[0][1] + a_t[0][1]*ata_i[1][1];
        atatai[1][0] = a_t[1][0]*ata_i[0][0] + a_t[1][1]*ata_i[1][0];
        atatai[1][1] = a_t[1][0]*ata_i[0][1] + a_t[1][1]*ata_i[1][1];

        a_p[0][0] = atatai[0][0]*a[0][0] + atatai[0][1]*a[1][0];
        a_p[0][1] = atatai[0][0]*a[0][1] + atatai[0][1]*a[1][1];
        a_p[1][0] = atatai[1][0]*a[0][0] + atatai[1][1]*a[1][0];
        a_p[1][1] = atatai[1][0]*a[0][1] + atatai[1][1]*a[1][1];

        b_p[0] = a_p[0][0]*b[0] + a_p[0][1]*b[1];
        b_p[1] = a_p[1][0]*b[0] + a_p[1][1]*b[1];

        cout << setw(10) << fixed << setprecision(2) << b_p[0] << '\n';
        cout << setw(10) << b_p[1];
    } else {
        cout << "No answer!";
    }
}