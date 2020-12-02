#include <iostream>
using namespace std;

int main() {
    char input[3][3];
    cin >> input[0][0] >> input[0][1] >> input[0][2]
    >> input[1][0] >> input[1][1] >> input[1][2]
    >> input[2][0] >> input[2][1] >> input[2][2];

    int o_count = 0, x_count = 0;
    int law = 0, winner = -1, turn = -1; //o:1, x:0, draw:2
    for (int i=0; i<3; i++) {
	    for (int j=0; j<3; j++) {
//	    	cout << input[i][j];
			if (input[i][j] == 'o') {
				o_count++;
			} else if (input[i][j] == 'x') {
				x_count++;
			}
	    }
//	    cout << endl;
    }

    if (x_count-o_count > 1 || o_count > x_count) {
    	law = 1;
    } else {
	    for (int i=0; i<3; i++) {
	    	if (input[i][0] == input[i][1] && input[i][2] == input[i][1]) {
	    		if (input[i][0] == 'o') {
	    			winner = 1;
	    		} else if (input[i][0] == 'x'){
	    			winner = 0;
	    		}
	    	} else if (input[0][i] == input[1][i] && input[2][i] == input[1][i]) {
			    if (input[0][i] == 'o') {
				    winner = 1;
			    } else if (input[0][i] == 'x'){
				    winner = 0;
			    }
		    }
	    }
	    if (input[0][0] == input[1][1] && input[2][2] == input[1][1]) {
		    if (input[0][0] == 'o') {
			    winner = 1;
		    } else if (input[0][0] == 'x'){
			    winner = 0;
		    }
	    }
	    if (input[0][2] == input[1][1] && input[2][0] == input[1][1]) {
		    if (input[0][2] == 'o') {
			    winner = 1;
		    } else if (input[0][2] == 'x'){
			    winner = 0;
		    }
	    }
	    if (winner == -1 && x_count+o_count == 9) {
	    	winner = 2;
	    }
    }
    if (x_count-o_count == 1){
    	turn = 1;
    } else {
    	turn = 0;
    }

    if (law) {
    	cout << "Some one breaks the law!" << endl;//
    } else {
    	if (winner == 0) {
    		cout << "Cross wins!" << endl;//
	    } else if (winner == 1) {
		    cout << "Circle wins!" << endl;//
	    } else if (winner == 2) {
		    cout << "This is a draw!" << endl;
	    } else {
	        if (turn) {
		        cout << "Circle's turn!" << endl;
	        } else {
		        cout << "Cross' turn!" << endl;//
	        }
    	}
    }
}