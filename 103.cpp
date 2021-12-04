#include<iostream>
// Print nth number in decreasing order
using namespace std;

void f(int n) {
	// base case
	if(n == 0) {
		return;
	}

	// recursive case
	cout << n << " ";
	f(n-1);
}

int main() {

	int n = 10;
	f(n);


}