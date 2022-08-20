/*
when we store key value pairs in maps, they will be stored in sorted order
but in unordered maps, they can be stored in any sequence.
maps are implemented internally using Red Black Tree => self balancing tree
maps are not continuous in nature => it++ will take you to next iterator.
elements in maps are pair of key and value.
*/
#include<bits/stdc++.h>
using namespace std;

void print(unordered_map<int, string> &m) {
	cout << m.size() << endl;
	for (auto &pr : m) {
		cout << pr.first << " " << pr.second << endl;
	}
}

int main() {
	/*
	map<int, string> m;
	m[1] = "abc"; // O(log(n)) n = current size
	m[5] = "cde";
	m[3] = "acd";
	m.insert({4, "afg"});
	/*
	map<int, string> :: iterator it;
	for (it = m.begin(); it != m.end(); ++it) {
		cout << (*it).first << " " << (*it).second << endl;
	}

	auto it = m.find(7); // return iterator to the element mentioned. If it is not present then it will return m.end() TC: O(log(n))
	/*
	if (it == m.end()) {
		cout << "No Value!";
	} else {
		cout << it->first << " " << it->second << endl;
	}

	if (it != m.end()) {
		m.erase(it); // we can pass iterator or key to remove that element from the map. TC: O(log(n)) n-> size of map. we can't pass any iterator which doesn't exist, it will give segmentation fault
	}
	m.clear(); // clears the map
	print(m);
	*/
	/*
	int N;
	cin >> N;
	map <string, int> m;
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		m[s]++;
	}
	for (auto pr : m) {
		cout << pr.first << " " << pr.second << endl;
	}
	*/
	// Unordered Maps
	/*
		1.inbuilt implementation -> uses hash table and keys are hashed and order is shuffled in this.
		unordered_map<int,string> m;
		2.Time Complexity -> avg O(1) using the hash table. insertion and access, find, erase everything
		m[1] = "abc"; // O(log(n)) n = current size
		m[5] = "cde";
		m[3] = "acd";
		m.insert({4, "afg"});
		3.valid key datatype
		Only generic data types can be used as keys, but in maps complex datatypes can also be used (pair,set etc), because in unordered_maps keys value are hashed and hash functions are only defined for generic datatype not complex datatypes, so they can not be hashed, hence they give compilation error, which is not the case in ordered maps or maps, because their implementation is based on RBT and comparison can be performed in those.
	*/
	int N;
	cin >> N;
	unordered_map <string, int> m;
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		m[s]++;
	}
	int q;
	cin >> q;
	while (q--) {
		string s;
		cin >> s;
		cout << m[s] << endl;
	}
	/*
	for (auto pr : m) {
		cout << pr.first << " " << pr.second << endl;
	}
	*/
}
// Maps store keys in sorted order.
// Insertion -> O(log(n)) where n = current size, even if you don't assign any value to a key , m[6] will consume log(n) time with default empty string here. whatever the value data type will be, a default blank value will be assigned.
// Duplicate values are not possible. It will only update the existing entry
// Accessing the elements in the maps is log(n). the for loop is of O(nlog(n))
// Time complexity depends upon the keys. If keys are strings then TC becomes s.size() * log(n) as string comparison will occur every time we insert something into the map. and on that basis they will get sorted.in case of int it is negligible.

/*
	multimap<int,int> m;
	can have duplicate(multiple) key, value pairs.
	in case we have to use multiple values we can use normal maps with value as vector
	map<int,vector<string>> m;
	In case we need to use complex datatype as keys, use Maps.
*/