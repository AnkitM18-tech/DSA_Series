#include<bits/stdc++.h>
using namespace std;

int digit_sum(int n) {
	if (n == 0 ) return 0;
	// int last_digit = n % 10;
	// n = n / 10;
	return digit_sum(n / 10) + (n % 10);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	cout << digit_sum(n);
}
// TC: O(log(n))

/*
	Array Sum
	int sum_array(int n, int a[]) {
		if (n < 0) return 0;
		return sum_array(n - 1, a) + a[n];
	}

	int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		cout << sum_array(n - 1, a);
	}
	TC : O(n)
*/