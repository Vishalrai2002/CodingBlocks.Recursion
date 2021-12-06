#include<iostream>
using namespace std;
// Tower of Hanoi problem using recursion

void f(int n, char src, char dst, char hlp) {
	if(n == 0) {
		// you are trying to move 0 disks from src to dst using hlp
		// so you've to do anything.
		return;
	}
	// recursive case
	// ask your friend to move n-1 disks from src('A') to hlp('C') using dst('B')
	f(n-1, src, hlp, dst);
	// move the largest disk from src('A') to dst('B')
	cout << "Move disk from " << src  << " to " << dst << endl;
	// ask your friend to move n-1 disks from hlp('C') to dst('B') using src('A')
	f(n-1, hlp, dst, src);
}
int main() {

	int n = 3;

	f(n, 'A', 'B', 'C');

	return 0;
}