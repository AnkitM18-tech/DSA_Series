/*
	Maximum Possible path between any two vertices -> diameter of a tree. => Max No of edges between any two vertices is called Diameter of a tree.

	We will find the maximum depth of each node by considering every node as root by running dfs from root. -> Brute force -> TC: ~ O(N^2) -> N nodes, O(N)

	Optimized way -> Take any node as root, find the node with maximum depth. Whichever node comes that will be part of one end of the diameter. With that node as root, find max depth. -> that's the diameter. Tc: O(N)

*/

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
int depth[N];

void dfs(int vertex, int parent = -1) {
	for (int child : g[vertex]) {
		if (child == parent) continue;
		depth[child] = depth[vertex] + 1;
		dfs(child, vertex);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	for (int i = 0; i < n - 1 ; ++i) { // edges -> n-1
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1);
	int max_depth = -1;
	int max_d_node;
	for (int i = 1; i <= n; ++i) {
		if (max_depth < depth[i]) {
			max_depth = depth[i];
			max_d_node = i;
		}
		depth[i] = 0; // resetting the depth array
	}
	dfs(max_d_node);
	max_depth = -1;
	for (int i = 1; i <= n; ++i) {
		if (max_depth < depth[i]) {
			max_depth = depth[i];
		}
	}
	cout << max_depth << endl;
}