#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
using namespace std;
int main()
{
	int seed;
	cout<<"Preset random sequence:\t";
	for (int i=1;i<=1000;i++) cout<< setw(3) <<rand()%10;
	cout<<endl;
	while (1) {
		cout<<"\nEnter a new seed: ";
		cin>>seed;
		srand(time(0));
		cout<<"\nNew random sequence:\t";
		for (int i=1;i<=10;i++) cout<< setw(3) <<rand()%10+1;
	}
}