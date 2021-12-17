/*

Given a n x n chess board, count the number of ways a chess elephant can move from (0, 0)
to (n-1, n-1) such that it can only move in the right or down direction at a time.

Example 
	Input : n = 2
	Output: 2
	
	Input : n = 3
	Output: 14
	
	Input : n = 4
	Output: 106

*/

#include<iostream>

using namespace std;

int countElephantWays(int n, int i, int j) {
	// base case
	if(i == n-1 && j == n-1) {
		// you are at the destination
		return 1;
	}

	// recursive case

	// you are the (i, j)th cell and you've two options - move right or move down

	// 1. move right
	int count1 = 0;
	for(int k=1; k<n; k++) {
		// you are at the (i, j)th cell, and you decide to move k steps to the
		// right to the (i, j+k)th cell
		if(j+k < n) {
			count1 += countElephantWays(n, i, j+k);
		} else {
			break;
		}
	}

	// 2. move down
	int count2 = 0;
	for(int k=1; k<n; k++) {
		// you are at the (i, j)th cell, and you decide to move k steps to the
		// down to the (i+k, j)th cell
		if(i+k < n) {
			count2 += countElephantWays(n, i+k, j);
		} else {
			break;
		}
	}

	return count1 + count2;
}

int main() {

	int n = 3;

	cout << countElephantWays(n, 0, 0) << endl;

	return 0;
}
