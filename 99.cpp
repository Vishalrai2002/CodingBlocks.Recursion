#include<iostream>

using namespace std;

int f(int n) {
	// base case
	if(n == 0) {
		// return the value 0!
		return 1;
	}

	// recursive case

	// ask your friend to compute the value of (n-1)!
	int A = f(n-1);
	return n * A;
}
 
int main() {

	int n = 5;

	cout << f(n) << endl;

	return 0;
}