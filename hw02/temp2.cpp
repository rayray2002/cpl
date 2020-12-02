//PREPEND BEGIN
#include <iostream>
using namespace std;
// each element in path range from 0 to N^2 -1
int path[10000] = {};
int path_length = 0;
int N=3; // size of puzzle

bool check(int *p){
	if(p[N*N-1] != 0) return false;
	for(int i=0;i<N*N-1;++i) if (p[i] != i+1) return false;
	return true;
}
//PREPEND END

//TEMPLATE BEGIN
/*
  you can declare your own function and variable here if needed.
*/
void solver(int *p){
	//TODO:
	path[0] = 6;
	path[1] = 7;
	path[2] = 8;
	path_length = 3;
}
//TEMPLATE END

//APPEND BEGIN
int main(){
	//each element in puzzle range from 1 to N^2
	int puzzle[9] = {};

	for(int i=0;i<N*N;++i)
		cin >> puzzle[i];

	solver(puzzle);

	// check the correctness of path
	for(int i=0;i < path_length-1;i++){
		// -----------------swap-----------------
		int temp = puzzle[path[i+1]];
		puzzle[path[i+1]] = puzzle[path[i]];
		puzzle[path[i]] = temp;
	}
	if(check(puzzle))
		cout<<"      #    ###################    _   _\n" \
        <<"     #     #                 #    *   *\n" \
        <<"#   #      #     CORRECT     #      |  \n" \
        <<" # #       #                 #    \\___/\n"\
        <<"  #        ###################         \n"<<endl;
	else
		cout<<"error!!!"<<endl;
	return 0;
}
//APPEND END