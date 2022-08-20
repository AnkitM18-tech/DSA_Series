/*
	In the matrix nodes can be connected in 4 sides.
	Up,Down,Left,Right -> 1 means connected, 0 means blank.

	i1,j1 <-> i2,j2 => edge exists when they are connected up,down,left,right.
*/

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;


void dfs(int i, int j, int initialColor, int newColor, vector<vector<int>>& image) {
	int n = image.size(); // n X m
	int m = image[0].size();
	if (i < 0 || j < 0) return;
	if (i >= n || j >= m) return;
	if (image[i][j] != initialColor) return;

	image[i][j] = newColor;

	dfs(i - 1, j, initialColor, newColor, image);
	dfs(i + 1, j, initialColor, newColor, image);
	dfs(i, j - 1, initialColor, newColor, image);
	dfs(i, j + 1, initialColor, newColor, image);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
	int initialColor = image[sr][sc];
	if (initialColor != newColor)
		dfs(sr, sc, initialColor, newColor, image);
	return image;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

/*
	We don't require visited array because, here if we are changing a node's color then we can't go there again bcoz of the condition.
	Number fo islands -> question
*/