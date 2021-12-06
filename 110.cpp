#include<iostream>
#include<cstring>
// Convert a string to an integer using recusion
// you can also do it by using stoi inbuilt function in c++
using namespace std;

int f(char* str, int i) {
	// base case
	if(i == 0) {
		// return the integer corr. to the substring that ends at the 0th index
		// i.e. str[0...0] which is just the character at the 0th index
		return str[i]-'0';
	}

	// if(i == -1) {
	// // return the integer corr. to an empty string
	// 	return 0;
	// }

	// recursive case

	// 1. Ask your friend for the integer corresponding to the substring
	// that ends at the (i-1)th index i.e. str[0....i-1]

	int integerFromMyFriend = f(str, i-1);
	return integerFromMyFriend*10 + (str[i]-'0');

}

int main() {

	char str[] = "123";
	int n = strlen(str);

	int ans = f(str, n-1);

	cout << ans << endl;
	cout << ans+1 << endl;

	return 0;
}