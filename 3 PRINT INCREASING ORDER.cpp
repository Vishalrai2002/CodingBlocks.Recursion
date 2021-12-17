#include<iostream>
// print nth number in increasing order by using recursion
using namespace std;

void f(int n) {
	// base case
	if(n == 0) {
		return;
	}

	// recursive case

	// ask your friend to print nos. from 1 to n-1 in the increasing order
	f(n-1);

	cout << n << " ";
}

int main() {

	int n = 10;

	f(n);


}
