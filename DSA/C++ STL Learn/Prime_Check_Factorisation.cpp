#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*
	// Prime Check
	int n; cin >> n;
	bool isPrime = true;
	for (int i = 2; i < n; ++i) {
		if (n % i == 0) {
			isPrime = false;
			break;
		}
	} // TC: O(N)
	cout << isPrime << endl;

	// SQRT(N) Prime Check
	int n; cin >> n;
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
	bool isPrime = true;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			isPrime = false;
			break;
		}
	} // TC: O(N^1/2)
	cout << isPrime << endl;

	// SQRT(N) Check is valid in this case also.

	int n; cin >> n;
	vector<int> prime_factors;
	for (int i = 2; i <= n; ++i) {
		while (n % i == 0) {
			prime_factors.push_back(i);
			n /= i;
		}
	} // TC: O(N)
	for (int prime : prime_factors) {
		cout << prime << " ";
	}
	*/
	int n; cin >> n;
	vector<int> prime_factors;
	for (int i = 2; i * i <= n; ++i) {
		while (n % i == 0) {
			prime_factors.push_back(i);
			n /= i;
		}
	} // TC: O(N^1/2)
	if (n > 1) { // will only come in case there is one prime number left because it won't go into the for loop, so we add that also.
		prime_factors.push_back(n);
	}
	for (int prime : prime_factors) {
		cout << prime << " ";
	}
}

// Any number's smallest divisor is prime , except for 1. Prime Factorisation -> divide by prime numbers until we get 1.

/*
int n; cin >> n;
vector<int> prime_factors;
for (int i = 2; i * i <= n; ++i) {
	while (n % i == 0) {
		prime_factors.push_back(i);
		n /= i;
	}
} // TC: O(N)
for (int prime : prime_factors) {
	cout << prime << " ";
}

there will exist atleast one prime number before sqrt(N) if N is a composite number(no-prime). Now if after division the remaining N is a prime number (like 3) then there won't be any prime number smaller than that. In that case our algo will fail and that number won't be added.

*/