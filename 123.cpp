/*

Given a m x n maze with some blocked cells (marked with 'X'), and rat that wants to
go from the src (0, 0) to the dst (m-1, n-1) design a recursive algorithm to
	
	> generate all the paths from src to dst

such at each step the rat can only move in the right or down direction.

Constraint 

 1 <= m, n < 10

Example 
	Input : 

		maze = {"0000",
	            "00X0",
	            "000X",
	            "0X00"}
	
	Output :

	       {"1100", {"1000", {"1000",
            "0100",	 "1100",  "1000",
            "0110",  "0110",  "1110",
            "0011"}  "0011"}  "0011"}

*/

#include<iostream>
// Program to generate all the possible path from src to dst.
using namespace std;

void printPaths(char maze[][10], char soln[][10], int m, int n, int i, int j) {
	// base case
	if(i == m-1 && j == n-1) {
		// you are at the destination
		soln[i][j] = '1';
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				cout << soln[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		soln[i][j] = '0';
		return;
	}

	// if(i == m or j == n) {
	// 	// rat has gone outside the grid
	// 	return;
	// }

	// recursive case

	if(maze[i][j] == 'X') {
		// you are at a blocked cell
		return;
	}

// "**************************************************************"
	if(i == m-1) {
		// you are at the cell which is in the last row, therefore
		// you have no options but to move right
		soln[i][j] = '1';
		printPaths(maze, soln, m, n, i, j+1);
		soln[i][j] = '0';		 // backtracking
		return;
	}
// "**************************************************************"
	if(j == n-1) {
		// you are at the cell which is in the last column, therefore
		// you have no options but to move down
		soln[i][j] = '1';
		printPaths(maze, soln, m, n, i+1, j);
		soln[i][j] = '0';        // backtracking 
		return;
	}

	// you are at a cell from which you've two options, you can either
	// move right or you can move down

	soln[i][j] = '1';

	// move right
	printPaths(maze, soln, m, n, i, j+1);
	// move down
	printPaths(maze, soln, m, n, i+1, j);

	soln[i][j] = '0';

}


int main() {

	char maze[][10] = {"0X00",
	           		   "00X0",
	                   "000X",
	                   "0X00"};
// Below Char 2d array is used to store our output
	char soln[][10] = {"0000",
	                   "0000",
	                   "0000",
	                   "0000"};
	int m = 4;
	int n = 4;

	printPaths(maze, soln, m, n, 0, 0);

	return 0;
}

