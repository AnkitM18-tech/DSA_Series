#include<bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;
long long ar[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	while (q--) {
		int a, b, d;
		cin >> a >> b >> d;
		ar[a] = ar[a] + d;
		ar[b + 1] -= d;
	}
	for (int i = 1; i <= n; ++i) {
		ar[i] += ar[i - 1];
	}
	long long mx = -1;
	for (int i = 1; i <= n; ++i) {
		if (mx < ar[i]) {
			mx = ar[i];
		}
	}
	cout << mx << endl;
	// TC: O(N) + O(N)
}
/*
	const int N = 1e7 + 10;
	long long ar[N];
	int n, q;
	cin >> n >> q;
	while (q--) {
		int a, b, d;
		cin >> a >> b >> d;
		for (int i = a; i <= b; ++i) {
			ar[i] += d;
		}
	}
	long long mx = -1;
	for (int i = 1; i <= n; ++i) {
		if (mx < ar[i]) {
			mx = ar[i];
		}
	}
	cout << mx << endl;
	// TC: O(Q*N) + O(N)
*/