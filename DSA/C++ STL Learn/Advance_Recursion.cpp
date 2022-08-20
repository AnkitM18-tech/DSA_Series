#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets;
/*
vector<string> valid;

// Generate Paranthesis
void generate(string &s, int open, int close) {
	if (open == 0 && close == 0) {
		valid.push_back(s);
		return;
	}

	if (open > 0) {
		s.push_back('(');
		generate(s, open - 1, close);
		s.pop_back(); // to maintain the same string for the further steps as we are not altering the string, otherwise the altered string will get considered for closing brackets.
	}
	if (close > 0) {
		if (open < close) { // checking if available opening brackets are less than available closing brackets, as we can only add ')' if No of '(' are more in the string
			s.push_back(')');
			generate(s, open, close - 1);
			s.pop_back(); // maintaining the same state for every check
		}
	}
}
*/
// Subset Generation
void generate(vector<int> &subset, int i, vector<int> &nums) {
	// Base Condition
	if (i == nums.size()) {
		subsets.push_back(subset);
		return;
	}
	// ith element not in subset
	generate(subset, i + 1, nums);
	// ith element in subset
	subset.push_back(nums[i]);
	generate(subset, i + 1, nums);
	subset.pop_back(); // back tracking step
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*
	int n; cin >> n;
	string s;
	generate(s, n, n);
	for (auto ele : valid) {
		cout << ele << endl;
	}
	*/
	int n; cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}
	vector<int> empty;
	generate(empty, 0, nums);
	for (auto subset : subsets) {
		for (auto ele : subset) {
			cout << ele << " ";
		}
		cout << endl;
	}
}

/*
	n = 2

	("",2,2)_____
		|		|
	("(",1,2)   X
	|		|
("((",0,2)  ("()",1,1)--|_____________
|		|				|			|
X       ("(()",0,1)  ("()(",0,1)    X
			|				|
	("(())",0,0)      ("()()",0,0)

	to maintain the same state for a recursion we have to pop back the paranthesis. (back tracking)
*/
/*
	[]
	[1]
	[1,2]
	[1,2,3]
	[2]
	[2,3]
	[3]
	[1,3]

*/