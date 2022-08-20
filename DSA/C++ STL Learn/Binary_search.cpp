#include<bits/stdc++.h>
using namespace std;
double eps = 1e-7;
// if i want accuracy upto x digits, then I need to take epsilon as 10^-(x+1).
double multiply(double mid, int n) {
	double ans = 1;
	for (int i = 0; i < n; ++i) {
		ans *= mid;
	}
	return ans;
}

/*
//Lower Bound and Upper Bound using Binary Search

int lower_bound(vector<int> &v, int element) {
	int lo = 0, hi = v.size() - 1;
	int mid;
	while (hi - lo > 1) {
		mid = (hi + lo) / 2;
		if (v[mid] < element) {
			lo = mid + 1;
		} else {
			hi = mid;
		}
	}
	if (v[lo] >= element) {
		return lo;
	}
	if (v[hi] >= element) {
		return hi;
	}
	return -1;
}

int upper_bound(vector<int> &v, int element) {
	int lo = 0, hi = v.size() - 1;
	int mid;
	while (hi - lo > 1) {
		mid = (hi + lo) / 2;
		if (v[mid] <= element) {
			lo = mid + 1;
		} else {
			hi = mid;
		}
	}
	if (v[lo] > element) {
		return lo;
	}
	if (v[hi] > element) {
		return hi;
	}
	return -1;
}
*/

// 4^.5 upto 2 precision search space = 1 1.01 1.02 ..... 4 -> monotonic function -> Binary Search
// nth root

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	double x;
	int n;
	cin >> x >> n;
	double lo = 1, hi = x, mid;
	while (hi - lo > eps) {
		mid = (hi + lo) / 2;
		if (multiply(mid, n) < x) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	// TC: 2log(2*10^d(accuracy)) -> square root
	// pth root of Number N => plog(N*10^d(accuracy)) -> from 1 to N every interval there will be 10^d intervals.

	cout << setprecision(10) << lo << "\n" << hi << endl;
	cout << pow(x, 1.0 / n) << endl;
	/*
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	int to_find;
	cin >> to_find;
	int lo = 0, hi = n - 1;
	int mid;
	while (hi - lo > 1) {
		mid = (hi + lo) / 2;
		if (v[mid] < to_find) {
			lo = mid + 1;
		} else {
			hi = mid;
		}
	}
	if (v[lo] == to_find) {
		cout << lo << endl;
	} else if (v[hi] == to_find) {
		cout << hi << endl;
	} else {
		cout << "Not Found";
	}
	*/
	/*
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	int element; cin >> element;
	// Here vector is already sorted, if input is not sorted then sort it before using binary search
	int lb = lower_bound(v, element);
	cout << lb << " " << (lb != -1 ? v[lb] : -1) << endl;
	int ub = upper_bound(v, element);
	cout << ub << " " << (ub != -1 ? v[ub] : -1) << endl;
	*/
}

/*

linear search =>
1 2 3 5 6 7 -> TC: O(N)
We can decrease the TC in case the array is monotonic.
binary search applies on monotonic functions,
which maintain a given order

Order must be followed
1 2 3 4 5 6 -> Increasing array
6 5 4 3 2 1 -> Decreasing array

We can implement binary search on any monotonic function

1 3 5 6 7 -> m
7 4 3 2 1 -> m
1 2 6 5 4 -> n.m
y = x^2 - m

We can also implement binary search on predicate functions, a function which returns true or false.
F F F F T T T T -> after false values it will only return true or vice versa. - monotonic function

Using binary search -> TC: O(log(N))

0 1 2 3 4 5 -> index
2 3 4 5 6 7

search space -> 0 - 5
mid    search space
2 			3-5 -> as it is increasing array(					right of 4)
4 			3-3 -> left side of search space(					left of 6)
3 = 5 found

*/