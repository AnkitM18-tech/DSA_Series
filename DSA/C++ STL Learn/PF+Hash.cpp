#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int hsh[N][26];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < 26; ++j) {
				hsh[i][j] = 0;
			}
		}
		int n, q;
		cin >> n >> q;
		string s;
		cin >> s;
		for (int i = 0; i < n; ++i) {
			hsh[i + 1][s[i] - 'a']++;
		}
		for (int i = 0; i < 26; ++i) {
			for (int j = 1; j <= n; ++j) {
				hsh[j][i] += hsh[j - 1][i];
			}
		}
		while (q--) {
			int l, r;
			cin >> l >> r;
			int oddCt = 0;
			for (int i = 0; i < 26; ++i) {
				int charCt = hsh[r][i] - hsh[l - 1][i];
				if (charCt % 2 != 0) oddCt++;
			}
			if (oddCt > 1) cout << "NO\n";
			else cout << "YES\n";
		}
	}
}
// TC : O(t * (n + n * 26 + q * 26))
/*
	In Palindrome we can have max one character whose count can be an odd number. Otherwise we can not make a palindrome out of them.
	If the number of odd numbered characters are 0 or 1 then we can arrange them as a palindrome

	int t;
	cin >> t;
	while(t--) {
		int n,q;
		cin >> n >> q;
		string s;
		cin >> s;
		while(q--) {
			int l,r;
			cin >> l >> r;
			int hsh[26];
			for(int i=0; i<26; ++i){
				hsh[i] = 0;
			}
			l--;r--;
			for(int i=l;i<=r;++i){
				hsh[s[i] - 'a']++;
			}
			int oddCt = 0;
			for(int i=0;i<26;++i){
				if(hsh[i]%2 != 0) oddCt++;
			}
			if (oddCt > 1) cout << "NO\n";
			else cout << "YES\n";
		}
	}
	// TC : O(t * (size of string + q * (26 + n + 26))) ~ O(t*q*n)

	Optimization : store the count for each character at every index of that string in an diffrent array for that character

	26 arrays of N size(Size of string)
*/

/*
	Modular Arithmatic
	(a+b) % M = ((a % M) + (b % M)) % M
	(a*b) % M = ((a % M) * (b % M)) % M
	(a-b) % M = ((a % M) - (b % M) + M) % M
	(a/b) % M = ((a % M) * (b^-1 % M)) % M

	% M is done to avoid the overflow of large numbers "long long", double has precision errors
	In cases where we can't store or print such large numbers we use Modulo Properties.

	(1 * 2 * 3 * 4 * 5) % M=> ((1*2*3*4)% M * 5% M) % M -> we can do likewise with others
	10^9 + 7 -> very close to maximum int value -> final answer can be stored in int data type
	Helpful in Multiplicative Inverse -> We can find Multiplicative Inverse for M = Prime for all the numbers from 1 -> M so 10^9 + 7 is prime and it makes it possible to find Multiplicative Inverse easily.
*/

/*
	Hashing in case of Negative Numbers ->
	Directly by using Map or Unordered Map
	else
	We can add the max -ve number as poistive to make the whole array positive and make a hash array out of them, then when giving the count we can add that number and return the count
*/