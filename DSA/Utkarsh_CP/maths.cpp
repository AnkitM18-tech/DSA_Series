#include<bits/stdc++.h>
using namespace std;


int main() {

}

/*

	Primality Check ->
		Counting Divisors

	i:(1...n) -> n%i == 0 -> O(n)
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			cnt++;
		}
	}
	cout << cnt;

	Optimized Way ->
	if i/n ==> (n/i)/n
	i * (n/i) = n -> n/i is also a divisor

	for (n)^1/2 -> if i < (n)^1/2 then n/i is > (n)^1/2 or vice versa

	for every divisor < (n)^1/2 we will check n/i, -> O((n)^1/2)-> i:(1...(n)^1/2)

	if we want to find number of divisors for a range of numbers then also takes a lot of time ~ n * (n)^1/2. So instead of wasting time on all comparisons, compare only iterate on multiples instead of finding factors upto n.

	int cnt_divisors(int n) {
	int cnt = 0;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			cnt++; // i is a factor
			if (i != (n / i)) {
				cnt++; // (n/i) is also a factor
			}
		}
	}
	return cnt;
	}

	int main() {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) // this also takes a lot of time ~ n * (n)^1/2
		{
			cout << cnt_divisors(i) << "\n";
		}
	}

	Much faster approach

	int main() {
		int n;
		cin >> n;
		vector<int> div(n + 1);

		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j += i) {
				div[j]++; // i is a divisor of j
			}
		}
		//time complexity for this would look like ->
		// n/1 + n/2 + n/3 + n/4 + ... + n/n -> O(nlogn)

		for (int i = 1; i <= n; i++) {
			cout << div[i] << "\n";
		}
	}

	Sieve of Eratosthenes ->

	1,2,3,4,5...100
	2 is a prime number so mark all 2's multiple -> they are not prime
	3 is a prime number so mark all 3's multiple -. they are not prime
	so on -> this goes on upto our desired number

	int n;
	cin >> n;
	vector<int> prime(n + 1, 1);
	prime[1] = 0;

	//O(nlog(log(n))) -> very fast -> almost linear
	for (int i = 2; i <= n; i++) {
		if (!prime[i]) continue;
		for (int j = i * i; j <= n; j += i) {
			prime[j] = 0;
		}
	}

	//prime[x] stores if x is prime or not

	Template of Sieve ->
	const int N = 100000

	#define SIEVE
	int primes[N];
	vector<int> pr;
	void sieve() {
		for(int i=2;i<N;i++){
			if(primes[i]==0){
				pr.pb(i);
				for(int j=i*i;j<N;j+=i){
					primes[j] = 1;
				}
			}
			primes[i]^=1;
		}
	}

	GCD -> Greatest Common Divisor

	co-prime numbers -> GCD(a,b) = 1

	euclidian way to find gcd -> gcd(a,b) = gcd(a,b-a) -> given that b > a
	e.g = gcd(8,18) = gcd(8,10)

	so gcd(a,b) = gcd(b%a,a) -> euclidian gcd algorithm
	Time Complexity -> O(log(max(a,b))) -> very fast

	// it is already implemented in c++ , __gcd(a,b)
	int gcd(int a, int b) {
		if (a == 0) {
			return b;
		}
		return gcd(b % a, a);
	}

	int main() {
	int a, b;
	cin >> a >> b;
	cout << __gcd(a, b);
	}

*/

