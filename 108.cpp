#include<iostream>
// print all index of the target index using recursion
using namespace std;

void f(int* A, int n, int t, int i, bool flag=false) {
	// base case
	if(i == n) {
		if(flag == false) {
			// you've not found any occurrences of the target in the
			// given array
			cout << -1 << " ";
		}
		return;
	}

	// recursive case
	if(A[i] == t) {
		// you've found the target at the ith index, print i and move forward
		flag = true; // you've found an occurrence of the target
		cout << i << " ";
	}

	// Ask your friend to search for other occurrences the 't' in A[i+1...n-1]
	f(A, n, t, i+1, flag);
	
}

int main() {

	int A[] = {10, 20, 30, 40, 10, 50};
	int n = sizeof(A) / sizeof(int);
	int t = 10;

	f(A, n, t, 0);
	
	return 0;
}