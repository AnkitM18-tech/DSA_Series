/*
	All pair shortest path
	Suppose we will allow k vertices, and we will calculate shortest path using those.

	Find all shortest paths, without including any other nodes/vertex. k=0
	k = 1 -> i -> j we can go through vertex 1, find shortest path including 1. so on...
	k = 2 -> i -> j we can go through vertex 1 and 2, find the shortest path including 1 and 2.

	S.P -> k nodes = i -> j - same - if the S.P remains unchanged even after adding the k+1 node.

	if it changes then -> (i->k+1) + (k+1->j) will be the new S.P.

	d[i][j] = d[i][k] + d[k][j]

	1.handles -ve weights.
	2.-ve weighted cycle can not be handled. - the distance keeps on decreasing as you go along.

*/

#include<bits/stdc++.h>
using namespace std;
const int N = 510;
const int INF = 1e9 + 10;

int dist[N][N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = INF;
		}
	}
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int x, y, wt;
		cin >> x >> y >> wt;
		dist[x][y] = wt;
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (dist[i][k] != INF && dist[k][j] != INF)//-ve weights
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	} // TC: O(N^3)

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (dist[i][j] == INF) {
				cout << "I ";
			} else {
				cout << dist[i][j] << " ";
			}
		}
		cout << endl;
	}
}