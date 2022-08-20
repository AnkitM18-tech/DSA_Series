#include<bits/stdc++.h>
using namespace std;

/***
 * Given array a of n integers. All the integers are present in even count except one. Find that one integer which has odd count in O(N) time complexity and O(1) space
 *
 *N < 10^5
 *a[i] < 10^5
 *
 *If we use hashing then O(N) space is required
 ***/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int x;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		ans ^= x;
	}
	cout << ans << endl;
}

/*

1.Swap 2 numbers using XOR

	1 0 --> 1
	0 1 --> 1
	0 0 --> 0
	1 1 --> 0

	101 ^ 101 -> 5 ^ 5 = 000 -> 0
	as they have same binary =>
	a number XOR that number = 0

	101 ^ 000 -> 5 ^ 0 = 101 -> 5
	a number XOR 0 = number itself.

	x^y^z == x^z^y == y^x^z -> associative

	int a = 4, b = 6;
	a = a ^ b;
	b = b ^ a; // b --> a
	// b = b ^ (a ^ b) => b ^ b ^ a => 0 ^ a = a
	a = a ^ b; // a --> b
	// a = (a ^ b) ^ a => a ^ a ^ b => 0 ^ b = b

2.Eliminate Odd one out/ Duplicate ELimination

	c ^ a ^ b ^ c ^ b --> c ^ c ^ b ^ b ^ a --> 0 ^ 0 ^ a --> a

	the numbers with even count, after XOR op become 0(x^x = 0). odd count number only remain. So we can just take XOR of every number in the array, we will get the odd one out

*/