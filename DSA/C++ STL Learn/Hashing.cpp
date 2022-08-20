#include<bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
long long fact[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		int ct = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] == x) {
				ct++;
			}
		}
		cout << ct << endl;
	}
	/*
	fact[0] = fact[1] = 1;
	for (int i = 2; i < N; ++i) {
		fact[i] = fact[i - 1] * i;
	}
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		/*
		long long fact = 1;
		for (int i = 2; i <= n; ++i) {
			fact = (fact * i) % M;
		}
		TC : O(T*N) without precomputation technique
		With precomputation technique : O(N) + O(T)

		cout << fact[n] << "\n";
	}
	*/
}
/*
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;++i) {
		cin >> a[i];
	}
	int q;
	cin >> q;
	while(q--) {
		int x;
		cin >> x;
		int ct = 0;
		for(int i=0;i<n;++i) {
			if(a[i] == x) {
				ct++;
			}
		}
		cout << ct << endl;
	}
	TC : O(N) + O(Q*N) ~ O(N^2)
*/
/*
	const int N = 1e7 + 10;
	int hash[N];
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;++i) {
		cin >> a[i];
		hash[a[i]]++;
	}
	int q;
	cin >> q;
	while(q--) {
		int x;
		cin >> x;
		cout << hash[x] << endl;
	}
	TC : O(N) + O(Q)
	Here hashing can be used because max array element is 1e7, if it is to be 1e9 then we can't use hashing as, we can't define array of that size globally(we need the value 1e9). It should be somewhere around 1e7.
*/