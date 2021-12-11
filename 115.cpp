/*

Given string str of size n, design a recursive algorithm to replace all occurrences of pi 
with 3.14 in the given string and print the modified string.

Example : 
	Input : inp[] = "pippppiiiipi"
	Output: out[] = "3.14ppp3.14iii3.14"

	Input : inp[] = "pip"
	Output: out[] = "3.14p"

	Input : inp[] = "xpix"
	Output: out[] = "x3.14x"

Constraints :

	1 < n < 10 

*/

#include<iostream>
using namespace std;
// Replace pi with 3.14 in the given string by using recursion
// "pippppiiiipi"

void replacepi(string s){
    if (s.length()==0){    // base case
        return ;
    }
    
    if (s[0]=='p' && s[1]=='i'){
        cout<<"3.14";
        replacepi(s.substr(2)); // further function is called by this we use 2 because after two character p and i we find the substr or "call for rest of the string"
    }
    else { 
        cout<<s[0];
        replacepi(s.substr(1));
    }

}

int main()
{
    string s="pippppiiipi";
    replacepi(s);
    return 0;
}