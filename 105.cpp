#include<iostream>
// Check if array is sorted or not using recursion
using namespace std;

bool f(int *A,int n,int i) {
	// base case
	if(i == n-1) {
		// here, your are checking if the subarray A[n-1...n-1]
		// is sorted 
		return true;
	}

	// recursive case

	// if(A[i] > A[i+1]) {
	// 	// you know for sure the array is not sorted
	// 	return false;
	// }

	// // ask your friend to check if the subarray A[i+1...n-1] is sorted

	// return f(A, n, i+1);

	return A[i] <= A[i+1] && f(A, n, i+1);
}

int main() {

	int A[] = {1, 2, 3, 4, 5};
	int n = sizeof(A) / sizeof(int);

	f(A, n, 0) ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}