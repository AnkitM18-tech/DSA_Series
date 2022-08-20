#include<bits/stdc++.h>
using namespace std;

bool isVowel(char ch) {
	return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

vector<string> subsets(string s) {
	int sz = (1 << s.size());
	vector<string> ans;
	for (int mask = 0; mask < sz; ++mask) {
		string subset;
		for (int bit = 0; bit < sz; ++bit) {
			if (mask & (1 << bit)) subset.push_back(s[bit]);
		}
		if (subset.size()) ans.push_back(subset);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string str[n];
		for (int i = 0; i < n; ++i) {
			cin >> str[i];
		}
		unordered_map<string, int> hsh;
		for (int i = 0; i < n; ++i) {
			set<char> distinct_vowels;
			for (char ch : str[i]) {
				if (isVowel(ch)) {
					distinct_vowels.insert(ch);
				}
			}
			string vowel_str;
			for (char ch : distinct_vowels) {
				vowel_str.push_back(ch);
			}
			vector<string> all_subsets = subsets(vowel_str);
			for (string vowel_subset : all_subsets) {
				hsh[vowel_subset]++;
			}
		}
		/*for (auto pr : hsh) {
			cout << pr.first << " " << pr.second << endl;
		}*/
		long long ans = 0;
		for (auto &pr : hsh) {
			if (pr.second < 3) continue;
			long long ct = pr.second;
			long long ways = ct * (ct - 1) * (ct - 2) / 6;
			if (pr.first.size() % 2 == 0) ans -= ways;
			else ans += ways;
		}
		cout << ans << "\n";
	}

}
/*
	A + B = A U B - AnB
	A U B U C = A + B + C - AnB - BnC - CnA + A n B n C
	odd pair -> final sign + , even pair-> final sign -

	if there is e in n people's name -> then we can select 3 people in nC3 ways. -> n(n-1)(n-2)/6

	E B A
	E C A
	E D A = 3c3 + 3c3 = 2,  but we have to deduct the common EnA = ans = 1.
*/