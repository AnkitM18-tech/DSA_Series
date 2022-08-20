/*
	Depth First Search
	We will traverse through a node's depth first,before moving onto other nodes.i.e we will cover all the depth of a node.

	In graphs to avoid the cycle of visiting child nodes again and again and stuck in a loop, we use visited array.

	length of the visiting nodes = number of nodes.
	We will mark that node 1 that we traverse. and for subsequent nodes we will ignore that node.

	We can start traversing from any node.
*/

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

vector<int> g[N];
bool vis[N];

void dfs(int vertex) { // will run once per vertex
	// Take action on vertex after entering the vertex
	// if (vis[vertex]) return; check after entering the vertex
	cout << vertex << endl;
	vis[vertex] = true;
	for (int child : g[vertex]) { // edges loop
		// Take action on child before entering the child node
		cout << "Par " << vertex << ", Child " << child << endl;
		if (vis[child]) continue;
		dfs(child);
		// Take action on child after exiting the child node
	}
	//Take action on vertex before exiting the vertex
} // TC : O(V+E) V-vertices,E-edges -> if we accumulate all the recursions, then for loop would run for equal to number of edges.

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int v1, v2;
		cin >> v1 >> v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
}