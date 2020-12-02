#include <iostream>
using namespace std;
int days_in_month=31;
void april()
{
	int birthday=2;
	days_in_month=30;
}

int main( )
{
	int birthday=0;
	cout<<"Before: days_in_month="<< days_in_month <<endl
	    <<"birthday="<< birthday <<endl;
	april();
	cout<<"After: days_in_month="<< days_in_month <<endl
	    <<"birthday="<< birthday <<endl;
	cout<<birthday+days_in_month;
}