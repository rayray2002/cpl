//PREPEND BEGIN
#include <iostream>
#define endl "\n"
using namespace std;
// each element in path range from 0 to N^2 -1
int path[10000] = {};
int path_length = 0;
int N=3; // size of puzzle
int counter = 0;
int min_step = 20;

bool check(const int *p){
	if(p[N*N-1] != 0) return false;
	for(int i=0;i<N*N-1;++i) if (p[i] != i+1) return false;
	return true;
}
//PREPEND END

//TEMPLATE BEGIN
/*
  you can declare your own function and variable here if needed.
*/
void print_path(){
	cout << "path length: " << path_length << endl << "path: ";
	for(int i=0;path[i] != -1;++i) cout << path[i] << ' ';
	cout << endl << endl;
}
void print_puzzle(int *p) {
	cout << "N: " << counter << endl;
	for(int i=0; i<3; i++) cout << p[3*i] << p[3*i+1] << p[3*i+2] << endl;
}
void rotate(int *p, int a, int b) {
	int temp = p[a];
	p[a] = p[b];
	p[b] = temp;
}
void solver(const int *puzzle){
	counter++;
//	if (counter == 11) {
//
//	}
	static int *p = nullptr;
	if (p == nullptr) {
		p = new int [N*N];
		for(int i=0;i<N*N;++i) {
			p[i] = puzzle[i];
		}
		for(int i=0;i<35;++i) {
			path[i] = -1;
		}
	}
//	print_puzzle(p);
//	print_path();

	if (check(p)) return;

	int pos = -1;
	if (path_length == 0) {
		for (int i = 0; i < N*N; i++) {
			if (p[i] == 0) pos = i;
		}
		path[0] = pos;
		path_length++;
		solver(p);
		return;
	} else {
		pos = path[path_length-1];
	}
	if (path_length > min_step) {
		rotate(p, path[path_length - 1], path[path_length - 2]);
		path_length--;
		path[path_length] = -1;
		return;
	} else {
		if (pos % 3 != 2 && path[path_length - 2] != pos+1) {
			//+1
			path[path_length] = pos + 1;
			path_length++;
			rotate(p, pos, pos + 1);
			solver(p);
			pos = path[path_length - 1];
		}
		if (check(p)) return;
		if (pos > 2 && path[path_length - 2] != pos-3) {
			//-3
			path[path_length] = pos - 3;
			path_length++;
			rotate(p, pos, pos - 3);
			solver(p);
			pos = path[path_length - 1];
		}
		if (check(p)) return;
		if (pos%3 != 0 && path[path_length - 2] != pos-1) {
			//-3
			path[path_length] = pos - 1;
			path_length++;
			rotate(p, pos, pos - 1);
			solver(p);
			pos = path[path_length - 1];
		}
		if (check(p)) return;
		if (pos < 6 && path[path_length - 2] != pos+3) {
			//-3
			path[path_length] = pos + 3;
			path_length++;
			rotate(p, pos, pos + 3);
			solver(p);
		}
		if (check(p)) return;

		rotate(p, path[path_length - 1], path[path_length - 2]);
		path_length--;
		path[path_length] = -1;
	}
}
//TEMPLATE END

//APPEND BEGIN
int main(){
	//each element in puzzle range from 1 to N^2
	int puzzle[9] = {};

	for(int i=0;i<N*N;++i)
		cin >> puzzle[i];

		int puzzle_temp[9];
		for(int i=0;i<N*N;++i)
			puzzle_temp[i] =  puzzle[i];
		solver(puzzle_temp);
		print_path();
		// check the correctness of path
		for (int i = 0; i < path_length - 1; i++) {
			// -----------------swap-----------------
			int temp = puzzle_temp[path[i + 1]];
			puzzle_temp[path[i + 1]] = puzzle_temp[path[i]];
			puzzle_temp[path[i]] = temp;
		}
		if (check(puzzle_temp)) {
			cout << "      #    ###################    _   _\n" \
 << "     #     #                 #    *   *\n" \
 << "#   #      #     CORRECT     #      |  \n" \
 << " # #       #                 #    \\___/\n"\
 << "  #        ###################         \n" << endl;
		} else {
			cout << "error!!!" << endl;
		}
	return 0;
}
//APPEND END