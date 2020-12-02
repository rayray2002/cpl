#include <iostream>
using namespace std;
double potential_energy(int, double);
double kinetic_energy(int, double);
int main( )
{
	int mass=15;
	double velocity=300, height = 5.2;
	double p, k;
	cout<<"The value of mass in main is: "<<mass<<endl;

	p = potential_energy(mass, height);
	k = kinetic_energy(mass, velocity);
	cout << k/p;

	cout<<"Now the value of mass in main is: "<<mass<<endl;
}

double potential_energy(int mass, double height)
{
	double pe;
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