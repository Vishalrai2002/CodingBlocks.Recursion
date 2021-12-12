/*

Suppose there is a ladder with n steps. A person standing at the bottom of the ladder and wants to 
reach to its top. Assume the person can take atmost k steps at a time. Then, count the number 
of ways, the person can reach the top of the ladder.

Example 
	Input : n = 4, k = 3
	Output: 7
	Explanation : [1, 1, 1, 1], 
	              [1, 1, 2], 
	              [1, 2, 1], 
	              [2, 1, 1],
	              [2, 2],
	              [1, 3],
	              [3, 1]
    Total Steps = 7 which is our Output.

*/
#include<iostream>
// Ladder Problem Using Recursion
using namespace std;

int countNumberOfWays(int n, int k, int i) {

	// base case
	if(i == n) {
		// you are already at the top
		return 1;
	}

	// // additional base case to handle situation when the person
	// // goes beyond the nth step
	// if(i > n) {
	// 	return 0;
	// }

	// recursive case

	int count = 0;
	for(int j=1; j<=k; j++) {
		// at the ith step, I can take a jump of size j and go to the (i+j)th
		if(i+j <= n) {
			count += countNumberOfWays(n, k, i+j);
		} else {
			break;
		}
	}

	return count;

}

int main() {

	int n = 4;
	int k = 3;

	cout << countNumberOfWays(n, k, 0) << endl;

	return 0;
}