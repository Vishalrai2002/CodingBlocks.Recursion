#include<iostream>
using namespace std;
// Merge sort using recursion

void merge(int* A, int s, int m, int e) {
	int i = s;
	int j = m+1;
	int k = s;

	int B[100];

	while(i <= m && j <= e) {
		if(A[i] < A[j]) {
			B[k] = A[i];
			i++;
			k++;
		} else {
			B[k] = A[j];
			j++;
			k++;
		}
	}

	while(i <= m) {
		B[k] = A[i];
		i++;
		k++;
	}

	while(j <= e) {
		B[k] = A[j];
		j++;
		k++;
	}

	for(int i=s; i<=e; i++) {
		A[i] = B[i];
	}

}

void f(int* A, int s, int e) {
	// base case
	if(s >= e) {
		return;
	}

	// recursive case
		
	// 1. Divide the array around the mid-point
	int m = s + (e-s)/2; // or (s+e)/2

	// 2. Recursively sort the two subarrays
	f(A, s, m);
	f(A, m+1, e);

	// 3. Merge the two sorted subarrays
	merge(A, s, m, e);

}

int main() {

	int A[] = {5, 4, 3, 2, 1};
	int n = sizeof(A) / sizeof(int);

	for(int i=0; i<n; i++) {
		cout << A[i] << " ";
	}

	cout <<  endl;

	f(A, 0, n-1);

	for(int i=0; i<n; i++) {
		cout << A[i] << " ";
	}

	cout <<  endl;

	return 0;
}