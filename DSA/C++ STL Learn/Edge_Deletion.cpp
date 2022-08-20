/*
	Delete an edge and divide the tree into two trees, such that the product of the sum of values associated with them becomes maximum.

	We can use Pre-Computation technique to store the subtree sum for the entire tree / nodes.

	when we delete an edge we get the subtree sum of one subtree and thenw e can delete it from entire tree sum to get another subtree sum.
	Then we can delete edges see which deletion leads to maximized product of subtrees.
*/

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int M = 1e9 + 7;
vector<int> g[N];
int subtree_sum[N];
int val[N];

void dfs(int vertex, int par = -1) {
	// Take action on vertex after entering the vertex
	subtree_sum[vertex] += val[vertex];
	for (int child : g[vertex]) { // edges loop
		// Take action on child before entering the child node
		if (child == par) continue;
		dfs(child, vertex);
		subtree_sum[vertex] += subtree_sum[child];
		// Take action on child after exiting the child node
	}
	//Take action on vertex before exiting the vertex
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;

	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1);
	long long ans = 0;
	for (int i = 2; i <= n; ++i) {
		int part1 = subtree_sum[i];
		int part2 = subtree_sum[1] - part1;
		ans = max(ans, (part1 * 1LL * part2) % M);
	}
	cout << ans << endl;
}