/*

Sudoku GAME PROBLEM

Given a partially filled 'n x n' grid, the goal is to assign digits from 1 to 9 to the empty cells 
so that every row, column, and subgrid of size '√n x √n'  contains exactly one instance of 
the digits from 1 to 9. 

Assume 'n' is a perfect square, hence there are 'n' subgrids of size '√n x √n' each.


*/

#include<iostream>
#include<cmath>

using namespace std;

bool canPlaceDigit(int grid[][9], int n, int i, int j, int d) {

	for(int k=0; k<n; k++) {
		if(grid[i][k] == d || grid[k][j] == d) {
			return false;
		}
	}

	int rn = sqrt(n);

	int sx = (i/rn) * rn; // row no. of the 1st element of the subgrid of which 
	                      // the (i, j)th cell is part of 
	int sy = (j/rn) * rn; // col. no. of the 1st element of the subgrid of 
					      // which the (i, j)th cell is part of 
	
	for(int x=sx; x<sx+rn; x++) {
		for(int y=sy; y<sy+rn; y++) {
			if(grid[x][y] == d) {
				return false;
			}
		}
	}

	return true;



}

void solveSudoko(int grid[][9], int n, int i, int j) {

	// base case

	if(i == n) {
		// you've filled all the empty cell in the given grid
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				cout << grid[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		return;
	}

	// recursive case

	if(j == n) {
		// you've filled all the empty cells in the ith row therefore
		// move to the next row
		solveSudoko(grid, n, i+1, 0);
		return;
	}

	if(grid[i][j] != 0) {
		// (i, j)th cell is a non-empty cell therefore skip it 
		// and start filling empty cell starting from (i, j+1)th
		// cell -- ask your friend
		solveSudoko(grid, n, i, j+1);
		return;
	}

	// (i, j)th cell is an empty cell therefore assign a valid digit
	// from 1 to 9 to it.
	for(int d=1; d<=9; d++) {
		if(canPlaceDigit(grid, n, i, j, d)) {
			grid[i][j] = d;
			solveSudoko(grid, n, i, j+1);
			grid[i][j] = 0; // backtracking
		}
	}

}


int main() {

	int n = 9;
	int grid[][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0}, 
			         {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
			         {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
			         {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
			         {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
			         {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
			         {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
			         {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
			         {0, 0, 5, 2, 0, 6, 3, 0, 0}};

	solveSudoko(grid, n, 0, 0);
	
	return 0;
}
