#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
// Q < 10^7, N < 10^7 -> won't pass with 10^7 * sqrt(10^7). if we used sqrt(N) algo, then TC would have been Q * sqrt(N). The following sieve algorithm will run this case.
vector<bool> isPrime(N, 1); // assume all numbers are prime.
vector<int> lp(N, 0), hp(N, 0);
vector<int> divisors[N];
int sum[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// Sieve Algorithm
	/*isPrime[0] = isPrime[1] = false;
	for (int i = 2; i < N; ++i) {
		if (isPrime[i] == true) {
			lp[i] = hp[i] = i; // a prime number's lowest prime and highest prime is the number itself.
			for (int j = 2 * i; j < N; j += i) {
				isPrime[j] = false;
				hp[j] = i; // j is a multiple of i ,last prime number that will mark j will be the highest prime number for j.hence we will iterate and update that value for j. highest prime will get replaced by recent primes that mark j.
				if (lp[j] == 0) { // initial marking only
					lp[j] = i;
				}
				// if a prime number i is marking j then we will not mark j for other upcoming numbers.
			}
		}// TC : N * (n/2 for 2's multiple + n/3 for 3's multiple + n/4 for 4's multiple + ... + n/n) if isPrime check is removed [TC : N*Log(N)] else it will run for primes only = O(N*log(log(N))) -> approximate*/

	// Divisors variation of sieve - remove the prime check
	// isPrime[0] = isPrime[1] = false;
	for (int i = 2; i < N; ++i) {
		// if (isPrime[i] == true) {
		// 	lp[i] = hp[i] = i; // a prime number's lowest prime and highest prime is the number itself.
		for (int j = i; j < N; j += i) { // running for multiples of i
			/*isPrime[j] = false;
			hp[j] = i; // j is a multiple of i ,last prime number that will mark j will be the highest prime number for j.hence we will iterate and update that value for j. highest prime will get replaced by recent primes that mark j.
			if (lp[j] == 0) { // initial marking only
				lp[j] = i;
			}*/
			// if a prime number i is marking j then we will not mark j for other upcoming numbers.
			divisors[j].push_back(i);
			sum[j] += i;
		} // TC : N log(N) = N(1/2+1/3+1/4+...+1/N) - applicable for upto 10^5 , sometimes give TLE for higher ranges.(>= 1e7 )
		// }
	}

	for (int i = 1; i < 10; ++i) {
		for (int div : divisors[i]) {
			cout << div << " ";
		}
		cout << endl;
	}

	// Prime Factorization
	// we can use hp or lp for prime factorization.
	/*int num; cin >> num;
	vector<int> prime_factors;
	while (num > 1) {
		int prime_factor = hp[num];
		while (num % prime_factor == 0) {
			num /= prime_factor;
			prime_factors.push_back(prime_factor);
		}
	} //TC: ~ log(N)*/

	/*// Counting prime factors using maps, we can use unordered_maps here as we are only storing count.
	int num; cin >> num;
	map<int, int> prime_factors;
	while (num > 1) {
		int prime_factor = hp[num];
		while (num % prime_factor == 0) {
			num /= prime_factor;
			prime_factors[prime_factor]++;
		}
	} //TC: ~ log(N)
	for (auto factor : prime_factors) {
		cout << factor.first << " " << factor.second << "\n";
	}*/

	// we can make other optimizations like i*i < N (sqrt(N)) or j = i*i, it will produce same accurate results.

	// N(1/2 + 1/3 + 1/4 + 1/5 + ....) = Nlog(N) approximate.

	/*for (int i = 1; i < 100; ++i) {
		cout << lp[i] << " " << hp[i] << endl;
	}*/

	/*int q; cin >> q;
	while (q--) {
		int num; cin >> num;
		if (isPrime[num]) { // this check now becomes O(1) as we have already marked the vector.
			cout << "Prime\n";
		} else {
			cout << "Not Prime\n";
		}
	} // TC: Q * O(1)*/

	/*for (int i = 1; i < 100; ++i) {
		cout << isPrime[i] << endl;
	}*/
}

/*
In sieve algorithm, we assume that every number is a prime number in that range. We mark 1 out. Then we strike out the multiples of numbers starting from 2 as they are not prime. Likewise we iterate. We go to the non-striked out numbers and continue the process.

*/