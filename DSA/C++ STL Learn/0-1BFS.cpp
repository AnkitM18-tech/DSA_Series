/*
	Weight of the edges are either 0 or 1. 0-1 BFS
	At a given time our queue only has nodes from two levels.

	q ->
	x =
	x+1 =

	If the weight is 0, then we process it in x level, front of the queue(after the parent node pop out). if weight is 1 then we process it in x+1 level, back of the queue.

	x -----> y   0 - front/ 1-back

	Chef and Reversing -> Codechef
	Keep normal edges with 0 weight, add reverse edges for all edges with 1 weight.

	In 0-1 BFS every node can be put into queue max 2 times. one from 1 initialize and other from 0 initialize.
*/

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int INF = 1e9 + 10;

vector<pair<int, int>> g[N];
vector<int> level(N, INF);
int n, m;

int bfs() {
	deque<int> q;
	q.push_back(1);
	level[1] = 0;
	while (!q.empty()) {
		int cur_v = q.front();
		q.pop_front();

		for (auto child : g[cur_v]) {
			int child_v = child.first;
			int wt = child.second;
			if (level[cur_v] + wt < level[child_v]) {
				level[child_v] = level[cur_v] + wt;
				if (wt == 1) {
					q.push_back(child_v);
				} else {
					q.push_front(child_v);
				}
			}
		}
	}
	return level[n] == INF ? -1 : level[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		if (x == y) continue; // self-loop
		g[x].push_back({y, 0});
		g[y].push_back({x, 1});
	}
	cout << bfs() << endl;
}