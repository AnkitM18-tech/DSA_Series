#include<bits/stdc++.h>
using namespace std;

bool is_positive(int x) {
	return x > 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// Lambda Function
	cout << [](int x) {return x + 2;}(2) << endl;
	cout << [](int x, int y) {return x + y;}(4, 7) << endl;
	auto sum = [](int x, int y) {return x + y;}; // now sum can be reused
	cout << sum(2, 3) << endl;
	// All_of -> returns a boolean true value if all the elements satisfies the condition, else return false
	vector<int> v = {2, 3, 5};
	cout << all_of(v.begin(), v.end(), [](int x) {return x > 0;}) << endl;
	cout << all_of(v.begin(), v.end(), is_positive) << endl;
	// Any_of -> returns a boolean true value if any of the elements satisfies the condition, if none of them satisfies the condition return false
	cout << any_of(v.begin(), v.end(), [](int x) {return x > 2;}) << endl;
	// None_of -> returns a boolean true value if none of them satisfies the condition, else return false
	cout << none_of(v.begin(), v.end(), [](int x) {return x > 5;}) << endl;
	// can be used with arrays
	/*
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	cout << *min_element(v.begin(), v.end()) << endl; // returns iterator to min element
	cout << *max_element(v.begin(), v.end()) << endl; // returns iterator to max element
	int sum = accumulate(v.begin(), v.end(), 0); // returns sum value -> (start, end, initial_sum_value)
	cout << sum << endl;
	int ct = count(v.begin(), v.end(), 6);
	// returns count of the required element -> (start,end,value)
	cout << ct << endl;
	// int element = *find(v.begin(), v.end(), 1);// returns iterator to the element we want to find
	// cout << element << endl;
	auto it = find(v.begin(), v.end(), 10);
	if (it != v.end()) cout << *it << endl;
	else cout << "Not Found" << endl;
	reverse(v.begin(), v.end()); // reverses the vector, array or string
	for (auto val : v) {
		cout << val << " ";
	}
	cout << endl;
	string s = "abcdefghij";
	reverse(s.begin(), s.end());
	cout << s << endl;
	*/
}
// All these functions we use on arrays and vectors they work in O(N) internally. maps and sets these ops are log(n).
// arrays -> v,v+n
// Offline queries vs Online Queries =>
// no updates --------- updates present