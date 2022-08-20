#include<bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

const int N = 1e5 + 10;
int fact[N];

int binExp(int a, int b, int m) {
	int result = 1;
	while (b > 0) {
		if (b & 1) {
			result = (result * 1LL * a) % m;
		}
		a = (a * 1LL * a) % m;
		b >>= 1;
	}
	return result;
}

/*
	There are N children and K toffees, K < N. Count the number of ways to distribute toffees among N students such that each student get 1 toffee only. ==  nCk % M, M = 1e9 + 7  == N < 10^6, K < N < 10^6, Q < 1e5 -> Queries => use pre-computation.

	nCr = n! / ((n-r)! * r!)
*/

/*
	Alphabets -- K symbols, N size password, K > N
	we have to choose N symbols from K alphabets, each symbol can be chosen once, kCn -- number of ways we can choose n symbols from k symbols. now comes the arrangement part --> (kCn) * n!
*/

// const int N = 1e6 + 10;
// int fact[N];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	fact[0] = 1;
	for (int i = 1; i < N; ++i) {
		fact[i] = (fact[i - 1] * 1LL * i) % M;
	} // O(N)
	while (t--) {
		int n, k;
		cin >> n >> k;
		int ans = fact[n];
		ans = (ans * 1LL * fact[k]) % M;
		int den = (fact[k - n] * 1LL * (fact[n])) % M;
		ans = (ans * 1LL * binExp(den, M - 2, M)) % M;
		cout << ans << endl;
	}
	// TC: O(t * log(N) + N)

	/*// int a;
	// cout << binExp(a, M - 2, M); // inverse of a.
	fact[0] = 1;
	for (int i = 1; i < N; ++i ) {
		fact[i] = (fact[i - 1] * 1LL * i) % M; // % M will bring it back to int range.
	}
	int q; cin >> q;
	while (q--) {
		int n, k;
		cin >> n >> k;
		int ans = fact[n];
		int denom = (fact[n - k] * 1LL * fact[k]) % M;
		ans = ans * binExp(denom, M - 2, M);
		cout << ans << endl;
	}*/
}

/*
	MMI ->

	(A/B) % M != ((A%M)/(B%M))%M
			  == (A * B^-1)%M = ((A % M) * ((B^-1) % M)) % M
	B^-1 % M => MMI of B
	A * B = 1 => B is MI of A
	(A * B) % M = 1 => B is MMI of A
	as we can break it like =>
	(A % M * B % M) % M = 1 => i.e B will be less than M , so it's range can be taken as 1 <= B < M - 1

	Loop B = 1 -> M - 1
	(A * B) % M = 1 => B is MMI.
	TC : O(M) -> M is very large, so not a optimized way.

	MMI doesn't exist for every number, we need to find MMI of A wrt M. whenever A and M are co-prime then only MMI of A can exist and it can be found out. co-prime = GCD(A,M) = 1

	It can be found out using Fermet's (little) theorem.

	A^(M-1) ~ 1 mod (M)-> Congruency of numbers -> if A^(M-1) is divided by M then remainder will be 1. M = Prime , A = not a multiple of M.
	e.g = M = 3 , A = 2 => 4 % 3 = 1.

	Multiply both sides by A^-1.
	A^(M-2) ~ A^-1 mod (M) => (A^(M-2) % M) = A^-1

	(A^(M-2) % M) => can be solved using binary exponentiation. i.e. binExp(A,M-2) -> TC: log(N)

	If A is non-prime, then we use Extended Euclid Algorithm to find MMI.but generally these cases are not frequent.
*/