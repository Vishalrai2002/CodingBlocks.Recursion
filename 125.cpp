/*

Given a phone keypad as shown below, and an n digit number, print all words which are possible by 
pressing the n digits on the keypad.

 1()     2(abc) 3(def) 
 4(ghi)  5(jkl) 6(mno)
 7(pqrs) 8(tuv) 9(wxyz)
         0()  
*/

#include<iostream>

using namespace std;
                 //0   1
string keypad[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void generateWords(char* inp, int i, char* out, int j) {
    // base case
    if(inp[i] == '\0') {
        // you've taken decision for all the n digits therefore you can stop
        out[j] = '\0';
        cout << out << endl;
        return;
    }
    // recursive case

    if(inp[i] == '0' || inp[i] == '1') {
        // skip this digit
        generateWords(inp, i+1, out, j);
        return;
    }

    // 1. extract the ith digit from inp
    int d = inp[i]  - '0';

    // 2. extract the options for the ith digit from keypad
    string options = keypad[d];

    // 3. map the ith digit to one of the possible options
   
    // for(int k=0; k<options.length(); k++) {
    //     char c_k = options[k];
    //     out[j] = c_k;
    //     generateWords(inp, i+1, out,  j+1);
    // }
     
     // For each loop
    for(char c_k : options) {
        out[j] = c_k;
        generateWords(inp, i+1, out, j+1);
    }
}

int main() {
	
    char inp[] = "23";
    char out[10];

    generateWords(inp, 0, out, 0);

	return 0;
}