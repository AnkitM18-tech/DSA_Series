#include<bits/stdc++.h>
using namespace std;

int main() {

}

/*

	Vertices or Nodes -> Represent entities such as building or people in LinkedIn

	Edges -> Represent the relationships between the entities

	The vertices along with edges together, are called a graph.
	The vertices that are joined by an edge are called "adjacent".

	Types of graphs ->
	-> Directed and Undirected
	-> Weighted and Unweighted

	In directed graphs, the connections are one-directional, for example, A city with one-way roads, or the linkedin "followers" system. If A is a follower of B, it doesn't mean that B is also a follower of A.

	In undirected graphs, the relations are symmetric and non-directional, for example, LinkedIn connections. If A is a connection of B , then B is also a connection of A.

	Undirected graphs have no arrow heads, but directed graphs have arrow heads in representation, information about the direction or relation. e.g. B follows C

	In weighted graphs, there is some extra information called "weight" on the edgesof the graphs. This weight denotes some additional information about the relations. For example, if a graph represents a metro n/w, the weights on the edges can represent the prices to get from point A to B, etc.


	In unweighted graphs, there is no additional information stored on the edges. Note: From a problem solving POV, an unweighted graph is equivalent to a weighted graph in which all edges have same weight.


*/
/*
	Representation in Computer program ->

	Adjacency Matrix Representation -> If there are V vertices, take a matrix of size VxV and store which vertices are adjacent to which vertices.

	If the graphs is directed, the matrix would be asymmetrical.
	If the graph is weighted, store the weight in matrix instead of true/false.
	Drawbacks -> Takes O(V^2) memory even if number of edges is small.

	Adjacency List Representation -> For each of the V vertices, keep a list of vertices which are adjacent to it.

	Graphs, in which the number of edges aren't a lot compared to the number of vertices, are called "Sparse Graphs". Adjacency List representation is necessary when dealing with sparse graphs.

	If the graph is weighted, store a pair of (vertex,weight) for all outgoing edges.
	Advantage -> takes O(V+E) memory. (V lists and every edge adds 2 items to the lists in total)

	Note: The number of items in the adjacency list of vertex is called the "degree" of that vertex.
*/

/*
	Terminology related to connectivity ->
	Path -> A sequence of distinct vertices such as A1 -> A2 -> A3 -> ... -> An, such that there is an edge from Ax to Ax+1.

	Connectivity -> Vertex X is connected to vertex Y if there is at least 1 path from X to Y

	Connected Component -> A maximal group of vertices such that each of them is connected to one other.

	How to find a connected component ->
	Start from a vertex, all vertices adjacent to that vertex are in the same connected component.

	All of the vertices adjacent to those are also in the same connected component and so on.

	think recursively -> Pseudocode of a very basic idea
	visit(X):
		for each Y in adj_list[X]:
			visit(Y)

	Ever lost in maze, try making some marks in the places you have already been, so you don't get stuck in infinite loops.

*/

/*
	DFS (Depth First Search) ->
	It is called Depth First Search or Depth First Traversal, because we firstly go as deep as possible in a certain direction before going elsewhere.

	Time Complexity of DFS -> O(V+E), where V is the numebr of vertices in the connected component, because every vertex is visited only once, and every edge is considered only twice - oncefrom while visiting each of the end points of the edge.

*/

/*
	Cycles in a Graph and Tree
	A cycle is like a path that starts and ends at the same vertex.
	e.g. 2 -> 3 -> 4 -> 2
	A connected graph w/o cycle is called a tree. (A disconnected graph w/o cycles is called Forest)


*/

/*
	Connected Components

	const int N = 2e5 + 5;
	vector<int> adj_list[N];
	bool visited[N];

	void dfs(int cur) {
		visited[cur] = true;
		for (int next : adj_list[cur]) {
			if (visited[next]) continue;
			dfs(next);
		}
	}

	int main() {
		int n, m; // vertices edges
		cin >> n >> m;

		for (int i = 0; i < m; i++)
		{
			int x, y; //edges
			cin >> x >> y;
			adj_list[x].push_back(y); // storing edges in adj_list
			adj_list[y].push_back(x);
		}

		int ans = 0;
		for (int i = 1; i <= n; i++) //vertices
		{
			if (visited[i]) continue;
			dfs(i);
			ans++;
		}
		cout << ans;
	}
*/

/*
	Grid/Maze is also a graph. Every square in the grid is a vertex and implicitly there are upto 4 edges. L,R,U,D

	WHen working with grids, we don't have need to keep an adjacency list, we can find all 4 adjacent vertices easily.

	For (x,y) the adjacent vertices are ->
	(x, y+1), (x+1, y), (x-1, y), (x, y-1) the four graph moves can be stored in the following way ->
	int dx[4] = {1,0,-1,0};
	int dy[4] = {0,1,0,-1};
*/

/*
	Shortest Path Problem in Unweighted Graph
	General Idea to solve this ->
		->Start with the source vertex, the "distance" for that is 0
		->All vertices adjacent to source have distance 1
		->All unvisited vertices which are adjacent to at least one of the vertices with distance 1 have distance 2.
		->All unvisited vertices which are adjacent to at least one of the vertices with distance x have distance (x+1).
		->Keep repeating previous step until the destination is found.
	We need to learn queue in order to implement this.

	Queue is a FIFO data structure. First In First out
	The elements that are pushed into the queue first are popped out first.

	queue<int> q;
	q.clear(); // clear the queue
	q.size(); // get the size of the queue
	q.empty(); // returns true if queue is empty
	q.push(x); // insert x into queue
	q.front(); //returns the value in the queue that was pushed earliest.
	q.pop(); // erase the front from the queue.

	Push and Pop are known as enqueue and dequeue.

	BFS(Breadth First Search) -> using a queue because of the FIFO principle. The vertex which is seen first is nearer to the source, so it is best if it is popped first, this guarantees that no vertex with a higher distance from the source is popped before a vertex with a lower distance.

	for(int i = 1; i <= n; i++)
		dist[i] = INF;

	dist[source] = 0;
	queue<int> q;
	q.push(source);
	while(!q.empty()){
		int current = q.front();
		q.pop();
		for(int next : adj_list[current]){
			if(dist[next] == INF){
				dist[next] = dist[current] + 1;
				q.push(next);
			}
		}
	}
	//dist[x] contains distance from source to x

	Time Complexity of BFS -> O(V+E).reason is similar to DFS, a vertex is visited only once and an edge is considered only twice at most.

*/