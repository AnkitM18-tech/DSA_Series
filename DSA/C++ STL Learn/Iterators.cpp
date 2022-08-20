#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<int> v = {2, 3, 5, 6, 7};
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << endl;
	/*
	vector<int> ::iterator it;
	for (it = v.begin(); it != v.end(); ++it) {
		cout << *it << " ";
	}
	// cout << (*(it + 1)) << endl;

	vector<pair<int, int>> v_p = {{1, 2}, {2, 3}, {3, 4}};
	vector<pair<int, int>> ::iterator it;
	for (it = v_p.begin(); it != v_p.end(); ++it) {
		cout << (*it).first << " " << (*it).second << endl;
		cout << it->first << " " << it->second << endl;
	}
	*/
	// Range besed loop
	for (int value : v) { // value gets the copy of elements from vector. to get the actual values from vector and manipulate them we need to use references.
		cout << value << " ";
	}
	cout << endl;
	vector<pair<int, int>> v_p = {{1, 2}, {2, 3}};
	for (pair<int, int> &value : v_p) {
		cout << value.first << " " << value.second << endl;
	}
	for (auto &value : v_p) {
		cout << value.first << " " << value.second << endl;
	}
	for (auto it = v.begin(); it != v.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	// Auto keyword
	auto a = 1; // assumes a value to be 1
	// auto keyword dynamically determine the data type of variables. comes handy when we use in case of iterators
	cout << a << endl;
}

// .begin() -> points to the first element
// .end() -> points to the last element + 1
/*
	v.begin() -> v[0]
	v.end() -> next to last v[n+1] -> non existent element
	vector<int> ::iterator it; // way to define iterator -> container_type ::iterator name;
	can be accessed just as a pointer. (*it) using *

	it++ -> move to next iterator => in continuous containers(vector) it is the next location as well
	it+1 -> move to next location => the address right after the iterator
	It won't be a issue for continuous containers but when there is maps or sets there will be problems. it++ will take you to the next iterator. it+1 won't do
*/