#include<iostream>
// find multipy using recursion
using namespace std;

int f(int a, int b) {
	// base case
	if(b == 0) {
		// add 'a' 0 times i.e. multiply a with 0
		return 0;
	}

	// recursive

	// ask your friend to add 'a', 'b-1' times i.e. multiply 'a' with 'b-1'
	
	// int A = f(a, b-1);
	// return a + A;

	return a + f(a, b-1);
}

int main() {

	int a = 3;
	int b = 2;

	cout << f(a, b) << endl;

	return 0;
}
