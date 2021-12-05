#include<iostream>
// WAP to find the first occurenct of an array using recurion
using namespace std;

int f(int* A, int n, int t, int i) {
	// base case
	if(i == n) {
		// you are trying to search for the index of the 1st of the target
		// in the subarray that starts from the nth index i.e. A[n...n-1],
		// and this can be treated like an empty subarray
		return -1;
	}

	// recursive case
	if(A[i] == t) {
		// you've found the target at the ith index, so you are done
		return i;
	}

	// Ask your friend to search for the 't' in A[i+1...n-1]
	int answerFromMyFriend = f(A, n, t, i+1);
	return answerFromMyFriend;
}

int main() {

	int A[] = {10, 20, 30, 40, 50};
	int n = sizeof(A) / sizeof(int);
	int t = 30;

	cout << f(A, n, t, 0) << endl;

	return 0;
}