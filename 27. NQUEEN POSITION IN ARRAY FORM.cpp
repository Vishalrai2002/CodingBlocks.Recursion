/*
N Queens Problem

The problem is to place 'n' queens on an 'n x n' chessboard, so that no two queens are attacking 
each other, this means that no two queens are in the same row, the same column, or the same diagonal.

Example 
	Input : N = 4
	Output: 
	        [1, 3, 0, 2] [2, 0, 3, 1]

Constraint:
	1<=n<=10	        

*/

#include<iostream>

using namespace std;

void f(int n, int* QPos, int r) {

	// base case
	if(r == n) {
		// you've placed all the n queens therefore you can stop and
		// print the solution you've built
		for(int i=0; i<n; i++) {
			cout << QPos[i] << " ";
		}
		cout << endl;
		return;
	}

	// place Qr in the jth column of row 'r' where 0 <= j < n
	// such that upon placing Qr in the jth column of row 'r'
	// it doesn't attack any previously placed queen Qi where,
	// 0 <= i <= r-1

	for(int j=0; j<n; j++) {
		
		// check if the jth column of row r is a valid column to place Qr or not

		bool canPlace = true; // assume the jth column is a valid column

		for(int i=0; i<=r-1; i++) {
            //    COLUMNS          LEFT DIAGONAL       RIGHT DIAGONAL
			if(QPos[i] == j || QPos[i] == j-(r-i) || QPos[i] == j+(r-i)) {
				canPlace = false;
				break;
			}
		}
		
		if(canPlace) {
			QPos[r] = j;
			f(n, QPos, r+1);
		}
	}

}

int main() {

	int n = 4;
	int QPos[10];// in this we store
//   N, QPOS   R
	f(n, QPos, 0);

	return 0;
}
