#include <iostream>
using namespace std;
void commute_time (double, double=20, int=8);
int main( )
{
	commute_time(40);
	commute_time(30, 20);
	commute_time(35, 30, 8);
}

void commute_time(double velocity, double distance, int num_lights)
{
	cout<<"The commute time is " <<(distance/velocity + num_lights*0.01)
	    <<" hours."<<endl;

}