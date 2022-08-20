// those entities which we can compare, we can use them as keys in maps. like sets,vectors or pairs => first elements will be compared, if same then second elements will be compared and so on. Value can be anything.

#include<bits/stdc++.h>
using namespace std;

int main() {
	/*
	map<pair<string, string>, vector<int>> m;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string fn, ln;
		int cnt;
		cin >> fn >> ln >> cnt;
		for (int j = 0; j < cnt ; ++j) {
			int x;
			cin >> x;
			m[ {fn, ln}].push_back(x); // m[{}] is a vector, so we can perform all vector ops
		}
	}
	for (auto &pr : m) { // map stores data as pair -> {{fn,ln},vector{}}
		auto &full_name = pr.first;
		auto &list = pr.second;
		cout << full_name.first << " " << full_name.second << endl;
		cout << list.size() << endl;
		for (auto &element : list) {
			cout << element << " ";
		}
		cout << endl;
	}

	map<int, multiset<string>> marks_map;
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		int marks; string name;
		cin >> name >> marks;
		marks_map[marks].insert(name);
	}
	auto curr_it = --marks_map.end();
	while (true) {
		auto &students = (*curr_it).second;
		int marks = (*curr_it).first;
		for (auto student : students) {
			cout << student << " " << marks << endl;
		}
		if (curr_it == marks_map.begin()) break;
		curr_it--;
	}
	*/
	map<int, multiset<string>> marks_map;
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		int marks; string name;
		cin >> name >> marks;
		marks_map[-1 * marks].insert(name);
	}
	for (auto &marks_student_pr : marks_map) {
		auto &students = marks_student_pr.second;
		int marks = marks_student_pr.first;
		for (auto student : students) {
			cout << student << " " << -1 * marks << endl;
		}
	}
}
// sets can be used accordingly