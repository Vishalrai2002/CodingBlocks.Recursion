#include<iostream>
// Print spelling in reverse order using recursion.
using namespace std;

string map[] = {"zero", "one", "two", "three", 
                "four", "five", "six", "seven",
                "eight", "nine"};
// first code print spelling in reverse order

void f1(int n) {
	// base case
	if(n == 0) {
		// you've already printed the spelling of all the digits
		// in the given number n.
		cout << endl;
		return;
	}

	// recursive case

	// 1. extract the digit at the one's place
	int d = n%10;
	// 2. map the digit to its corresponding spelling
	cout << map[d] << " ";
	// 3. ask your friend to print the spelling of n/10 in reverse
	f1(n/10);
}
// second code print spelling in correct order

void f2(int n) {
	// base case
	if(n == 0) {
		// you've already printed the spelling of all the digits
		// in the given number n.
		cout << endl;
		return;
	}

	// recursive case

	// 1. ask your friend to print the spelling of n/10
	f2(n/10);
	// 2. extract the digit at the one's place
	int d = n%10;
	// 3. map the digit to its corresponding spelling
	cout << map[d] << " ";
	
}

int main() {

	int n = 123;

	f1(n);
	f2(n);

	return 0;
}