/*
	Modulo Arithmetic

	instead of answer, just asked for even or odd or mod 10^9 + 7

	Specific case of mod arithmetic -> even or odd -> (ans mod 2)

	e + e = e
	o + o = e
	e + o = o + e = o

	e * e = e * o = o* e = e
	o * o = o

	so just by storing whether the numbers are even or odd, we can easily tell the answer without having to store large numbers.

	(a+b) % m = ((a % m) + (b % m)) % m;
	whenever a number is even -> remainder 0
	whenever a number is odd -> remainder 1

	a -> k1m + r1
	b -> k2m + r2
	a + b -> (k1 + k2)m + (r1 + r2) -> part 1 is multiple of m, so it will get 0 when divided by m. so 2nd part is remainder ->
	r1 = a % m , r2 = b % m

	(a * b)% m = ((a % m) * (b % m)) % m
	(a - b)% m = ((a % m) - (b % m) + m) % m -> + m is to ensure the value is never less than 0.
	(a ^ b)% m -> O(b) -> multiply a, b times

	To do it faster we will use recursion ->
	 a^b = {
				1, b=0
				(a^(b/2))^2, b=even
				a.(a^((b-1)/2)^2), b=odd
	 		}


	// binary exponentiation or binpow
	// O(log b) -> faster
	int pw(int a, int b, int m) {
		if (b == 0) {
			return a % m;
		}
		if (b % 2 == 0) {
			int t = pw(a, b / 2, m);
			return (1ll * t * t % m); // chances of t * t overflow so multiply 1ll
		}
		else {
			int t = pw(a, (b - 1) / 2, m);
			t = (1ll * t * t) % m; //to prevent overflow multiply 1ll
			return 1ll * a * t % m;
		}
	}

	int main() {
		int a, b, m;
		cin >> a >> b >> m;
		cout << pw(a, b, m);
	}

	//Division under mod
	we use multiplicative inverse, we don't divide instead we multiply the number with its multiplicative inverse.

	6 / 2 % 5 -> 6 % 5 -> 1 and 2 % 5 -> 2
	-> 1 * 2 ^ -1 = 1 * 3 = 3 -> 3 % 5 = 3 and 6/2 = 3 % 5 = 3

	multiplicative inverse of 2 -> 2x % 5 = 1, then x is the multiplicative inverse of 2.
	2 ^ -1 = 3

	38/2 % 5 -> 38 % 5 -> 3 and 2 % 5 -> 2
	-> 3 * 3 = 9 % 5 -> 4 and 38/2 = 19 % 5 -> 4

	What is the guarantee that multiplicative inverse exist?
		-> inverse of b exists in % m => gcd(b,m) = 1
		-> usually m is prime number and prime numbers are co-prime to all other numbers smaller than them , so obviously b will be co-prime to m.
		-> that's why 10^9 + 7 is so famous, as it is prime and sufficiently large and easy to remember.

	How to find it?
		-> If we go until m - 1 numbers it will be very slow -> O(m)
		-> to find b ^ -1, find b ^ (m-2). b ^ -1 = b ^ (m-2) % m
		-> using binpow we can find it in O(log m) time. -> Only for prime number m

	Demonstration ->

	int pw(int a, int b, int m) {
	if (b == 0) {
		return a % m;
	}
	if (b % 2 == 0) {
		int t = pw(a, b / 2, m);
		return (1ll * t * t % m); // chances of t * t overflow so multiply 1ll
	}
	else {
		int t = pw(a, (b - 1) / 2, m);
		t = (1ll * t * t) % m; //to prevent overflow multiply 1ll
		return 1ll * a * t % m;
	}
	}

	int inverse(int x, int m) {
		return pw(x, m - 2, m);
	}

	int main() {
		int a, b, m;
		cin >> a >> b >> m; // only if m is prime

		int res1 = (a / b) % m;

		a = a % m;
		int inv_b = inverse(b, m); //fermat's little theorem

		int res2 = a * inv_b % m;
		cout << res1 << " " << res2;
	}

*/

/*
	Combinatorics ->
		-> Permutations and Combination
		-> nCr = n!/r!(n-r)!
		-> Combined with mod arithmetics
		-> n! -> very slow -> O(n)
		-> We can store the factorials and use them later -> to increase performance -> O(log n)
		-> We can further improve the complexity to O(1) -> If we store inverse as well.
		-> fact[] -> O(n) to store, inv_fact[] -> O(n log m) to store
		-> find factorials first and then find inverse factorials as well.
		n!^-1 -> (n-1)!^-1 = n * inv_fact[n]
		1/n! = 1/n * (n-1)! => n/n! = 1/(n-1)! => (n-1)!^-1 = n * n!^-1

	In this way we can find big factorials in linear time complexity.

	#define NCR
	#define PRIME M
	int pw(int a, int p = M - 2, int MOD = M) {
		int result = 1;
		while (p > 0) {
			if (p & 1) {
				result = a * result % MOD;
			}
			a = a * a % MOD;
			p >>= 1;
		}
		return result;
	}
	int fact[N], invfact[N];
	void init() {
		int p = PRIME;
		fact[0] = 1;
		int i;
		for (i = 1; i < N; i++) {
			fact[i] = i * fact[i - 1] % p;
		}
		i--;
		invfact[i] = pw(fact[i], p - 2, p);
		for (i--; i >= 0; i--) {
			invfact[i] = invfact[i + 1] * (i + 1) % p;
		}
	}
	int ncr(int n, int r) {
		if (r > n || n < 0 || r < 0) return 0; // ncr is not valid
		return fact[n] * invfact[r] % PRIME * invfact[n - r] % PRIME;
	}
*/