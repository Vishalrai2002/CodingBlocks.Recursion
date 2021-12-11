/*

Given a string str, design a recursive algorithm to move all the occurrence of letter x 
to the end of the string str.

Example 
	Input : str = "axbcxdxfx"
	Output: str = "abcdfxxxx"

	Input : str = "xabcxdxfx"
	Output: str = "abcdfxxxx"

*/

#include<iostream>

using namespace std;

string moveX(string str) {

	// base case
	if(str.empty()) {
		// str represents an empty string therefore, we don't 
		// have to do anything, just return back the string
		// itself
		return str;
	}

	// recursive case

	// 1. extract the substring that starts from the 1st index
	string subString = str.substr(1);

	// 2. ask your friend to move all the 'x' characters in the substring
	// to the end
	string subStringFromMyFriend = moveX(subString);

	// 3. extract the character at the 0th index
	// char firstChar = str[0]; // you cannot compare a character
						        // with a string, nor can you 
	 				            // append a char with a string
	string firstChar = str.substr(0, 1);

	if(firstChar == "x") {
		return subStringFromMyFriend + firstChar;
	} else {
		return firstChar + subStringFromMyFriend;
	}

}

int main() {

	string str = "xaxbcxdxfx";

	cout << moveX(str) << endl;

	return 0;
}