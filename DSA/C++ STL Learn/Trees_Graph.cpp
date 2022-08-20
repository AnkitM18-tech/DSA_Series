/*
	Trees/Graphs -> Representation
	- Matrix
	- List
		- Arrays of Vectors
		- Vectors of Vectors

	Traversal ->
	- DFS
	- BFS

	Algorithms ->
	- Djikstra
	- Bellman-Ford
	- Disjoint Set Union
	- Minimum Spanning Tree
	- Directed Acyclic Graph
	- Topological Sort

	Graphs ->

	1----2  vertex, the line is called edge. if no arrow -> bi-directional, if arrow -> uni directional. two vertices can be there independently, and we can call it a graph(collection of edges and vertices). vertices can be connected to number of other vertices. there can be cycles in a graph.

	Tree ->

	It is a graph, that has no cycles in it.
	If there are n nodes in a tree, there will be n-1 edges.

	Connected components ->

	we can reach a node from any node in that component by an edge. single node is also a connected component.

	1---3---5    2
		|   |
		--6--
	Here we have 2 connected components in a graph.

	In directed graph edges have a direction.
	Acyclic -> no cycle
	Components in directed graph -> strongly connected components. -> we can travel from any node to any node.(bi-direction)/ cycle.

	In some books collection of connected components can be refered as forest.

	Trees -> Root node -> tree is hanged by root, Parent node -> have child nodes under it, Child node,Subtree -> partial set of a tree.

	Leaf nodes are those who don't have a child node.
	Depth of a node = distance of that node from root node.
	Height = longest distance from any leaf node to that node. can't take any curves

	Lowest Common Ancestor-> LCA -> nearest common parent of two nodes going upwards.

	Graph -> Representation -> Adjacency Matrix / Adjacency List.

	To represent any graph with adjacency matrix -> make a V X V matrix.
	   2     3
	0 --- 1 --- 2 -> undirected graph, so i,j connected = j,i connected. In directed graph only keep the one that is directed.

	0 1 2
0     1       a[i][j] = 1 => i,j are connected
1   1    1    a[i][j] = 0 => i,j are not connected
2     1

	In case we have weights , we can say a[i][j] = weight. and replace 1 with weights in the matrix.

	Information we get ->
	N = Number of Vertices, M = Number of Edges
	We get the connected vertices info in M lines,
	-> 1,2 -> 2,3 -> 3,4 -> like these we get the edges.

	In adjacency list we store values in a list. We keep N number of lists -> N = no of vertices.
	In each list we store the nodes that are connected to it.

	0 -> 1
	1 -> 0,2
	2 -> 1

	Here we don't need N X N space to store, we just need the number of vertices amount(N) number of lists. In adjacency list SC : O(V+E)
	In a graph with V vertices, we can have VC2 edges(E) maximum. ->(V^2) -> most of the times the space complexity here will never exceed.

*/

#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int graph1[N][N]; // global variable by default is zero. This approach's space complexity is more.That's a problem. SC : O(N^2) -> N Vertices. if N > 1e5 then our solution is going to fail. N<1e3
vector<pair<int, int>> graph2[N]; // adjacency list.SC: O(N+M), here N can be 1e5, but edges should not exceed 1e7. to store undirected weighted graph we use this. otherwise only vector is good.

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int v1, v2, wt;
		cin >> v1 >> v2 >> wt;
		graph1[v1][v2] = 1;//wt
		graph1[v2][v1] = 1;//wt

		graph2[v1].push_back({v2, wt});
		graph2[v2].push_back({v1, wt});
	}
}

/*
	Adjacency Matrix ->
		-- i,j connected ? , i,j --> wt ?
		This can be done in O(1).
		if(graph1[i][j] == 1){
			connected
		}
		graph1[i][j]; -> wt
		Can't store large graphs

	Adjacency List ->
		-- It can take O(N) time, coz of loop.
		for(pair<int,int> child:graph2[i]){
			if(child.first == j){
				connected
				child.second; -> wt
			}
		}
		Can store large graphs
*/