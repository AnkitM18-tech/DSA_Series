//Containers
// Sequential -> Vectors,Stack,Queue,Pair(kind of a class)
// Ordered -> Maps,Multimaps,Set,Multiset
// Unordered -> Unordered Map, Unordered Set
// Nested Containers => vector<vector<int>>
// map<int,vector<int>>,set<pair<int,string>>,vector<map<int,set<int>>>

// Iterators
// Point to memory address of containers
// .begin(),.end()
// vector<int>::iterator it; (datatype::iterator it)
// continuity for containers

// Algorithms and Functors
// Classes which can act as functions

#include<bits/stdc++.h>
using namespace std;

void printVec(vector<int> v) {
	cout << "Size: " << v.size() << endl;
	// cout << "Capacity: " << v.capacity() << endl;
	// v.size() => O(1)
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << endl;
}
/*
void printVec(vector<pair<int, int>> &v) {
	cout << "Size: " << v.size() << endl;
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i].first << " " << v[i].second << endl;
	}
	cout << endl;
}
*/
int main() {
	/*
	pair<int, string> p;
	p = make_pair(2, "abc");
	p = {2, "abc"};
	pair<int, string> p1 = p; // copied by value, not copy by reference, if we change any value it won't be reflected in other, p1.first = 3, only changes p1's first value not p.
	// If we pass pair<int,string> &p1 = p; then it will be copied by reference
	p1.first = 3;
	cout << p.first << " " << p.second << endl;
	// Pair is used to maintain relationship between two entities.
	int a[] = {1, 2, 3}; int b[] = {2, 3, 4};
	pair<int, int> p_array[3];
	p_array[0] = {1, 2};
	p_array[1] = {2, 3};
	p_array[2] = {3, 4};
	swap(p_array[0], p_array[2]);
	for (int i = 0; i < 3; ++i) {
		cout << p_array[i].first << " " << p_array[i].second << endl;
	}
	// We don't need to maintain relation manually.Pair will take care.
	cin >> p.first; cout << p.first << " ";
	*/
	/*
	// Dynamic arrays -> can vary size of vectors
	vector<int> v;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		printVec(v);
		v.push_back(x);//O(1)
	}
	printVec(v);
	// Locally can create vector of size 1e5 and globally 1e7 just like arrays. Else we will get runtime error in TLE in CP. This limitation is on continuous memory allocation.
	*/
	/*
	vector<int> v(10, 3); // size with default value to be filled in. not mentioned anything vector of size 0 or if size mentioned without default value then default value 0.
	v.push_back(7); // added as 11th value in vector
	printVec(v);
	vector<int> v2 = v; // copies the entire vector, which is not possible in array. If we do a1 = a2; then the array's pointers will be copied. they are not different they are basically the same. If one changes then the other will change too. But in vectors v2 is a copy, any changes made to it won't be reflected in the original vector. TC: O(N)
	// When the vectors are passed into the function it is passed as a copy and it is expensive operation, pass reference instead, if you don't want to make a copy of the vector. We can add & before v2 to avoid making any copies.
	*/
	// Nesting in vectors
	/*
	Vector of Pairs
	vector<pair<int, int>> v; /*= {{1, 2}, {2, 3}, {4, 5}};
	printVec(v);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		v.push_back({x, y});
	}
	printVec(v);
	// Array of vectors
	int N;
	cin >> N;
	vector<int> v[N]; // 10 vectors of size 0
	for (int i = 0; i < N; ++i) {
		int n;
		cin >> n;
		for (int j = 0; j < n; ++j) {
			int x; cin >> x;
			v[i].push_back(x);
		}
	}
	for (int i = 0; i < N; ++i) {
		printVec(v[i]);
	}
	*/
	// Vector of vectors
	int N;
	cin >> N;
	vector<vector<int>> v;
	for (int i = 0; i < N; ++i) {
		int n;
		cin >> n;
		vector<int> temp;
		for (int j = 0; j < n; ++j) {
			int x; cin >> x;
			temp.push_back(x);
		}
		v.push_back(temp);
	}
	v[0].push_back(10);
	v.push_back(vector<int> ()); // pushing blank vector
	for (int i = 0; i < v.size(); ++i) {
		printVec(v[i]);
	}
}