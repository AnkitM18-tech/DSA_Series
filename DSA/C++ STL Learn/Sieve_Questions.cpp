#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;
int a[N];
int hp[N];
int canRemove[N]; // if i can be removed or not 1/0
int hsh[N]; // if a number is present or not
// int multiple_ct[N];
vector<int> distinctPF(int x) {
	vector<int> ans;
	while (x > 1) {
		int pf = hp[x];
		while (x % pf == 0) x /= pf;
		ans.push_back(pf);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*// Monk & Divisor Conundrum - Hacker Earth
	// inclusion & exclusion => x+y-z
	// Our motive is to pre-compute the possible multiples in an array.So we can use sieve approach.
	// We will store the number of multiples of a number as the value in that index.
	// ct[i] = multiples of i in array.
	// TC : n/2 + n/3 + n/4 + ... as we are operating with multiples in the array.
	// Our answer will be ct[p] + ct[q] - ct[lcm(p,q)], for values p & q
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		hsh[x] ++;
	}
	for (int i = 1; i < N; ++i) {
		for (int j = i; j < N; j += i) {
			multiple_ct[i] += hsh[j];
		}
	}
	// for (int i = 0; i < 10; ++i) {
	// 	cout << i << " " << multiple_ct[i] << endl;
	// }
	int q; cin >> q;
	while (q--) {
		int p, q;
		cin >> p >> q;
		long long lcm = p * 1LL * q / __gcd(p, q);
		long ans = multiple_ct[p] + multiple_ct[q];
		if (lcm < N) {
			ans -= multiple_ct[lcm];
		}
		cout << ans << "\n";
	}*/
	/*
		Hacker Decrypting Messages.
		for the number 10^6, the no of distinct prime factors will be less than 10, because the multiplication of first 10 prime numbers exceed 10^6.
	*/
	for (int i = 2; i < N; ++i) {
		if (hp[i] == 0) {
			for (int j = i; j < N; j += i) {
				hp[j] = i;
			}
		}
	}
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x; hsh[x] = 1;
	}
	for (int i = 2; i < N; ++i) {
		if (hsh[i]) { // mark the ith num and all its powers as well.
			for (long long j = i; j < N; j *= i) {
				canRemove[j] = 1;
			}
		}
	}
	while (q--) {
		int x;
		cin >> x;
		vector<int> pf = distinctPF(x);
		bool isPossible = false;
		for (int i = 0; i < pf.size(); ++i) {
			for (int j = i; j < pf.size(); ++j) {
				int product = pf[i] * pf[j];
				if (i == j &&  x % product != 0)  continue; // if the number exists twice in the PF vector.
				int toRemove = x / product;
				if (canRemove[toRemove] == 1 || toRemove == 1) { //toRemove ==1 if the number is made of two numbers
					isPossible = true;
					break;
				}
			}
			if (isPossible) break;
		}
		cout << (isPossible ? "YES\n" : "NO\n");
	} // TC: O(Q * (N^2 + log(N)))
}