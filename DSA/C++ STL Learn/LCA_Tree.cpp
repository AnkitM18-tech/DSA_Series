/*
	Whenever it's asked LCA, store paths from root to those nodes. Then we traverse through those paths and the last common ancestor will be the answer.
	Now paths can be stored by storing parent of each node.
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
int par[N];

void dfs(int v, int p = -1) {
	par[v] = p;
	for (int child : g[v]) {
		if (child == p) continue;
		dfs(child, v);
	}
} // O(V+E) ~ O(N)

vector<int> path(int v) {
	vector<int> ans;
	while ( v != -1) {
		ans.push_back(v);
		v = par[v];
	}
	reverse(ans.begin(), ans.end());
	return ans;
} // O(N)

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

	int x, y;
	cin >> x >> y;
	vector<int> path_x = path(x);
	vector<int> path_y = path(y);
	int min_length = min(path_x.size(), path_y.size());
	int lca = -1;
	for (int i = 0; i < min_length; ++i) {
		if (path_x[i] == path_y[i]) {
			lca = path_x[i];
		} else {
			break;
		}
	}
	cout << lca << endl;
} // TC: O(N)

/*
	Another approach could be -- find the difference between their(2 nodes) depth, and then come to same depth (level) and go up until you find common node, that will be the LCA. TC: O(N), Memory efficient, no need to store paths.


	Binary Uplifting -> O(log(N))

*/