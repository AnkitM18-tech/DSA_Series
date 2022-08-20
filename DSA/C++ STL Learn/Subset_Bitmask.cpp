#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
	int n = nums.size();
	int subsets_ct = (1 << n);
	vector<vector<int>> subsets;
	for (int mask = 0; mask < subsets_ct; ++mask) {
		vector<int> subset;
		for (int i = 0; i < n; ++i) {
			if ((mask & (1 << i)) != 0) {
				// cout << ((mask & (1 << i))) << endl;
				subset.push_back(nums[i]);
			}
		}
		subsets.push_back(subset);
	} // O(n * 2^n) , in recursion TC is O(2^n)
	return subsets;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	auto all_subsets = subsets(v);
	for (auto subset : all_subsets) {
		for (int ele : subset) {
			cout << ele << " ";
		}
		cout << endl;
		// cout << (2 & (1 << 0));
	}
	// cout << (2 & 1) << endl;
	// cout << (1 << 2) << endl;
}

/*

n size array -> subsets = 2^n
[2,4,5] = 8  n = 2^n
Bitmask of n size array ranges from -> 0 to (2^n)-1 = total = 8 numbers
Bitmasks for the abpve ->

	5 4 2 -> array
	2 1 0 -> ith bit
0 - 0 0 0 - []
1 - 0 0 1 - [2]
2 - 0 1 0 - [4]
3 - 0 1 1 - [2,4]
4 - 1 0 0 - [5]
5 - 1 0 1 - [2,5]
6 - 1 1 0 - [4,5]
7 - 1 1 1 - [2,4,5]

we will get bitmasks -> whichever bit is set in a bitmask, then we will include that element in our subset

*/