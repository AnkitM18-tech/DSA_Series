#include<bits/stdc++.h>
using namespace std;

/*
unordered_map<char, int> symbols = {{'[', -1}, {'{', -2}, {'(', -3}, {']', 1}, {'}', 2}, {')', 3}};

string isBalanced(string s) {
	stack<char> st;
	for (char bracket : s) {
		if (symbols[bracket] < 0) { // pushing opening brackets into the stack
			st.push(bracket);
		} else {
			if (st.empty()) return "NO";
			char top = st.top();
			st.pop();
			if (symbols[top] + symbols[bracket] != 0) { // checking if addition of top and element in the stack is 0 or not.
				return "NO";
			}
		}
	}
	if (st.empty()) return "YES";
	return "NO";
}
*/
vector<int> NGE(vector<int> v) {
	vector<int> nge(v.size());
	stack<int> st;
	for (int i = 0; i < v.size(); ++i) {
		while (!st.empty() && v[i] > v[st.top()]) {
			nge[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	while (!st.empty()) {
		nge[st.top()] = -1;
		st.pop();
	}
	return nge;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*
	stack<int> s;
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}

	queue<string> q;
	q.push("ankit");
	q.push("anya");
	q.push("neha");
	while (!q.empty()) {
		cout << q.front() << endl;
		q.pop();
	}

	// Balanced Paranthesis
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		cout << isBalanced(s) << endl;
	}

	*/
	// Next Greater Element
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	vector<int> nge = NGE(v);
	for (int i = 0; i < n; ++i) {
		cout << v[i] << " " << (nge[i] == -1 ? -1 : v[nge[i]]) << endl;
	}
}
// Stack -> LIFO -> push,pop,top
// Queue -> FIFO -> push,pop,front