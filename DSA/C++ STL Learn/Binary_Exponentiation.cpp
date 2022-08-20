#include<bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

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

/*
// Recursive Method
int binExpRecur(int a, int b) {
	// base condition
	if (b == 0) {
		return 1;
	}
	int res = binExpRecur(a, b / 2);// here we are calculating once then reuse them.
	if (b & 1) {
		// return a * binExpRecur(a, b / 2) * binExpRecur(a, b / 2); // here it will increase the complexity, for both the function call. won't get the answer in log(N) time.
		return (a * ((res * 1LL * res) % M)) % M;
	} else {
		// return binExpRecur(a, b / 2) * binExpRecur(a, b / 2);
		return (res * 1LL * res) % M;
	} // to avoid overflow we use 1LL while calculation, else we can make res long long
}
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a = 212344, b = 1312131;
	/*
	int ans = 1;
	for (int i = 0; i < b; ++i) {
		ans *= a;
		ans %= M;
	} // TC: O(b), not a good TC to calculate power
	cout << ans << endl;
	*/
	// cout << binExpRecur(a, b);
	cout << binExpIter(a, b);

}

/*
	binary exponentiation = a^b
	pow(2,3) -> inbuilt function, but it has precision errors.So we need algorithm for binary exponentiation

	double d = 1e20;
	cout << fixed << setprecision(30) << d;

	double d = 1e24;
	cout << fixed << setprecision(30) << d;
	// gives precision error -> doucle can store large numbers but can't store them accurately
	So we avoid double in programming. pow(a,b) returns double. So we need to avoid it in CP.

	binary exponentiation -> O(log(b)) , b = power => uses divide and conquer principle. We will break the power to smaller powers by dividing them by 2,hence reducing steps.

	when the power is odd, we will convert it to even power => 3^13 = 3 * 3^12, now we can break the 12 power.
	3^12 = 3^6 * 3^6
	3^6 = 3^3 * 3^3
	3^3 = 3 * 3^2
	3^2 = 3 * 3
	3 = 3 * 3^0

	f(a,b) ----> (b is even) = f(a,b/2) * f(a,b/2)
		   ----> (b is odd) = a * f(a,b/2) * f(a,b/2)
*/

/*
	3^13 = we need to break 13, into 2's power.
	binary of 13 = 1101-> 3^1101 --> 3^(8+4+0+1) --> 3^8 * 3^4 * 3^0 * 3^1

	we need to check which bits of the binary are set and multiply those corresponding powers of the base. Maximum numbers there can be log(b), b=power. Binary can have maximum log(b) bits.

	right shift the power, if the 0th bit is set, then multiply that power of base to ans. increase the power of base by multiplying it with itself.

	3^13  -->  3^1101
	   b       a       ans=1
	  1101     3        * 3
	   110     3^2       --
	    11     3^4      * 3^4 = 3^5
	     1     3^8      * 3^8 = 3^13
*/