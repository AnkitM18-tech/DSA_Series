#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int prefixSum[N];
int a[N];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		prefixSum[i] = prefixSum[i - 1] + a[i];
	}
	int q;	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << prefixSum[r] - prefixSum[l - 1] << endl;
	}
	// TC : O(N) + O(Q)
}
/*
int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		long long sum = 0;
		for (int i = l; i <= r; ++i) {
			sum += a[i];
		}
		cout << sum << endl;
	}
	// TC : O(N) + O(Q*N) ~ O(N^2)
*/