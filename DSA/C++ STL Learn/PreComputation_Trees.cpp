#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
int subtree_sum[N];
int even_ct[N];
// int depth[N], height[N];

/*
	Given Q queries, Q <= 1e5
	In each query given, print subtree sum of V & number of even numbers in subtree of V.

	For these kinds of problems, we need to pre compute the sum of sub trees as TC for every dfs will be more.

	Sum of subtrees ->
	start from leaf nodes as they have no sub trees.so sub tree sum of leaf nodes are their values.

	Then while going up we will determine the subtree sum by adding the node to its child's subtree sum.

*/

void dfs(int vertex, int parent = 0) { // will run once per vertex
	// Take action on vertex after entering the vertex
	if (vertex % 2 == 0) even_ct[vertex]++;
	subtree_sum[vertex] += vertex; // if a separate value array is given then it would just become val[vertex]
	for (int child : g[vertex]) { // edges loop
		// Take action on child before entering the child node
		if (child == parent) continue;
		// depth[child] = depth[vertex] + 1;
		dfs(child, vertex);
		// height[vertex] = max(height[vertex], height[child] + 1);
		// Take action on child after exiting the child node
		subtree_sum[vertex] += subtree_sum[child];
		even_ct[vertex] += even_ct[child];
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
	/*for (int i = 1; i <= n; ++i) {
		cout << depth[i] << " " << height[i] << endl;
	}*/
	for (int i = 1; i <= n; ++i) {
		cout << subtree_sum[i] << " " << even_ct[i] << endl;
	}
	/*int q; cin >> q;
	while (q--) {
		int v; cin >> v;
		cout << subtree_sum[v] << even_sum[v] << endl ;
	} //TC: O(Q)
	*/
}