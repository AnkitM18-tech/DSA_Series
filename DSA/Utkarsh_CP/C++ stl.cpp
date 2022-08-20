#include<bits/stdc++.h>
using namespace std;

/*
Using STL we can write shorter code that runs faster.
The prewritten codes in STL are extremely erro-free and optimized.
STL is very important when you learn advanced concepts.
*/

int main() {

}

/*
	Vector -> It is a dynamic sized array. Number of elements can be increased or decreased. Java equivalent of ArrayList
*/

/*
	vector<int> v; //empty vector of integers
	vector<int> v(10); // vector of integers with 10 elements (all 0)
	vector<char> v(10, 'h'); // vector of characters with 10 elements (all 'h')

	//Important functions
	v.push_back(x) //-> insert value x to the end of the vector. O(1)
	v.pop_back() //-> erase the last element. O(1)
	v.clear() //->erase all the elements. O(n)
	v.size() //->returns the current size of the vector. O(1)
	[] //-> operator can be used to access elements like an array.
	cout << v[0]; // prints first element of the vector.
*/

/*
	vector<int> v;
	v.push_back(5);
	v.push_back(6);
	v.push_back(3);

	cout << v[0] << " " << v[1] << " " << v[2];

	v.pop_back();
	v.push_back(9);
	cout << "\n";

	cout << v[0] << " " << v[1] << " " << v[2];
*/

// vector<int> v(50) // 50 elements with value 0
// vector<int> v(50, 7); // 50 elements with value 7 {7,7,7...7}
// vector<int> v[50] // array of 50 vectors

/*
	sort() -> this function can be used to sort an array or vector or a string. The underlying sorting algorithm is called the gcc_sort (quick sort, insertion sort, heap sort )which is a hybrid algorithm which is implemented in a very efficient way. O(NLogN)

	If we manually write a sorting algo, it will be slower than this.

	int a[n]; -> sort(a,a+n); // pointer to first element and pointer to element after the last element(ptr last element + 1) -> we can partially sort the vector or array too.
	vector<int> v; -> sort(v.begin(),v.end());
	string s; -> sort(s.begin(), s.end());

	note: begin() and end() are called iterators, they are a little bit similar to pointers.

	int a[4] = {5,4,1,2};
	sort(a,a+3);
	for (int i=0;i<4;i++) {
		cout << a[i] << " ";
	}
*/

/*
	Pair -> Pair is a way of creating a Composite-Datatype composed of 2 different primitive or composite datatypes.

	pair<int,int> p; // pair of 2 ints
	pair<int,string> p; // pair of int and string
	pair<int,pair<int,string>> p; // pair f int and (pair of int and string)
	pair<vector<int>,string> p; // a pair of (vector of int) and string

	Advantages -> In case you want to return multiple values from a function.

	pair<string,int> p = {"hello",6};
	cout << p.first << " " << p.second; // prints hello 6 -> access elements using .first and .second

	pair<int,string> p ={7,"Ankit"};
	p.first = 21;

	cout << p.first << " " << p.second;

	Sorting arrays/vectors of pairs (Useful)

	pair<int,int> p[5]; // array of 5 pairs
	p[0] = {1,2}; p[1] = {5,2}; p[2] = {8,1}; p[3] = {1,0}; p[4] = {3,4};

	sort(p,p+5);
	//Now the array looks like this
	[{1,0},{1,2},{3,4},{5,2},{8,1}]
	//Sorting is done in a way that the ordering is done by the first element, but whenever the first is equal, ties are broken by comparing second.

	//sort the students with decreasing marks
	vector<pair<int, string>> v; // {score,name}
	//after populating the vector
	sort(v.begin(), v.end());

*/

/*
	Iterators -> behave a lot like pointers.
	vector<int> v = {10,15,12,5,20};
	vector<int>::iterator it = v.begin();
	//OR
	auto it = v.begin(); // auto keyword is used to deduce datatype automatically.
	cout << *it; //10
	it++;
	cout << *it; //15
	it--;
	cout << *it; //10
	cout << *(it+3); //5
	note: v.end() is the iterator to a non-existent element(after the last element)

	//Pointer analogy
	int a[5] = {10,15,12,5,20};
	int *p = a;

	cout << *p; //10
	p++;
	cout << *p; //15
	p--;
	cout << *p; //10
	cout << *(p+3); //5

*/

