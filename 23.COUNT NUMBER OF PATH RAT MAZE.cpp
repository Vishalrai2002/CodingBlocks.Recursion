/*

Given a m x n maze with some blocked cells (marked with 'X'), and rat that wants to
go from the src (0, 0) to the dst (m-1, n-1) design a recursive algorithm to
	
	> count the number of paths that exist between src and dst

such at each step the rat can only move in the right or down direction.

Constraint 

 1 <= m, n < 10

Example 
	Input : 

		maze = {"0000",
	            "00X0",
	            "000X",
	            "0X00"};
	
	Output : 3
	
*/

#include<iostream>

using namespace std;

int countWays(char maze[][10], int m, int n, int i, int j) {
	// base case
	if(i == m-1 && j == n-1) {
		// you are at the destination
		return 1;
	}

	if(i == m || j == n) {
		// rat has gone outside the grid
		return 0;
	}

	// recursive case

	if(maze[i][j] == 'X') {
		// you are at a blocked cell
		return 0;
	}

	// you are at a cell from which you've two options, you can either
	// move right or you can move down

	// move right
	int X = countWays(maze, m, n, i, j+1);

	// move down
	int Y = countWays(maze, m, n, i+1, j);

	return X + Y;

}


int main() {

	char maze[][10] = {"0000",
	                   "00X0",
	                   "000X",
	                   "0X00"};
	int m = 4;
	int n = 4;

	cout << countWays(maze, m, n, 0, 0) << endl;

	return 0;
}

