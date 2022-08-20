/*
	Popular algorithm to find shortest path where you have proper weighted graph. One source, multiple destinations -> we use Djikstra.

	Similar to BFS. We use priority queue in Djikstra algorithm.-> for optimization - stores nodes in a particular sequence.

	We make distance as INF, and put the source node in a list, and make its distance as 0. Then if the distance of other nodes from source can be reduced we will reduce it.

	List ---> (0,1) [(distance,node)] we will keep on updating the list with distances and nodes. Remove the node with least distance after processing it. We use PQ becoz, finding the least distance node would become log(N). Uisng a list will increase the TC. we also mark the nodes we visited using visited array, after processing each node and adding its child to PQ, and taking the processed node out of the PQ.

*/

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int INF = 1e9 + 10;

vector<pair<int, int>> g[N];//(node,weight)

void djikstra(int source) {
	vector<int> vis(N, 0);
	vector<int> dist(N, INF);
	set<pair<int, int>> st;//(weight,node)
	st.insert({0, source});
	dist[source] = 0;

	while (st.size() > 0) {
		auto node = *st.begin();
		int v = node.second;
		int dis = node.first;
		st.erase(st.begin());
		if (vis[v]) continue; // we don't put it inside the loop becoz the node can be entered multiple times with updated distances.
		vis[v] = 1;
		for (auto child : g[v]) {
			int child_v = child.first;
			int wt = child.second;
			if (dist[v] + wt < dist[child_v]) {
				dist[child_v] = dist[v] + wt;
				st.insert({dist[child_v], child_v});
			}
		}
	}

} // TC : O(V + E * log(V)) - while loop runs V times, insert complexity log(V) performed E times.

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	for (int i = 0; i < m; ++i) {
		int x, y, wt;
		cin >> x >> y >> wt;
		g[x].push_back({y, wt});
	}
}