#include<iostream>
#include<set>
// All about set container
using namespace std;

int main() {

	set<int> s;

	s.insert(5);
	s.insert(4);
	s.insert(3);
	s.insert(2);
	s.insert(1);

	cout << "size : " << s.size() << endl;  // 5

	s.erase(5);

	cout << "size : " << s.size() << endl;  // 4

	for(auto it=s.begin(), end=s.end(); it != end; it++) {
		cout << *it << " "; // 1 2 3 4
	}

	cout << endl;

	for(auto x : s) {
		cout << x << " ";   // 1 2 3 4
	}

	cout << endl;

	if(s.find(3) != s.end()) {
		cout << "3 is present" << endl;  // 3 is present
	} else {
		cout << "3 is absent" << endl;  
	}

	if(s.count(5)) {
		cout << "5 is present" << endl;
	} else {
		cout << "5 is absent" << endl;   // 5 is absent
	}


	s.clear();

	cout << "size : " << s.size() << endl;   // size : 0

	return 0;
}
