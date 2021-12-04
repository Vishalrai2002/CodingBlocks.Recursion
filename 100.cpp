#include<iostream>

using namespace std;

int f(int n) {
	// base case
	if(n == 0 || n == 1) {
		return n;
	}

	// recursive case

	// ask your friend to compute (n-1)th fibonacci no.
	int A = f(n-1);

	// ask your friend to compute (n-2)th fibonacci no.
	int B = f(n-2);

	return A+B;

}

int main() {

	int n;
    cin>>n;

	cout << f(n) << endl;

}