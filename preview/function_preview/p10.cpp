#include <iostream>
using namespace std;
double potential_energy();
double kinetic_energy(int, double);
int main( )
{
	int mass=15;
	double velocity=300;
	double k, p;
	cout<<"The value of mass in main is: "<<mass<<endl;

	p = potential_energy();
	k = kinetic_energy(mass, velocity);
	cout << k/p << endl;
	cout<<"Now the value of mass in main is: "<<mass<<endl;
}

double potential_energy()
{
	int mass=6;
	double pe, height=5.2;
	double g=9.81;
	pe = mass*g*height;
	cout<<"Potential energy="<<pe<<endl;

	return pe;
}

double kinetic_energy(int m, double v)
{
	double ke;
	ke = 0.5*m*v*v;
	cout<<"Kinetic energy="<<ke<<endl;

	return ke;
}