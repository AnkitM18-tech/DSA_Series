#include<bits/stdc++.h>
using namespace std;
/*
const int N = 1e6 + 10;
long long n; // n trees
long long m; // m wood
long long trees[N];

bool isWoodSufficient(int h) {
	long long wood = 0;
	for (int i = 0; i < n; ++i) {
		if (trees[i] >= h) {
			wood += (trees[i] - h);
		}
	}
	return wood >= m;
}
*/
const int N = 1e5 + 10;
int n, cows;
int positions[N];

bool canPlaceCows(int minDist) {
	int lastPos = -1;
	int cows_cnt = cows;
	for (int i = 0; i < n; ++i) {
		if (positions[i] - lastPos >= minDist || lastPos == -1) {
			cows_cnt--;
			lastPos = positions[i];
		}
		if (cows_cnt == 0) {
			break;
		}
	}
	return cows_cnt == 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> cows;
		for (int i = 0; i < n; ++i) {
			cin >> positions[i];
		}
		sort(positions, positions + n); // Nlog(n)
		int lo = 0, hi = 1e9, mid;
		while (hi - lo > 1) {
			mid = (hi + lo) / 2;
			if (canPlaceCows(mid)) {
				lo = mid;
			} else {
				hi = mid - 1;
			}
		} // log((search space)10^9) * N
		if (canPlaceCows(hi)) {
			cout << hi << endl;
		} else {
			cout << lo << endl;
		}
	}
	/*
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> trees[i];
	}
	long long lo = 0, hi = 1e9, mid;
	while (hi - lo > 1) {
		mid = (hi + lo) / 2;
		if (isWoodSufficient(mid)) {
			lo = mid;
		} else {
			hi = mid - 1;
		}
	}
	if (isWoodSufficient(hi)) {
		cout << hi << endl;
	} else {
		cout << lo << endl; // as it is mentioned in the question that we will always get M amount of wood.
	}
	// TC : O(Nlog(H)) N -> array size | H -> height
	*/
}

/*
	Predicate function => Returns True/False
	Binary Search can be performed on monotonic predicate functions -> consistent behavior
	TTTFFFF -> after some point it return only True and before that False
	FFFTTTT -> after some point it return only True and before that False
	Using Binary Search we can find last True or First False.

	//EKO
	func(height) -> max height sawable
	wood >= M -> True
	else -> False

	Increasing the height gradually from 0 to find last True, where we won't get M wood, it will decrease.

	0 x ------h
	T T T T T F

	//AGGRCOW
	maximize the minimum distance b/w cows
	m.d - 0 T
	m.d - 1 T
	m.d - 2 T
	m.d - 3 T
	m.d - 4 T
	m.d - 5 T
	m.d - 10 F
	T T T T T T F F F F -> predicate function
	func(min_distance) -> T F
	find last True, that would be maximum min_distance. increasing the min_dist from 0 to d
*/
/*
//EKO

#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
long long n; // n trees
long long m; // m wood
long long trees[N];

bool isWoodSufficient(int h) {
	long long wood = 0;
	for (int i = 0; i < n; ++i) {
		if (trees[i] >= h) {
			wood += (trees[i] - h);
		}
	}
	return wood >= m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> trees[i];
	}
	long long lo = 0, hi = 1e9, mid;
	while (hi - lo > 1) {
		mid = (hi + lo) / 2;
		if (isWoodSufficient(mid)) {
			lo = mid;
		} else {
			hi = mid - 1;
		}
	}
	if (isWoodSufficient(hi)) {
		cout << hi << endl;
	} else {
		cout << lo << endl; // as it is mentioned in the question that we will always get M amount of wood.
	}
	// TC : O(Nlog(H)) N -> array size | H -> height
}
*/

// TC in Recursion
// Number of Function Calls * TC of one function Call
// Generate Paranthesis -> O(2^n) -> recursion tree is divided into  2 sections
// Subset generation -> O(2^n) -> recursion tree is divided into 2 sections