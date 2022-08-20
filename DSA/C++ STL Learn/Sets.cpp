#include<bits/stdc++.h>
using namespace std;

void print(set<string> &s) {
	for (string value : s) {
		cout << value << endl;
	}
	// for (auto it = s.begin(); it != s.end(); ++it) {
	// 	cout << *it << endl;
	// }
}

int main() {
	/*
	set<string> s;
	s.insert("abc");
	s.insert("zsdf");
	s.insert("bcd");
	auto it = s.find("abc");
	if (it != s.end()) {
		// cout << *it << endl;
		s.erase(it); // s.erase("abc");
	}
	print(s);

	set<string> s;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;
		s.insert(str);
	}
	for (auto &value : s) {
		cout << value << endl;
	}

	unordered_set<string> s;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;
		s.insert(str);
	}
	int q;
	cin >> q;
	while (q--) {
		string str;
		cin >> str;
		if (s.find(str) != s.end()) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	*/
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		multiset<long long> bags;
		for (int i = 0; i < n; ++i) {
			long long candy_count;
			cin >> candy_count;
			bags.insert(candy_count);
		}
		long long total_candies = 0;
		for (int i = 0; i < k; ++i) {
			auto last_it = (--bags.end());
			long long candy_cnt = *last_it;
			total_candies += candy_cnt;
			bags.erase(last_it);
			bags.insert(candy_cnt / 2);
		}
		cout << total_candies << endl;
	}
}

/*
set store data in sorted order.
TC insertion = Olog(n)
TC accessing = Olog(n)

find will return iterator of the element, if not exist return s.end() TC= O(log(n))

set stores unique elements, no duplicates

s.erase() can take iterator and value as well

sets also use Red Black Tree as internal working implementation

unordered_set = unordered_map analogy
TC will become : O(1) because of Hash table implementation (when order doesn't matter)

we can't store complex data types in unordered_set.For that we need to use set
because hash functions are not defined for them in standard library.. boost library has these implementations but we can't use them directly in CP.

multiset<string> s;
all operations become O(log(n)) -> RB tree implementation. we can store dupliate values in multisets. Multiple same value insertion is allowed.
s.find will return iterator to the first element in the multiset in case there are multiple values present.
so s.erase will remove only that one element from multiset if iterator is passed. if value is passed then all the values will be removed.
*/