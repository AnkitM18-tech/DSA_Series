#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
int vis[N];
int level[N];

void bfs(int source) {
	queue<int> q;
	q.push(source);
	vis[source] = 1;

	while (!q.empty()) {
		int cur_v = q.front();
		q.pop();
		cout << cur_v << " ";
		for (int child : g[cur_v]) {
			if (!vis[child]) {
				q.push(child);
				vis[child] = 1;
				level[child] = level[cur_v] + 1;
			}
		}
	} // TC: V - nodes E -edges
	// TC: O(V+E)
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;

	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	bfs(1);
	for (int i = 1; i <= n; ++i) {
		cout << i << ": " << level[i] << endl;
	}
}

/*
	While calculating shortest path ->  when there are no weights in edges or equal weighted edges, BFS level will give the shortest path from source vertex.

*/


/*
	Breadth First Search - Traversal - we will travel the entire level first and then go on to the next level. - Level Order Traversal

	The implementation of BFS , we need Queue -> because we need a property where we process the first thing that we enter first.

	So we will keep on updating a queue and a visited array. source node to queue and after moving it out we add nodes(children) we visited in the next level to queue and mark them in visited array, to ensure level wise traversal.

	we will repeat this procedure add parent to queue and mark them in visited array, then remove parent and then add its children.

	q -> 1 2 3 13 5 4 6 7 8 9 10 12 11
	vis -> all marked

*/