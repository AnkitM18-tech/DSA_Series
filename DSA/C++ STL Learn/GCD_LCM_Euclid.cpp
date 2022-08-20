#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	// base condition
	// if (a % b == 0) return b;
	// No need for swaping the numbers if the dividend is smaller, eventally it will swap itself. e.g -> 12 / 18 = 0 -> Q and R -> 12, then it will become 18 / 12.
	if (b == 0) return a;
	// a % b
	return gcd(b, a % b);
} //TC : O(log(n)) -> we take here max range when dividing by 2, TC: log(n), It will be less but around this complexity

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// Larger number as dividend first argument
	cout << gcd(12, 4) << endl;
	cout << gcd(18, 12) << endl;
	// Smaller number as dividend first argument
	cout << gcd(4, 12) << endl;
	cout << gcd(12, 18) << endl;
	// LCM
	cout << ((12 * 18) / gcd(12, 18)) << endl;
	// Inbuilt function
	cout << __gcd(12, 18) << endl; // TC: O(log(n))
	// gcd(gcd(a,b),c) -> we can do something like this
	// we can use gcd concept to find min fraction of two numbers, a/b = (a/gcd(a,b))/(b/gcd(a,b))
	// gcd(a,b) = provided that b is non-zero, if it is 0 , then a%b will be undefined.
}

/*
	GCD ->
	4 12 - 4
	12 18 - 6

	4 = 2^2 * 3^0
	12 = 2^2 * 3^1

	GCD -> minimum powers extraction = 2^2 * 3^0 = 4

	LCM ->
	4 12 - 4
	12 18 - 6

	4 = 2^2 * 3^0
	12 = 2^2 * 3^1

	LCM -> maximum powers extraction = 2^2 * 3^1 = 12

	18 = 2^1 * 3^2

	GCD 12 & 18 = 2^1 * 3^1 = 6 (min power extraction)
	LCM 12 & 18 = 2^2 * 3^2 = 36 (max power extraction)

	(2^2 * 2 * 3 * 3^2)/2*3 = 36
	=> a = 12, b = 18
	=> (a * b) / GCD = LCM , we can get LCM in O(1), if we know how to calculate the GCD of 2 numbers.

	we can find GCD by long division, until we get 0 remainder, if we get remainder then it becomes the divisor and the previous divisor will become the dividend and so on until we get 0 remainder. The last divisor is the GCD.

	12 / 4 = 3 -> Q , 0 -> R => GCD = 4
	18 / 12 = 1 -> Q , 6 -> R
	12 / 6 = 2 -> Q , 0 -> R => GCD = 6

	This is the Euclid Algorithm.

*/