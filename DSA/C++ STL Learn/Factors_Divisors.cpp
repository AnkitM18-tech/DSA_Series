#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*
	// normal divisor check, count and sum
	int n; cin >> n;
	int ct = 0; int sum = 0;
	for (int i = 1; i <= n; ++i) {
		if (n % i == 0) {
			cout << i << endl;
			ct++;
			sum += i;
		}
	}
	cout << ct << " " << sum << endl;
	// TC: O(N)
	*/
	// SQRT method
	int n; cin >> n;
	int ct = 0; int sum = 0;
	for (int i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			cout << i << " " << n / i << endl;
			ct += 1;
			sum += i;
			if (i != n / i) {
				sum += n / i;
				ct += 1;
			}
		}
	}
	cout << ct << " " << sum << endl;
} // TC : O(N^1/2)

// Above method will fail if we give Q queries 10^6 and for each query we need to find all the things, count,sum etc.

/*
	SQRT method

	1 * 24
	2 * 12
	3 * 8
	4 * 6
	-------------- repeated pattern, so we need to go to sqrt(n) numbers to find all, coz after that there will be repeated pattern afterwards. when n1 * n2 -> n1 may be equal to n2.

	6 * 4
	8 * 3
	12 * 2
	24 * 1

	TC : O(N^1/2)

	we can derive formula for count and sum =>
	using prime factorisation , x = p1^n1 * p2^n2 * p3^n3 ...

	36 = 2^2 * 3^2 = 2 * 2 * 3 * 3 => if we take any subset of the factorisation then we can get factors/divisors.

	applying permutations and combinations -->
	we can get (n1+1) * (n2+1) * (n3+1) -> kitne type se factors choose kar sakte hain... 2,2^2,3,3^2,2*3,4*3 ...etc. We can choose from 0 -> n1, 0 -> n2, 0-> n3 like this.

	no of divisors = (n1+1) * (n2+1) * (n3+1)

	x = p1^n1 * p2^n2 * p3^n3 ... * pt^nt
	  = (n1+1) * (n2+1) * (n3+1) * .. * (nt+1) = no of divisors. - count

	for sum =>

	the choices are -> multiply all the possible divisors
	(1 + p1 + p1^2 + ... p1^n1)
	* (1 + p2 + p2^2 + ... p2^n2)
	* (1 + p3 + p3^2 + ... p3^n3)

	if we multiply all, then we will get all the divisors and the sum eventually. these are all GPs.[1*1 + 1*p2+ 1*p2^2 + ...]... each term is a divisor =  likewise all the divisors sum we will get. e.g for 36 = 2^2 * 3^2 = (2^0+2^1+2^2) * (3^0+3^1+3^2) = [1*1 + 1*3 + 1*9 + 2*1 + 2^3 + 2*9 + 4*1 + 4*3 + 4*9] = sum of all the divisors.

	((p1^(n1+1))-1)/p1-1 * ((p2^(n2+1))-1)/p2-1 * ..... =
	e.g 36 = 2^2 * 3^2 = 2^3 - 1/2 -1 * 3^3 - 1/3 - 1 = 7 * 13 = 91

	24 = 2^3 * 3 = 2^4 -1 /2 - 1 * 3^2 - 1 /3 - 1 = 15 * 4 = 60 , ct = (3+1) * (1+1) = 8

	we can find prime factorizations in optimal way.
*/