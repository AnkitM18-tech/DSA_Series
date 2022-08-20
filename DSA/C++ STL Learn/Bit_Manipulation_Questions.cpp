#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int c; cin >> c;
	int bit_ct = (int)log2(c) + 1;
	int a = 0, b = 0;
	vector<int> set_bits;
	for (int i = 0; i < bit_ct; ++i) {
		if (c & (1 << i)) {
			set_bits.push_back(i);
		} else { // both bits 1
			a |= (1 << i);
			b |= (1 << i);
		}
	}
	long long ans = -1;
	int sz = (1 << set_bits.size());
	for (int mask = 0; mask < sz; ++mask) {
		int a_copy = a, b_copy = b;
		for (int j = 0; j < set_bits.size(); ++j) {
			if (mask & (1 << j)) {
				a_copy |= (1 << set_bits[j]);
			} else {
				b_copy |= (1 << set_bits[j]);
			}
		}
		ans = max(ans, a_copy * 1LL * b_copy);
	}
	cout << ans << endl;
}

/*
	Monk and his Father ->

	x1 -> God
	2x1 -> Father
	x2 -> God
	2^2x1 + 2x2 -> Father
	.....
	2^nx1 + 2^n-1x2 + ... + 2^2xn-1 + 2xn = binary conversion type.
	We have to minimize (x1 + x2 + x3 + ... + xn) money given by God.

	We can take amounts as 1 or 0, so automatically it will minimize. and there is no constraints on number of days.
	5 -> 2^2 + 2^0 -> set bits are the days he took money from god.

	int t; cin >> t;
	while (t--) {
		long long x; cin >> x;
		cout << __builtin_popcountll(x) << "\n";
	}
*/

/*
	A XOR Challenge
	A ^ B = C -> C value is given, A and B such that A * B product is maximum. So in order to do that I need to maximize both A and B.

	C = 1 1 0 1 0 1 0 1 1 0 1 1
	A =     1   1   1     1
	B =     1   1   1     1

	0 0 = 0 / 1 1 = 0 -> to maximize we need 1.
	0 1 = 1 / 1 0 = 1

	10^5 = log(10^5) = 16 bits approx. so we can generate and compare all subsets => 2^16
*/