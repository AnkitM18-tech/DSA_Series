// calculate a^b mod 1337, where a = positive integer and b is extremely large +ve integer given in form of array.

// we can write a division function which divides the array by 2 until it becomes 0.

// 1337 -> not prime -> 7 * 191
/*
	phi(1337) = 1337 * (1-1/7) * (1-1/191) = 1140.

	a^b % 1337 = (a^(b % 1140))%1337

	b = [4,3,3,8,5,2] => 2 * 10^0 % 1140
						 + 5 * 10^1 % 1140
						 + 8 * 10^2 % 1140
						 + 3 * 10^3 % 1140
						 + 3 * 10^4 % 1140
						 + 4 * 10^5 % 1140

*/
#include<bits/stdc++.h>
using namespace std;

int binExp(int a, int b, int m) {
	a %= m;
	int ans = 1;
	while (b > 0) {
		if (b & 1) {
			ans = (ans * 1LL * a) % m;
		}
		a = (a * 1ll * a) % m;
		b >>= 1;
	}
	return ans;
}

int superPow(int a, vector<int> &b) {
	int bmod = 0;
	for (int val : b) {
		bmod = (bmod * 10 + val) % 1140;
	}
	return binExp(a, bmod, 1337);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> v = {1, 0};
	cout << superPow(2, v);
}