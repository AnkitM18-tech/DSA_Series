/*
	Height of a node -> distance from the farthest leaf node in its subtree. maximum should be taken.

	Finding depth and height in trees using DFS.
	depth of root - 0, height of leaf nodes 0.

	Depth can be stored while going down, depth of prev node(parent node) + 1 while going down.

	Height can be stored while going up, as we know the height of leaf nodes to be 0.

	Height can be stored while going up, height of prev node(child node) + 1 while going up. In case of multiple child nodes we will take the maximum of the heights.
*/

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
int depth[N], height[N];

void dfs(int vertex, int parent = 0) { // will run once per vertex
	// Take action on vertex after entering the vertex
	for (int child : g[vertex]) { // edges loop
		// Take action on child before entering the child node
		if (child == parent) continue;
		depth[child] = depth[vertex] + 1;
		dfs(child, vertex);
		height[vertex] = max(height[vertex], height[child] + 1);
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
	for (int i = 1; i <= n; ++i) {
		cout << depth[i] << " " << height[i] << endl;
	}
}