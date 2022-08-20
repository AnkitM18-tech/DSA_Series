#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	vector<int> masks(n, 0);
	for (int i = 0; i < n; ++i) {
		int num_workers;
		cin >> num_workers;
		int mask = 0;
		for (int j = 0; j < num_workers; ++j) {
			int day;
			cin >> day;
			mask = (mask | (1 << day));
		}
		masks[i]  = mask;
	}
	int max_days = 0;
	int person1 = -1;
	int person2 = -1;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int intersection = (masks[i] & masks[j]);
			int common_days = __builtin_popcount(intersection);
			if (common_days > max_days) {
				max_days = common_days;
				person1 = i;
				person2 = j;
			}
			max_days = max(max_days, common_days);
			// cout << i << " " << j << " " << common_days << endl;
		}
	}
	cout << person1 << " " << person2 << " " << max_days << endl;
	// TC: O(N^2 * 30) -> Normally, with Bit mask it is O(N^2)
}

/*
	We can find the intersection of 2 sorted arrays in O(N) time. N = no of fruits
			  3	2 1	0
	1. 2,3 -> 1 1 0 0 -> bit representation of this set.
	2. 0,1,2 -> 0 1 1 1
	3. 1,3 -> 1 0 1 0

	we have 4 types of fruit. We can use bit masking

	we can find common fruit using AND op.
	AND of sets will give the common fruit. Just like the intersection.
	AND op is O(1), hence we can save time when number of fruits are larger. We can use bit masking rather than intersection.

	And the number should be small, unsigned int we can take 32, unsigned long long 64. Then we can't use bit mask. int = 31, long long = 63
*/