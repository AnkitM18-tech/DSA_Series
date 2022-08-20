#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int ar[N][N];
long long preFixSum[N][N];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n ; ++i) {
		for (int j = 1 ; j <= n; ++j) {
			cin >> ar[i][j];
			preFixSum[i][j] = ar[i][j] + preFixSum[i - 1][j] + preFixSum[i][j - 1] - preFixSum[i - 1][j - 1];
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		long long sum = 0;
		cout << preFixSum[c][d] - preFixSum[a - 1][d] - preFixSum[c][b - 1] + preFixSum[a - 1][b - 1] << endl;
	}
	// TC : O(N^2) + O(Q)
}
/*

int n;
	cin >> n;
	for (int i = 1; i <= n ; ++i) {
		for (int j = 1 ; j <= n; ++j) {
			cin >> ar[i][j];
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		long long sum = 0;
		for (int i = a; i <= c; ++i) {
			for (int j = b; j <= d; ++j) {
				sum += ar[i][j];
			}
		}
		cout << sum << endl;
	}
	// TC : O(N^2) + O(Q*N^2)

	pf[i][j] = a[i][j] + pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1]
	assuming that each cell stores prefix sum of previous cells

	preFixSum[c][d] - preFixSum[a - 1][d] - preFixSum[c][b - 1] + preFixSum[a - 1][b - 1]

*/