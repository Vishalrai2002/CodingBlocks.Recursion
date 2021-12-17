#include<iostream>
using namespace std;
// Binary Search using Recursion

int f(int* A, int t, int s, int e) {
	// base case
	if(s > e) {
		// you are trying to search for the target in an empty search space 
		// i.e. A[e...s]
		return -1;
	}

	// recursive case
	int m = s + (e-s)/2; // or (s+e)/2
	if(A[m] == t) {
		// you've found the target at index m, and you are done
		return m;
	} else if(A[m] > t) {
		// eliminate the right-half of the search space and search for the
		// target towards the left of the mid i.e. in the subarray which 
		// starts from s and ends at m-1 A[s....m-1]

		// Ask your friend to search for the target in A[s...m-1]
		return f(A, t, s, m-1);
	} else {
		// Ask your friend to search for the target in A[m+1...e]
		return f(A, t, m+1, e);
	}
}

int main() {

	int A[] = {10, 20, 30, 40, 50};
	int n = sizeof(A) / sizeof(int);
	int t = 40;

	cout << f(A, t, 0, n-1) << endl;

	return 0;
}
