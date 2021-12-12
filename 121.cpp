/*

Given a m x n maze with some blocked cells (marked with 'X'), and rat that wants to
go from the src (0, 0) to the dst (m-1, n-1) design a recursive algorithm to
	
	> check if there exists a path from src to dst

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

		true (Yes, a path exist from src to dst)

*/

#include<iostream>

using namespace std;

bool checkPath(char maze[][10], int m, int n, int i, int j) {
	// base case
    // AND operator
	if(i == m-1 && j == n-1) {
		// you are at the destination
		return true;
	}

	// if(i == m || j == n) {
	// 	// rat has gone outside the grid
	// 	return false;
	// }

	// recursive case

	if(maze[i][j] == 'X') {
		// you are at a blocked cell
		return false;
	}

	if(i == m-1) {
		// you are at the cell which is in the last row, therefore
		// you have no options but to move right
		return checkPath(maze, m, n, i, j+1);
	}

	if(j == n-1) {
		// you are at the cell which is in the last column, therefore
		// you have no options but to move down
		return checkPath(maze, m, n, i+1, j);
	}

	// you are at a cell from which you've two options, you can either
	// move right or you can move down

	// move right
	bool X = checkPath(maze, m, n, i, j+1);

	// move down
	bool Y = checkPath(maze, m, n, i+1, j);

// Or operator
	return X || Y;

}

int main() {

	char maze[][10] = {"0000",
	                   "00X0",
	                   "000X",
	                   "0X00"};
	int m = 4;
	int n = 4;

	checkPath(maze, m, n, 0, 0) ? cout << "true" << endl :
							      cout << "false" << endl;

	return 0;
}

