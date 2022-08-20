#include<bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
// const long long int M = 1e18 + 7;
/*
// a <= 10^9 , b <= 10^9 , M
// Iterative method -> faster than recursive method
int binExpIter(int a, int b) {
	int ans = 1;
	while (b > 0) {
		if (b & 1) {
			ans = (ans * 1LL * a) % M;
		}
		a = (a * 1LL * a) % M;
		b >>= 1;
	} // TC: O(log(b)) ,b = power
	return ans;
}
*/

// b <= 10^18 -> the below code will run, but we can only give upto 10^18 directly here, not more than that.
int binExpIter(int a, long long b, int m) {
	int ans = 1;
	while (b > 0) {
		if (b & 1) {
			ans = (ans * 1LL * a) % m;
		}
		a = (a * 1LL * a) % m;
		b >>= 1;
	} // log(b) times the loop is running
	return ans;
}

/*
	a^(b^c) % M; let take b = b^c it can be very large

	50^(64^32) -> it will be very difficult, we can not divide 64^32 (right shift)

	co-prime -> gcd(a,b) = 1
	ETF -> Euler Totient Function
	any number N -> 1 se le kar N tak jitne values hain, usme se jo v N ke co-prime hain woh uski ETF value hai.
	N -> count of K such that 1 <= K <= N
	where K and N are co-prime.

	e.g: 5 -> 1,2,3,4 = 4 ETF value
	phi(6) -> [1,5] = 2      __
	ETF value = Phi(n) = n * ||(1-1/p) [ multiplication of all distinct prime factors(duplicates not taken)] p = prime factors of n.

	phi(5) = 5 * (1-1/5) = 4
	phi(6) = 6 * (1-1/2) * (1-1/3) = 6 * 1/2 * 2/3 = 2

	(a^b) % M (b in terms of b % M-> Euler's Theorem -> a^b congruent (a ^ (b % phi(n))) % n => if we divide a^b with n then remainder will be a ^ (b % phi(n)).

	(a^b % n) = (a^(b % phi(n)) % n

	a ^ b % M
	= (a ^ (b % phi(M))) % M , M any number
	= (a ^ (b % (M-1))) % M , M is prime

	n is prime => phi(n) = n(1-1/n) = n - 1
*/


/*
// a <= 10^18 , 2 ^ 1024
int binExpIter(int a, int b) {
	a %= M; // if a's value is big -> 10^18
	a = binExpIter(2, 1024); // 2 ^ 1024
	int ans = 1;
	while (b > 0) {
		if (b & 1) {
			ans = (ans * 1LL * a) % M;
		}
		a = (a * 1LL * a) % M;
		b >>= 1;
	} // TC: O(log(b)) ,b = power
	return ans;
}
*/

long long binMultiply(long long int a, long long int b) {
	int ans = 0;
	while (b > 0) {
		if (b & 1) {
			ans = (ans + a) % M;
		}
		a = (a + a) % M;
		b >>= 1;
	} // TC: O(log(b)) ,b = power
	return ans;
}

// N = 1e18 -> when M's value is large
long long binExpIter(long long a, long long b) {
	a %= M; // if a's value is big -> 10^18
	// a = binExpIter(2, 1024); // 2 ^ 1024
	int ans = 1;
	while (b > 0) {
		if (b & 1) {
			// ans = (ans * 1LL * a) % M;
			ans = binMultiply(ans, a);
		}
		// a = (a * 1LL * a) % M; // we can't multiply a * a, if a is in range of 1e18 as there will be overflow.
		a = binMultiply(a, a);
		b >>= 1;
	} // TC: O(log^2(n))
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// 50 ^ 64 ^ 32 % M
	cout << binExpIter(50, binExpIter(64, 32, M - 1), M);
}

/*
	50 ^ (64 ^ 32) % M => (50 ^ (64^32 % M-1)) % M
	the power again can be calculated using binary exponentiation
*/

// a^b % M = ((a%M)^b) % M, using this we can bring a to int range

/*
// Step multiplication
// a = 10^18, a*a -> add a, a times
// a + a + a ..... + a times
a + a < 2 * 10^18
	% M < 10^18 , cause M is 10^18
  + a < 2 * 10^18
  	% M < 10^18
  	... do it a times -> it will take us O(n) time, if we run a loop.

  	a * b -> 3 * (13) -> 3 * (1101) -> 3 * (8+4+0+1) -> here the max binary bits will be log(n) (2's power). So we can solve it in O(log(n)) TC.

  	3 -> 3 -> 0th
  	add the number(a)
  	6 -> - -> 1st
  	12 -> 15 -> 2nd
  	24 -> 39 -> 3rd

  	same procedure as exponentiation, but we add here when bit is set. we can't directly multiply them , rather we add and then % M them.
*/