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
//vector<vector<int>> cc;
//vector<int> current_cc;
bool vis[N];

bool dfs(int vertex, int par) { // will run once per vertex
	// Take action on vertex after entering the vertex
	// if (vis[vertex]) return; check after entering the vertex
	// current_cc.push_back(vertex);
	// cout << vertex << endl;
	vis[vertex] = true;
	bool isLoopExists = false;
	for (int child : g[vertex]) { // edges loop
		// Take action on child before entering the child node
		// cout << "Par " << vertex << ", Child " << child << endl;
		if (vis[child] && child == par) continue; // check if the node is visited and it's the parent.
		if (vis[child]) return true; // cycle detected
		isLoopExists |= dfs(child, vertex);
		// Take action on child after exiting the child node
	}
	return isLoopExists;
	//Take action on vertex before exiting the vertex
} // TC : O(V+E) V-vertices,E-edges -> if we accumulate all the recursions, then for loop would run for equal to number of edges.

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, e;
	cin >> n >> e;
	for (int i = 0; i < e; ++i) {
		int v1, v2;
		cin >> v1 >> v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	// int ct = 0;
	bool isLoopExists = false;
	for (int i = 1; i <= n; ++i) {
		if (vis[i]) continue;
		// current_cc.clear();
		if (dfs(i, 0)) {
			isLoopExists = true;
			break;
		}
		// cc.push_back(current_cc);
		// ct++;
	}
	/*cout << cc.size() << endl;
	for (auto c_cc : cc) {
		for (int vertex : c_cc) {
			cout << vertex << " ";
		}
		cout << endl;
	}*/
	// cout << ct << endl;
	cout << isLoopExists << endl;
}

/*
	The number of connected components = number of times dfs ran. and marked each node out. When we run dfs on unvisited node then it will mark the entire connected component.

	Cycle Detection -
	We need to keep track of the vertex from which the the traversal came and also while checking dfs we need to see if the node is visited or not.

*/