/*
	Set -> a container which keeps a unique copy of every element in sorted order. Java equivalent of TreeSet. It implements Red and Black tree DS internally to keep it sorted.
	set<int> s; // empty set of integers
	set<string> s; // empty set of strings

	Functions ->
	s.insert(x); // insert value x into set, do nothing if already present. O(log N)
	s.erase(x); // erase the value x from set if present. O(log N)
	s.count(x); // return 0 if x is not in set and 1 if x is in set. O(log N)
	s.clear() // erase all elements. O(n)
	s.size(); // returns the current size of the set. O(1)

	[] operator doesn't work with set container. cout << s[0]; // wrong random access is not allowed in sets

	Set Iterators ->
	offer less features than vector iterators.

	auto it = s.begin(); // it is the iterator to the first element
	it++,it--,++it,--it -> all valid and work in O(log N) time.
	note : (it+5) or it+=2 etc are invalid, to advance multiple steps , do it++ multiple times.

	Functions related to set iterators -->
	s.find(x); //return iterator to element with value x. return s.end() if not found. -> O(log N)
	s.lower_bound(x); //returns iterator to the first element which is >=x. returns s.end() if not found --> O(log N)
	s.upper_bound(x); // returns iterator to the first element which is > x. returns s.end() if not found. --> O(log N)
	s.erase(it); erases the element with iterator it --> O(log N)

	Both of the next 2 lines are exactly same ->
	if(s.find(10) == s.end()) cout << "Not found";
	if(s.count(10) == 0) cout << "Not found";

*/

/*
	Map -> can be thought of as special arrays in which the indices (keys) of elements can be negative or very big or even strings! These are like python-dictionaries. In Java equivalent is TreeMap.

	map<key_datatype, value_datatype> m;
	map<string,int> m; // defines a map in which the keys of elements are strings.

	note: maps are very similar to sets, in sets the values are unique and sorted, in maps keys are unique and sorted.(lexicographically increasing order)

	m["hello"] = 50;
	m["world"] = 12;

	cout << m["hello"] << m["world"]; // 50 12

	map<int,int> m;
	m[-234] = 49; // negative ints are also valid as keys

	very common use case: Count frequency of various objects

	m.clear() -> clears a map
	m[key] -> value of element with key. -> O(log N)
	m.count(key), m.find(key), m.erase(key), m.lower_bound(key), m.upper_bound(key) -> similar to set.

	note: map iterators behave similar to set iterators , but upon doing *it(dereference) instead of getting the value, we get a pair of {key,value}.

	note:
	(*it).first and (*it).second ca be written as ->
	it -> first
	it -> second
	This works for pointers and iterators also.

	Examples ->
	map<string,double> m;
	//insert values in map
	auto it = m.find("ankit");
	pair<string,double> p = *it; // {"ankit",m["ankit"]}

	map<int, int> m;
	cout << m.size() << "\n";
	cout << m[15]; // if element is not present and we try to print it, it instantly create the element with key->15 and value 0.
	//size of map also increases,
	m[10] = 100;
	m[26] = 1000;
	cout << "\n" << m.size();

*/

/*
	//CodeForces Problem

	map<string, int> freq;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (freq[s] == 0) {
			cout << "OK" << "\n";
		} else {
			cout << s << freq[s] << "\n";
		}
		freq[s]++;
	}

*/

/*
	Iterating Containers

	for(auto it = s.begin(); it != s.end(); it++){
		//*it
	}

	//This works for all three -> set,map,vector

	Shorthand ->

	vector<int> v;
	for(int x:v){
		//x;
	}

	set<int> s;
	for(int x:s){
		//x;
	}

	map<int,int> m;
	for(pair<int,int> x:m){
		//x.first , x.second;
	}

*/

/*

	set<int> s;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		s.insert(x);
	}

	for (int x : s) {
		cout << x << " ";
	}

	//at every step all the elements remain in increasing order, even though we erase any element. powerful thing about set

*/

/*

	set<pair<int,string>> s; //int->price, string->name
	s.begin() will give the cheapest object
	//good use case for sets.
*/

/*
	Custom Comparators-> define your own rule for sorting
	Ex :->
		bool decreasing_order(int x, int y){
			return x > y;
		}
		int a[10];
		sort(a,a+10, decreasing_order); // sorts in descending order

	The comparator with arguments (x,y) should return true IF AND ONLY IF, x is necessarily on the left of y in the sorted array.

*/

/*
	Further Studies
		-> Queue
		-> Stack
		-> Deque (Doubly Ended Queue)
		-> Priority_Queue
		-> multiset / multimap -> can store duplicates
		-> unordered_set / unordered_map -> HashSet / HashMap in Java

*/